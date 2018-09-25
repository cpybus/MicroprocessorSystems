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
#include "LCD.c"

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
char rng_str[3];
unsigned char j = 0;

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

    XBR0=0x04;
	XBR1=0x80;
	XBR2=0x40;						// Enable Crossbar with Weak Pullups

	P7MDOUT=0x07;					// Set E, RW, RS controls to push-pull
	P6MDOUT=0x00;					// P6 must be open-drain to be bidirectional:
									// used for both read & write operations

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
	lcd_cmd(0x01);		// clear display
	large_delay(10);
	lcd_goto(0);			// set cursor address to 0
	large_delay(10);
	
	lcd_puts((char *) &"Answer: ");
	large_delay(10);

	lcd_goto(0x40);			// set cursor address to 64; second line
	large_delay(10);
	if (r)
	{
		lcd_puts((char *) &"Yes. ");
		large_delay(10);
	}
	else
	{
		lcd_puts((char *) &"No. ");
		large_delay(10);
	}
}
void TF(void)
{
	SFRPAGE = UART0_PAGE;
	r = rand()%2;
	lcd_cmd(0x01);		// clear display
	large_delay(10);
	lcd_goto(0);			// set cursor address to 0
	large_delay(10);
	lcd_puts((char *) &"Answer: ");
	large_delay(10);
	
	lcd_goto(0x40);			// set cursor address to 64; second line
	large_delay(10);
	if (r)
	{
		lcd_puts((char *) &"True. ");
		large_delay(10);
	}
	else
	{
		lcd_puts((char *) &"False. ");
		large_delay(10);
	}
}
void Day(void)
{
	SFRPAGE = UART0_PAGE;
	r = rand()%7;
	
	lcd_cmd(0x01);		// clear display
	large_delay(10);
	lcd_goto(0);			// set cursor address to 0
	large_delay(10);
	lcd_puts((char *) &"Answer: ");
	large_delay(10);
	
	lcd_goto(0x40);			// set cursor address to 64; second line
	if (r == 0)
	{
		lcd_puts((char *) &"Monday. ");
		large_delay(10);
	}
	else if (r == 1)
	{
		lcd_puts((char *) &"Tuesday. ");
		large_delay(10);
	}
	else if (r == 2)
	{
		lcd_puts((char *) &"Wednesday.");
		large_delay(10);
	}
	else if (r == 3)
	{
		lcd_puts((char *) &"Thurday.");
		large_delay(10);
	}
	else if (r == 4)
	{
		lcd_puts((char *) &"Friday.");
		large_delay(10);
	}
	else if (r == 5)
	{
		lcd_puts((char *) &"Saturday.");
		large_delay(10);
	}
	else if (r == 6)
	{
		lcd_puts((char *) &"Sunday. ");
		large_delay(10);
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
	
	lcd_cmd(0x01);		// clear display
	large_delay(10);
	lcd_goto(0);			// set cursor address to 0
	large_delay(10);
	lcd_puts((char *) &"Answer: ");
	
	large_delay(10);
	lcd_goto(0x40);			// set cursor address to 64; second line
	large_delay(10);
	//output rng value
	//while (rng_str[j])
	//{
	//	rng_str[j] = rng/(10^(2-j));
	//	rng = rng - (rng_str[j]*10^(2-j));
	//	j++;		
	//}
	//lcd_dat(rng_str[0]);
	//lcd_dat(rng_str[1]);
	//lcd_dat(rng_str[2]);
	
}

void main(void)
{
	SYSCLK_INIT();          // Initialize the oscillator
    PORT_INIT();            // Initialize the Crossbar and GPIO
    UART0_INIT();           // Initialize UART0
	lcd_init();				// Initialize LCD
	WDTCN = 0xDE;   // Disable the watchdog timer
    WDTCN = 0xAD;
    SFRPAGE = UART0_PAGE;   // Direct output to UART
    printf("\033[2J");     // Erase ANSI terminal & move cursor to home position
	
	lcd_cmd(0x3F);		// set display to 2 lines 5x8
						// (0x30=1 line 5x8, 0x34=1 line 5x10)
	large_delay(10);
	lcd_cmd(0x0C);		// turn on display and cursor
	large_delay(10);
	lcd_cmd(0x01);		// clear display
	large_delay(10);
	
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