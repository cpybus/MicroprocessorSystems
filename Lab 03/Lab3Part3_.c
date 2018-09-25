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
char SPI_Transfer (char SPI_byte, char rw);

//-------------------------------------------------------------------------------------------
// MAIN Routine
//-------------------------------------------------------------------------------------------
void main (void)
{
	char byte;
	
	WDTCN   = 0xDE; // Disable watchdog timer.
    WDTCN   = 0xAD;
	
    SFRPAGE = CONFIG_PAGE;
	
    SYSCLK_Init(); // Initialize the oscillator.
	TIMER_Init(); // Initialize timers
    UART_Init(); // Initialize UARTs.
    PORT_Init(); // Configure the Crossbar and GPIO.
	SPI_Init();
	ADC_Init();							// Initialize ADC 2
	

	while(1)
	{
		printf("Testing write \n\r");
		//get data from keyboard
		byte = getchar();
		printf("\r\nReceived from keyboard\r\n");
		//send data on spi
		SPI_Transfer(byte, 0);
		printf("Sent to SPI\r\n");
		
		//recieve data from spi
		byte = SPI_Transfer(0,1);
		printf("Received from SPI \r\n");
		//print on screen
		printf("Data recieved: %c\n\r", byte);
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
	XBR1	  = 0x00;
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
	//IE        = 0x90; //enable all interrupts, and uart0 interrupt   
	
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
    SPI0CN    = 0x0D;
    SPI0CKR   = 0x0A;
}

char SPI_Transfer (char SPI_byte, char rw)
{
	//rw determines read or write. 0 for write,1 for read
	SFRPAGE = 0;

	if (!rw)
	{
		//write
		NSSMD0 = 1;							//enable slave select
		while(!SPIF);						//check if spi is busy
		SPIF = 0;
		SPI0DAT = SPI_byte;					//write data to spi
		WCOL = 0;							//clear write collision flag
	}
	else if (rw)
	{
		int i = 0;
		//Read
		NSSMD0 = 0;							//release slave select
		for(i = 0; i<4000; i++);			//wait 1-2ms
		SPI0DAT = 0xFF;						//write dummy bit to register
		while(!SPIF);						//Check if SPI is busy
		SPIF = 0;							//clear flag
		SPI_byte = SPI0DAT;						//read data
	
	}
	return SPI_byte;
	
}


