# Duopop Game Show popper mod

Modify a DUO pop to work with a PC (MacOS, Linux, Windows.) The mod uses an Adafruit PRO Trinket (5V 16MHz) embedded in the DUOPOP receiver box. The DUOPOP logic board is replaced by the Trinket. Batteries are no longer required in the receiver, and the Trinket makes use of the DUOPOP IR receivers. The Trinket interfaces with a computer via USB cable, and when it receives IR patterns from the DUOPOP buzzers, an emulated keyboard press is sent to the PC. The keyboard presses are meant to be interpreted by software such as Game Show Presenter or similar.   

Based on the Adafruit guide https://learn.adafruit.com/wireless-game-show-poppers/introduction

## Duopop poppers

### Disassembly

* Remove the screw inside the battery compartment
* Remove the screw hidden beneath the circular notched plug (It is pressure fit. I threaded a screw into the plastic then just pulled)

#### Jumper settings

![The top of the DUOPOPPER PCB contains five jumper traces. ](popper.png?raw=true "Duo POP buzzer PCB")

The poppers (buzzers) all share the same PCB, but they have solderable jumpers which change the flash pattern of the IR LED. Jumpers 1 through 4 seem to control the IR pattern emitted. Jumper 5's function is unknown. New IR flash patterns can be achieved by changing jumpers 1 through 4, to enable games with more than 4 buzzers. Below are the jumper settings and IR flash patterns which have been tested. The IR flash patterns are discovered using Adafruit's [Using An IR Sensor](https://learn.adafruit.com/ir-sensor/using-an-ir-sensor) tutorial. The below patterns are normalized and truncated for use in the Trinket's code. For examples of raw flash patterns as observed, refer to ir-patterns.md.


|           | J1      | J2      | J3      | J4      | J5      | Pattern                                                                                       |
|-----------|---------|---------|---------|---------|---------|-----------------------------------------------------------------------------------------------|
| Grn       | FALSE   | TRUE    | FALSE   | TRUE    | FALSE   | 150,  50, 100, 100,	 50,  50, 100, 100,	 50,  50, 100, 100,	 50,  50, 100, 100,	 50,  50,	100 |
| Blu       | FALSE   | TRUE    | TRUE    | TRUE    | FALSE   | 150,  50, 100,  50, 100,  50, 100, 100,	 50,  50, 100,  50, 100,  50, 100, 100,	 50,  50,	100 |
| Red       | TRUE    | FALSE   | TRUE    | TRUE    | FALSE   | 150,  50, 100,  50, 100, 100,  50,  50, 100,  50, 100,  50, 100, 100,  50,  50, 100,  50,	100 |
| Yel       | TRUE    | FALSE   | TRUE    | FALSE   | FALSE   | 150, 100,  50,  50, 100, 100,  50,  50, 100, 100,  50,  50, 100, 100,  50,  50, 100,  50, 100 |
| Org (mod) | TRUE    | TRUE    | TRUE    | FALSE   | FALSE   | 150, 100,  50,  50, 100,  50, 100,  50, 100, 100,  50,  50, 100,  50, 100,  50, 100,  50, 100 |
| Pnk (mod) | TRUE    | FALSE   | FALSE   | FALSE   | FALSE   | 150, 100,  58, 100,  54, 100,  54,  46, 100, 100,  48, 100,  56, 100,  54,  48, 100,  48, 100 |
| Yel (ada) | UNKNOWN | UNKNOWN | UNKNOWN | UNKNOWN | UNKNOWN | 140, 100,  50,  50, 100, 100,  50,  50, 100, 100,  50,  50, 100, 100,  50,  50, 100,  50, 100 |
