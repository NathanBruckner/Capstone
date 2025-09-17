**Electrical Design Decision**

# Component Selections

1. Microcontroller Selection

- Chose between ESP32 and STM32 (likely ESP)
  Decide which language to put everything in

2. Measurement Device

- Hall Effect Sensor / Encoder
- String Potentiometer
- Geared Potentiometer
- Laser / Optical Encoder

3. Display Device

- 7 Segment Display
- LCD

4. Battery

## Implementation Decisions

1. Location of measurement device, readout
2. Whether or not we combine measurement device and black box containing Microcontroller
3. Do we need a PCB? (Likely not, at least for now)
4. Actuating clutch // Work with Josh
