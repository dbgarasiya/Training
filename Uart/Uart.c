#include <reg51.h>
#include <stdio.h>

void Serial_Init(int);

void main()
{
	Serial_Init(9600);
	while(1)
	{
		putchar('D');
	}
}

void Serial_Init(int baudrate)
{
	switch(baudrate)
	{
		case 9600:
			SCON  = 0x50;                   /* SCON: mode 1, 8-bit UART, enable rcvr    */
			TMOD |= 0x20;                   /* TMOD: timer 1, mode 2, 8-bit reload      */
			TH1   = -3;	                    /* TH1:  reload value for 9600 baud         */
			TR1   = 1;                      /* TR1:  timer 1 run                        */
			TI    = 1;                      /* TI:   set TI to send first char of UART  */
		break;
	}
}