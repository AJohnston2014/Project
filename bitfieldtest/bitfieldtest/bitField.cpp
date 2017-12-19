//#include "bitField.h"
//
//deserializeSetBit(uint32_t *dest, bool value, _int32 bit,_int32 width)
//{
//	uint32_t maxBits = 31;
//	uint32_t leastSig = bit;
//	//uint32_t bitWidth = width;
//	uint32_t bitWidth = 5;
//	uint32_t mostsig = bitWidth + leastSig - 1;
//	uint32_t leftShift = maxBits - mostsig;
//	uint32_t rightShift = leftShift + leastSig;
//	uint32_t leftShifted=value<<leftShift;
//	uint32_t rightShifted = leftShifted >> rightShift;
//	*dest = *dest&rightShifted;
//	return dest;
//}
//int32_t* bitField::ideserializeSetBit(int32_t *dest, bool value, _int32 bit, _int32 width) //?
//{
//	uint32_t maxBits = 31;
//	uint32_t leastSig = bit;
//	//uint32_t bitWidth = width;
//	uint32_t bitWidth = 5;
//	uint32_t mostsig = bitWidth + leastSig - 1;
//	uint32_t leftShift = maxBits - mostsig;
//	uint32_t rightShift = leftShift + leastSig;
//	uint32_t leftShifted = value << leftShift;
//	uint32_t rightShifted = leftShifted >> rightShift;
//	*dest = *dest&rightShifted;
//	return dest;
//}
//uint32_t* bitField:: setBit(uint32_t* dest, bool value, __int32 bit)
//{
//	uint32_t maxBits = 31;
//	uint32_t Shift = maxBits - bit;
//	uint32_t invMask = 1 << Shift;
//	uint32_t mask = ~invMask;
//	uint32_t shifted = ((uint32_t)value) << Shift;
//	uint32_t masked = mask | shifted;
//	(*dest) = (*dest)& masked;
//	cout << *dest << endl;
//	return dest;
//}
//int32_t* bitField::fiveBit(int32_t* integer, bool value, int32_t bit) //?
//{
//	//*integer=static_cast<int32_t>(*integer & 0x1F);
//	//or
//	//*integer=static_cast<int>(*integer & 0x1F);
//	//or just  *integer &1F;
//	const int32_t fiveBitQuantity = 5;
//	int32_t maxBits = 31;
//	int32_t shifts;
//	if (bit >= 28)
//	{
//		shifts = 0;
//		int32_t invMask = 0x1F << shifts;
//		int32_t mask = ~invMask;//1F or calculate how many bits you want to shift and  do 1F << shifts
//		int32_t shifted = ((int32_t)value) << shifts;
//		int32_t masked = mask | shifted;
//		(*integer) = (*integer)& masked;
//
//		cout << *integer << endl;
//		return integer;
//	}
//	else
//	{
//		//int32_t shifts = maxBits - bit - fiveBitQuantity+1;
//		shifts = maxBits - bit - fiveBitQuantity + 1;
//		int32_t invMask = 0x1F << shifts;
//		int32_t mask = ~invMask;//1F or calculate how many bits you want to shift and  do 1F << shifts
//		int32_t shifted = ((int32_t)value) << shifts;
//		int32_t masked = mask | shifted;
//		(*integer) = (*integer)& masked;
//
//		cout << *integer << endl;
//		return integer;
//	}
//}