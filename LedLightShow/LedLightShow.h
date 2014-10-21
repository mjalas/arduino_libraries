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