#include<SR74HC595.h>
/*
 This library uses the SPI of the Arduino UNO
 CLK / SH-CP - PIN 13 
 DIN / DS - PIN 11  
 CS - PIN 10
 SRCLR - PIN 9
 RCLK / ST_CP - PIN 8




 (Number of shift registers in series, Bit order, clock division)
 ^^^the code is optimized for up to 8 shift registers, anything above that in series may show significant speed reduction
 !!!bit order - MSB_FIRST/LSB_FIRST, these are the allowed values for the bit order
 !!!the code works by breaking the data into byte sizes and shifted out per byte
 !!!use LSB_FIRST if the least significant bit of the byte is to be shifted out first
 !!!use MSB_FIRST if the most significant bit of the byte is to be shifted out first
 ***clock division - CLK_DIV_2 /  CLK_DIV_4 / CLK_DIV_8 / CLK_DIV_16 / CLK_DIV_32 / CLK_DIV_64 / CLK_DIV_128,
 ***these are used to setup the speed of the clock. they are the division factors (prescalers).
 a couple simplification was made to the hardware ie, the output enable is tied low to keep it active and must be done by the user, optinally it can be connected to an arduino pin and toggled as needed.
 the chip select pin is available as a macro called "CS", it can be used if it is needed.
 make sure you setup the right amount of shift registers you have in series, else the data might be over shifted.
 it is advisable to the same settings for all shift register objects.
 to avoid shifting into the wrong shift register, the SRCLR pin can be used.
*/

SHIFT_REGISTER s(2, LSB_FIRST, CLK_DIV_2); 
void setup()
{
    s.Reset();      //the Reset method, clears the output register
}
void loop()
{
  for(int i = 0; i < 0xFFF; i++)
   {
    	s.Transmit(0XFFF);   //the Transmit method is used to shift the data into the shift register
    	s.Show(); 	    //the Show method shifts the data to the output register.
    	delay(1000);
   }

}
