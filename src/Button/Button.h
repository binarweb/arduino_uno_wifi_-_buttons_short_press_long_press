#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

#define BUTTON_PUSHED              HIGH
#define BUTTON_RELEASED            LOW
#define BUTTON_DEBOUNCE_TIME_SHORT 300 // in milliseconds
#define BUTTON_DEBOUNCE_TIME_LONG  1000 // in milliseconds

class Button {
public:
	Button(uint8_t p_pin);
	void run();
	bool isPressedShort();
	bool isPressedLong();
	void setDebounceTimeShort(uint16_t p_time);
	void setDebounceTimeLong(uint16_t p_time);
private:
	uint8_t _buttonPin;
	uint16_t _debounceTimeShort = BUTTON_DEBOUNCE_TIME_SHORT;
	uint16_t _debounceTimeLong = BUTTON_DEBOUNCE_TIME_LONG;
	uint8_t _lastStateShort = BUTTON_RELEASED;
	uint8_t _lastStateLong = BUTTON_RELEASED;
	unsigned long _timeNowShort = 0;
	unsigned long _timeNowLong = 0;
	bool _buttonIsPressedShort = false;
	bool _buttonIsPressedLong = false;
	bool _ignoreReadingShort = false; // to trigger button pressed event only once (until it gets released)
	bool _ignoreReadingLong = false; // to trigger button pressed event only once (until it gets released)
};

#endif