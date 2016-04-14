# PhotoLite-Brite-X
(UNDER DEVELOPMENT) Long Exposure Photography Gigantic Stick Light Brite

## WS2812B 144 LED Strip

While creating the VHDL module for the Led strip, 
we realized that the documentation was not clear enough to understand the 
protocol used for lighting the leds. Even more, sometimes we were confused 
by the value that was displaying on the leds, even when we were not sending any data. 

We decided to create our own documentation based on what can be found out there.
First, it is important to understand that this 144 Led strip is made out of 
144 WS2812B components (one for each pixel). In this documentation, a pixel is just one 
WS2812B component out of the 144.

This document does not contain information regarding the Maximum Ratings or electrical 
characteristics. Please see the datasheet to get this information.

The WS2812B is an **Intelligent control LED integrated light source** and corresponds to our pixel. 
It has 3 different leds: Red, Blue and Green. Each led has 256 levels of brightness encoded in 8 bits.
This adds up to a total of 24 bits per pixel. Data is sent in serial transmission, one bit at a time, starting from
the MSB of the 8 bits representing the brightness of the *green* led.
After transmitting the 8 bits for the *green* led, we send the *red* led's bits, followed by the *blue* led's bits starting 
always from the MSB to the LSB. Once the 24 bits are received by the first pixel, further data is cascaded to the following pixel.
**In other words, the order is GRB, from MSB to LSB**.

**IMPORTANT:** Once a led is light up, it will retain its value and will remain on until the value is overwrited after a reset.
In order to turn off a pixel it is necessary to write 0 to all the 24 bits.

### Pins of the WS2812B

There are 4 pins per WS2812B.

1. VCC (+3.5 ~ +5.3 V)
2. VDD/GND
3. DATA_IN
4. DATA_OUT

![alt tag](https://cloud.githubusercontent.com/assets/1594240/14506449/de5e4a86-018b-11e6-8260-2fc3ba46a2f0.png)

*VCC* and *VDD/GND* are self-explanatory. *DATA_IN* receives the data corresponding to the input for the
24 bits that assign brightness to each of the colors (GBR, 8 bits each). However, once
the value of the pixel is assigned, all new data arriving to DATA_IN is ignored and it is retransmitted through 
the DATA\_OUT pin, until a reset is performed. This is, the purpose of the DATA\_OUT is to retransmit the bits to 
the following pixel's DATA_IN (j+1) once the current pixel (j) is already assigned a value. 

### Timing is really important

One of the major challenges when sending the data to the led strip is timing. 
We will explain a single pixel first, then we will expand our explanation to multiple pixels. 
A bit must be sent every 1.25 +/- 0.6 microseconds. Within that 1.25 microseconds, the bit is either 
1 or 0 depending on how long the signal was held high. If the time on high is 0.4 +/- 0.15 microseconds, 
the bit is consider a 0. If the time on high is 0.8 +/- 0.15 microseconds. The bit is considered a 1. 

A timeline of a bit would seen like this:

![alt tag](https://cloud.githubusercontent.com/assets/1594240/14508664/9bd1f964-0196-11e6-90c3-e7f4f9be524e.png)

For a single pixel, 24 bits must be sent, which means, a pixel takes 30 microseconds to write (If transmitting at exactly 1.25 microseconds).
For the whole 144 pixels, we need to transmit 3456 bits taking 4.32 ms (~230 Hz).

In order to change the value of a pixel it is necessary to do a reset. This is done by keeping the DATA_IN on low for 50 microseconds or more.
However, reset will not turn off the pixel, it will just release the register to be overwritten by the next 24 bits coming from the DATA_IN port.

**Once a pixel is written, it will retain its value until it is overwritten. If we want to turn off the led, it is 
necessary to send 24 0's to that pixel after a reset**
