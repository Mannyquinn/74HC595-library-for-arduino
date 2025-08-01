  #include<SR74HC595.h>
  SHIFT_REGISTER::SHIFT_REGISTER(int num_shift_reg, bool BIT_ORDER, int CLK_DIV = CLK_DIV_2) : num_shift_reg(num_shift_reg)
  {
    DDRB |= 1 << MOSI | 1 << CLK | 1 << SRCLR | 1 << RCLK | 1 << CS;                 //set MOSI , CLK and CS(compulsory) as OUTPUT 
    DDRB &=~(1 << MISO);  //set MISO as input
	PORTB |= 1 << SRCLR;                                                                                                                                          
    SPCR = 0x00;
    SPCR |=  (1 << SPE) | (BIT_ORDER << DORD) | (1 << MSTR);     //SPI ENABLED ,SET BIT ORDER LSB FIRST,SET SPI AS MASTER
    SPCR &= ~(1 << SPR1 | 1 << SPR0);
    SPSR &= ~(1 << SPI2X);
    switch(CLK_DIV)
         {
            case 2: SPSR |= (1 << SPI2X);
                 break;
            case 4: //do nothing
                 break;
            case 8: SPCR |= (1 << SPR0);
                    SPSR |= (1 << SPI2X);
                 break;
            case 16: SPCR |= (1 << SPR0);
                 break;
            case 32: SPCR |=  (1 << SPR1);
                     SPSR |=  (1 << SPI2X);
                 break;
            case 64: SPCR |= (1 << SPR0 | 1 << SPR1);
                     SPSR |= ( 1 << SPI2X);
                 break;
            case 128: SPCR |= (1 << SPR0 | 1 << SPR1);
                 break;
            default: SPSR |= (1 << SPI2X);
           	 break;
                   
         }
    
    
  }
  
  template <typename T> void SHIFT_REGISTER::Transmit(T data)
  {
	switch(num_shift_reg)
	{
	case 1:	
		SPDR = (data & 0xFF);     //the (i << 3) is the same as i*8 in this case but shift operation might be faster than multiplication in some cases                                                                            //put the data in the register ,this starts the SPI clock
    		while(!(SPSR & (1 << SPIF)));  				// wait for SPIF to become 1 to show end of transmission
		break;

	case 2:
		SPDR = (data) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 8) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 	
		break;	
	
	case 3:
		SPDR = (data) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 8) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 16) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		break;
	
	case 4:
		SPDR = (data) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 8) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 16) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 24) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		break;
	
	case 5:
		SPDR = (data) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 8) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 16) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 24) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 32) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		break;
		
	case 6:
		SPDR = (data) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 8) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 16) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 24) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 32) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 40) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 	
		break;

	case 7:
		SPDR = (data) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 8) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 16) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 24) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 32) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 40) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 48) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		break;
																					
	case 8:
		SPDR = (data) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 8) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 16) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 24) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 32) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 40) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 48) & 0xFF;
		while(!(SPSR & (1 << SPIF))); 
		SPDR = (data >> 56) & 0xFF;
		while(!(SPSR & (1 << SPIF)));
		break;
	
	default:
		for(int i = 0; i < num_shift_reg; ++i)
		{
			SPDR = (data >> (i << 3)) & 0xFF;                                                                       
    			while(!(SPSR & (1 << SPIF))); 
		}
	}
		                                                                       
  }
  void SHIFT_REGISTER::Reset()
  {
      PORTB &= ~(1 << SRCLR);
      PORTB |= 1 << RCLK;
      PORTB &= ~(1 << RCLK);
      PORTB |= 1 << SRCLR;
  }
  void SHIFT_REGISTER::Show()
  {
      PORTB |= 1 << RCLK;
      PORTB &= ~(1 << RCLK);
  }

template void SHIFT_REGISTER::Transmit<int>(int);

template void SHIFT_REGISTER::Transmit<uint8_t>(uint8_t);

template void SHIFT_REGISTER::Transmit<uint16_t>(uint16_t);

template void SHIFT_REGISTER::Transmit<uint32_t>(uint32_t);

template void SHIFT_REGISTER::Transmit<uint64_t>(uint64_t);
