// Lab 3 Part 1.c
// Chris Pybus and Jeff Pistacchio
//
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
void getChar(void);

//-------------------------------------------------------------------------------------------
// MAIN Routine
//-------------------------------------------------------------------------------------------
void main (void)
{
	WDTCN   = 0xDE; // Disable watchdog timer.
    WDTCN   = 0xAD;
	
    SFRPAGE = CONFIG_PAGE;
	
    SYSCLK_Init(); // Initialize the oscillator.
	TIMER_Init(); // Initialize timers
    UART_Init(); // Initialize UARTs.
    PORT_Init(); // Configure the Crossbar and GPIO.

	
	SFRPAGE = UART0_PAGE;
    printf("\033[2J"); //Erase screen and move cursor to the home position.
	printf("This is UART0.\n\r");
    
	
	SFRPAGE = UART1_PAGE;
    printf("\033[2J"); //Erase screen and move cursor to the home position.
	printf("This is UART1.\n\r");

	
	while(1)
	{
		getChar();
	}
}

//-------------------------------------------------------------------------------------------
// Functions
//-------------------------------------------------------------------------------------------
void getChar(void)
{
	char c;
	
	while(1)
	{
		SFRPAGE = UART0_PAGE;
		if(RI0 == 1)
		{
			RI0 = 0;
			c = SBUF1;
			break;
		}
		
		SFRPAGE = UART1_PAGE;
		if(RI1 == 1)
		{
			RI1 = 0;
			c = SBUF1;
			break;
		}
	}
	
	SFRPAGE = UART1_PAGE;
	printf("%c\n\r", c);
	
	SFRPAGE = UART0_PAGE;
	printf("%c\n\r", c);
}

//-------------------------------------------------------------------------------------------
// Timer_Init
//-------------------------------------------------------------------------------------------
void TIMER_Init(void)
{
	//Timer1, used for UART1, baud 115200
	SFRPAGE   = TIMER01_PAGE;
	TCON = 0x40;
	TMOD = 0x20;
	CKCON = 0x10;
	TH1 = 0xA0;
	
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
	XBR2 = 0x44; //enable UART1
	
	P0MDOUT = 0x05;
	P0 = ~0x05;
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
		
	//UART1
    SFRPAGE   = UART1_PAGE;
    SCON1     = 0x30;
	TI1 = 1;
}


