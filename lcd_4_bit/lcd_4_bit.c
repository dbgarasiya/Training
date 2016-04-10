#include<reg51.h>

sbit RS=P0^0;
sbit EN=P0^1;
sfr  lcd_port=0X05;

void lcd_ini();
void lcd_command(unsigned char);
void lcd_display(unsigned char);
void delay_ms(unsigned int);
void lcd_string(unsigned char*);

void main()
{

	lcd_ini();
	lcd_command(0x80);
	lcd_display('D');
	lcd_display('I');
	lcd_display('P');
	lcd_display('A');
	lcd_display('K');

while(1)

{
	 lcd_command(0x80);
	 lcd_string("HELLO WORLD");
}

}

void lcd_ini()
{
	lcd_command(0x28);
	delay_ms(30);
	lcd_command(0x0F);
	delay_ms(10);
	lcd_command(0x06);
	delay_ms(10);
	lcd_command(0x01);
	delay_ms(10);

} 

void lcd_command(unsigned char command)
{
	RS=0;
	lcd_port=command;
	EN=1;
	EN=0;
}

void lcd_display(unsigned char display)
{
	RS=1;
	lcd_port=display;
	EN=1;
	EN=0;
}

void delay_ms(unsigned int x)
{
	int i,j;
	for(i=0;i<=x;i++)
		for(j=0;j<=1275;j++);

}

void lcd_string(unsigned char* name)
{
	while(*name!='\0')
	{
		lcd_port(*name)
		name++;
	}
		

}


















}
