**Core Ideas**

- Because the potentiometer has error, it would be useful to automatically search for the highest voltage read by the controller and re-calculate the ratio.

**Inputs**

1. Strain Gauge
   _Beep when overloaded_
1. Gauge Selection (up and down buttons)
   _Temporarily toggle LCD to display the selected gauge setting, or just have the top line read out the gauge_
1. Voltage Readout (from potentiometer)
   _ADC sampling_
1. Mute Volume Toggle

**Output Format**

2x20

<<[RAIL_TYPE] [MUTE]>>
......|..[]......... // OR just put the measurement readout in the middle
