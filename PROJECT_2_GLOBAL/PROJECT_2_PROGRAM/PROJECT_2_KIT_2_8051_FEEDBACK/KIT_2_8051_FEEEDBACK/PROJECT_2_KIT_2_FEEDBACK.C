/*---------------------------------------------------
arest nuvoton kit 2 8051 feedback circuit from kit 1
----------------------------------------------------*/

/*--------------------------------------------------------
  KIT-1 SENDING TO SIGNAL TO LED DISPLAY AND FROM FEEDBK  
  CONNECTOR WIRES GOES TO KIT-2 CONNECTOR PORT-1  AFTER READING 
  DATA FROM PORT1 KIT2 THAT PATTERN OF SIGNAL KIT1 FEEDBK 
  DISPLAY ON SEVEN SEGMENT ....
--------------------------------------------------------*/

#include <REG51F.H>
 

#define ssd P0		 //seven segment for output
#define led_fb P1		//port 1 for feed back
#define sl P2	//selection of 7seg and sending feedback signal to esp8266

sbit fb1=P2^5; //feedback from keypad connector 
sbit fb2=P2^6; //feedback from keypad connector
sbit fb3=P2^7; //feedback from keypad connector
//----------------------------------------------------------------------

void delay(unsigned int);

void display(void);
void led_pattern();
//----------------------------------------------------------------------
unsigned char var,ds1,ds2,ds3,ds4;

code unsigned char disp[10]={0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE};
//----------------------------------------------------------------------

void main()
{
	led_fb=ds1=ds2=ds3=ds4=0x00;

	//ds4=0x1c;		//for L
	//ds3=0xde;		//for e
	//ds2=0x7a;		//for d
	while(1)
	{
	    led_pattern();
		led_fb=0xFf;  //setting input(7F) line from P1.0 TO P1.6

		switch(led_fb)
		{
			case 0x01:
				ds1=0x60;
				fb1=fb2=0;		//0001
				fb3=1;
		 		led_pattern();
				break;

			case 0x02:
				ds1=0xDA;
				fb1=fb3=0;		//0010
				fb2=1;
				led_pattern();
				break;

			case 0x04:
				ds1=0xF2;
				fb1=0;			//0011
				fb2=fb3=1;
				led_pattern();
				break;

			case 0x08:
				ds1=0x66;
				fb2=fb3=0;		//0100
				fb1=1;
				break;
			case 0x10:
				ds1=0xB6;
				fb2=0;			//0101
				fb1=fb3=1;
				led_pattern();
				break;

			case 0x20:
				ds1=0xBE;
				fb3=0;			//0110
				fb1=fb2=1;
				led_pattern();
				break;

			case 0x40:
				ds1=0xE0;
				fb1=fb2=fb3=1; 	//0111
			 	led_pattern();
			  	break;
		   
		   case 0x00:
				//ds1=0xE0;
				fb1=fb2=fb3=0; 	//0111
			 	ds4=0xfc;		//for L
				ds3=0x8e;		//for e
				ds2=0x8e;
			  	break;


		 		 
		}
		led_fb=0xFF;
		display();
		ds1=0x00;
	}
}

void led_pattern()
{
   	ds4=0x1c; //pattern for L
	ds3=0xde; //pattern for e
	ds2=0x7a; //pattern for d

}

void display()
{
  unsigned char k;
  for(k=0; k<28; k++)
  {
	sl&=0xf0;
	sl|=0x0e;
	ssd=ds1;
	delay(5);
	sl&=0xf0;
	sl|=0x0d;
	ssd=ds2;
	delay(5);
	sl&=0xf0;
	sl|=0x0b;
	ssd=ds3;
	delay(5);
	sl&=0xf0;
	sl|=0x07;
	ssd=ds4;
	delay(5);
   }
}

void delay(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++)
		for(j=0;j<=120;j++);
}