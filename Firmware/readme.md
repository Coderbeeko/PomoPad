# pomopad

![pomopad](imgur.com image replace me!)

*A short description of the keyboard/project*
Pomopad is a small 3x3 macropad I designed for productivity and media control.  
It runs on an RP2040 (Seeed XIAO RP2040) and uses QMK firmware.

I wanted something compact that still had more than just switches, so I added a rotary encoder, an OLED screen, and RGB underglow.

## Hardware

- 3x3 ortholinear layout  
- Seeed XIAO RP2040  
- Rotary encoder  
- 128x32 OLED  
- WS2812 RGB underglow  
- USB-C  

## What it does

The encoder controls volume.  
The keys are programmed for shortcuts and macros, such as copy, paste, opening specific websites used for studying such as savemyexams and past papers, and just general everyday used websites like gmail and chatgpt.
The OLED can be used to display status or custom info.


* Keyboard Maintainer: [Ahmed Barakat](https://github.com/ahmedbarakat)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make pomopad:default

Flashing example for this keyboard:

    make pomopad:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
