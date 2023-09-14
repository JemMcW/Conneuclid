//---------------------------------------------------------
//--------------- EuclidNamo ------------------------------
//---------------------------------------------------------
//
// Euclidean Rythm Sequencer using Arduino Nano Every as
// the processor, a NeoPixels led ring as the main UI
// Rotary Encoder + push button, two buttons a toggle and
// a potentiometer as input devices
//
// The sequencer has 4 channels each with up to 16 steps
// 4 Eurorack Gate outputs are provided
// The sequencer has internal clock, but can be switch to
// use an external clock from Eurorack
//
//---------------------------------------------------------

//---------------------------------------------------------
//
// File: PushButtons.ino
// Functions to handle digital push buttons and inputs
//
// Original Author: Israel Roth
// Date: May 28, 2021
//
// Modified by: Jemison W.
// Date: Sep 14th, 2023
// 
// Adds a "reset" button input, returns the note being sent to the start again
//
//---------------------------------------------------------

#define DEBOUNCE_DELAY            75

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 75;

int lastButtonState = HIGH;   // the previous reading from the input pin
int last_value_channel_button = 0;

void PushButtonsSetup()
{
	lastDebounceTime = millis();
	pinMode(PLAY_STOP_BTN_PIN, INPUT_PULLUP);
	last_value_channel_button = stableAnalogRead(CHANNEL_SEL_BTN_PIN);
}

void handlePlayButtonPressed()
{
	Serial.println("Play Button Pressed");
	if (edit_mode == EDIT_MODE_MEMORY)
	{  // PLAY button used as Load
		loadCurrentPatchFromSlot(cur_memory_pos);
		edit_mode = EDIT_MODE_PATTERN_LEN;
	}
	else
	{
		isPlaying = !isPlaying;
	}
}

void handleChannelButtonPressed()
{
	Serial.println("Channel Button Pressed");
	if (edit_mode == EDIT_MODE_MEMORY)
	{  // CHAN button used as Store
		storeCurrentPatchToSlot(cur_memory_pos);
		edit_mode = EDIT_MODE_PATTERN_LEN;
	}
	else
	{
		curChannel++;
		if (curChannel >= NUM_CHANNELS)
		{
			curChannel = 0;
		}
	}
}

void handlePlayButton()
{
	int reading = digitalRead(PLAY_STOP_BTN_PIN);
	if (reading != lastButtonState)
	{
		// reset the debouncing timer
		lastDebounceTime = millis();
	}
	if ((millis() - lastDebounceTime) > debounceDelay)
	{
		if (reading != buttonState)
		{
			buttonState = reading;
			if (buttonState == LOW)
			{
				handlePlayButtonPressed();
			}
		}
	}
	lastButtonState = reading;
}

void handleChannelButton()
{
	int cur_value = stableAnalogRead(CHANNEL_SEL_BTN_PIN);
	if (abs(cur_value - last_value_channel_button) < 100)
	{
		last_value_channel_button = cur_value;
		return;
	}
	last_value_channel_button = cur_value;
	if (cur_value < 100)
	{
		handleChannelButtonPressed();
	}
}

void handlePushButtons()
{
	handlePlayButton();
	handleChannelButton();
}
