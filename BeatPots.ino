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
// File: BeatPots.ino
// Reads 4 potentiometers to control the number of beats per
// channel
//
// Author: Jemison W.
// Date: Sep 14th, 2023
//
//---------------------------------------------------------

const int numBeatsPotPins[4] = {NUM_BEATS_CH1_POT_PIN, NUM_BEATS_CH2_POT_PIN, NUM_BEATS_CH3_POT_PIN, NUM_BEATS_CH4_POT_PIN};
int numBeatsPrevPotValues = {0, 0, 0, 0};

void HandleNumBeatsPots()
{
	for (int channel = 0; channel < 4; ++channel)
		SetNumBeatsFromPot(channel);
}

void SetNumBeatsFromPot(int channel)
{
	int potReading = stableAnalogRead(numBeatsPotsPins[channel]); // 0-1023
	int numBeats = (potReading + 1) / 64 - 8;

	if (numBeats != numBeatsPrevPotValues[channel])
	{
		numBeatsPrevPotValues[channel] = numBeats;
		pattern_nactive[channel] = numBeats;
		euclid(pattern_length[curChannel], pattern_nactive[curChannel], curChannel, pattern_offset[curChannel]);
	}
}