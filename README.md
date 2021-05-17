[![Build Status](https://travis-ci.com/vi7/digispark-usb-blink.svg?branch=master)](https://travis-ci.com/vi7/digispark-usb-blink)

Digispark USB ATTiny85 Usage Tips
=================================

Usage tips and examples for the Digispark USB ATTiny85 clone. Built-in LED resides on the pin 1 (`PB1`)

This README also contains info about programming of the Digispark USB ATTiny85 clone with the [Bus Pirate](http://dangerousprototypes.com/docs/Bus_Pirate)


Program Micronucleus bootloader to the ATtiny85
-----------------------------------------------

### Tools versions

- `avrdude` - `6.3`
- `micronucleus` bootloader - [v2.5](https://github.com/micronucleus/micronucleus/raw/v2.5/firmware/releases/t85_default.hex)
- `Bus Pirate` device - [v3b custom mod](https://sandboxelectronics.com/?product=bus-pirate-v3b-with-probe-cable)

### Hardware connection

| Bus Pirate  | Digispark ATtiny85 |
|-------------|--------------------|
| GND (BR)    | GND (or pin4)      |
| +5V (OR)    | 5V (or pin8)       |
| CS (WT)     | P5 (RESET)         |
| MOSI (GR)   | P0 (MOSI)          |
| MISO (Blk)  | P1 (MISO)          |
| CLK (PU)    | P2 (SCLK/CLK)      |

### Program commands cheat sheet

Check buspirate connection:
```bash
avrdude -P /dev/tty.usbserial -c buspirate -p t85 -v
```

Flash Micronucleus bootloader and set default Digispark fuses:
```bash
curl -LO https://github.com/micronucleus/micronucleus/raw/v2.5/firmware/releases/t85_default.hex

avrdude -P /dev/tty.usbserial -c buspirate -p t85 -b 115200 -U flash:w:t85_default.hex -U lfuse:w:0xe1:m -U hfuse:w:0xdd:m -U efuse:w:0xfe:m
```

### Additional information

* The default fuses for a Digispark board:
  - ATtiny85 Lfuse: 0xE1 - (digispark default) PLL Clock + Startup 64 ms
  - ATtiny85 Hfuse: 0xDD - External Reset pin enabled (Pin5 not usable as I/O) + BOD 2.7 V + Enable Serial Program and Data Downloading
  - ATtiny85 Efuse: 0xFE - self programming enabled.
    BOD enabled requires additional 20 µA in sleep state and therefore may be not desirable for low power battery applications. To disable BOD, use 0xDF as Hfuse.

* AVR fuses calc: https://www.engbedded.com/fusecalc/

* Microcontroller pinout cheat sheet: https://tinkerlog.com/2009/06/18/microcontroller-cheat-sheet/

* Bus Pirate AVR Programming: http://dangerousprototypes.com/docs/Bus_Pirate_AVR_Programming


Serial console (UART)
---------------------

### Digispark ATTiny85

[`dtiny` core](https://github.com/ArminJo/DigistumpArduino) `TinyDebugSerial` overrides `Serial` and uses:
- `PB3` as TX for CPU frequencies <= 8MHz
- `PB2` as TX for other frequencies

See [TinyDebugSerial.h](https://github.com/ArminJo/DigistumpArduino/blob/master/digistump-avr/cores/tiny/TinyDebugSerial.h) for the details

### Generic ATtiny85

[`tiny` core](https://github.com/SpenceKonde/ATTinyCore/blob/master/avr/extras/ATtiny_x5.md#uart-serial-support) `TinySoftwareSerial` overrides `Serial` and uses:
- `AIN0` (`PB0`) as TX
- `AIN1` (`PB1`) as RX

See [src/main.cpp](src/main.cpp) for the example.
