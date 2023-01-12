# Buzzer-Box

One of my first projects using an arduino board to test my CAD, electronics and programming skills.

## Parts List

_Microcontroller:_ Arduino Nano

_Range Finder:_ VL53L0X

_RGB Diode x 2_

_Buttons x 6:_

_Custom Case:_ `BuzzerBoxCase.stl` and `BuzzerBoxLid.stl` stored in `STL` folder

## Pin Layout

| VL53L0X Pin |        Arduino Pin         |
| :---------: | :------------------------: |
|     VCC     |             5V             |
|     GND     |            GND             |
|     SDA     |   A4 or SDA if Available   |
|     SCL     |   A5 or SCL if Available   |
|    GPIO1    |    Leave it Unconnected    |
|    XSHUT    | D12 (digital 12 or pin 12) |

|  LED Pin   | Arduino Pin |
| :--------: | :---------: |
|  LED Red   |   Pin D7    |
| LED Green  |   Pin D8    |
|  LED Blue  |   Pin D9    |
| Ground Pin |     GND     |

| Buzzer Pin | Arduino Pin |
| :--------: | :---------: |
|  Positive  |     D5      |
|  Negative  |     GND     |
