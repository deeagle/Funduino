# Funduino Project

[![CI](https://github.com/deeagle/Funduino/actions/workflows/ci.yml/badge.svg)](https://github.com/deeagle/Funduino/actions/workflows/ci.yml)

This project includes my experience with the Funduino UNO starter pack.
Funduino UNO is a clone of the Arduino UNO.

I still develop some basic IoT actors
based on the microcontrollers *arduino* and *esp8266/esp32*.
Most of the time I used a debian based development environment.

## Environment preparation

There are some packages in the official repository (on *bullseye*, 11).

- You can find them via shell:

  ```bash
  $ sudo aptitude search arduino
  
  p   arduino                 - AVR development board IDE from Arduino CC
  p   arduino-builder         - Command line tool for compiling Arduino sketches
  v   arduino-core            -
  p   arduino-core-avr        - Arduino Core for AVR microcontroller
  p   arduino-ctags           - Arduino fork of exuberant ctags
  p   arduino-mighty-1284p    - Platform files for Arduino to run on ATmega1284P
  p   arduino-mk              - Program your Arduino from the command line
  p   octave-arduino          - Octave Arduino Toolkit
  ```

- Get further details via
  
  ```bash
  sudo aptitude show arduino
  ```

- Install via:

  ```bash
  sudo aptitude install -yq arduino
  ```

### Grant user access for serial port

- Add user to group *dialout*

  ```bash
  # usermod -aG dialout <username>
  ```

- Relogin your user (*logout and login*)
- When you relog you can start a shell and type the following command and you
  should see, that your current user is added to the group *dialout*

  ```bash
  $ id | grep dialout 
  ..., 20(dialout), ...
  ```

## Weblinks

- [Repo on github.com](https://github.com/deeagle/Funduino)
- Funduino
  - [Project URL](http://funduino.de)
  - [Starter pack](http://funduino.de/lernsets)
  - Tutorials
    - [de (html)](http://funduino.de/anleitungen)
    - [en (pdf)](http://funduino.de/Arduino-tutorials-en.pdf)
