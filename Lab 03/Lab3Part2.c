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
void UART0int (void) __interrupt 4;
void UART1int (void) __interrupt 20;

void sendToUART0(char c);
void sendToUART1(char c);

char sendtouart0 = 0;
char sendtouart1 = 0;
char uart1char = 0;
char uart0char = 0;

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

	sendToUART0('U');
	sendToUART0('A');
	sendToUART0('R');
	sendToUART0('T');
	sendToUART0('0');
	sendToUART0('\n');
	sendToUART0('\r');
	
	sendToUART1('U');
	sendToUART1('A');
	sendToUART1('R');
	sendToUART1('T');
	sendToUART1('1');
	sendToUART1('\n');
	sendToUART1('\r');

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
void UART0int (void) __interrupt 4
{
	char c; 
	IE=0x00; //Turning off interrupt to prevent recursion
	
	SFRPAGE = UART0_PAGE;
	c=SBUF0; //read in character from buffer
	RI0 = 0; //set flag back to low
	
	//none of the below lines set off the interrupt because it is disabled
	SBUF0=c; //send character back to console 
	while(TI0==0); //wait until TI0 is high
	TI0=0; //set flag back to 0

	IE=0x90; //turn flag back on
	
	sendtouart1 = 1;
	uart1char = c;

}

void UART1int (void) __interrupt 20
{
	char c; 
	IE=0x00; //Turning off interrupt to prevent recursion
	
	SFRPAGE = UART1_PAGE;
	c=SBUF1; //read in character from buffer
	RI1 = 0; //set flag back to low
	
	//none of the below lines set off the interrupt because it is disabled
	SBUF1=c; //send character back to console 
	while(TI1==0); //wait until TI0 is high
	TI1=0; //set flag back to 0

	IE=0x90; //turn flag back on
	
	sendtouart0 = 1;
	uart0char = c;
	
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
    //PLL0CN    = 0x04;
    //CCH0CN    &= ~0x20;
    //SFRPAGE   = LEGACY_PAGE;
    //FLSCL     = 0x90;
    //SFRPAGE   = CONFIG_PAGE;
    //CCH0CN    |= 0x20;
    //PLL0CN    |= 0x01;
    //PLL0DIV   = 0x04;
    //PLL0FLT   = 0x2F;
    //PLL0MUL   = 0x09;
    //for (i = 0; i < 15; i++);  // Wait 5us for initialization
    //PLL0CN    |= 0x02;
    //while ((PLL0CN & 0x10) == 0);
    CLKSEL = 0x01;
    OSCICN &= ~0x80;
}

//-------------------------------------------------------------------------------------------
// UART0_Init
//-------------------------------------------------------------------------------------------
void UART_Init()
{
	IE        = 0x90; //enable all interrupts, and uart0 interrupt   
	EIE2      = 0x40; //enable  uart1 interrupts
	
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


