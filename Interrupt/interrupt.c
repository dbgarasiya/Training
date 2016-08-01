#include <reg51.h>

sbit LED = P1^7;

int a = 0;

void main()
{
	IE = 0x81;
	TCON = 0x01;

	a++;

	while(1)
	{
		P2 ^= 0xFF;
	}
}

void ISR0()	interrupt 0
{
	a++;
	LED ^= 1;
}