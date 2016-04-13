# PhotoLite-Brite-X
Long Exposure Photography Gigantic Stick Light Brite

## WS2812B 144 LED Strip

While creating the VHDL module for the Led strip, 
we realize that the documentation was not clear enough to understand the 
protocol used for ligthing the leds. Even more, sometimes we were confused 
by the value that was displaying on the leds, even when we were not sending. 

We decided to create our own documentation based on what can be found out there.
First, it is important to understand that this 144 Led strip is made out of 
144 WS2812B (one for each pixel). 

The WS2812B is an **Intelligent control LED integrated light source **. 
It has 3 different leds of 256 (8 bits) of brightness levels, one for 
each color. This adds up to a total of 24 bits per pixel. There are 4 pins 
per WS2812B. 

1. VCC
2. GND
3. DATA_IN
4. DATA_OUT

VCC and GND are self-explanatory. DATA_IN receive the data corresponding to the 
24 bits to assign brightness to each of the colors (RGB, 8 bits each). However, once
the data is assigned, new information is ignored and it is retransmitted through 
the DATA_OUT pin. This is, the purpose of the DATA_OUT is to retransmitt the bits to 
the following pixel's DATA_IN (j+1) once the current pixel (j) is already assign. 


![alt tag](https://raw.githubusercontent.com/josemonsalve2/PhotoLite-Brite-X/master/LED_STRIP.png)
