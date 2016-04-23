#include<reg51.h>
#define lcd_port P2
sbit RS=P0^0;
sbit EN=P0^1;



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
	lcd_command(0x38);
	lcd_command(0x83);
	lcd_command(0x03);
	lcd_command(0x82);
	lcd_command(0x02);
	lcd_command(0x28);
	lcd_command(0x28);
	lcd_command(0x10);
	lcd_command(0x01);
	lcd_command(0x0F);
	lcd_command(0x0C);
	lcd_command(0x06);
	lcd_command(0x01);
	lcd_command(0x80);

} 

void lcd_command(unsigned char command)
{
	RS=0;
	lcd_port = command & 0XF0;
	EN=1;
	lcd_port = command & 0XF0;
	EN=0;
	delay_ms(1);

	lcd_port = ((command & 0X0F)<<4);
	EN=1;
	lcd_port = ((command & 0X0F)<<4);
	EN=0;
	delay_ms(1);
}

void lcd_display(unsigned char display)
{
	RS=1;
	lcd_port= display & 0XF0;
	EN=1;
	lcd_port= display & 0XF0;
	EN=0;
	delay_ms(1);

	lcd_port=((display & 0X0F)<<4);
	EN=1;
	lcd_port=((display & 0X0F)<<4);
	EN=0;
	delay_ms(1);
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
		lcd_display(*name);
		name++;
	}
		

}
