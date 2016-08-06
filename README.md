# Funduino Project

This project includes my experience with the Funduino UNO starter pack.
Funduino UNO is a clone of the Arduino UNO.

## Funduino
* [Funduino project URL](http://funduino.de)
* [Funduino starter pack](http://funduino.de/lernsets)
* [Funduino Tutorials de](http://funduino.de/anleitungen)
    * [Funduino Tutorials en](http://funduino.de/Arduino-tutorials-en.pdf)

** Installation for OS Debian 

### Install the packages from the repo

There are some packages in the official repository.
You can find them via shell
```bash
# aptitude search arduino
p   arduino                                                                                                                                                 - AVR development board IDE and built-in libraries                                                                                                                 
p   arduino-core                                                                                                                                            - Code, examples, and libraries for the Arduino platform                                                                                                           
p   arduino-mighty-1284p                                                                                                                                    - Platform files for Arduino to run on ATmega1284P                                                                                                                 
p   arduino-mk                                                                                                                                              - Program your Arduino from the command line                                                                                                                      
```

Package details:
```bash
# aptitude show arduino
Package: arduino                         
New: yes
State: not installed
Version: 2:1.0.5+dfsg2-4
Priority: extra
Section: electronics
Maintainer: Scott Howard <showard@debian.org>
Architecture: all
Uncompressed Size: 1,727 k
Depends: default-jre | java6-runtime, libjna-java, librxtx-java (>= 2.2pre2-3), arduino-core (= 2:1.0.5+dfsg2-4)
Recommends: extra-xdg-menus, policykit-1
Description: AVR development board IDE and built-in libraries
 Arduino is an open-source electronics prototyping platform based on flexible, easy-to-use hardware and software. It's intended for artists, designers, hobbyists, and anyone interested in creating interactive objects or environments. 
 
 This package will install the integrated development environment that allows for program writing, code verfication, compiling, and uploading to the Arduino development board. Libraries and example code will also be installed.
Homepage: http://www.arduino.cc
Tags: field::electronics, role::program
```

Install via:
```bash

# aptitude install arduino
The following NEW packages will be installed:
  arduino arduino-core{a} avr-libc{a} avrdude{a} binutils-avr{a} extra-xdg-menus{a} gcc-avr{a} libftdi1{a} libjna-java{a} libjna-jni{a} librxtx-java{a} 
0 packages upgraded, 11 newly installed, 0 to remove and 0 not upgraded.
Need to get 20.8 MB of archives. After unpacking 123 MB will be used.
Do you want to continue? [Y/n/?] y
...
```

### Grant user access for serial port

```bash
# usermod -a -G dialout <username>
```

Then do a *logout/login*

When you relog you can start a shell and type the following command and you should see, that your current user is added to the group *dialout*
```bash
$ id -> ..., 20(dialout), ...
```
