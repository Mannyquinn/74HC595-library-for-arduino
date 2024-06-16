#ifndef SHIFT_REGISTER_V1.1_H
#define SHIFT_REGISTER_V1.1_H
#include <Arduino.h>

void _PinWrite_(uint8_t, uint8_t, uint8_t);
void _PinType_(uint8_t , uint8_t);

class SHIFT_REGISTER
{
	uint8_t RCLK_PORT;
	uint8_t SRCLR_PORT;	
	uint8_t CLK_PORT;
	uint8_t DIN_PORT;
	
	uint8_t RCLK_BIT ;
	uint8_t SRCLR_BIT;
	uint8_t CLK_BIT;
	uint8_t DIN_BIT ;
	
  public:
  int RCLK ,SRCLR ,number_of_shift_registers ,CLK,DIN;	  	
  SHIFT_REGISTER(int RCLK , int SRCLR ,int CLK ,int DIN,int number_of_shift_registers );
  void reset();
  void show();
  template <typename size>
  void write(size data);
};
#endif
