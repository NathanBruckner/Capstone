**Necessary Functions**

Turn on N-channel MOSFET to drive actuator
Accept button presses
Update distance readout
Detect when position changes and shut off after a certain time, have a refractory time

Always
{
pole sensor at definable rate

}

Modes

- Automatic
  - Set different gauges
  - Disengage clutch within tolerance

- Manual
- Only have readout

Regardless of tool mode, readout should always be stored.

Make a pole() function that returns the most recent value of ToF
Make a moving average filter movAvg() that populates 10 readings at a time and averages them. This is what is displayed

Put the pole() function in a sensor class
Make the moving average filter in main()

Make a wait() function that makes the menu wait after each input.

Up / Down arrows should cycle through pre-defined track gauges.

There should be an automatic boolean that controls the auto-shutoff mechanic of the clutch.

Have a loop that is constantly running perform
{
dataPt = sensor.pole()
readOut = DSP(data)
if (automatic)
{
if abs(readOut - gauge) <= tolerance
solenoid.activate() //wait two seconds and deactivate
if abs(readOut - gauge) <= secondTolerance
//have logic here to prevent tool from repeatedly triggering the solenoid until readOut-gauge becomes greater than second tolerance.
}

}

So, we will have four classes. display, button, solenoid, and sensor.

**Classes**

1. button
   Button should have one member keeping track of its last status. Basically, just make it a T-flip-flop. E.g. if pressed, status = !status.
   Make it have 1 function: button.push().
1. display
   Display should have one function that displays an input string on a specified line. display.print(string, lineNumer);
1. solenoid
   solenoid should have a solenoid.trigger() that triggers the solenoid and waits for 2 seconds before turning it off.
   its member variables should include the port information to control it.
1. sensor
   sensor should have sensor.pull() that pulls a reading from the laser. We could fit the dsp functions in sensor
