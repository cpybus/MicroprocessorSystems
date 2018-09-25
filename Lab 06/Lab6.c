// Filename: LCDTEST8051.c
// Basic test program for the Hitachi HD 44780
// interfaced to the C8951F120
//-- Updated for SDCC C compiler and C8051F120
//-- RPK Oct 2007
//
// An extra 10k pull-up resistor may be needed on the E control line P7.2
// to the +3.3V supply on P8051F120 board if P7 is configured as open-drain.

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <c8051f120.h>
#include <stdio.h>
#include "putget.h"
#include <stdlib.h>
#include "LCD.c"

char interrupt = '~';

unsigned char question = 0; //takes value of question
unsigned short int r = 0; //basic random number
unsigned short int floor =0; //bottom value for range function
unsigned short int ceil = 0; //top value for range function
unsigned short int rng = 0; //random number in range
char rng_str[3];
unsigned char j = 0;

#define EXTCLK      22118400    // External oscillator frequency in Hz
#define SYSCLK      22118400    // Output of crystal oscillator
#define BAUDRATE    28800       // UART baud rate in bps

void SYSCLK_Init(void)
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

void UART_Init()
{
	char SFRPAGE_SAVE;

    SFRPAGE_SAVE = SFRPAGE;     // Save Current SFR page
    SFRPAGE = TIMER01_PAGE;

    TCON = 0x40;
    TMOD &= 0x0F;
    TMOD |= 0x20;               // Timer1, Mode 2, 8-bit reload
    CKCON |= 0x10;              // Timer1 uses SYSCLK as time base
    TH1 = 0xE8;                 // 0xE8 = 232
    TR1 = 1;                    // Start Timer1

    SFRPAGE = UART0_PAGE;
    SCON0 = 0x50;               // Mode 1, 8-bit UART, enable RX
    SSTA0 = 0x00;               // SMOD0 = 0, in this mode
                                // TH1 = 256 - SYSCLK/(baud rate * 32)

    TI0 = 1;                    // Indicate TX0 ready

    SFRPAGE = SFRPAGE_SAVE;     // Restore SFR page
}

void PORT_Init()
{
	char SFRPAGE_SAVE = SFRPAGE;    // Save Current SFR page
    SFRPAGE = CONFIG_PAGE;
	
	XBR0=0x04;
	XBR1=0x84;
	XBR2=0x40;						// Enable Crossbar with Weak Pullups
	
    P0MDOUT   = 0x04;
	P7MDOUT=0x07;					// Set E, RW, RS controls to push-pull
	P6MDOUT=0x00;					// P6 must be open-drain to be bidirectional:
									// used for both read & write operations
	P3MDOUT=0xF0; // hi nibble to push-pull, lo nibble to open-drain
	P3=0x0F; // write 0's to Port 3 hi nibble, lo nibble set for input
	TCON=TCON & 0xFC; // Clear INT0 flag and set for level triggered
	IE=IE|0x81; // Enable all interrupts & enable INT0
	
	SFRPAGE = SFRPAGE_SAVE;     // Restore SFR page
}

void YesNo(void)
		lcd_puts((char *) &"Yes. ");
		
	}
	else
	{
		lcd_puts((char *) &"No. ");
		
	}
{
	SFRPAGE = UART0_PAGE;
	r = rand()%2;
	lcd_cmd(0x01);		// clear display
	
	lcd_goto(0);			// set cursor address to 0
	
	
	lcd_puts((char *) &"Answer: ");
	

	lcd_goto(0x40);			// set cursor address to 64; second line
	
	if (r)
	{
}

void TF(void)
{
	SFRPAGE = UART0_PAGE;
	r = rand()%2;
	lcd_cmd(0x01);		// clear display
	
	lcd_goto(0);			// set cursor address to 0
	
	lcd_puts((char *) &"Answer: ");
	
	
	lcd_goto(0x40);			// set cursor address to 64; second line
	
	if (r)
	{
		lcd_puts((char *) &"True. ");
		
	}
	else
	{
		lcd_puts((char *) &"False. ");
		
	}
}

void Day(void)
{
	SFRPAGE = UART0_PAGE;
	r = rand()%7;
	
	lcd_cmd(0x01);		// clear display
	lcd_goto(0);			// set cursor address to 0
	lcd_puts((char *) &"Answer: ");
	
	
	lcd_goto(0x40);			// set cursor address to 64; second line
	if (r == 0)
	{
		lcd_puts((char *) &"Monday. ");
		
	}
	else if (r == 1)
	{
		lcd_puts((char *) &"Tuesday. ");
		
	}
	else if (r == 2)
	{
		lcd_puts((char *) &"Wednesday.");
		
	}
	else if (r == 3)
	{
		lcd_puts((char *) &"Thurday.");
		
	}
	else if (r == 4)
	{
		lcd_puts((char *) &"Friday.");
		
	}
	else if (r == 5)
	{
		lcd_puts((char *) &"Saturday.");
		
	}
	else if (r == 6)
	{
		lcd_puts((char *) &"Sunday. ");
		
	}
}

void range(void)
{
	char letter = ' ';
	char hund = 0;
	char tens = 0;
	interrupt = '~';


	SFRPAGE = UART0_PAGE;
	floor =0;
	ceil = 0;
	rng = 0;

	lcd_cmd(0x01);		// clear display
	lcd_goto(0);			// set cursor address to 0	
	lcd_puts((char *) &"Enter low bound");

	lcd_goto(0x40);

	while(interrupt == '~'){}
	floor = interrupt - '0';
	lcd_dat(interrupt);
	interrupt = '~';

	while(interrupt == '~'){}
	floor = floor*10 + (interrupt - '0');
	lcd_dat(interrupt);
	interrupt = '~';

	while(interrupt == '~'){}
	floor = floor*10 + (interrupt - '0');
	lcd_dat(interrupt);
	interrupt = '~';

	lcd_cmd(0x01);		// clear display
	lcd_goto(0);			// set cursor address to 0	
	lcd_puts((char *) &"Enter high bound");
	lcd_goto(0x40);

	while(interrupt == '~'){}
	ceil = interrupt - '0';
	lcd_dat(interrupt);
	interrupt = '~';

	while(interrupt == '~'){}
	ceil = ceil*10 + (interrupt - '0');
	lcd_dat(interrupt);
	interrupt = '~';

	while(interrupt == '~'){}
	ceil = ceil*10 + (interrupt - '0');
	lcd_dat(interrupt);
	interrupt = '~';
	
	rng = floor + (rand()%(ceil-floor));

	//printf("%i", rng);
	
	lcd_cmd(0x01);		// clear display
	lcd_goto(0);			// set cursor address to 0
	lcd_puts((char *) &"Answer: ");
	
	
	lcd_goto(0x40);			// set cursor address to 64; second line

	hund = rng / 100;
	letter = hund + '0';
	lcd_dat(letter);

	tens = (rng - (hund * 100)) / 10;
	letter = tens + '0';
	lcd_dat(letter);

	letter = rng - (hund * 100) - (tens * 10);
	letter = letter + '0';
	lcd_dat(letter);
	
	
}

void SW2_ISR (void) __interrupt 0  
{
	unsigned int i,j = 0;
	char savedValue = P3 & 0x0F;
	char portvalue;
	char input = '?';

	P3=0x8F; // check if row one (top) was active
	for(i = 0; i<300; i++); // wait for the output and input pins to stabilize
	
	portvalue = P3 & 0x0F;  // read the value of the lower 4 bits
	if (portvalue == 0x0F)  // if this row was selected then the value will be 0x0F						// since the 1 on bit 7 will allow the 4 inputs to be hi
	{
		if (savedValue == 0x07) // look at the value of the low 4 bits
			input = '1'; // return the value of the matching key
		else if (savedValue == 0x0B)
			input = '2';
		else if (savedValue == 0x0D)
			input = '3';
		else
			input = 'A';
	}
	
	
	P3=0x4F; // check if row one (top) was active
	for(i = 0; i<300; i++); // wait for the output and input pins to stabilize
	portvalue = P3 & 0x0F;  // read the value of the lower 4 bits
	if (portvalue == 0x0F)  // if this row was selected then the value will be 0x0F
							// since the 1 on bit 7 will allow the 4 inputs to be hi
	{
		if (savedValue == 0x07) // look at the value of the low 4 bits
			input = '4'; // return the value of the matching key
		else if (savedValue == 0x0B)
			input = '5';
		else if (savedValue == 0x0D)
			input = '6';
		else
			input = 'B';
	}
	
	
	P3=0x2F; // check if row one (top) was active
	for(i = 0; i<300; i++); // wait for the output and input pins to stabilize
	portvalue = P3 & 0x0F;  // read the value of the lower 4 bits
	if (portvalue == 0x0F)  // if this row was selected then the value will be 0x0F
							// since the 1 on bit 7 will allow the 4 inputs to be hi
	{
		if (savedValue == 0x07) // look at the value of the low 4 bits
			input = '7'; // return the value of the matching key
		else if (savedValue == 0x0B)
			input = '8';
		else if (savedValue == 0x0D)
			input = '9';
		else
			input = 'C';
	}
	
	
	P3=0x1F; // check if row one (top) was active
	for(i = 0; i<300; i++); // wait for the output and input pins to stabilize
	portvalue = P3 & 0x0F;  // read the value of the lower 4 bits
	if (portvalue == 0x0F)  // if this row was selected then the value will be 0x0F
							// since the 1 on bit 7 will allow the 4 inputs to be hi
	{
		if (savedValue == 0x07) // look at the value of the low 4 bits
			input = '*'; // return the value of the matching key
		else if (savedValue == 0x0B)
			input = '0';
		else if (savedValue == 0x0D)
			input = '#';
		else
			input = 'D';
	}
	
	
	for(i=0; i<15; i++)// long pause for display
		for(j=0; j<50000; j++);
	
	P3 = 0x0F;
	
	interrupt = input;
	
	while (P3 != 0x0F); // wait while the key is still pressed
	
	
}

char pressedCharacter()
{
	return 'a';
}

void main()
{
	WDTCN = 0xDE;		// Disable the watchdog timer
	WDTCN = 0xAD;		// note: = "DEAD"!
	
	SYSCLK_Init();		// Initialize the oscillator
	PORT_Init();
	UART_Init();

	lcd_init();			// initialize the LCD screen
	lcd_cmd(0x3F);		// set display to 2 lines 5x8
						// (0x30=1 line 5x8, 0x34=1 line 5x10)
	
	lcd_cmd(0x0C);		// turn on display and cursor
	
	lcd_cmd(0x01);		// clear display
	

	SFRPAGE = UART0_PAGE;   // Direct output to UART0
	
	printf("\033[2J");     // Erase ANSI terminal & move cursor to home position
	//printf("test");
	
	printf("Ask your question to the Magic 8 Ball and select the question type:\r\n 1) Yes or No\r\n 2) True or False \r\n 3) Day of the Week \r\n 4) Number Question \r\n 5) Clear Screen\r\n");
	
	while(1)
    {
		
		while(interrupt == '~')
		{
			
		}
		
		if (interrupt == '1')
			YesNo();
		else if (interrupt == '2')
			TF();
		else if (interrupt == '3')
			Day();
		else if (interrupt == '4')
			range();
		else if (interrupt == '5')
			printf("\033[2J"); 
		else
			printf("You must enter a number 1-5 \r\n");
		
		interrupt = '~';
		
    }

}
