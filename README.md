# Duopop Game Show popper mod

Modify a DUO pop to work with a PC (MacOS, Linux, Windows)

Based on the Adafruit guide https://learn.adafruit.com/wireless-game-show-poppers/introduction

## Duopop poppers

### Disassembly

* Remove the screw inside the battery compartment
* Remove the screw hidden beneath the circular notched plug (It is pressure fit. I threaded a screw into the plastic then just pulled) 

#### Jumper settings

The poppers (buzzers) all share the same pcb, but they have jumper settings to assumedly change the flash pattern of the IR LED. Further testing is needed to prove this theory. It would be interesting to see if new patterns could be achieved, to enable games for more than 4 players.

|         | J1      | J2      | J3      | J4      | J5      |
|---------|---------|---------|---------|---------|---------|
| Yellow  | TRUE    | FALSE   | TRUE    | FALSE   | FALSE   |
| Green   | FALSE   | TRUE    | FALSE   | TRUE    | FALSE   |
| Blue    | FALSE   | TRUE    | TRUE    | TRUE    | FALSE   |
| Red     | TRUE    | FALSE   | TRUE    | TRUE    | FALSE   |

