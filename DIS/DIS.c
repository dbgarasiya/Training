#include<reg51.h>
#include "lcd_4bit.h"															/* Including header file */

#define timer_05min
#define data_lcd

sbit relay_1=P2^0;																/* 8 relay is connected on port 2*/
sbit relay_2=P2^1;
sbit relay_3=P2^2;
sbit relay_4=P2^3;
sbit relay_5=P2^4;
sbit relay_6=P2^5;
sbit relay_7=P2^6;
sbit relay_8=P2^7;

sbit sensor_1=P0^0;																/* sensors are connected on port 0*/
sbit sensor_2=P0^1;
sbit sensor_3=P0^2;
sbit sensor_4=P0^3;
sbit sensor_5=P0^4;
sbit sensor_6=P0^5;
sbit sensor_7=P0^6;
sbit sensor_8=P0^7;

sbit switch_pin=P3^2;

Serial_init(unsigned long freq,unsigned long int baudrate);
void delay();
void start_timer(unsigned int choice);
void send_string(unsigned char *display);
void timer(void) interrupt 1;
void ISR_ex0(void) interrupt 0;

void main()
{
	IE = 0x81; 																	/* Exeternal interrupt enable*/
	P0=0XFF;																	/*Sensors as input*/
	P2=0X00;																	/*Relays  as output*/
	switch_pin=1;  																/*switch as input*/
	Serial_init();

	while (1)
	{
			if(sensor_1==0 && relay_1==0)										/* If door1 is opens remaining doors are closed*/
			{

				send_string("Door 1 is Opening",1);								/* Display on lcd*/
				relay_2=relay_3=relay_4=relay_5=relay_6=relay_7=relay_8=1;

				start_timer(05);
				TR0=0;														/* Timer of 5 minutes */
				if(sensor_1==0 && relay_1==0)									/* if door remains opened by mistake then,*/
				{																/* closed doors are unlocked after 5 minutes*/
					relay_2=relay_3=relay_4=relay_5=relay_6=relay_7=relay_8=0;
				}
			}
			else if(sensor_2==0 && relay_2==0)									/* If door2 is opens remaining doors are closed*/
			{

				send_string("Door 2 is Opening",1);								/* Display on lcd*/
				relay_1=relay_3=relay_4=relay_5=relay_6=relay_7=relay_8=1;

				start_timer(05);
				TR0=0;															/* Timer of 5 minutes*/
				if(sensor_2==0 && relay_2==0)									/* if door remains opened by mistake then,*/
				{																/* closed doors are unlocked after 5 minutes*/
					relay_1=relay_3=relay_4=relay_5=relay_6=relay_7=relay_8=0;
				}
			}
			else if(sensor_3==0 && relay_3==0)									/* If door3 is opens remaining doors are closed*/
			{

				send_string("Door 3 is Opening",1);								/* Display on lcd*/
				relay_1=relay_2=relay_4=relay_5=relay_6=relay_7=relay_8=1;

				start_timer(05);
				TR0=0;															/* Timer of 5 minutes*/
				if(sensor_3==0 && relay_3==0)									/* if door remains opened by mistake then,*/
				{																/* closed doors are unlocked after 5 minutes*/
					relay_1=relay_2=relay_4=relay_5=relay_6=relay_7=relay_8=0;
				}
			}
			else if(sensor_4==0 && relay_4==0)									/* If door4 is opens remaining doors are closed*/
			{

				send_string("Door 4 is Opening",1);								/* Display on lcd*/
				relay_1=relay_2=relay_3=relay_5=relay_6=relay_7=relay_8=1;

				start_timer(05);
				TR0=0;															/* Timer of 5 minutes*/
				if(sensor_4==0 && relay_4==0)									/* if door remains opened by mistake then,*/
				{																/* closed doors are unlocked after 5 minutes*/
					relay_1=relay_2=relay_3=relay_5=relay_6=relay_7=relay_8=0;
				}
			}
			else if(sensor_5==0 && relay_5==0)									/* If door5 is opens remaining doors are closed*/
			{

				send_string("Door 5 is Opening",1);								/* Display on lcd*/
				relay_1=relay_2=relay_3=relay_4=relay_6=relay_7=relay_8=1;

				start_timer(05);
				TR0=0;															/* Timer of 5 minutes*/
				if(sensor_5==0 && relay_5==0)									/* if door remains opened by mistake then,*/
				{																/* closed doors are unlocked after 5 minutes*/
					relay_1=relay_2=relay_3=relay_4=relay_6=relay_7=relay_8=0;
				}
			}
			else if(sensor_6==0 && relay_6==0)									/* If door6 is opens remaining doors are closed*/
			{

				send_string("Door 6 is Opening",1);								/* Display on lcd*/
				relay_1=relay_2=relay_3=relay_4=relay_5=relay_7=relay_8=1;

				start_timer(05);
				TR0=0;															/* Timer of 5 minutes*/
				if(sensor_6==0 && relay_6==0)									/* if door remains opened by mistake then,*/
				{																/* closed doors are unlocked after 5 minutes*/
					relay_1=relay_2=relay_3=relay_4=relay_5=relay_7=relay_8=0;
				}
			}
			else if(sensor_7==0 && relay_7==0)									/* If door7 is opens remaining doors are closed*/
			{

				send_string("Door 7 is Opening",1);								/* Display on lcd*/
				relay_1=relay_2=relay_3=relay_4=relay_5=relay_6=relay_8=1;

				start_timer(05);
				TR0=0;															/* Timer of 5 minutes*/
				if(sensor_7==0 && relay_7==0)									/* if door remains opened by mistake then,*/
				{																/* closed doors are unlocked after 5 minutes*/
					relay_1=relay_2=relay_3=relay_4=relay_5=relay_6=relay_8=0;
				}
			}
			else if(sensor_8==0 && relay_8==0)									/* If door8 is opens remaining doors are closed*/
			{

				send_string("Door 8 is Opening",1);								/* Display on lcd*/
				relay_1=relay_2=relay_3=relay_4=relay_5=relay_6=relay_7=1;

				start_timer(05);
				TR0=0;															/* Timer of 5 minutes*/
				if(sensor_8==0 && relay_8==0)									/* if door remains opened by mistake then,*/
				{																/* closed doors are unlocked after 5 minutes*/
					relay_1=relay_2=relay_3=relay_4=relay_5=relay_6=relay_7=0;
				}
			}

	}
}
Serial_init(unsigned long freq,unsigned long int baudrate)						/* Baud-rate of 9600 serial communication*/
{
	TMOD |= 0x20;
	SCON = 0x50;
	TH1  = -(((freq/12)/32)/baudrate);											/* calculation= (11.0592/12)/32=28800, 28800/9600=3*/
	TR1  = 1;
	TI = 1;
}
void send_string(unsigned char *display)										/* Function to send  STRING*/
{
	enum show {lcd,uart};
	enum show data;																/* we can #define lcd 0 and uart 1*/
	data=lcd;
	data=uart;

	switch(data)
	{
		#ifdef data_lcd
		case lcd:
			while(*display!='\0')												/* Display on LCD*/
			{
				lcd_display(*display);
				display++;
			}
			break;
		#endif
		#ifdef data_uart
		case uart:
			while(*display!='\0')												/* FOR UART*/
			{
				putchar(*display)
				display++;
			}
			break;
		#endif
	}
}
void ISR_ex0(void) interrupt 0													/* Exeternal interrupt for Emergency*/
{
	if(switch_pin==0)
	{
		relay_1=relay_2=relay_3=relay_4=relay_5=relay_6=relay_7=relay_8=0;
	}

}
void timer(void) interrupt 1 													//Interrupt no. 1 for Timer 0
{
	relay_1=relay_2=relay_3=relay_4=relay_5=relay_6=relay_7=relay_8=0;			/* All doors are unlocked*/
}

void start_timer(unsigned int choice)
{
	int count,sec;
	switch(choice)
	{
		#ifdef timer_05min
		case 05:
			   for(sec=0;sec<300;sec++)
				{
					count=0;
					while(count!=50)
					{
						TMOD=0X01;      										/* 16- bit timer0 selected*/
						TH0=0xB8;												/* Calculation= delay(half time) /(6/11.0592Mhz)=value*/
						TL0=0x12;
						IE=0X82;												/* 65535-value= timer value , now  put timer value in Hex in TH0(Higher byte) and TL0(Lower byte)*/
						TR0=1;													/* Running  the timer*/
					}
					count++;	 												/* Clear timer flag bit for next calculation*/
				}
				break;
		#endif
		#ifdef timer_10min
		case 10:
				for(sec=0;sec<600;sec++)
				{
					count=0;
					while(count!=50)
					{
						TMOD=0X01;      										/* 16- bit timer0 selected*/
						TH0=0xB8;												/* Calculation= delay(half time) /(6/11.0592Mhz)=value*/
						TL0=0x12;
						IE=0X82;												/* 65535-value= timer value , now  put timer value in Hex in TH0(Higher byte) and TL0(Lower byte)*/
						TR0=1;													/* Running  the timer*/
					}
					count++;	 												/* Clear timer flag bit for next calculation*/
				}
				break;
		#endif
	}
}
