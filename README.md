# Duopop Game Show popper mod

Modify a DUO pop to work with a PC (MacOS, Linux, Windows)

Based on the Adafruit guide https://learn.adafruit.com/wireless-game-show-poppers/introduction

## Duopop poppers

### Disassembly

* Remove the screw inside the battery compartment
* Remove the screw hidden beneath the circular notched plug (It is pressure fit. I threaded a screw into the plastic then just pulled)

#### Jumper settings

The poppers (buzzers) all share the same pcb, but they have jumper settings to assumedly change the flash pattern of the IR LED. Further testing is needed to prove this theory. It would be interesting to see if new patterns could be achieved, to enable games for more than 4 players.

|           | J1      | J2      | J3      | J4      | J5      | Pattern                                                                                       |
|-----------|---------|---------|---------|---------|---------|-----------------------------------------------------------------------------------------------|
| Grn       | FALSE   | TRUE    | FALSE   | TRUE    | FALSE   | 150,  50, 100, 100,	 50,  50, 100, 100,	 50,  50, 100, 100,	 50,  50, 100, 100,	 50,  50,	100 |
| Blu       | FALSE   | TRUE    | TRUE    | TRUE    | FALSE   | 150,  50, 100,  50, 100,  50, 100, 100,	 50,  50, 100,  50, 100,  50, 100, 100,	 50,  50,	100 |
| Red       | TRUE    | FALSE   | TRUE    | TRUE    | FALSE   | 150,  50, 100,  50, 100, 100,  50,  50, 100,  50, 100,  50, 100, 100,  50,  50, 100,  50,	100 |
| Yel       | TRUE    | FALSE   | TRUE    | FALSE   | FALSE   | 150, 100,  50,  50, 100, 100,  50,  50, 100, 100,  50,  50, 100, 100,  50,  50, 100,  50, 100 |
| Org (mod) | TRUE    | TRUE    | TRUE    | FALSE   | FALSE   | 150, 100,  50,  50, 100,  50, 100,  50, 100, 100,  50,  50, 100,  50, 100,  50, 100,  50, 100 |
| Pnk (mod) | TRUE    | FALSE   | FALSE   | FALSE   | FALSE   | 150, 100,  58, 100,  54, 100,  54,  46, 100, 100,  48, 100,  56, 100,  54,  48, 100,  48, 100 |
| Yel (ada) | UNKNOWN | UNKNOWN | UNKNOWN | UNKNOWN | UNKNOWN | 140, 100,  50,  50, 100, 100,  50,  50, 100, 100,  50,  50, 100, 100,  50,  50, 100,  50, 100 |
