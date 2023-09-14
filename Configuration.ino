//---------------------------------------------------------
//--------------- NanoEuclid ------------------------------
//---------------------------------------------------------
//
// Euclidean Rythm Sequencer using Arduino Nano Every as
// the processor, a NeoPixels led ring as the main UI
// Rotary Encoder + push button, two buttons a toggle and
// a potentiometer as input devices
//
// The sequencer has 4 channels each with up to 16 steps
// 4 Eurorack Gate outputs are provided
// The sequencer has internal clock, but can be switched to
// use an external clock from Eurorack
//
//---------------------------------------------------------

//---------------------------------------------------------
//
// File: Configuration.ino
// This is a convenient place to change pin assignments and
// settings so this project is easier to configure
//
// Author: Jemison W.
// Date: Sep 14th, 2023
//
//---------------------------------------------------------

// Settings
#define ENABLE_INTERNAL_CLOCK_SWITCH false
#define NUM_BEAT_POTS_INSTALLED false

// Outputs
#define CHANNEL_1_PIN			2
#define CHANNEL_2_PIN			3
#define CHANNEL_3_PIN			4
#define CHANNEL_4_PIN			5

// Lights
#define NEOPIXELS_PIN       	6

// Encoder
#define PIN_ENCODER_A      		7
#define PIN_ENCODER_B      		8
#define PIN_ENCODER_SWITCH 		9

// Digital Inputs / Buttons
#define PIN_SYNC_IN 			10  // clock in pin
#define PLAY_STOP_BTN_PIN		11
#define RESET_BTN_PIN			12
#define CHANNEL_SEL_BTN_PIN		17

// Potentiometers
#define TEMPO_POT_PIN			A1	// Pin 15
#define NUM_BEATS_CH1_POT_PIN	A2	// Pin 16
#define NUM_BEATS_CH2_POT_PIN	A3	// Pin 17
#define NUM_BEATS_CH3_POT_PIN	A4	// Pin 18
#define NUM_BEATS_CH4_POT_PIN	A5	// Pin 19

