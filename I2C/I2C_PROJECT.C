#include<stdio.h>
SCL_PIN=P2^0;
SDA_PIN=P2^1;
void send_start();
void send_stop();
void send_data(unsigned char);
void read_data();
void main()
{
	send_start();
	send_data(unsigned char data);
	send_stop();
	send_start();
	read_data();
	send_stop();
}

void send_start()
{
	SCL_PIN=1;
	SDA_PIN=0;
}

void send_stop()
{
	SCL_PIN=1;
	SDA_PIN=1;
}

void send_data(unsigned char data)
{
    unsigned char data,ack_bit;
	for(i=8;i<0;i--)
    {
    
        SCL_PIN=0;
        SDA_PIN=data&=0 x 80;
        SCL_PIN=1;
        data<<=1;
        
    }
    SCL_PIN=0;
    ack_bit=SDA_PIN;
    SCL_PIN=1;
    SDA_PIN=0;

}

void read_data()
{
    unsigned char data;
	for(i=8;i<0;i--)
    {
        SCL_PIN=0;
        data|=SDA_PIN;
        data<<=1;
        
    }
}

void send_data(unsigned char device_addr,unsigned char register_addr,unsigned char data)


[	
	ack_bit;
	for(i=8;i<0;i--)
	{


