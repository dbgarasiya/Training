#include<reg51.h>

sfr lcd_port=0xA0;

sbit RS = P0^0;
sbit RW = P0^1;
sbit EN = P0^2;

void lcd_ini();	   																/*  drive level*/
void lcd_command(unsigned char);												/*  driver level*/
void lcd_display(unsigned char);												/*  driver level */
void delay_ms(unsigned int);													/*  application level*/
void lcd_string(unsigned char*);												/*  application level*/

main()
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
		lcd_string("Hello world");
	}

}

void lcd_ini()
{

 		lcd_command(0x38);
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

		RW=0;
		RS=0;
		lcd_port=command;
		EN=1;
		EN=0;
		delay_ms(5);
		
	}


void lcd_display(unsigned char display)
    {


      	RW=0;
		RS=1;
		lcd_port=display;
		EN=1;
		EN=0;
		delay_ms(1);
		
	
	}

void  delay_ms(unsigned int x)
{

	int i,j;
	for(i=0;i<=x;i++)
		for(j=0;j<=1275;j++);

}


void  lcd_string(unsigned char* name)
{
	while(*name!='\0')
	{
		lcd_display(*name);
		name++;
	}		   		
}
















