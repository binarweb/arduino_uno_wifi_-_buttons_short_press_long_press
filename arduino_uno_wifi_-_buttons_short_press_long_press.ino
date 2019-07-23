#include "src/Button/Button.h"

// setari
#define TEST_BUTTON1 4          // D5
#define TEST_BUTTON2 5          // D6
#define SERIAL_BAUDRATE 115200  // indeajuns de rapid

Button testButton(TEST_BUTTON1);
Button pairingButton(TEST_BUTTON2);

void setup() {
	Serial.begin(SERIAL_BAUDRATE);

	// setup test buttons
	testButton.setDebounceTimeShort(100);
	testButton.setDebounceTimeLong(2000);

	pairingButton.setDebounceTimeShort(100);
	pairingButton.setDebounceTimeLong(2000);

	Serial.println("!!! Button test");
}

void loop() {
	if (testButton.isPressedShort()) {
		Serial.println("Button 1 pressed SHORT!");
	}
	if (testButton.isPressedLong()) {
		Serial.println("Button 1 pressed LONG!");
		Serial.println("**********************");
	}
	if (pairingButton.isPressedShort()) {
		Serial.println("Button 2 pressed SHORT!");
	}
	if (pairingButton.isPressedLong()) {
		Serial.println("Button 2 pressed LONG!");
		Serial.println("**********************");
	}

	testButton.run();
	pairingButton.run();
}