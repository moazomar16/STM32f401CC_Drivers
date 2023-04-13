#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/******************************************************
 * operations at specific bit in register 
 ******************************************************/
#define SET_BIT(Reg,Bit)            (Reg |= (1<<Bit))
#define CLR_BIT(Reg,Bit)            (Reg &= ~(1<<Bit))
#define TGL_BIT(Reg,Bit)            (Reg ^= (1<<Bit))
#define GET_BIT(Reg,Bit)            ((Reg>>Bit) & 0x01)


/******************************************************
 * operations at specific bit in register 
 ******************************************************/
#define SET_PORT(Reg,Value)            (Reg =  Value)
#define CLR_PORT(Reg,Value)            (Reg &= Value)
#define TGL_PORT(Reg,Value)            (Reg ^= Value)
#define GET_PORT(Reg,Value)            (Value)



/*****************************************************
 * operations at low nibble in register
 *****************************************************/
#define SET_LOW_NIB(Reg)            (Reg |= 0x0F)
#define CLR_LOW_NIB(Reg)            (Reg &= 0xF0)
#define GET_LOW_NIB(Reg)            (Reg & 0x0F)
#define TGL_LOW_NIB(Reg)            (Reg ^= 0x0F)


/***************************************************** 
 * operations at high nibble in register 
 *****************************************************/
#define SET_HIGH_NIB(Reg)           (Reg |= 0xF0)
#define CLR_HIGH_NIB(Reg)           (Reg &= 0x0F)
#define GET_HIGH_NIB(Reg)           ((Reg & 0xF0)>>4)
#define TGL_HIGH_NIB(Reg)           (Reg ^= 0xF0)


/******************************************************
 * Assign value into register 
 ******************************************************/
#define ASSIGN_REG(Reg,value)       (Reg = value)
#define ASSIGN_LOW_NIB(Reg,value)   (Reg = (Reg&0xF0) | value)
#define ASSIGN_HIGH_NIB(Reg,value)  (Reg = (Reg&0x0F) | (value<<4))


/******************************************************
 * Shift register by value
 ******************************************************/
#define SHIFT_RIGHT(Reg,value)     (Reg >>= value)
#define SHIFT_LEFT(Reg,value)      (Reg <<= value)


/*****************************************************
 * Circular shift of a register by a value
 ******************************************************/
#define CIR_RIGHT_SHIFT(Reg,value) (Reg = (Reg>>value) | (Reg<<(sizeof(Reg)*8-value)))
#define CIR_LEFT_SHIFT(Reg,value)  (Reg = (Reg<<value) | (Reg>>(sizeof(Reg)*8-value)))

#endif /* BIT_MATH_H_ */