// Lab 2.c
// Chris Pybus and Jeff Pistacchio
//
// /INT0 is configured to be on P0.2
// UART0 is used to communicate to the user through ProCOMM or SecureCRT
//
//-------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------
#include <c8051f120.h>          // SFR declarations.
#include <stdio.h>              // Necessary for printf.
#include "putget.h"             // Necessary for printf
#include <stdlib.h>


//-------------------------------------------------------------------------------------------
// Global CONSTANTS
//-------------------------------------------------------------------------------------------
#define EXTCLK      22118400    // External oscillator frequency in Hz
#define SYSCLK      49766400    // Output of PLL derived from (EXTCLK * 9/4)
#define BAUDRATE    115200      // UART baud rate in bps
//#define BAUDRATE  19200       // UART baud rate in bps

unsigned int intrpt = 0;
unsigned int debounceTimer = 0;

unsigned char pushbuttonPress = 0; 

__bit SW2press = 0;

//-------------------------------------------------------------------------------------------
// Function PROTOTYPES
//-------------------------------------------------------------------------------------------
void main(void);
void PORT_INIT(void);
void SYSCLK_INIT(void);
void UART0_INIT(void);

void timer2_ISR (void) __interrupt 5;
void SW2_ISR (void) __interrupt 0;

void flashScreen(void);
//-------------------------------------------------------------------------------------------
// MAIN Routine
//-------------------------------------------------------------------------------------------
void main (void)
{
    __bit restart = 0;

	int reactionTimes[5] = { 0, 0, 0, 0, 0 };
	unsigned int avg = 0;
	char index = 0;
	unsigned int r = 0;

    SFRPAGE = CONFIG_PAGE;

    PORT_INIT();                // Configure the Crossbar and GPIO.
    SYSCLK_INIT();              // Initialize the oscillator.
    UART0_INIT();               // Initialize UART0.

    SFRPAGE = LEGACY_PAGE;
    IT0     = 1;                // /INT0 is edge triggered, falling-edge.

    SFRPAGE = UART0_PAGE;       // Direct the output to UART0
	
	EX0 = 1; // Enable Ext Int 0 only after everything is settled.
	
	//Overall game control
	while(1)
	{
		printf("\033[2J");        // Erase screen and move to home
		printf("\033[0;44;33m"); //reset attributes, set background to blue, set forground to yellow

		printf("\033[2;22HPress push button when screen flashes");
		printf("\033[H");
		
		reactionTimes[0] = 0;
		reactionTimes[1] = 0;
		reactionTimes[2] = 0;
		reactionTimes[3] = 0;
		reactionTimes[4] = 0;
		
		//PLAY FIVE GAMES
		index = 0;
		for(index = 1; index <= 5; index = index + 1 ) 
		{
			//DETERMINE RANDOM AMOUNT OF TIME
			r = (rand() % 500) + 200; //number between 200 and 700 (2 and 7 seconds)
			
			//WAIT THAT AMOUNT OF TIME
			intrpt = 0;
			while(1)
			{
				if(intrpt >= r || pushbuttonPress == 1) //time equals random time OR button was pressed
				{
					break;
				}
			}
			
			if(pushbuttonPress == 1) //button was pressed early
			{
				printf("\033[%d;0H", index+4);
				printf("Whoops! Too early! Try again... \n\r");
				index = index - 1; 
				printf("\033[H");
			}
			else
			{
				flashScreen();

				intrpt = 0;
				while(1)
				{
					if(pushbuttonPress == 1) //button pressed
					{
						printf("\033[%d;0H", index+4);
						printf_fast_f("Seconds: %.2f                  \n\r", (intrpt/100.0));
						reactionTimes[index - 1] = intrpt;
						printf("\033[H");
						
						break;
					}
				}
			}
			
			pushbuttonPress = 0;
		}
		
		avg = reactionTimes[0] + reactionTimes[1] + reactionTimes[2] + reactionTimes[3] + reactionTimes[4];
		avg = avg / 5.0;
		
		printf("\033[12;0H");
		printf_fast_f("Your average reaction time was %.2f seconds", (avg/100.0));
		printf("\033[H");


		//WAIT TEN SECONDS AND THEN RESTART
		intrpt = 0;
		while(1)
		{
			if(intrpt > 1000) 
			{
				break;
			}
			else if(intrpt % 100 == 0)
			{
				printf("\033[15;30H");
				printf_fast_f("Game restarting in... %d  ", (10 - (intrpt/100)));
				printf("\033[H");
			}
		}
		
		//go back to parent while loop
	}
}

//-------------------------------------------------------------------------------------------
// Interrupt Service Routines
//-------------------------------------------------------------------------------------------
void timer2_ISR (void) __interrupt 5
{
    TF2 = 0; //clear interrupt flag
	
	intrpt = intrpt + 1; //each intrpt = .01 seconds

	if(debounceTimer < 200)
	{
		debounceTimer = debounceTimer + 1;
	}

	TMR2L = 0x6C;		//Set T2 low bit
	TMR2H = 0x6B;		//Set T2 High Bit More accurate

}

void SW2_ISR (void) __interrupt 0 
{
	if(debounceTimer > 50) //button wasnt recently pressed
	{
		pushbuttonPress = 1;
		debounceTimer = 0;
	}
}

//-------------------------------------------------------------------------------------------
// Other Stuff
//-------------------------------------------------------------------------------------------
void flashScreen(void)
{
	char index2 = 0;
	
	
	printf("\033[15;35H"); //move to flash location
	printf("\033[43m"); //change background to yellow
	for(index2 = 13; index2 <= 17; index2 = index2+1)
	{
		printf("         ");
		printf("\033[%d;35H", index2);
	}
	printf("\033[H");

	intrpt = 0;
	while(1)
	{
		if (intrpt >= 10) //if .1 Seconds (exactly) have passed
		{
			break;
		}
	}

	printf("\033[15;35H"); //move to flash location
	printf("\033[44m"); //change background to blue
	for(index2 = 13; index2 <= 17; index2 = index2+1)
	{
		printf("         ");
		printf("\033[%d;35H", index2);
	}
	printf("\033[H");
}

//-------------------------------------------------------------------------------------------
// PORT_Init
//-------------------------------------------------------------------------------------------
//
// Configure the Crossbar and GPIO ports
//
void PORT_INIT(void)
{
    char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.

    SFRPAGE = CONFIG_PAGE;
    WDTCN   = 0xDE;             // Disable watchdog timer.
    WDTCN   = 0xAD;
    EA      = 1;                // Enable interrupts as selected.
	ET2		= 1;				// Enable timer 2 interrupt

    XBR0    = 0x04;             // Enable UART0.
    XBR1    = 0x84;             // /INT0 routed to port pin.
    XBR2    = 0x40;             // Enable Crossbar and weak pull-ups.

    P0MDOUT = 0x01;             // P0.0 (TX0) is configured as Push-Pull for output.
            // P0.1 (RX0) is configure as Open-Drain input.
            // P0.2 (SW2 through jumper wire) is configured as Open_Drain for input.
    P0      = 0x06;             // Additionally, set P0.0=0, P0.1=1, and P0.2=1.

    SFRPAGE = SFRPAGE_SAVE;     // Restore SFR page.
}

//-------------------------------------------------------------------------------------------
// SYSCLK_Init
//-------------------------------------------------------------------------------------------
//
// Initialize the system clock
//
void SYSCLK_INIT(void)
{
    int i;

    char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.

    SFRPAGE = CONFIG_PAGE;
    OSCXCN  = 0x67;             // Start external oscillator
    for(i=0; i < 256; i++);     // Wait for the oscillator to start up.
    while(!(OSCXCN & 0x80));    // Check to see if the Crystal Oscillator Valid Flag is set.
    CLKSEL  = 0x01;             // SYSCLK derived from the External Oscillator circuit.
    OSCICN  = 0x00;             // Disable the internal oscillator.

    SFRPAGE = CONFIG_PAGE;
    PLL0CN  = 0x04;				//(4)Frequency is not locked. (2)PLL ref clock is ext osc. (0)Bias generator is deactivated
    SFRPAGE = LEGACY_PAGE;
    FLSCL   = 0x10;				//Flash Memory Control: Tells Flash that Sysclock is <= 50 MHz.
    SFRPAGE = CONFIG_PAGE;
    PLL0CN |= 0x01;				//(0) PLL bias gen is active.
    PLL0DIV = 0x04;				//Multiplies by 4
    PLL0FLT = 0x11;				//Clock output is 19-30 MHz. 
    PLL0MUL = 0x09;				//Multiplies re clock by 17
    for(i=0; i < 256; i++);		
    PLL0CN |= 0x02;				// PLL is enabled.
    while(!(PLL0CN & 0x10));	// Waits for PLL frequency to lock
    CLKSEL  = 0x02;             // SYSCLK derived from the PLL.

    SFRPAGE = SFRPAGE_SAVE;     // Restore SFR page.
}

//-------------------------------------------------------------------------------------------
// UART0_Init
//-------------------------------------------------------------------------------------------
//
// Configure the UART0 using Timer1, for <baudrate> and 8-N-1.
//
void UART0_INIT(void)
{
    char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page.

    SFRPAGE = TIMER01_PAGE;
    TMOD   &= ~0xF0;
    TMOD   |=  0x20;            // Timer1, Mode 2: 8-bit counter/timer with auto-reload.
    TH1     = (unsigned char)-(SYSCLK/BAUDRATE/16); // Set Timer1 reload value for baudrate
    CKCON  |= 0x10;             // Timer1 uses SYSCLK as time base.
    TL1     = TH1;
    TR1     = 1;                // Start Timer1.

	//Timer 2 config
	SFRPAGE = 0x00;		//Timer 2 SFR page
	
	TMR2CN &= 0xF0;  //enable timer 2
	TMR2CF &= 0xE0;	//T2 uses sysclk/12

	TMR2L = 0x6C;		//Set T2 low bit
	TMR2H = 0x6B;		//Set T2 High Bit More accurate
	
	TR2 = 1;			//Start Timer 2	

    SFRPAGE = UART0_PAGE;
    SCON0   = 0x50;             // Set Mode 1: 8-Bit UART
    SSTA0   = 0x10;             // UART0 baud rate divide-by-two disabled (SMOD0 = 1).
    TI0     = 1;                // Indicate TX0 ready.

    SFRPAGE = SFRPAGE_SAVE;     // Restore SFR page.
}