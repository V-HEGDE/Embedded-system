#include<Arduino.h>
#include "switch_pub.h"
#define sw 7
int is_switch_pressed(void){
    int switch_pressed=false;
    if(!digitalRead(sw)){
        switch_pressed=true;
    }
    else{
        switch_pressed=false;
    }
    return switch_pressed;
}
