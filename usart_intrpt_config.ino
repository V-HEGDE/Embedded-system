byte rx;
void setup() {
  // put your setup code here, to run once:
UBRR0H=0X00;
UBRR0L=103;

UCSR0B=(1<<TXEN0)|(1<<RXEN0)|(1<<RXCIE0);
UCSR0C=(1<<UCSZ00)|(1<<UCSZ01);
}

void loop() {
  // put your main code here, to run repeatedly:

}
ISR(USART_RX_vect){
  rx=UDR0+1;
  UDR0=rx-1;
}
