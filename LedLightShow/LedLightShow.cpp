/*
 LedLightShow.cpp - Library for creating a light show with a row of LEDs. 

 Copyright 2013 Mats Jalas

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#include "Arduino.h"
#include "LedLightShow.h"

LedLightShow::LedLightShow(int firstLed, int lastLed){
	first = firstLed;
	last = lastLed;

	for(int i = firstLed; i <= lastLed; i++){
		pinMode(i, OUTPUT);
	}
}
	
void LedLightShow::led_on(int led, int delay_time){
	digitalWrite(led, HIGH);
  	delay(delay_time);
}

void LedLightShow::led_off(int led, int delay_time){
	digitalWrite(led, LOW);
  	delay(delay_time);
}

void LedLightShow::leds_off_left(int delay_time){
	for(int i = first; i <= last; i++){
   		led_off(i, delay_time);
  	}
}

void LedLightShow::leds_off_right(int delay_time){
	for(int i = last; i >= first; i--){
    	led_off(i, delay_time);
  	}
}

void LedLightShow::blink_all(int times, int delay_time){
	for(int i = 0; i < times; i++){
    	turn_all_LEDs(true, delay_time);
    	turn_all_LEDs(false, delay_time);
  	}
}

void LedLightShow::side_in_side_out(int delay_time, int freeze_time){
	//turn LEDs on
	for(int i = first; i <= (last/2)+1; i++){
   		digitalWrite(i, HIGH);  
    	delay(delay_time);
    	digitalWrite(13-i, HIGH);   
    	delay(delay_time);
  	}

  	//keep LEDs on
  	delay(freeze_time); 

 	//Turn LEDs off
  	for(int i = 2; i <= 6; i++){
    	digitalWrite(i, LOW);  
    	delay(delay_time);
    	digitalWrite(13-i, LOW);   
    	delay(delay_time);
  	}
  
  	//keep LEDs off
  	delay(freeze_time);
}

void LedLightShow::turn_all_LEDs(bool on, int delay_time){
	if(on == true){
    	for(int i = first; i <= last; i++){
    	 	digitalWrite(i,HIGH);
    	}
  	}else{
    	for(int i = first; i <= last; i++){
     		digitalWrite(i,LOW);
    	}
  	}
  	delay(delay_time);
}

void LedLightShow::leds_on_left(int delay_time){
	for(int i = first; i <= last; i++){
   		led_on(i, delay_time);
  	}
}

void LedLightShow::leds_on_right(int delay_time){
	for(int i = last; i >= first; i--){
    	led_on(i, delay_time);
  	}
}

void LedLightShow::light_wave(int delay_time, int leds_on){
	for(int i = first; i <= last; i++){
   		//Leds on.
   		for(int j = i; j <= (i+leds_on); j++){
     		digitalWrite(j, HIGH);
   		}
   
   		delay(delay_time);
   		//Leds off.
   		for(int j = i; j <= i+leds_on; j++){
     		digitalWrite(j, LOW);
   		}
 	} 
}

void LedLightShow::light_wave_reverse(int delay_time, int leds_on){
	for(int i = last; i >= first; i--){
   		//Leds on.
   		for(int j = i; j >= (i-leds_on); j--){
     		digitalWrite(j, HIGH);
   		}
   
   		delay(delay_time);
   		//Leds off.
   		for(int j = i; j >= i-leds_on; j--){
     		digitalWrite(j, LOW);
   		}
 	} 
}

void LedLightShow::worm(int delay_time){
	int i = first;
   	digitalWrite(i, HIGH);
    i++;
    delay(delay_time);
    
  	while(i <= last){
    	digitalWrite(i-2, LOW);
    	delay(delay_time);
    	digitalWrite(i,HIGH);
    	i++;
    	delay(delay_time);
    	digitalWrite(i, HIGH);
    	delay(delay_time);
    	digitalWrite(i-2, LOW);
    	delay(delay_time);
    	i++;
    
  	}
  	i--;
  	
  	digitalWrite(i-1,LOW);
}

void LedLightShow::worm_reverse(int delay_time){
	int i = last;
   	digitalWrite(i, HIGH);
   	i--;
   	delay(delay_time);
    
  	while(i >= first){
    	digitalWrite(i+2, LOW);
    	delay(delay_time);
    	digitalWrite(i, HIGH);
    	i--;
    	delay(delay_time);
    	digitalWrite(i,HIGH);
    	delay(delay_time);
    	digitalWrite(i+2, LOW);
    	delay(delay_time);
    	i--;
    
  	}
  	i++;
  	digitalWrite(i+1,LOW);
}

void LedLightShow::light_wave_stopper(int delay_time, int leds_on, boolean on){
	int ledON = HIGH;
    int ledOFF = LOW;
  	if(on == false){
    	ledON = LOW;
    	ledOFF = HIGH;
  	}
  
  	int diff = (last-first);
  	int stopper = 1;
  	int new_last = last;
  	int temp_last = 0;
  
  	for(int i = 0; i <= diff; i++){
  
    	for(int j = first; j <= new_last; j++){
      
    	  	if(j >= new_last-2){
        		temp_last = new_last;
      		}else{
        		temp_last = j + leds_on;
      		}
      
      		for(int k = j; k <= temp_last; k++){
       			digitalWrite(k, ledON);
      		}
   
      		delay(delay_time);
      		for(int k = j; k <= temp_last-stopper; k++){
       			digitalWrite(k, ledOFF);
      		}
    	}
    	new_last--;
  	}
}

void LedLightShow::light_wave_stopper_reverse(int delay_time, int leds_on, boolean on){
	int ledON = HIGH;
    int ledOFF = LOW;
  	if(on == false){
    	ledON = LOW;
    	ledOFF = HIGH;
  	}
  
  	int diff = (last-first);
  	int stopper = 1;
  	int new_last = first;
  	int temp_last = 0;
  
  	for(int i = 0; i <= diff; i++){
  
    	for(int j = last; j >= new_last; j--){
      
      		if(j <= new_last+2){
        		temp_last = new_last;
      		}else{
        		temp_last = j - leds_on;
      		}
      
      		for(int k = j; k >= temp_last; k--){
       			digitalWrite(k, ledON);
      		}
   
     		delay(delay_time);
      		for(int k = j; k >= temp_last+stopper; k--){
       			digitalWrite(k, ledOFF);
      		}
    	}
    	new_last++;
  	}
}

void LedLightShow::two_roller_lights(int delay_time){
	int i= first;
  	digitalWrite(i,HIGH);
    digitalWrite((last-i+first),HIGH);
    delay(delay_time);
    i++;
  	
  	while(i <= last/2 + 1){
    
    	digitalWrite(i,HIGH);
    	digitalWrite((last-i+first),HIGH);
    	delay(delay_time);
    	digitalWrite(i-1, LOW);
    	digitalWrite((last-i+first)+1, LOW);
    	i++;
    	delay(delay_time);
   
  	}
  
  	digitalWrite(i, LOW);
  	digitalWrite(i-1, LOW);
}

void LedLightShow::two_roller_lights_reverse(int delay_time){
	int i= last/2 + 1;
  	digitalWrite(i,HIGH);
  	digitalWrite((last-i+first),HIGH);
  	delay(delay_time);
  	i--;
  
  	while(i >= first){
    
    	digitalWrite(i,HIGH);
    	digitalWrite((last-i+first),HIGH);
    	delay(delay_time);
    	digitalWrite(i+1, LOW);
    	digitalWrite((last-i+first)-1, LOW);
    	i--;
    	delay(delay_time);
  	}
  
  	digitalWrite(i+1, LOW);
  	digitalWrite(i+last-1, LOW);
}

