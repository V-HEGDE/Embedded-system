unsigned long current_val_ms;
unsigned long task200_ms=0;
unsigned long task500_ms=0;


#define TASK_200MS_ACTIVE 50
#define TASK_500MS_ACTIVE 500
#define sw 7
#define led 13

int switch_state;
int led_state;

void setup() {
  pinMode(sw,INPUT_PULLUP);
  pinMode(led,OUTPUT);
}


void loop() {
  current_val_ms=millis();

  if(current_val_ms-task200_ms >= TASK_200MS_ACTIVE){
    task200_ms=current_val_ms;

    if(digitalRead(sw) == LOW){
      switch_state++;
    }
    
  }

  if(current_val_ms-task500_ms >= TASK_500MS_ACTIVE){
    task500_ms=current_val_ms;
    if(switch_state){
      led_state=(led_state^1);
      digitalWrite(led,led_state);
      switch_state--;
    }
    else{
      digitalWrite(led,LOW);
    }
  }
}
