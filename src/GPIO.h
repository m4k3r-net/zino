/*
 .----------------.  .----------------.  .-----------------. .----------------.
| .--------------. || .--------------. || .--------------. || .--------------. |
| |   ________   | || |     _____    | || | ____  _____  | || |     ____     | |
| |  |  __   _|  | || |    |_   _|   | || ||_   \|_   _| | || |   .'    `.   | |
| |  |_/  / /    | || |      | |     | || |  |   \ | |   | || |  /  .--.  \  | |
| |     .'.' _   | || |      | |     | || |  | |\ \| |   | || |  | |    | |  | |
| |   _/ /__/ |  | || |     _| |_    | || | _| |_\   |_  | || |  \  `--'  /  | |
| |  |________|  | || |    |_____|   | || ||_____|\____| | || |   `.____.'   | |
| |              | || |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------'

 Github: https://github.com/saleem-hadad/zino
*/

#ifndef ZINO_GPIO_H
#define ZINO_GPIO_H

#include "Pin.h"

class GPIO {
public:
    /*
    setup static method:
    @params:
    Pin& pin
    PinMode mode
    @return:
    void
    ---
    Use it to setup the needed pin mode to the
    selected pin & port on the Arduino board
	*/
    static void setup(Pin& pin, PinMode mode);

    /*
    read static method:
    @params:
    Pin& pin
    @return:
    int
    ---
    Use it to read the current status of a given
    pin on any given port, e.g. PortB or PortD
	*/
    static int read(Pin& pin);

    /*
    analogRead static method:
    @params:
    char pin
    @return:
    int
    ---
    Use it to read analog pin on PortC where you
    can select the pin's number, later on you
    can select the bandgap and temp sensor.
	*/
    static int analogRead(char pin);

    /*
    write static method:
    @params:
    Pin& pin
    char value
    @return:
    void
    ---
    Use it to write digital or analog values to
    any pin on given a digital/analog port.
	*/
    static void write(Pin& pin, char value);

    /*
    high static method:
    @params:
    Pin& pin
    @return:
    void
    ---
    Use it as a shortcut to write high value to
    any pin on a given digital port only.
	*/
    static void high(Pin& pin);

    /*
    low static method:
    @params:
    Pin& pin
    @return:
    void
    ---
    Use it as a shortcut to write low value to
    any pin on a given digital port only.
	*/
    static void low(Pin& pin);
private:
    /*
    private constructor:
    @params:
    void
    @return:
    void
	*/
    GPIO();
};

#endif
