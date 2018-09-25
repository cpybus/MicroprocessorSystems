// Battleship.c
// Chris Pybus and Jeff Pistacchio
//


//Own terminal is uart0, talks to opponent on uart1
//-------------------------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------------------------
#include <c8051f120.h>          // SFR declarations.
#include <stdio.h>              // Necessary for printf.
#include "putget.h"             // Necessary for printf
#include <LCD.c>

char ready = 0; // Flag that indicates when game is ready to start, 
				// the player has finished setting up their board.

//From lab 6.3
char interrupt = 0;
unsigned char myBoard[8][8]; //store all of my board's values
unsigned char opBoard[8][8]; //store all of the values that I try to strike
								//initialize to all zeros

unsigned char sub[2][3];	//store locations of boats
unsigned char pt[2][2];
unsigned char carrier[5][2];
unsigned char cruiser[3][2];
unsigned char battleship[4][2];
unsigned char i = 0;	//used for incrementing matrices
unsigned char j = 0;

char win = 0;	//Character to end game if a player wins.


__sbit __at (0xB0) P3_0 ;
__sbit __at (0xB1) P3_1 ;
__sbit __at (0xB2) P3_2 ;
__sbit __at (0xB3) P3_3 ;
__sbit __at (0xB4) P3_4 ;
__sbit __at (0xB5) P3_5 ;
__sbit __at (0xB6) P3_6 ;
__sbit __at (0xB7) P3_7 ;
//-------------------------------------------------------------------------------------------
// Function PROTOTYPES
//-------------------------------------------------------------------------------------------
void main(void);
void TIMER_Init(void);
void PORT_Init(void);
void SYSCLK_Init(void);
void UART_Init(void);
unsigned char getChar(void);
void SW2_ISR (void) __interrupt 0;

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
	//printf("This is UART0.\n\r");
    
	
	//SFRPAGE = UART1_PAGE;
    //printf("\033[2J"); //Erase screen and move cursor to the home position.
	//printf("This is UART1.\n\r");
	
	//Have user set up their board.
	while (ready == 0)
	{
		printf("Set up your board.\r\n");
		printf("0 - Empty\r\n2 - PT boat\r\n 3 - Cruiser/Sub\r\n5 - Carrier\r\n");
		for(i=0; i<=8; i++)
		{
			for(j=0;j<=8;j++)
			{
				myBoard[i][j] = getchar();
				printf("[%c]",myBoard[i][j]);
			}
			printf("\r\n");
		}
		//Run function to check board properties, store each boat location
		ready = 1;
	}
	
	//while a player has not won
		//Run function to send hit
	
	
}
//-------------------------------------------------------------------------------------------
// Functions
//-------------------------------------------------------------------------------------------
void sendHit(void)
{
	unsigned char x=0;
	unsigned char y = 0;
	SFRPAGE = UART0_PAGE;
	
	//Obtain coordinates of strike
	printf("Enter coordinates of strike: \r\n");
	printf("X: ");
	x = getchar();
	printf("\r\nY: ");
	y = getchar();
	printf("\r\n");
	
	//wait for response
	//update both boards, clear screen and print
	//check for hit or miss
	//check for sunk ship
}
void checkBoard(unsigned char board[8][8])
{
	char sum = 0;
	for(i=0; i<=8; i++)
	{
		for(j=0;j<=8;j++)
		{
			if (board[i][j] == '5')
			{
				sum = sum+5;
			}
			else if (board[i][j] == '4') 
			{
				sum = sum+4;
			}
			else if (board[i][j] == '3')
			{
				sum = sum + 3;
			}
			else if (board[i][j] == '2')
			{
				sum = sum + 2;
			}			
		}
		
	}
	if (sum != 54)
	{
		printf("Incorrect board. Reenter and follow the rules.\r\n");
	}
}
char getChar(void)  //From lab3.1
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
	
	//SFRPAGE = UART1_PAGE;
	//printf("%c\n\r", c);
	
	//SFRPAGE = UART0_PAGE;
	//printf("%c\n\r", c);
	return c;
}

//-------------------------------------------------------------------------------------------
// Timer_Init  From lab 3.1
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
// PORT_Init  from lab 3.1
//-------------------------------------------------------------------------------------------
void PORT_Init()
{
	SFRPAGE = CONFIG_PAGE;
	
	
	//XBR0 = 0x04; //eanble UART0
	//XBR1 = 0x00; 
	//XBR2 = 0x44; //enable UART1
	
	P0MDOUT = 0x05;
	P0 = ~0x05;
	
	//From lab 6.3
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

	
}

//-------------------------------------------------------------------------------------------
// SYSCLK_Init from lab 3.1
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
// UART0_Init from lab 3.1
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
//From lab 6.3
void SW2_ISR (void) __interrupt 0  
{
	unsigned int i,j = 0;
	char savedValue = P3 & 0x0F;
	char portvalue;

	P3=0x8F; // check if row one (top) was active
	for(i = 0; i<300; i++); // wait for the output and input pins to stabilize
	
	portvalue = P3 & 0x0F;  // read the value of the lower 4 bits
	if (portvalue == 0x0F)  // if this row was selected then the value will be 0x0F						// since the 1 on bit 7 will allow the 4 inputs to be hi
	{
		if (savedValue == 0x07) // look at the value of the low 4 bits
			lcd_dat('1'); // return the value of the matching key
		else if (savedValue == 0x0B)
			lcd_dat('2');
		else if (savedValue == 0x0D)
			lcd_dat('3');
		else
			lcd_dat('A');
	}
	
	
	P3=0x4F; // check if row one (top) was active
	for(i = 0; i<300; i++); // wait for the output and input pins to stabilize
	portvalue = P3 & 0x0F;  // read the value of the lower 4 bits
	if (portvalue == 0x0F)  // if this row was selected then the value will be 0x0F
							// since the 1 on bit 7 will allow the 4 inputs to be hi
	{
		if (savedValue == 0x07) // look at the value of the low 4 bits
			lcd_dat('4'); // return the value of the matching key
		else if (savedValue == 0x0B)
			lcd_dat('5');
		else if (savedValue == 0x0D)
			lcd_dat('6');
		else
			lcd_dat('B');
	}
	
	
	P3=0x2F; // check if row one (top) was active
	for(i = 0; i<300; i++); // wait for the output and input pins to stabilize
	portvalue = P3 & 0x0F;  // read the value of the lower 4 bits
	if (portvalue == 0x0F)  // if this row was selected then the value will be 0x0F
							// since the 1 on bit 7 will allow the 4 inputs to be hi
	{
		if (savedValue == 0x07) // look at the value of the low 4 bits
			lcd_dat('7'); // return the value of the matching key
		else if (savedValue == 0x0B)
			lcd_dat('8');
		else if (savedValue == 0x0D)
			lcd_dat('9');
		else
			lcd_dat('C');
	}
	
	
	P3=0x1F; // check if row one (top) was active
	for(i = 0; i<300; i++); // wait for the output and input pins to stabilize
	portvalue = P3 & 0x0F;  // read the value of the lower 4 bits
	if (portvalue == 0x0F)  // if this row was selected then the value will be 0x0F
							// since the 1 on bit 7 will allow the 4 inputs to be hi
	{
		if (savedValue == 0x07) // look at the value of the low 4 bits
			lcd_dat('*'); // return the value of the matching key
		else if (savedValue == 0x0B)
			lcd_dat('0');
		else if (savedValue == 0x0D)
			lcd_dat('#');
		else
			lcd_dat('D');
	}
	
	
	for(i=0; i<15; i++)// long pause for display
		for(j=0; j<50000; j++);
	
	P3 = 0x0F;
	
	//while (P3 != 0x0F); // wait while the key is still pressed
	//
}
//From Lab 6.3
char pressedCharacter()
{
	return 'a';
}