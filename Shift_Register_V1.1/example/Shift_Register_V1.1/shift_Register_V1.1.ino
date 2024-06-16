/* 
 This is for the 74HC595 serial in parallel out shift register
 The shift register library can handle up to 8 shift registers, 
 it can be easily modified to work with more.

 The output control isn't handled by the library,
 i'd normally enable it by default by connecting it to ground
 but you can connect it to a digitalpin and be accountable for it

 Please always use the right variable type to store your values, 
 uint8_t for a byte, uint16_t for 2 bytes , uint32_t for 4 byte, etc.

 Note that the number of shift registers set in code will determine how many will
 be used correctly even if you have more than you set physically hooked up.

 There are three main methods in the library
 1. reset() to clear the output of the shift register, usually done before writing .
 2. write() to shift in the word, usually done before show.
 3. show() to output the word shifted into the registers.

*/

#include<Shift_Register_V1.1.h>
#define RCLK 5	 //ST_CP
#define SRCLR 7 //MR
#define CLK 6  //SH_CP
#define DIN 4 //DS


SHIFT_REGISTER reg1(RCLK,SRCLR ,CLK ,DIN ,3); // ,create shift register object called reg1 (RCLK ,SRCLR ,CLOCK , DATA IN , NUMBER OF SHIFT REGISTERS)
void setup()
{
  
  reg1.reset();  //reset it

}

void loop() {
 for(uint32_t i = 1; i < 255 ; i++)
 {
  reg1.write(i); //write a value to the shift registers
  reg1.show(); // output the written values
  delay(500);
  reg1.reset();
 }
 

}
