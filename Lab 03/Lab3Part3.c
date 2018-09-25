// Lab 3 Part 1.c
// Chris Pybus and Jeff Pistacchio
//
//-------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------
#include <c8051f120.h>          // SFR declarations.
#include <stdio.h>              // Necessary for printf.
#include "putget.h"             // Necessary for printf

__sbit __at (0x82) MOSI ;
__sbit __at (0x83) MISO ;
__sbit __at (0x84) SCK ;
__sbit __at (0x85) NSS ;

//-------------------------------------------------------------------------------------------
// Function PROTOTYPES
//-------------------------------------------------------------------------------------------
void main(void);
void TIMER_Init(void);
void PORT_Init(void);
void SYSCLK_Init(void);
void UART_Init(void);
void SPI_Init(void);

char SPI_Write(char txdata);

//-------------------------------------------------------------------------------------------
// MAIN Routine
//-------------------------------------------------------------------------------------------
void main (void)
{
	char choice;
	char topscrollline = 1; //max == 12
	char bottomscrollline = 14; //max == 25
	
	WDTCN   = 0xDE; // Disable watchdog timer.
    WDTCN   = 0xAD;
	
    SFRPAGE = CONFIG_PAGE;
	
    SYSCLK_Init(); // Initialize the oscillator.
	TIMER_Init(); // Initialize timers
    UART_Init(); // Initialize UARTs.
    PORT_Init(); // Configure the Crossbar and GPIO.
	SPI_Init();
	
	printf("\033[2J"); //Erase screen and move cursor to the home position.
	
	//Scroll area
	
	
	
	
	//Set top header
	printf("\033[1;0H"); //move cursor
	printf("Keys typed on keyboard:");
	
	//set border
	printf("\033[13;0H"); 
	printf("================================================");
	
	//set bottom header
	printf("\033[14;0H"); //move curosr
	printf("Keys received from SPI:");
	
	
	while(1)
	{
		SFRPAGE   = UART0_PAGE;
		choice = getchar(); 
		
		if(topscrollline < 12)
		{
			topscrollline++; //go to next line because there is still space
			printf("\033[%i;0H", topscrollline);
			printf("%c", choice);
		}
		else
		{
			printf("\033[2;12r"); //set scroll area on top
			printf("\033[11;0H");
			printf("\n\r%c", choice);
		}
		
		choice = SPI_Write(choice);
		
		if(bottomscrollline < 25)
		{
			bottomscrollline++; //go to next line because there is still space
			printf("\033[%i;0H", bottomscrollline);
			printf("%c", choice);
		}
		else
		{
			printf("\033[15;25r"); //set scroll area on bottom
			printf("\033[25;0H");
			printf("\n\r%c", choice);
		}
	}
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
    SFRPAGE   = CONFIG_PAGE;
    P0MDOUT   = 0x35;
    XBR0      = 0x06;
	XBR1      = 0x00;
    XBR2      = 0x40;
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

//-------------------------------------------------------------------------------------------
// SPI
//-------------------------------------------------------------------------------------------
void SPI_Init(void)
{
    SFRPAGE   = SPI0_PAGE;
    SPI0CFG   = 0x40;
    SPI0CN    = 0x09; 
    SPI0CKR   = 0x18; //clock rate is 442368
	
	//NSSMD1 = 1;
}

char SPI_Write(char txdata)
{
	unsigned int i = 1;
	char data;
	
	SFRPAGE   = UART0_PAGE;
	
	//printf("Sent: %c\n\r", txdata);
	
	SFRPAGE   = SPI0_PAGE;
	//write
	SPIF = 0;
	NSSMD0 = 0;					//enable slave select
	while(SPI0CFG & 0x80); 		//wait for completed transfer before 
	SPIF = 0; 					//set SPI busy 
	SPI0DAT = txdata;			//write data to spi
	while(!SPIF);
	SPIF = 0;
	NSSMD0 = 1; 					//release slave select
	
	//Read
	for(i = 0; i<60000; i++);	//wait 1-2ms
	SPI0DAT = 0xFF;				//write dummy byte to register
	while(SPI0CFG & 0x80); 		//wait for completed transfer before
	SPIF = 0;					//clear flag
	
	data = SPI0DAT;				//read data
	
	return data;
} 


