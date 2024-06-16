#include "Shift_Register_V1.1.h"
void _PinType_(uint8_t Pin, uint8_t mode)
{
  uint8_t bit = digitalPinToBitMask(Pin);
  uint8_t port = digitalPinToPort(Pin);
  volatile uint8_t *reg;
  if(port == NOT_A_PIN) return;
  reg = portModeRegister(port);
  if(mode == INPUT) *reg &= ~bit;
  else *reg |= bit;
}
void _PinWrite_(uint8_t port, uint8_t bit , uint8_t state)
{
  volatile uint8_t *reg;
  if(port == NOT_A_PIN) return;
  reg = portOutputRegister(port);
  if(state == HIGH) *reg |= bit;
  else *reg &= ~bit;
}

  SHIFT_REGISTER::SHIFT_REGISTER(int RCLK , int SRCLR ,int CLK ,int DIN,int number_of_shift_registers) :RCLK(RCLK) ,SRCLR(SRCLR),CLK(CLK),DIN(DIN),number_of_shift_registers(number_of_shift_registers)
  {

    _PinType_(CLK ,OUTPUT);
	_PinType_(RCLK ,OUTPUT);
	_PinType_(SRCLR ,OUTPUT);    
	_PinType_(DIN ,OUTPUT);  
	 
	RCLK_BIT = digitalPinToBitMask(RCLK);
   	SRCLR_BIT = digitalPinToBitMask(SRCLR);
	CLK_BIT = digitalPinToBitMask(CLK);
	DIN_BIT = digitalPinToBitMask(DIN); 
	 
	RCLK_PORT = digitalPinToPort(RCLK);
	SRCLR_PORT = digitalPinToPort(SRCLR);	
	CLK_PORT= digitalPinToPort(CLK);
	DIN_PORT =digitalPinToPort(DIN);
	                                                                                                            
    digitalWrite(SRCLR ,HIGH);                                                                                                                                          
  	digitalWrite(CLK ,LOW);
  }
   void SHIFT_REGISTER::reset()
  {
      _PinWrite_(SRCLR_PORT,SRCLR_BIT ,LOW);
      delayMicroseconds(1);
      _PinWrite_(RCLK_PORT,RCLK_BIT  ,HIGH);
      delayMicroseconds(1);
      _PinWrite_(RCLK_PORT,RCLK_BIT ,LOW);
      delayMicroseconds(1);
      _PinWrite_(SRCLR_PORT,SRCLR_BIT,HIGH);
      delayMicroseconds(1);
   
  }
  void SHIFT_REGISTER::show()
  {
     _PinWrite_(RCLK_PORT,RCLK_BIT,HIGH);
     delayMicroseconds(1);
     _PinWrite_(RCLK_PORT,RCLK_BIT ,LOW);
  }
  
 template <typename size>
 void SHIFT_REGISTER::write(size data) {
    _PinWrite_(SRCLR_PORT, SRCLR_BIT, HIGH);
    static bool state = 0;
    size step = (size)1 << (number_of_shift_registers * 8) - 1;

    for (int i = 0; i < (number_of_shift_registers * 8); ++i) 
	{
        state = (data & step) != 0;
        _PinWrite_(DIN_PORT, DIN_BIT, state);
        _PinWrite_(CLK_PORT, CLK_BIT, HIGH);
        delayMicroseconds(1);
        _PinWrite_(CLK_PORT, CLK_BIT, LOW);
        delayMicroseconds(1);
        step >>= 1;
    }
}

template void SHIFT_REGISTER::write<int>(int);
template void SHIFT_REGISTER::write<uint8_t>(uint8_t);
template void SHIFT_REGISTER::write<uint16_t>(uint16_t);
template void SHIFT_REGISTER::write<uint32_t>(uint32_t);
template void SHIFT_REGISTER::write<uint64_t>(uint64_t);
 
