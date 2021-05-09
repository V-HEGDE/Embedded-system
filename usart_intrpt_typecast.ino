char rx;
unsigned long var_l;

void setup() {
   var_l='a';
   var_l|=('b'<<8);
   var_l|=(unsigned long)'c'<<16;
   var_l|=(unsigned long)'d'<<24;
   UBRR0H=0X00;
   UBRR0L=103;

  UCSR0B=(1<<TXEN0)|(1<<RXEN0)|(1<<RXCIE0);
  UCSR0C=(1<<UCSZ00)|(1<<UCSZ01);;
}

void sendchar(unsigned char *c){
  int i;
  rx=0;
  for(i=0;i<4;i++){
    UDR0=*c;
    c++;
    while(!(UCSR0A&(1<<5)));
  }
}


ISR(USART_RX_vect){
  rx=UDR0;
  if(rx==1){
  sendchar((unsigned char*)&var_l);
  }
}
