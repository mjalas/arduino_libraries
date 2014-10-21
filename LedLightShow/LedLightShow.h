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

#ifndef LEDLIGHTSHOW_H
#define LEDLIGHTSHOW_H

#include "Arduino.h"

class LedLightShow{
public:
	LedLightShow(int firstLed, int lastLed);
	void led_on(int led, int delay_time);
	void led_off(int led, int delay_time);
	void leds_off_left(int delay_time);
	void leds_off_right(int delay_time);
	void blink_all(int times, int delay_time);
	void side_in_side_out(int delay_time, int freeze_time);
	void turn_all_LEDs(bool on, int delay_time);
	void leds_on_left(int delay_time);
	void leds_on_right(int delay_time);
	void light_wave(int delay_time, int leds_on);
	void light_wave_reverse(int delay_time, int leds_on);
	void worm(int delay_time);
	void worm_reverse(int delay_time);
	void light_wave_stopper(int delay_time, int leds_on, boolean on);
	void light_wave_stopper_reverse(int delay_time, int leds_on, boolean on);
	void two_roller_lights(int delay_time);
	void two_roller_lights_reverse(int delay_time);


private:
	int first;
	int last;

};

#endif