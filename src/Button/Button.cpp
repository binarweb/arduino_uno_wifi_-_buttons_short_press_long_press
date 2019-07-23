#include "Button.h"

Button::Button(uint8_t p_pin) : _buttonPin(p_pin) {
	pinMode(_buttonPin, INPUT);
}

bool Button::isPressedShort() {
	return _buttonIsPressedShort;
}

bool Button::isPressedLong() {
	return _buttonIsPressedLong;
}

void Button::setDebounceTimeShort(uint16_t p_time) {
	_debounceTimeShort = p_time;
}

void Button::setDebounceTimeLong(uint16_t p_time) {
	_debounceTimeLong = p_time;
}

void Button::run() {
	unsigned long millisec = millis();
	uint8_t reading = digitalRead(_buttonPin);

	// short press
	_buttonIsPressedShort = false;

	if (reading != _lastStateShort) {
		_timeNowShort = millisec;
	}

	if (reading == BUTTON_PUSHED && (millisec - _timeNowShort) > _debounceTimeShort) {
		if (!_ignoreReadingShort) {
			_buttonIsPressedShort = true;
			_ignoreReadingShort = true;
		}
	} else {
		_ignoreReadingShort = false;
	}
	_lastStateShort = reading;

	// long press
	_buttonIsPressedLong = false;

	if (reading != _lastStateLong) {
		_timeNowLong = millisec;
	}
	if (reading == BUTTON_PUSHED && (millisec - _timeNowLong) > _debounceTimeLong) {
		if (!_ignoreReadingLong) {
			_buttonIsPressedLong = true;
			_ignoreReadingLong = true;
		}
	} else {
		_ignoreReadingLong = false;
	}
	_lastStateLong = reading;
}