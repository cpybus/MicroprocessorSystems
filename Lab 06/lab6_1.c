//Lab 6.1
//Write a program that goes through the decision tree perscribed in the labs

//Chris Pybus, Jeff Pistacchio

//------------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------------
#include <c8051f120.h>
#include <stdio.h>
#include "putget.h"
#include <stdlib.h>

//------------------------------------------------------------------------------------
// Global Constants
//------------------------------------------------------------------------------------
#define EXTCLK      22118400    // External oscillator frequency in Hz
#define SYSCLK      22118400    // Output of crystal oscillator
#define BAUDRATE    115200       // UART baud rate in bps

unsigned char question = 0; //takes value of question
unsigned short int r = 0; //basic random number
unsigned short int floor =0; //bottom value for range function
unsigned short int ceil = 0; //top value for range function
unsigned short int rng = 0; //random number in range
//-------------------------------------------------------------------------------------------
// Function PROTOTYPES
//-------------------------------------------------------------------------------------------
void main(void);
void PORT_INIT(void);
void SYSCLK_INIT(void);
void UART0_INIT(void);
void YesNo(void);
void TF(void);
void Day(void);
void range(void);


void SYSCLK_INIT(void)
{
    int i;
    char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page SFRPAGE = CONFIG_PAGE;
    SFRPAGE = CONFIG_PAGE;

    OSCXCN = 0x67;              // Start ext osc with 22.1184MHz crystal
    for(i=0; i < 3000; i++);    // Wait for the oscillator to start up
    while(!(OSCXCN & 0x80));
    CLKSEL = 0x01;              // Switch to the external crystal oscillator
    OSCICN = 0x00	;              // Disable the internal oscillator

    SFRPAGE = SFRPAGE_SAVE;     // Restore SFR page
}

void PORT_INIT(void)
{
    char SFRPAGE_SAVE = SFRPAGE;    // Save Current SFR page
    SFRPAGE = CONFIG_PAGE;

    XBR0 = 0x04;        // Enable UART0
    XBR1 = 0x00;
    XBR2 = 0x40;        // Enable Crossbar and weak pull-up

    //Will have to enable port 3 for output and input for the LCD Screen

	// EMI_Init, split mode with no banking

    SFRPAGE = EMI0_PAGE;
    EMI0CF = 0x3b;              //34
    EMI0TC = 0xFF;

    SFRPAGE = SFRPAGE_SAVE;     // Restore SFR page
}

void UART0_INIT(void)
{
    char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page
    SFRPAGE = TIMER01_PAGE;

    TCON = 0x40;
    TMOD &= 0x0F;
    TMOD |= 0x20;               // Timer1, Mode 2, 8-bit reload
    CKCON |= 0x10;              // Timer1 uses SYSCLK as time base
    TH1 = 0xFA;                 // 
    TR1 = 1;                    // Start Timer1

    SFRPAGE = UART0_PAGE;
    SCON0 = 0x50;               // Mode 1, 8-bit UART, enable RX
    SSTA0 = 0x00;               // SMOD0 = 0, in this mode
                                // TH1 = 256 - SYSCLK/(baud rate * 32)

    TI0 = 1;                    // Indicate TX0 ready

    SFRPAGE = SFRPAGE_SAVE;     // Restore SFR page
}
void YesNo(void)
{
	SFRPAGE = UART0_PAGE;
	r = rand()%2;
	printf("\r\nAnswer: ");
	if (r)
	{
		printf("Yes\r\n");
	}
	else
	{
		printf("No\r\n");
	}
}
void TF(void)
{
	SFRPAGE = UART0_PAGE;
	r = rand()%2;
	printf("\r\nAnswer: ");
	if (r)
	{
		printf("True\r\n");
	}
	else
	{
		printf("False\r\n");
	}
}
void Day(void)
{
	SFRPAGE = UART0_PAGE;
	r = rand()%7;
	printf("\r\nAnswer: ");
	if (r == 0)
	{
		printf("Monday\r\n");
	}
	else if (r == 1)
	{
		printf("Tuesday\r\n");
	}
	else if (r == 2)
	{
		printf("Wednesday\r\n");
	}
	else if (r == 3)
	{
		printf("Thursday\r\n");
	}
	else if (r == 4)
	{
		printf("Friday\r\n");
	}
	else if (r == 5)
	{
		printf("Saturday\r\n");
	}
	else if (r == 6)
	{
		printf("Sunday\r\n");
	}
}
void range(void)
{
	SFRPAGE = UART0_PAGE;
	floor =0;
	ceil = 0;
	rng = 0;
	
	printf("\r\nEnter 3 digit lower bound: \r\n");
	floor = getchar() - '0';
	floor = floor*10 + (getchar() - '0');
	floor = floor*10 + (getchar() - '0');
	//printf("\r\nFloor %i",floor);
	printf("\r\nEnter 3 digit upper bound: \r\n");
	ceil = getchar() - '0';
	ceil = ceil*10+(getchar() - '0');
	ceil = ceil*10+(getchar() - '0');
	//printf("\r\nCeil %i",ceil);
	
	
	rng = floor + (rand()%(ceil-floor));
	printf("\r\nAnswer: %i\r\n",rng);
}

void main(void)
{
	SYSCLK_INIT();          // Initialize the oscillator
    PORT_INIT();            // Initialize the Crossbar and GPIO
    UART0_INIT();           // Initialize UART0
	
	WDTCN = 0xDE;   // Disable the watchdog timer
    WDTCN = 0xAD;
	
    SFRPAGE = UART0_PAGE;   // Direct output to UART0

    printf("\033[2J");     // Erase ANSI terminal & move cursor to home position
	
	while(1)
    {
		printf("Ask your question to the Magic 8 Ball and select the question type:\r\n 1) Yes or No\r\n 2) True or False \r\n 3) Day of the Week \r\n 4) Number Question \r\n 5) Clear Screen\r\n",question);
		question = getchar();
		
		if (question == '1')
		{
			YesNo();
		}
		else if (question == '2')
		{
			TF();
		}
		else if (question == '3')
		{
			Day();
		}
		else if (question == '4')
		{
			range();
		}
		else if (question == '5')
		{
			printf("\033[2J"); 
		}
		else
		{
			printf("You must enter a number 1-5 \r\n");
		}
		
    }
}