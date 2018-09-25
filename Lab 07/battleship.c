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
unsigned char myBoard[8][8];//store all of my board's values
unsigned char opBoard[8][8];//store all of the values that I try to strike
							//initialize to all zeros
/*unsigned char sub[2][3];	//store locations of boats
unsigned char pt[2][2];
unsigned char carrier[2][5];
unsigned char cruiser[2][3];
unsigned char battleship[2][4];
*/
unsigned char sub =0;	//store number of hits on each ship
unsigned char pt=0;
unsigned char carrier=0;
unsigned char cruiser=0;
unsigned char battleship=0;

unsigned char i = 0;	//used for incrementing matrices
unsigned char j = 0;
unsigned char k = 0;	//used for incrementing boat locations
char win = 0;	//Character to end game if a player wins.


__sbit __at (0xB0) P3_0 ;
__sbit __at (0xB1) P3_1 ;
__sbit __at (0xB2) P3_2 ;
__sbit __at (0xB3) P3_3 ;
__sbit __at (0xB4) P3_4 ;
__sbit __at (0xB5) P3_5 ;
__sbit __at (0xB6) P3_6 ;
__sbit __at (0xB7) P3_7 ;

__sbit __at () P1_1 ;
//-------------------------------------------------------------------------------------------
// Function PROTOTYPES
//-------------------------------------------------------------------------------------------
void main(void);
void TIMER_Init(void);
void PORT_Init(void);
void SYSCLK_Init(void);
void UART_Init(void)
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
		
	//Have user set up their board.
	while(win == 0)
	{
		while (ready == 0)
		{
			printf("Set up your board.\r\n");
			printf("0 - Empty\r\n1 - PT boat\r\n2 - Sub\r\n3 - Cruiser\r\n4 - Battleship\r\n5 - Carrier\r\n");
			for(i=0; i<8; i++)
			{
				for(j=0;j<8;j++)
				{
					myBoard[i][j] = getchar();
					printf("[%c]",myBoard[i][j]);
					//store ship locations
							
				}
				printf("\r\n");
			}
			//Run function to check board properties, store each boat location
			checkBoard(myBoard);
			

			ready = 1;
		}
	
	//while a player has not won
	sendHit();
	//Run function to send hit
	}
	if (win == 1)
	{
		//you won
	}
	if (win == 2)
	{
		//you lost noob.
	}
	
}
//-------------------------------------------------------------------------------------------
// Functions
//-------------------------------------------------------------------------------------------
void sendHit(void)
{
	unsigned char x=0; //x coord
	unsigned char y = 0; //y coord
	unsigned char val = 0; //returned value Hit, Miss
	unsigned char sunk = 0; //which boat was sunk if any
	SFRPAGE = UART0_PAGE;
	
	//Obtain coordinates of strike
	printf("Enter coordinates of strike: \r\n");
	printf("X: ");
	x = getchar();	//switch with keypad input
	printf("\r\nY: ");
	y = getchar();
	printf("\r\n");
	
	// Program needs to wait for three commands. 
	// set flag to certain number after each step
	// when 'z' is sent over the UART then proceed.
	
	//send location to other player
	SFRPAGE = UART1_PAGE;
	printf("zx%cy%c",x,y);
	
	//wait for response and check other player input
	while(SBUF1 != 'z');
	x = SBUF1;
	while(SBUF1 != 'z');
	y = SBUF1;
		
	//check for hit or miss
	if (myBoard[y][x] == '0')
	{
		val = 'M'; //record as miss. will send to other player
		myBoard[y][x] == 'M'; //update own board
		//No Boat sunk
		sunk = 'N';
	}
	else if (mBoard[y][x] == '1') //if a pt boat was hit
	{
		val = 'H'; // record as hit
		myBoard[y][x] = 'H';
		pt = pt + 1; // increment number of pt boat hits
		if (pt > 1)
		{
			//PT Boat sunk
			sunk = 'P';
		}
		else
		{
			//No Boat sunk
			sunk = 'N';
		}
	}
	else if (mBoard[y][x] == '2') //if a sub was hit
	{
		val = 'H'; // record as hit
		myBoard[y][x] = 'H';
		sub = sub + 1; // increment number of pt boat hits
		if (sub > 2)
		{
			//Sub sunk
			sunk = 'S';
		}
		else
		{
			//No Boat sunk
			sunk = 'N';
		}
	}
	else if (mBoard[y][x] == '3') //if a cruiser was hit
	{
		val = 'H'; // record as hit
		myBoard[y][x] = 'H';
		cruiser = cruiser + 1; // increment number of cruiser hits
		if (cruiser > 2)
		{
			//cruiser sunk
			sunk = 'C';
		}
		else
		{
			//No Boat sunk
			sunk = 'N';
		}
	}
	else if (mBoard[y][x] == '4') //if a battleship was hit
	{
		val = 'H'; // record as hit
		myBoard[y][x] = 'H';
		battleship = battleship+ 1; // increment number of battleship hits
		if (battleship > 3)
		{
			//Battleship sunk
			sunk = 'B';
		}
		else
		{
			//No Boat sunk
			sunk = 'N';
		}
	}
	else if (mBoard[y][x] == '5') //if a carrier was hit
	{
		val = 'H'; // record as hit
		myBoard[y][x] = 'H';
		carrier = carrier + 1; // increment number of carrier hits
		if (carrier > 4)
		{
			//PT Boat sunk
			sunk = 'X';
		}
		else
		{
			//No Boat sunk
			sunk = 'N';
		}
	}
	
	// Send sunk infromation to other player. 
	//'P' Sunk pt boat. 'S' sunk sub. 'C' sunk cruiser. 'B' Sunk battleship. 'X' Sunk carrier. 'N' no boat sunk
	SFRPAGE = UART1_PAGE;
	prinf('z%c',sunk);
	
	//Check if one of our boats was sunk
	
	
	//update both boards
	//clear screen and print
	SFRPAGE = UART0_PAGE;
}

void checkBoard(unsigned char board[8][8])
{
	char num1 = 0;
	char num2 = 0; //stores the number of tiles for the PT boat
	char num3 = 0; //same as above
	char num4 = 0;
	char num5 = 0;
	
	//This checks if the right number of each ship is present.
	//check if the right amount of ships
	for(i=0; i<=8; i++)
	{
		for(j=0;j<=8;j++)
		{
			if (board[i][j] == '5')
			{
				num5 = num5+1; //check the number of carrier spots
			}
			else if (board[i][j] == '4') 
			{
				num4 = num4+1; //check the number of battleship spots
			}
			else if (board[i][j] == '3')
			{
				num3 = num3+1; //check the number of cruiser spots
			}
			else if (board[i][j] == '2')
			{
				num2 = num2+1; //check the number of sub spots
			}
			else if (board[i][j] == '1')
			{
				num1 = num1+1; //check the number of PT boat spots
			}
		}
		
	}
	if (num5 != 5) || (num4 != 4) || (num3 != 3) || (num2 != 3) || (num1 != 2)
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
void sound(void)
{
	P1_1 = 0;
	Delay(10);
	P1_1 = 1;
	Delay(20);
	P1_1 = 0;
	Delay(10);
	P1_1 = 1;
	Delay(40);
	P1_1 = 0;
	Delay(10);
	P1_1 = 1;
	Delay(60);
	P1_1 = 0;
}

