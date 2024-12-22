//kit 1 for webpage local as well as feedback for kit2
//this is final program from esp8266 to 8051 combinatin of leds...

#include<reg51.h>
#define ssd P0
#define led P1
#define sl P2

void delay(unsigned int time);
void display();

unsigned char var,ds1,ds2,ds3,ds4;
code unsigned char disp[10]={0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE};
//code unsigned char led_val[10]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
code unsigned char led_val[10]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

void main()
{
	led=ds1=ds2=ds3=ds4=0x00;
	ds4=0x1c;		//for L
	ds3=0xde;		//for e
	ds2=0x7a;		//for d
	
while(1)
	{
		P2=0xe0;
		var=P2&0xE0;
		led=led_val[var>>5];       //msb data shift by 5 
		ds1=disp[var>>5];          //sending data on zeroth position from 5th position
		display();	             //from 5 6 7 to 0 1 2 
		led=ds1=0x00;
	}
}




void display()
{
	sl=0x0e;	
	ssd=ds1;
	delay(5);
	sl=0x0d;	
	ssd=ds2;  //for d
	delay(5);
	sl=0x0b;	
	ssd=ds3; //for e
	delay(5);
	sl=0x07;	
	ssd=ds4; //for L
	delay(5);
}

void delay(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++)
		for(j=0;j<=120;j++);
}



