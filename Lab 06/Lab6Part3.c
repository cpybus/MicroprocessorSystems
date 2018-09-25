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
#include <LCD.c>

char interrupt = 0;

__sbit __at (0xB0) P3_0 ;
__sbit __at (0xB1) P3_1 ;
__sbit __at (0xB2) P3_2 ;
__sbit __at (0xB3) P3_3 ;
__sbit __at (0xB4) P3_4 ;
__sbit __at (0xB5) P3_5 ;
__sbit __at (0xB6) P3_6 ;
__sbit __at (0xB7) P3_7 ;


void SYSCLK_INIT(void)
{
	int i;
	char SFRPAGE_SAVE;

	SFRPAGE_SAVE = SFRPAGE;			// Save Current SFR page
	SFRPAGE = CONFIG_PAGE;

	OSCXCN    = 0x67;
	for (i = 0; i < 3000; i++);		// Wait 1ms for initialization
	while (!(OSCXCN & 0x80));
	CLKSEL    = 0x01;

	SFRPAGE   = CONFIG_PAGE;
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

	SFRPAGE = SFRPAGE_SAVE;			// Restore SFR page
}

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

char pressedCharacter()
{
	return 'a';
}

void main()
{
	unsigned int i, j;
	char buffer[]="Hello.";

	WDTCN = 0xDE;		// Disable the watchdog timer
	WDTCN = 0xAD;		// note: = "DEAD"!
	
	SYSCLK_INIT();		// Initialize the oscillator

	lcd_init();			// initialize the LCD screen
	lcd_cmd(0x3F);		// set display to 2 lines 5x8
						// (0x30=1 line 5x8, 0x34=1 line 5x10)
	lcd_cmd(0x0C);		// turn on display and cursor
	lcd_cmd(0x01);		// clear display
	
	lcd_goto(0);		// set cursor address to 0
	lcd_dat('G');		// write "Good Morning    "
	lcd_dat('o');		//       "Dave            "
	lcd_dat('o');
	lcd_dat('d');
	lcd_dat(' ');
	lcd_dat('M');
	lcd_dat('o');
	lcd_dat('r');
	lcd_dat('n');
	lcd_dat('i');
	lcd_dat('n');
	lcd_dat('g');
	lcd_dat(',');

	lcd_goto(0x40);		// set cursor address to 0x40=64
	lcd_dat('D');
	lcd_dat('a');
	lcd_dat('v');
	lcd_dat('e'); 
	lcd_dat('.'); 
	
		
	while(1)
	{
		if(interrupt == 1)
		{
			interrupt = 0;
			//pressedCharacter();
		}
	}
	
	//for(i=0; i<200; i++)// long pause for display
	//	for(j=0; j<50000; j++);
	
	//lcd_cmd(0x01);		// clear display

}
