# arduino-ad-mux-lib
Arduino library for controlling [analog/digital multiplexers](https://en.wikipedia.org/wiki/Multiplexer) (A/D mux) like those belonging to the CMOS 4000 series (e.g. 4051 (CD4051, 74HC4051), 4067 (CD4067, 74HC4067)).

This library was forked from project MUX74HC4067 (https://github.com/nlamprian/MUX74HC4067) in order to generalize and streamline its functionalities at both interface and implementation levels.

## Getting started

Currently, two common ICs are explicitly implemented (`Type4051Mux` and `Type4067Mux`); others can be controlled through the generic class (`GenericMux`).

This library provides several examples that demonstrate its functionalities; they all revolve around the same simple life cycle: 

1. Object initialization

MCU pins are assigned to signal and channel control:

```cpp
// Mux declared with analog input signal on pin A0 and channel control on digital pins 8, 9, 10 and 11.
Type4067Mux mux(A0, INPUT, ANALOG, 8, 9, 10, 11);
```

The signal pin can also be assigned (and possibly replaced) through the `setSignalPin` method.

2. Object I/O 

After selecting the channel, read/write operations can be invoked:

```cpp
// Select 3rd channel!
mux.setChannel(2);
// Read data from the current channel (that is 3rd)!
int16_t data = mux.read();
```

Alternatively, the channel can be directly specified within the read/write operation:

```cpp
// Read data from the 3rd channel!
int16_t data = mux.read(2);
```

## Advanced use

*The same mux can be physically connected to multiple signal pins at once*, as any invocation to `setSignalPin` method ensures that the previous pin is set to high impedance state before switching to the new one.

Conversely, *the same signal pin can be physically connected to multiple ICs through a common data line*, as `setEnabled` method controls whether the mux I/O operates.

## Repository

[https://github.com/stechio/arduino-ad-mux-lib](https://github.com/stechio/arduino-ad-mux-lib)
