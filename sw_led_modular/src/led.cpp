#include<Arduino.h>
#define ld 13

void Led_State(int state){
    digitalWrite(ld,state);
}
