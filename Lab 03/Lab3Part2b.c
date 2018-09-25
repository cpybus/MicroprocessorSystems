// Lab 3 Part 2b.c
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
void UART0int (void) __interrupt 4;
void UART1int (void) __interrupt 20;

void sendToUART0(char c);
void sendToUART1(char c);

char sendtouart0 = 0;
char sendtouart1 = 0;
char uart1char = 0;
char uart0char = 0;
char sendingtouart1 = 0;

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
	
	IE        = 0x90; //enable all interrupts, and uart0 interrupt   
	EIE2      = 0x40; //enable  uart1 interrupts
	
	while(1)
	{
		if(sendtouart0 == 1 || sendtouart1 == 1)
		{
			if(sendtouart0 == 1)
			{
				sendToUART0(uart0char);
				sendtouart0 = 0;
				uart0char = 0;
			}
			else if(sendtouart1 == 1)
			{
				sendToUART1(uart1char);
				sendtouart1 = 0;
				uart1char = 0;
			}
		}
	}
}

//-------------------------------------------------------------------------------------------
// Interrupts
//-------------------------------------------------------------------------------------------
void UART0int (void) __interrupt 04
{
	char c; 
	
	IE=0x00; //Turning off interrupt to prevent recursion
	
	SFRPAGE = UART0_PAGE;
	if(RI0==1)
	{
		c=SBUF0; //read in character from buffer, page 0
		RI0 = 0; //set flag back to low
		
		sendtouart1 = 1;
		uart1char = c;
		sendingtouart1=1;
	}
	
	SBUF0=c; //send character back to console, page 0
	while(TI0==0); //wait until TI0 is high because flag goes high when transmit is complete
	TI0=0; //set flag back to 0
	
	IE=0x90; //turn flag back on
	
	return;
}

void UART1int (void) __interrupt 20
{
	char c; 
	
	IE=0x00; //Turning off interrupt to prevent recursion
	
	SFRPAGE = UART1_PAGE;
	
	if(sendingtouart1==1) //if interrupt is coming from UART0, simply print to screen (which will transmit to other UART1)
	{
		sendingtouart1 = 0;
		
		if(RI1==1)
		{
			c=SBUF1; //read in character from buffer, Page 1
			RI1 = 0; //set flag back to low	
			
			sendtouart0 = 1;
			uart0char = c;
		}
		
		SBUF1=c; //send character back to console, page 1
		while(TI1==0); //wait until TI0 is high because flag goes high when transmit is complete
		TI1=0; //set flag back to 0
	}
	else //if transmit is coming from other UART1, simply send along to UART0. Do not print to screen.
	{
		if(RI1==1)
		{
			c=SBUF1; //read in character from buffer, Page 1
			RI1 = 0; //set flag back to low	
			
			sendtouart0 = 1;
			uart0char = c;
		}
	}
	
	IE=0x90; //turn flag back on
	
	return;
}

//-------------------------------------------------------------------------------------------
// Other Functions
//-------------------------------------------------------------------------------------------
void sendToUART0(char c)
{
	IE=0x00;
	
	SFRPAGE = UART0_PAGE;
	SBUF0=c; //send character back to console 
	while(TI0==0); //wait until TI0 is high
	TI0=0; //set flag back to 0
	
	IE=0x90; //turn flag back on
}

void sendToUART1(char c)
{
	IE=0x00;
	
	SFRPAGE = UART1_PAGE;
	SBUF1=c; //send character back to console 
	while(TI1==0); //wait until TI0 is high
	TI1=0; //set flag back to 0
	
	IE=0x90; //turn flag back on
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
	//EIP2      = 0x40; //set UART1 interrupt priority to high
	
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


