#include<reg51.h>
sbit en=P1^2;
sbit rs=P1^3;
sfr lcd_port=0x90;
void lcd_command(unsigned char command);
void lcd_display(unsigned char display);
void delay_ms(unsigned int x);
void lcd_ini();

int main()
{
	while(1)
	{
		lcd_ini();
		lcd_command(0x80);
		lcd_display('D');
		lcd_display('i');
		lcd_display('p');
		lcd_display('a');
		lcd_display('k');
			
	}
	
}

void lcd_ini()
{
	
	lcd_command(0x33);
	delay_ms(30);
	lcd_command(0x32);
	delay_ms(30);
	lcd_command(0x28);
	delay_ms(30);
	lcd_command(0x0E);
	delay_ms(10);
	lcd_command(0x06);
	delay_ms(10);
	lcd_command(0x01);
	delay_ms(10);
}

void lcd_command(unsigned char command)
{
	rs=0;
	lcd_port=(command & 0xF0);
	en=1;
	en=0;
	delay_ms(5);
	lcd_port=((command<<4) & 0xF0);
	en=1;
	en=0;
	delay_ms(5);
	
}
void delay_ms(unsigned int x)
{
	int i,j;
	for(i=0;i<=x;i++)
		for(j=0;j<=1275;j++);
	
}

void lcd_display(unsigned char display)
{
	rs=1;
	lcd_port=(display & 0xF0);
	en=1;
	en=0;
	delay_ms(10);
	lcd_port=((display<<4) & 0xF0);
	en=1;
	en=0;
	delay_ms(10);
}