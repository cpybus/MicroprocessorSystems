// Lab 4 Part 1.c
// Chris Pybus and Jeff Pistacchio
//
//This program polls an Analog input and outputs the voltage in hex and dec
//-------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------
#include <c8051f120.h>          // SFR declarations.
#include <stdio.h>         
#include <math.h>
#include "putget.h"             // Necessary for printf


//-------------------------------------------------------------------------------------------
// Function PROTOTYPES
//-------------------------------------------------------------------------------------------
void main(void);
void TIMER_Init(void);
void PORT_Init(void);
void SYSCLK_Init(void);
void UART_Init(void);
void ADC_Init(void);
void DAC_Init();
unsigned short int read_AD_input(void);
void dac_output(unsigned short value);
void dac_output_sinwave(void);
void dac_output_sawtooth();

//-------------------------------------------------------------------------------------------
// Global Variables
//-------------------------------------------------------------------------------------------
unsigned int count = 0;	 //used to count the number of MAC iteration
__sbit __at (0x90) PB;

//-------------------------------------------------------------------------------------------
// MAIN Routine
//-------------------------------------------------------------------------------------------
void main (void)
{
	unsigned short int volt = 0;
	int index = 0;
	//float volt2 = 0;
	
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
	
	printf("Press push button to start part 3");
	while(PB);
	printf("\rRunning Part 3                       \n\n\r");
	
	while(1)
	{
		volt = read_AD_input();
		//volt2 = volt;
		//printf_fast_f("Voltage: %.2f V \r", (volt * 2.4/4096));
		
		dac_output(volt);
	}
	
}

//-------------------------------------------------------------------------------------------
// Timer_Init
//-------------------------------------------------------------------------------------------
void TIMER_Init(void)
{
	
	//Timer2, used for UART0, baud 115200
    SFRPAGE   = TMR2_PAGE;
    TMR2CN    = 0x04;
    TMR2CF    = 0x08;
    RCAP2L    = 0xF4;
    RCAP2H    = 0xFF;
}

//-------------------------------------------------------------------------------------------
// PORT_Init
//-------------------------------------------------------------------------------------------
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
	//P1MDIN = 0xFE;
}

//-------------------------------------------------------------------------------------------
// SYSCLK_Init
//-------------------------------------------------------------------------------------------
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

//-------------------------------------------------------------------------------------------
// UART0_Init
//-------------------------------------------------------------------------------------------
void UART_Init()
{
	//UART0
	SFRPAGE   = UART0_PAGE;
    SCON0     = 0x50;
    SSTA0     = 0x05;
	TI0 = 1;
		
}
void ADC_Init(void)
{
 	SFRPAGE = 0;
	REF0CN = 0x03; 		// Set Vref to use internal reference voltage (2.4 V)
	AMX0CF &= 0xF0;		// Configure A/D pins
	AMX0SL &= 0xF0;	// Set AIN0.0 to single ended input
 	ADC0CF |= 0x28; 	// Set A/D converter gain to 1 and define SAR clock speed 2Mhz
	ADC0CN = 0x80; 		// Enable A/D converter (ADC2)
}

void DAC_Init()
{
    SFRPAGE   = DAC0_PAGE;
    DAC0CN    = 0x80;
}

unsigned short int read_AD_input(void)
{
	unsigned short int volt;
	
	SFRPAGE = 0x00;
	AD0BUSY = 1;		//Start conversion
	while (!AD0INT);	//wait for ADC to finish
	
	volt = ADC0H<<8 | ADC0L;

	//printf("currently: %i  \r\n", volt);
	
	return volt;
}

void dac_output(unsigned short val)
{
	DAC0L = val;
	DAC0H = val >> 8;
}