//Arest 8051 kit 1 program with esp8266
//8/oct/2018 little modified for kit-1 with esp8266 from fingedesigner website

#include<reg51.h>
#define ssd P0	//port 0 for seven segment
#define led P1	//port 1 for led indication as well as feed to another kit2
#define sl P2  //port 2 (p2.5,6,7) getting signal from esp8266 

void delay(unsigned int time);
void display();

unsigned char var,ds1,ds2,ds3,ds4;
code unsigned char disp[10]={0x00,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE};

//code unsigned char led_val[10]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};

code unsigned char led_val[10]={0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

unsigned char first_time,sec;

void main()
{
	led=ds1=ds2=ds3=ds4=0x00;  //LEDs on port 1 with ds1,2,3,4 variable
		P2=0xE0;
		
	//first_time=1;
	while(1)
	{
	   	P2=0xe0;
	    	//Port_2 = oxff,it was absent in previous program 
		  //new modification port 2 should be high pull up 8/oct/2018
		//P2=0X00 SL ALSO P2;
		var=P2&0xE0; //signal from esp8266 to p2.5,6,7 checking
	   	 //if(first_time==1)
	     //{
		   if((var>>5)==0x00)  //it shoud not be 0x00 /0x70 here is 0x07
		   {
		   	ds4=0xFc;		//for 'O' pattern on seven segment
			ds3=0x8e;		//for 'F'
			ds2=0x8e;		//for 'F'
			ds1=0x00;
			//P2=0xF0;
			var=P2&0xE0;
			led=led_val[var>>5]; //ON PORT 1=shifting 3bits by 5 to zeroth position
			ds1=disp[var>>5];  
		    }	
		 // }
	   
	   else
		  {
			ds4=0x1c;		//for L
			ds3=0xde;		//for e
			ds2=0x7a;		//for d
			var=P2&0xE0;
			led=led_val[var>>5]; //ON PORT 1=shifting 3bits by 5 to zeroth position
			ds1=disp[var>>5];  //data on ds1 for disply on port 0
		    //P2=0x00;
			//first_time=0; 
		   }
		 
	    		display();
		       led=ds1=0x00; //port 1 = led
			//P2=0x00;
        }
 }

void display()
{
	sl&=0xf0;
	sl|=0x0e; //P2 =0X0E	
	ssd=ds1;  //SSD = P0 =DS1
	delay(5);

	sl&=0xf0;
	sl=0x0d;	
	ssd=ds2;
	delay(5);

	sl&=0xf0;
	sl=0x0b;	
	ssd=ds3;
	delay(5);

	sl&=0xf0;
	sl=0x07;	
	ssd=ds4;
	delay(5);
}

void delay(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++)
		for(j=0;j<=120;j++);
}
