#include<reg51.h>
send_startingsequence()
send_stoppingsequence()
send_data(unsigned char)
read_data()


void main()
{

send_startingsequence()
{
	SCL_pin=1;
	SDL_pin=0;
}

send_stoppingsequence()
{
	SCL_pin=1;
	SDL_pin=1;
}

send_data(unsigned char _data)
{
	for(i=8; i>0 ; i--)
	{
		SCL_pin=0;
		SDA_PIN = (_data & 0x80);
		_data = _data << 1;
		SCL_PIN = 1;
	}
}

read_data()
{

	
}























}