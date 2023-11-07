#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"


int main(){

  P1DIR |= LEDS;
  P1OUT &= ~LED_RED;

  
  configureClocks();
  switch_init();
  led_init();
  buzzer_init();


  enableWDTInterrupts();

  
  or_sr(0x18);
  
}

int buzzerLimit = 1000;
int buzzerCount = 0;
int secondCount = 0;
int buzzerSound = 1000;

void
__interrupt_vec(WDT_VECTOR) WDT(){

  /*if(buzzerCount >= buzzerLimit){
    buzzerCount = 0;
    buzzerSound = 1000;
    buzzer_set_period(buzzerSound);
  }else{
    buzzerSound++;
    buzzerCount++;
    buzzer_set_period(buzzerSound);
  }
  */

  if(secondCount == 0){
    buzzer_set_period(1000);
  }

  if(secondCount == 125){
    buzzer_set_period(2000);
  }
  if(secondCount == 250){
    buzzer_set_period(1000);
  }
  if(secondCount == 375){
    buzzer_set_period(2000);
  }
  if(secondCount == 500){
    buzzer_set_period(1000);
  }
  if(secondCount == 625){
    buzzer_set_period(2000);
  }
  if(secondCount == 750){
    buzzer_set_period(1000);
  }
  if(secondCount == 875){
    buzzer_set_period(2000);
  }
  
  if(secondCount % 50 == 0){
    P1OUT |= LED_GREEN;
  }else
    P1OUT &= ~LED_GREEN;
  
  secondCount ++;
  if(secondCount >= 1000){
    secondCount = 0;
  }
  
}
