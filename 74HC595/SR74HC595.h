#include<Arduino.h>
#ifndef SR74HC595_H
#define SR74HC595_H

#define CLK PB5 //13 CLK //shcp
#define MISO PB4
#define MOSI PB3 //11 DIN //DS
#define CS PB2
#define SRCLR PB1//pulse to clear //SRCLR
#define RCLK PB0 //pulse to show //stcp

#define LSB_FIRST 1 
#define MSB_FIRST 0

#define CLK_DIV_2 2 
#define CLK_DIV_4 4 
#define CLK_DIV_8 8 
#define CLK_DIV_16 16
#define CLK_DIV_32 32
#define CLK_DIV_64 64 
#define CLK_DIV_128 128 

class SHIFT_REGISTER
{
  private:
  int num_shift_reg;
  public:
  SHIFT_REGISTER(int num_shift_reg, bool BIT_ORDER = LSB_FIRST, int CLK_DIV = CLK_DIV_2);
  template <typename T> void Transmit(T data);
  void Reset();
  void Show();
  void Setup();
};
#endif;
