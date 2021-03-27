#define sw 7
#define led 8
void setup() {
  // put your setup code here, to run once:
  pinMode(sw,INPUT);
  pinMode(led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(sw)==HIGH){
    digitalWrite(led,HIGH);
    delay(200);
    digitalWrite(led,LOW);
    delay(200);
    digitalWrite(led,HIGH);
    delay(200);
    digitalWrite(led,LOW);
    delay(200);
  }

}
