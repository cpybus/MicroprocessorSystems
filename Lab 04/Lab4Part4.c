// Lab 4 Part 4.c
// Chris Pybus and Jeff Pistacchio
//
//This program polls an Analog input and outputs the voltage in hex and dec
//-------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------
#include <c8051f120.h>          // SFR declarations.
#include <stdio.h>     
#include "putget.h"             // Necessary for printf

__sbit __at (0x90) PB;

void SYSCLK_Init(void)
{
    int i = 0;
    SFRPAGE = CONFIG_PAGE;
    OSCXCN = 0x67;
    for (i = 0; i < 3000; i++);  // Wait 1ms for initialization
    while ((OSCXCN & 0x80) == 0);
    CLKSEL = 0x01;
    OSCICN &= ~0x80;
}

void TIMER_Init(void)
{
	//Timer2, used for UART0, baud 115200
    SFRPAGE   = TMR2_PAGE;
    TMR2CN    = 0x04;
    TMR2CF    = 0x08;
    RCAP2L    = 0xF4;
    RCAP2H    = 0xFF;
}

void UART_Init()
{
	//UART0
	SFRPAGE   = UART0_PAGE;
    SCON0     = 0x50;
    SSTA0     = 0x05;
	TI0 = 1;	
}

void PORT_Init()
{
	SFRPAGE = CONFIG_PAGE;
	
	XBR0 = 0x04; //eanble UART0
	XBR1 = 0x00; 
	XBR2 = 0x40; 
	
	P0MDOUT = 0x05;
	P0 = ~0x05;
	P1MDOUT &= 0xFE;
	P1 |= 0x01;		//PB input on p1.0
}

void ADC_Init(void)
{
 	SFRPAGE = ADC0_PAGE;
	REF0CN = 0x03; 		// Set Vref to use internal reference voltage (2.4 V)
	AMX0CF &= 0xF0;		// Configure A/D pins
	AMX0SL &= 0xF0;	// Set AIN0.0 to single ended input
 	ADC0CF = 0x28; 	// Set A/D converter gain to 1 and define SAR clock speed 2Mhz
	ADC0CN = 0x81; 		// Enable A/D converter (ADC) and left justify output
}

void DAC_Init()
{
    SFRPAGE   = DAC0_PAGE;
	DAC0CN    = 0x84; //left aligned
}

void MAC_Init(void)
{
	MAC0CF = 0x0A;
}

void main (void)
{
	unsigned short int x2 = 0;	//2 inputs ago
	unsigned short int x1 = 0;	//previous input
	unsigned short int x = 0;	//current input
	unsigned short int y1 = 0;	//previous output
	unsigned short int y = 0;	//current output.
	
	WDTCN   = 0xDE; // Disable watchdog timer.
    WDTCN   = 0xAD;
	
    SFRPAGE = CONFIG_PAGE;
	
    SYSCLK_Init(); // Initialize the oscillator.
	TIMER_Init(); // Initialize timers
    UART_Init(); // Initialize UARTs.
    PORT_Init(); // Configure the Crossbar and GPIO.
	ADC_Init(); 
	DAC_Init(); 
	
	printf("\033[2J"); //Erase screen and move cursor to the home position.
	
	printf("Press push button to start part 4");
	while(PB);
	printf("\rRunning Part 4                       \n\n\r");
	
	while(1)
	{
		SFRPAGE = ADC0_PAGE;
		AD0BUSY = 1;		//Start conversion
		while (!AD0INT);	//wait for ADC to finish
		x = ((ADC0H << 8) | ADC0L); //Turn 12 bit adc output to 16 bit fractional value
									//MSB must be zero (if positive) bc 2'c compliment
									//X will become a number between 0 and 1 that's relative to 0 to 4096
									//ie, if ADC measures 2048, x will be .5
		
		//MAC Operations///////////////////////////
		SFRPAGE = MAC0_PAGE;
		MAC0CF = 0x0A; //clear accumulator and operate in fractional mode
		
		// Operation: 10/32 * x(k)
		// set Mac A value: Coefficient
		// 10/32 = .3125 => 0|010 1000 0000 0000 => 0x2800    
		MAC0AH = 0x28;
		MAC0AL = 0x00; 
		//Set Mac B value
		MAC0BH = x>>8;
		MAC0BL = x;
		
		// Operation: 25/104 * x(k-1)
		// set Mac A value: Coefficient
		// 25/104 = 0.24038 => 0|001 1110 1100 0100 => 0x1EC4
		MAC0AH = 0x1E;
		MAC0AL = 0xC4;
		//Set Mac B value
		MAC0BH = x1>>8;
		MAC0BL = x1;
		
		// Operation: 10/32 * x(k-2)
		// set Mac A value: Coefficient
		// 10/32 = .3125 => 0|010 1000 0000 0000 => 0x2800
		MAC0AH = 0x28;
		MAC0AL = 0x00; 
		//Set Mac B value
		MAC0BH = x2>>8;
		MAC0BL = x2;
		
		// Operation: 19/64 * y(k-1)
		// set Mac A value: Coefficient
		// 19/64 = .296875 => 0|010 0110 0000 0000 => 0x2600 
		MAC0AH = 0x26;
		MAC0AL = 0x00;
		//Set Mac B value
		MAC0BH = y1>>8;
		MAC0BL = y1;

		SFRPAGE = MAC0_PAGE; //wait for operation

		y = (MAC0ACC3<<8) | MAC0ACC2;
		
		//reset stored values
		y1 = y;
		x2 = x1;
		x1 = x;

		//output y to DAC
		SFRPAGE = DAC0_PAGE;
		DAC0H = y >> 8;
		DAC0L = y;
		
	}
	
}