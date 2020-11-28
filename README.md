Digispark USB Blink Example
===========================

LED blink example for the Digispark USB ATTiny85 clone. LED resides on the pin 1

This README also contains info about programming of the Digispark USB ATTiny85 clone with the [Bus Pirate](http://dangerousprototypes.com/docs/Bus_Pirate)


Program Micronucleus bootloader to the ATtiny85
-----------------------------------------------

### Tools versions

- `avrdude` - `6.3`
- `micronucleus` bootloader - [1.11](https://github.com/micronucleus/micronucleus/blob/v1.11/firmware/releases/micronucleus-1.11.hex)
- `Bus Pirate` device - [v3b custom mod](https://sandboxelectronics.com/?product=bus-pirate-v3b-with-probe-cable)

### Commands cheat sheet

Check buspirate connection:
```bash
avrdude -P /dev/tty.usbserial -c buspirate -p t85 -v
```

Flash Micronucleus bootloader and set fuses:
```bash
curl -LO https://github.com/micronucleus/micronucleus/blob/v1.11/firmware/releases/micronucleus-1.11.hex

avrdude -P /dev/tty.usbserial -c buspirate -p t85 -b 115200 -U flash:w:micronucleus-1.11.hex -U lfuse:w:0xe1:m -U hfuse:w:0xdd:m -U efuse:w:0xfe:m
```

### Additional information

AVR fuses calc: https://www.engbedded.com/fusecalc/

Microcontroller pinout cheat sheet: https://tinkerlog.com/2009/06/18/microcontroller-cheat-sheet/

Bus Pirate AVR Programming: http://dangerousprototypes.com/docs/Bus_Pirate_AVR_Programming
