// Lab 4 Part 1.c
// Chris Pybus and Jeff Pistacchio
//
//This program polls an Analog input and outputs the voltage in hex and dec
//-------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------
#include <c8051f120.h>          // SFR declarations.
#include <stdio.h>              // Necessary for printf.
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
void MAC_Init(void);
unsigned short int read_AD_input(void);

//-------------------------------------------------------------------------------------------
// Global Variables
//-------------------------------------------------------------------------------------------

unsigned int count = 0;				//used to count the number of MAC iterations 
									//for the average value calculation
__sbit __at (0x90) PB;
unsigned char n = 0;				//for for loop in calc average 
//-------------------------------------------------------------------------------------------
// MAIN Routine
//-------------------------------------------------------------------------------------------
void main (void)
{
	unsigned short int volt;
	float print;
	float voltL = 2.5;		//store low voltage value
	float voltH = 0;		//store high voltage value
	unsigned long int avgV = 0;	//store average voltage running sum
	unsigned short int value;
	unsigned char sum1;
	unsigned char sum2;
	unsigned char sum3;
	unsigned char sum4;
	
	WDTCN   = 0xDE; // Disable watchdog timer.
    WDTCN   = 0xAD;
	
    SFRPAGE = CONFIG_PAGE;
	
    SYSCLK_Init(); // Initialize the oscillator.
	TIMER_Init(); // Initialize timers
    UART_Init(); // Initialize UARTs.
    PORT_Init(); // Configure the Crossbar and GPIO.
	ADC_Init();
	
	printf("\033[2J"); //Erase screen and move cursor to the home position.
	
	printf("Press Push Button\r\n");
	while(PB);
	printf("\033[2J");
	
	while(1)
	{
		//printf("\033[2J");
		//Read Analog Input
		volt = read_AD_input();
		value = volt;
		
		//Check for low Value
		if (volt < voltL)
		{
			voltL = volt;
		}
		//Check for high value
		if (volt > voltH)
		{
			voltH = volt;
		}
		
		//MAC_____________
		SFRPAGE = MAC0_PAGE;
		//Clear Accumulator
		MAC0CF = 0x08;
		//set Mac A value
		MAC0AH = 0x00;
		MAC0AL = 0x01;
		//Set Mac B value
		value = volt>>8;
		MAC0BH = value;
		value = (char)volt%16;
		MAC0BL = value;
		SFRPAGE = MAC0_PAGE;
		SFRPAGE = MAC0_PAGE;
		//Multiply, Accumulate
		//Set Mac B value
		value = (volt>>8);
		MAC0BH = value;
		value = (char)volt%16;
		MAC0BL = value;
		SFRPAGE = MAC0_PAGE;
		SFRPAGE = MAC0_PAGE;
		//Multiply, Accumulate
		//Set Mac B value
		value = (volt>>8);
		MAC0BH = value;
		value = (char)volt%16;
		MAC0BL = value;
		SFRPAGE = MAC0_PAGE;
		SFRPAGE = MAC0_PAGE;
		//Multiply, Accumulate
		//Set Mac B value
		value = (volt>>8);
		MAC0BH = value;
		value = (char)volt%16;
		MAC0BL = value;
		SFRPAGE = MAC0_PAGE;
		SFRPAGE = MAC0_PAGE;
		//Multiply, Accumulate
		//Set Mac B value
		value = (volt>>8);
		MAC0BH = value;
		value = (char)volt%16;
		MAC0BL = value;
		SFRPAGE = MAC0_PAGE;
		SFRPAGE = MAC0_PAGE;
		//Multiply, Accumulate
		//Set Mac B value
		value = (volt>>8);
		MAC0BH = value;
		value = (char)volt%16;
		MAC0BL = value;
		SFRPAGE = MAC0_PAGE;
		SFRPAGE = MAC0_PAGE;
		//Multiply, Accumulate
		//Set Mac B value
		value = (volt>>8);
		MAC0BH = value;
		value = (char)volt%16;
		MAC0BL = value;
		SFRPAGE = MAC0_PAGE;
		SFRPAGE = MAC0_PAGE;
		//Multiply, Accumulate
		//Set Mac B value
		value = (volt>>8);
		MAC0BH = value;
		value = (char)volt%16;
		MAC0BL = value;
		SFRPAGE = MAC0_PAGE;
		SFRPAGE = MAC0_PAGE;
		//Multiply, Accumulate
		//Set Mac B value
		value = (volt>>8);
		MAC0BH = value;
		value = (char)volt%16;
		MAC0BL = value;
		SFRPAGE = MAC0_PAGE;
		SFRPAGE = MAC0_PAGE;
		//Multiply, Accumulate
		//Set Mac B value
		value = (volt>>8);
		MAC0BH = value;
		value = (char)volt%16;
		MAC0BL = value;
		SFRPAGE = MAC0_PAGE;
		SFRPAGE = MAC0_PAGE;
		//Multiply, Accumulate
		
		//put accumulator registors onto a long int
		avgV = MAC0ACC3;
		avgV = (avgV<<8)+ MAC0ACC2;
		avgV = (avgV<<8)+ MAC0ACC1;
		avgV = (avgV<<8)+ MAC0ACC0;

		sum1 = MAC0ACC0; sum2 = MAC0ACC1; sum3 = MAC0ACC2; sum4 = MAC0ACC3;
		
		SFRPAGE = UART0_PAGE;
		//Print Digital voltage value to six decimal places
		print = volt; //store ADC value on float.
		printf_fast_f("        Voltage: %.6f V | ", (print * 2.4/4096));
		printf("%x \r",volt);
		printf_fast_f("\n    Low Voltage: %.6f V | ", (voltL * 2.4/4096));
		printf("%x \r",voltL);
		printf_fast_f("\n   High Voltage: %.6f V | ",  (voltH * 2.4/4096));
		printf("%x \r",voltH);
		print = avgV;
		printf_fast_f("\nAverage Voltage: %.6f V | ", (2*print*2.4/(77100)));
		printf("%llx \r",avgV/10);
		//printf("\n BHigh %x BLow %x \r\n Byte 4 %x \r\n Byte 3 %x \r\n Byte 2 %x \r\n Byte 1 %x \r", volt%16, volt/16, sum4, sum3, sum2,sum1);
		
		printf("\033[1;0H");
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

unsigned short int read_AD_input(void)
{
	unsigned short int volt;
	
	SFRPAGE = 0x00;
	
	AD0BUSY = 1;		//Start conversion
	while (!AD0INT);	//wait for ADC to finish	
	volt = (ADC0H << 8) + ADC0L;
	
	return volt;
}
void MAC_Init(void)
{
	MAC0CF = 0x0A;
}
