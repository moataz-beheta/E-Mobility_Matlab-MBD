#ifndef			BIT_MATH_H		
#define			BIT_MATH_H

#define			SET_BIT(REG,BIT_NUM)		(REG |= (1 << BIT_NUM))	   //set a particle bit
#define			CLR_BIT(REG,BIT_NUM)		(REG &=~(1 << BIT_NUM))    //clear a particle bit
#define			TOG_BIT(REG,BIT_NUM)		(REG ^= (1 << BIT_NUM))    //toggle a particle bit using XOR
#define			GET_BIT(REG,BIT_NUM)		( (REG >> BIT_NUM) & 1)    //get a particle bit

#endif