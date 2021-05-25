#include<stdlib.h>
#include<string.h>


char error_message[]={"invalid value\n\0"};
char prompt[]={"enter voltage in the format a.bc :\n\0"};
char ack[]={"voltage set success\n\0"};

char rx[5];
volatile int count=0;
float value;


void set_usart(){
UBRR0H=0X00;
UBRR0L=103;
UCSR0B=(1<<TXEN0)|(1<<RXEN0)|(1<<RXCIE0);
UCSR0C=(1<<UCSZ00)|(1<<UCSZ01);
}



void send_message(char* tx)
{
  int i=0;
  while(tx[i]!='\0')
  {
    while(!( UCSR0A & (1<<UDRE0)));
      UDR0=tx[i];
      i++;
    
  }
}



void set_voltage(char *st)
{
  if(count==4)
  {
    
    if(st[0]=='-')
    {
      send_message(error_message);
      count=0;
    }
    else
    {
      count=0;
      value=atof(st);
     if(value<0 || value>5)
      {
       send_message(error_message);
       send_message(prompt);
      }
     else
     {
       OCR0A=255*value/5;
       send_message(ack);
       send_message(prompt);
     }
   }
  }
}



void set_pwm()
{
  pinMode(6,OUTPUT);
  TCCR0A=0X83;
  TCCR0B=0X04;
  set_voltage(rx);
}



void setup(){
  set_usart();
  set_pwm();
  
}



void loop(){
  set_voltage(rx);
 }



ISR(USART_RX_vect){
  rx[count++]=UDR0;
}
