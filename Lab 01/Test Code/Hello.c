//------------------------------------------------------------------------------------
// Hello.c
//------------------------------------------------------------------------------------
//8051 Test program to demonstrate serial port I/O.  This program writes a message on
//the console using the printf() function, and reads characters using the getchar()
//function.  An ANSI escape sequence is used to clear the screen if a '2' is typed. 
//A '1' repeats the message and the program responds to other input characters with
//an appropriate message.
//
//Any valid keystroke turns on the green LED on the board; invalid entries turn it off
//------------------------------------------------------------------------------------
// Resources
//------------------------------------------------------------------------------------
//http://www.rapidtables.com/convert/number/hex-to-ascii.htm
//http://www.tutorialspoint.com/c_standard_library/c_function_isprint.htm
//http://stackoverflow.com/questions/8060170/printing-hexadecimal-characters-in-c
//
//
//------------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------------
#include <c8051f120.h>
#include <stdio.h>
#include <ctype.h>
#include "putget.h"

//------------------------------------------------------------------------------------
// Global Constants
//------------------------------------------------------------------------------------
#define EXTCLK      22118400            // External oscillator frequency in Hz
#define SYSCLK      49766400            // Output of PLL derived from (EXTCLK * 9/4)
#define BAUDRATE    115200              // UART baud rate in bps

//------------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------------
void main(void);
void SYSCLK_INIT(void);
void PORT_INIT(void);
void UART0_INIT(void);

//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------
__sbit __at (0x90) Pot0; //Input on Port 1, Pin 0 (12 on board)
__sbit __at (0x91) Pot1; //Input on Port 1, Pin 1 (13 on board)
__sbit __at (0x92) Pot2; //Input on Port 1, Pin 2 (10 on board)
__sbit __at (0x93) Pot3; //Input on Port 1, Pin 3 (11 on board)

__sbit __at (0xA0) LED0; //Output on port 2, Pin 0, (29 on board)
__sbit __at (0xA1) LED1; //Output on port 2, Pin 0, (30 on board)
__sbit __at (0xA2) LED2; //Output on port 2, Pin 0, (27 on board)
__sbit __at (0xA3) LED3; //Output on port 2, Pin 0, (28 on board)

//------------------------------------------------------------------------------------
// MAIN Routine
//------------------------------------------------------------------------------------
void main(void)
{
    char Mem0;
	char Mem1;
	char Mem2;
	char Mem3;

    WDTCN = 0xDE;                       // Disable the watchdog timer
    WDTCN = 0xAD;

	PORT_INIT();                        // Initialize the Crossbar and GPIO
    SYSCLK_INIT();                      // Initialize the oscillator
    UART0_INIT();                       // Initialize UART0

    SFRPAGE = UART0_PAGE;               // Direct output to UART0

	Mem0 = Pot0;
	Mem1 = Pot1;
	Mem2 = Pot2;
	Mem3 = Pot3;
	while(1)
    {
	    printf("\033[H"); //go home, top left
        
		if(Pot0 != Mem0 || Pot1 != Mem1 || Pot2 != Mem2 || Pot3 != Mem3)
		{
			printf("\033[2J"); //erase screen
		
			if(Pot0 == 1)
			{
				LED0 = 1;
				printf("LED0 is HIGH");
			}
			else
			{
				LED0 = 0;
				printf("LED0 is LOW");
			}
			Mem0 = Pot0;
			
			printf("\n\r");
			
			if(Pot1 == 1)
			{
				LED1 = 1;
				printf("LED1 is HIGH");
			}
			else
			{
				LED1 = 0;
				printf("LED1 is LOW");
			}
			Mem1 = Pot1;
			
			printf("\n\r");
			
			if(Pot2 == 1)
			{
				LED2 = 1;
				printf("LED2 is HIGH");
			}
			else
			{
				LED2 = 0;
				printf("LED2 is LOW");
			}
			Mem2 = Pot2;
			
			printf("\n\r");
			
			if(Pot3 == 1)
			{
				LED3 = 1;
				printf("LED3 is HIGH");
			}
			else
			{
				LED3 = 0;
				printf("LED3 is LOW");
			}
			Mem3 = Pot3;
			
		}
		printf("\033[H"); //go home, top left
    }
}

//------------------------------------------------------------------------------------
// SYSCLK_Init
//------------------------------------------------------------------------------------
//
// Initialize the system clock to use a 22.1184MHz crystal as its clock source
//
void SYSCLK_INIT(void)
{
    int i;
    char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page

    SFRPAGE = CONFIG_PAGE;
    OSCXCN  = 0x67;                     // Start ext osc with 22.1184MHz crystal
    for(i=0; i < 256; i++);             // Wait for the oscillator to start up
    while(!(OSCXCN & 0x80));
    CLKSEL  = 0x01;
    OSCICN  = 0x00;

    SFRPAGE = CONFIG_PAGE;
    PLL0CN  = 0x04;
    SFRPAGE = LEGACY_PAGE;
    FLSCL   = 0x10;
    SFRPAGE = CONFIG_PAGE;
    PLL0CN |= 0x01;
    PLL0DIV = 0x04;
    PLL0FLT = 0x01;
    PLL0MUL = 0x09;
    for(i=0; i < 256; i++);
    PLL0CN |= 0x02;
    while(!(PLL0CN & 0x10));
    CLKSEL  = 0x02;

    SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
}

//------------------------------------------------------------------------------------
// PORT_Init
//------------------------------------------------------------------------------------
//
// Configure the Crossbar and GPIO ports
//
void PORT_INIT(void)
{    
    char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page

    SFRPAGE  = CONFIG_PAGE;
    XBR0     = 0x04;                    // Enable UART0
    XBR1     = 0x00;
    XBR2     = 0x40;                    // Enable Crossbar and weak pull-up

    P0MDOUT |= 0x01;                    // Set TX0 on P0.0 pin to push-pull

    //Port 1 (input)
    P1MDOUT &= 0xF0; //Sets input pins 0-3 using F0: 1111 0000
    P1 |= 0x0F; //Pules input pins 0-3 with 0000 1111

	//Port 2 (output)
    P2MDOUT |= 0x0F; //set output pins (port 1) to pushpull using 0000 1111

    SFRPAGE = SFRPAGE_SAVE;            // Restore SFR page
}


//------------------------------------------------------------------------------------
// UART0_Init
//------------------------------------------------------------------------------------
//
// Configure the UART0 using Timer1, for <baudrate> and 8-N-1
//
void UART0_INIT(void)
{
    char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page

    SFRPAGE = TIMER01_PAGE;
    TMOD   &= ~0xF0;
    TMOD   |=  0x20;                    // Timer1, Mode 2, 8-bit reload
    TH1     = -(SYSCLK/BAUDRATE/16);    // Set Timer1 reload baudrate value T1 Hi Byte
    CKCON  |= 0x10;                     // Timer1 uses SYSCLK as time base
    TL1     = TH1;
    TR1     = 1;                        // Start Timer1

    SFRPAGE = UART0_PAGE;
    SCON0   = 0x50;                     // Mode 1, 8-bit UART, enable RX
    SSTA0   = 0x10;                     // SMOD0 = 1
    TI0     = 1;                        // Indicate TX0 ready

    SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
}
