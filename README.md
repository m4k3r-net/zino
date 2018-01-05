![zino](https://github.com/saleem-hadad/zino/blob/master/assets/logo.png)

# 𝓩ino ♥️

Custom C++ based Arduino library provides a convenient and fast way for developing embedded systems projects.

## Getting Started

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/Pin.png" alt="Zino Pin class"/>

The library introduces this new concept of shaping the pin as an object which has a port address and pin number.

The **Pin** class used in many different other classes to handle the process of assigning the pin either ```Output```, ```Input``` or ```InputWithPullUp``` resister.

The reason for using Pin class instead of the pin number as Arduino library uses is first for educational purpose where the students can get a clue of the register concept and also to make the code very clean and organised.

```c
#include <Pin.h>

Pin redLedPin(PortB, 0);            // portName: PortB, pinNumber: 0 // same as digital pin 8
Pin greenLedPin(PortD, 1);          // portName: PortD, pinNumber: 1 // same as digital pin 1
Pin temperatureSensorPin(PortC, 4); // portName: PortC, pinNumber: 4 // same as analog pin A4
```

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/GPIO.png" alt="Zino GPIO class"/>

The library has its own ```GPIO``` wrapper(class) to use, which is much more faster than the Arduino library. [See the comparison](https://github.com/saleem-hadad/zino/blob/master/examples/CompareFrequencies/CompareFrequencies.cpp).

Working with I/O using ```GPIO``` class is pretty straightforward! Here some examples:

```c
// Blinking LED on and off without delay.
#include <GPIO.h>
#include <Pin.h>

Pin redLedPin(PortB, 0);

void setup()
{
    GPIO::setup(redLedPin, Output); // You can choose Output, Input or InputWithPullUp
}

void loop()
{
    GPIO::high(redLedPin);      // Turn on the LED
    GPIO::low(redLedPin);       // Turn off the LED
    //or
    GPIO::write(redLedPin, 1);  // Turn on the LED
    GPIO::write(redLedPin, 0);  // Turn off the LED
}
```

```c
// Reading analog input from PortC, pin number 4 and print the result to the serial.
#include <Arduino.h>
#include <GPIO.h>
#include <Pin.h>

Pin temperatureSensorPin(PortC, 4);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    // For analog reading you don't have to call GPIO::setup method :)
    int temperature = GPIO::read(temperatureSensorPin);
    Serial.println(temperature);
}
```

more examples you can find [here](https://github.com/saleem-hadad/zino/tree/master/examples)

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/button.png" alt="Zino Button class"/>

The library solves some of the common issue when working with push buttons, like edge detection and bouncing problem.

The class ```Button``` provides very easy way to handle physical actions like button pressed, or long press(in development), here an example:

```c
// Print "Button has been pressed 🤠" to the serial when the button pressed.
#include <Arduino.h>
#include <Button.h>
#include <Pin.h>

Button button;

void buttonPressed()
{
    Serial.println("Button has been pressed 🤠");
}

void setup()
{
    Serial.begin(9600);

    // The 1st parameter: the pin connected with the button
    // The 2nd parameter: the debouncing period [35-40 ms is recommended]
    // The 3rd parameter: true or false [default logic is high?]
    // The 4th parameter: true or false [with internal Pull Up?]
    button.init(Pin(PortB, 5), 40, false, false);
    button.pressed = buttonPressed; // set the handler
}

void loop()
{
    button.refresh(); // important
}
```

more examples you can find [here](https://github.com/saleem-hadad/zino/tree/master/examples)

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/LED.png" alt="Zino LED class"/>

LEDs are the fun things to play with 🤓, for that, the ```LED``` class handles some cool features that you might need to control the LEDs very easily.

```c
#include <Arduino.h>
#include <Pin.h>
#include <LED.h>

Pin ledPin(PortB, 4); // same as digital pin 12
LED led;

void setup()
{
    led.init(ledPin);
}

void loop()
{
    led.on();
    led.off();
    // or
    led.toggle();
}
```

more examples you can find [here](https://github.com/saleem-hadad/zino/tree/master/examples)

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/Blinky.png" alt="Zino Blinky class"/>

The ```Blinky``` class provides an easy way for blinking(flashing) LEDs, generating a square wave or controlling DC motors.. etc.

Here is an example of how to use it in your applications:

```c
/*
    Blinking an LED connected to PortB on pin 0 (same as digital pin 8)
    for a period of 1000ms on and 100ms off, without using the delay
    Arduino library's function, and without affecting other codes
*/
#include <Arduino.h>
#include <Blinky.h>
#include <Pin.h>

Blinky led;

void setup()
{
    led.init(Pin(PortB, 0), 1000, 100); // (pin, onTime, offTime)
}

void loop()
{
    led.refresh();
}
```

more examples you can find [here](https://github.com/saleem-hadad/zino/tree/master/examples)

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/DCMotor.png" alt="Zino DCMotor class"/>

(*This class still in development*)

Controlling DC Motors needs a lot of hardware and software configurations to be handled. However, ```DCMotor``` class provides a convenient way of controlling the DC motors by generating a software PWM signal on any digital pin and not only the timers ones (with [~] label), which means you can control the dc motor by any digital pin 😎

```c
#include <Arduino.h>
#include <DCMotor.h>
#include <Pin.h>

DCMotor motor;

void setup()
{
    motor.init(Pin(PortB, 4), 200); // provide the pin and frequency(in hz) needed
    motor.setDutyCycle(0.5);        // control the speed by adjusting the dutyCycle between 0.0 and 1.0
}

void loop()
{
    motor.refresh();
}
```

more examples you can find [here](https://github.com/saleem-hadad/zino/tree/master/examples)

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/Delay.png" alt="Zino Delay class"/>

Most probably you came across this issue when you deal with the delay function that Arduino library provides, which halts the CPU for specific period in ms. However, you might need to perform an action with delay without delaying the whole process. For example, you might need send a message to serial port every 1s without affecting other functionalities! for that, the Zino library provides an alternative way for using the delay concept, here is an example:

```c
#include <Arduino.h>
#include <Delay.h>

Delay myDelay;       // default duration 1000 ms.
// Delay myDelay(1000); //Other initialization

void callback()
{
    Serial.println("Hello world 🖐"); // print "Hello world 🖐" every 0.5 s
}

void setup()
{
    Serial.begin(9600);
    myDelay.init(500); // duration = 500 ms. (0.5 s)

    myDelay.callback = callback; // set the callback to be notified
}

void loop()
{
    myDelay.refresh();
    //Other stuff goes here
}
```

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/AnalogComparator.png" alt="Zino AnalogComparator class"/>


## Development

### Future implementation and classes

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/future.png" alt="Zino Future process"/>

### Supported Boards

+ UNO

### Prerequisites

It's highly recommended to avoid using Arduino IDE, instead, use [Atom](https://atom.io/) or [VSCode](https://code.visualstudio.com/) text-editor with [Platform IO](http://platformio.org/platformio-ide) for a better development environment.

### Installing

#### If you are using Atom/VSCode with Platform IO you have **two ways**

1. First way (recommended ✌️)

Create a new project, then add this line to ```platformio.ini``` file

```
lib_deps = https://github.com/saleem-hadad/zino/archive/master.zip
```

<img src="https://github.com/saleem-hadad/zino/blob/master/assets/installing.gif" alt="Zino installing process"/>

2. Second way

Create a new project then [Download the library](https://github.com/saleem-hadad/zino/archive/master.zip) and extract the files into the ```lib``` folder.

#### If you are using Arduino IDE*

1. [Download the library](https://github.com/saleem-hadad/zino/archive/master.zip)
2. navigate to Arduino IDE > click on ```sketch``` > ```include Library``` > add .Zip library then add the ```zino-master.zip```

*I did NOT test the library on the Arduino IDE, so please notify me if you get any warning/error!


## Running the examples

Navigate to the examples folder, copy the code of your fav. one and paste it in ```scr/main.cpp```, then upload it, that's it 🤓

## Author(s)

* **Saleem Hadad** - *Binary Torch* - [saleem-hadad](https://github.com/saleem-hadad)

## License

This library is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details.
