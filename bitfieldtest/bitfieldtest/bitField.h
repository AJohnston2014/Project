#ifndef foo_h
#define foo_h
#include <iostream>
using namespace std;


struct foo
{
	bool b1;

	bool b2;

	int32_t n1;

	uint32_t n2;
};

	
//Code uses big endian bit order 0,1,2,3,.....
uint32_t buffer[10];
uint32_t* setBit(uint32_t* dest, bool value, __int32 bit);
uint32_t* deserializeSetBit(uint32_t *dest, bool value, _int32 bit, _int32 width);
int32_t* fiveBit(int32_t* integer, bool value, int32_t bit);
int32_t* ideserializeSetBit(int32_t *dest, bool value, _int32 bit, _int32 width);
//void setBit(uint32_t& dest,bool value, uint32_t bitPosition); // sets a single bit in a 32 bit unsigned integer
//bool getBit(uint32_t& src, uint32_t bitPosition); // returns true or false if a bit is in found in that position
void setBits(uint32_t& dest, uint32_t leastSigBit, uint32_t bitWidth, uint32_t value);
void serializeStruct(foo);
void deserializeStruct(foo);
bool equals(foo);

uint32_t* deserializeSetBit(uint32_t *dest, bool value, _int32 bit, _int32 width)
{
	uint32_t maxBit = 31;
	uint32_t leastSig = bit;
	//uint32_t bitWidth = width;
	uint32_t bitWidth = 5;
	uint32_t mostsig = bitWidth + leastSig - 1;
	uint32_t leftShift = maxBit - mostsig;
	uint32_t rightShift = leftShift + leastSig;
	uint32_t leftShifted = value << leftShift;
	uint32_t rightShifted = leftShifted >> rightShift;
	*dest = *dest&rightShifted;
	return dest;
}
int32_t* ideserializeSetBit(int32_t *dest, bool value, _int32 bit, _int32 width) //?
{
	uint32_t maxBits = 31;
	uint32_t leastSig = bit;
	//uint32_t bitWidth = width;
	uint32_t bitWidth = 5;
	uint32_t mostsig = bitWidth + leastSig - 1;
	uint32_t leftShift = maxBits - mostsig;
	uint32_t rightShift = leftShift + leastSig;
	uint32_t leftShifted = value << leftShift;
	uint32_t rightShifted = leftShifted >> rightShift;
	*dest = *dest&rightShifted;
	return dest;
}
uint32_t* setBit(uint32_t* dest, bool value, __int32 bit)
{
	uint32_t maxBits = 31;
	uint32_t Shift = maxBits - bit;
	uint32_t invMask = 1 << Shift;
	uint32_t mask = ~invMask;
	uint32_t shifted = ((uint32_t)value) << Shift;
	uint32_t masked = mask | shifted;
	(*dest) = (*dest)& masked;
	cout << *dest << endl;
	return dest;
}
int32_t* fiveBit(int32_t* integer, bool value, int32_t bit) //?
{
	//*integer=static_cast<int32_t>(*integer & 0x1F);
	//or
	//*integer=static_cast<int>(*integer & 0x1F);
	//or just  *integer &1F;
	const int32_t fiveBitQuantity = 5;
	int32_t maxBits = 31;
	int32_t shifts;
	if (bit >= 28)
	{
		shifts = 0;
		int32_t invMask = 0x1F << shifts;
		int32_t mask = ~invMask;//1F or calculate how many bits you want to shift and  do 1F << shifts
		int32_t shifted = ((int32_t)value) << shifts;
		int32_t masked = mask | shifted;
		(*integer) = (*integer)& masked;

		cout << *integer << endl;
		return integer;
	}
	else
	{
		//int32_t shifts = maxBits - bit - fiveBitQuantity+1;
		shifts = maxBits - bit - fiveBitQuantity + 1;
		int32_t invMask = 0x1F << shifts;
		int32_t mask = ~invMask;//1F or calculate how many bits you want to shift and  do 1F << shifts
		int32_t shifted = ((int32_t)value) << shifts;
		int32_t masked = mask | shifted;
		(*integer) = (*integer)& masked;

		cout << *integer << endl;
		return integer;
	}
}
void setuBit(uint32_t& dest, uint32_t bitPosition, bool value)
{
	uint32_t maxBits = 31;
	uint32_t Shift = maxBits - bitPosition;
	uint32_t invMask = 1 << Shift;
	uint32_t mask = ~invMask;
	uint32_t shifted = ((uint32_t)value) << Shift;
	uint32_t masked = mask | shifted;
	dest = dest& masked;
	cout << &dest << endl;
}
//Tells whether a bit is found returns true or false if a bit is in found in that position.
//If the bit is found it will print out that the bit is found otherwise say that its not found.
bool getuBit(uint32_t src, uint32_t bitPosition)
{
	int maxShifts = 31;
	int shifts = maxShifts - bitPosition;
	int copy=src&(1 << shifts);
	if (copy == src)
	{
		cout << "The bit is found at " << bitPosition << endl;
		return true;
	}
	else {
		cout << "The bit isn't found at " << bitPosition << " position"<<endl;
		return false;
	}
}
int getuBits(uint32_t src, uint32_t bitPosition)
{
	int returnValue=0;
	int maxShifts = 31;
	int shifts = maxShifts - bitPosition;
	uint32_t copy = (src << bitPosition);
	uint32_t rightShift = copy >> bitPosition;
	uint32_t zero = rightShift >> shifts;
	uint32_t regular = zero<< shifts;
	uint32_t clone = regular&(1 << shifts);
	if (regular == clone)
	{
		if (regular == 0)
		{
			cout << "The bit is found at " << bitPosition << endl;
			return returnValue = 0;
		}
		cout << "The bit is found at " << bitPosition << endl;
		return returnValue=1;
	}
	else {
		cout << "The bit isn't found at " << bitPosition << " position" << endl;
		return returnValue=0;
	}

	//uint32_t zero=src>>
}
//void setuBits(uint32_t& dest, uint32_t leastSigBit, uint32_t bitWidth, uint32_t value) 
//{
//	uint32_t maxBits = 31;
//	uint32_t leastSig = leastSigBit;
//	uint32_t bitWidth = bitWidth;
//	uint32_t mostSig = leastSig - bitWidth + 1;
//	uint32_t leftShift = 0xFFFFFFFF << mostSig + 1;
//	uint32_t rightShift=mostSig>>leftShift;
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
//stores the number  on the right 
//stores the dest on the leftside and the value on the right side
void setUBits(uint32_t& dest, uint32_t leastSigBit, uint32_t bitWidth, uint32_t value)
{
	uint32_t maxBits = 31;
	uint32_t leastSig = leastSigBit;
	//uint32_t bitwidth = bitWidth;
	uint32_t mostSig = leastSig - bitWidth +1 ;
	uint32_t preservedMostSig=0;
	uint32_t preservedLeastSig;
	//uint32_t value=dest;
	if (mostSig > 0)
	{

			preservedLeastSig = mostSig - 1;
	}
	// value = dest;
	uint32_t shifts = maxBits - bitWidth;
	value = value << shifts;
	value = value >> shifts;
	//uint32_t mask = 0xFFFFFFFF << shifts;
	if (preservedLeastSig == preservedMostSig)
	{
		return;
	}
	for (uint32_t j = preservedMostSig; j < preservedLeastSig; j++)
	{
		if (getuBits(dest, j))
		{
			value = value | (1 << j);
		}
	}
	dest = value;
}
//stores the number on the left handside big endian. ?? working on
void setUBitsL(uint32_t& dest, uint32_t leastSigBit, uint32_t bitWidth, uint32_t value)
{
	uint32_t maxBits = 31;
	uint32_t leastSig = leastSigBit;
	//uint32_t bitwidth = bitWidth;
	uint32_t mostSig = leastSig - bitWidth + 1;
	uint32_t preservedMostSig = 0;
	//uint32_t value=dest;

	// value = dest;
	uint32_t shifts = maxBits - bitWidth+1;
	value = value << shifts;
	//value = value >> shifts;
	//uint32_t mask = 0xFFFFFFFF << shifts;
	
	for (uint32_t j = bitWidth; j < maxBits; j++)
	{
		if (getuBits(dest, j))
		{
			value = value | (1 << j);
		}
	}
	dest = value;
}
//I want this function to preserve the left hand side. of the destination and change the right side
void setUBitsTest(uint32_t& dest, uint32_t leastSigBit, uint32_t bitWidth, uint32_t value)
{
	uint32_t maxBits = 31;
	uint32_t leastSig = leastSigBit;
	//uint32_t bitwidth = bitWidth;
	uint32_t mostSig = leastSig - bitWidth + 1;
	uint32_t rightHandMostSig = leastSig+1;
	uint32_t rightHandLeastSig=31;
	//uint32_t value=dest;
	/*if (mostSig > 0)
	{

		preservedLeastSig = mostSig - 1;
	}*/
	// value = dest;
	uint32_t shifts = maxBits - bitWidth;
//	value = value << shifts;
	//value = value >> shifts;
	//uint32_t mask = 0xFFFFFFFF << shifts;
	if (rightHandLeastSig == rightHandMostSig)
	{
		return;
	}
	for (uint32_t j = 0; j < leastSig+1; j++)
	{
		if (getuBits(dest, j)!=0)
		{
			value = value | (1 << (maxBits-j));
		}
	}
	dest = value;
}
//I want this function to change the leftside of the destination and preserve the right side of the destination
void setUBitsTestL(uint32_t& dest, uint32_t leastSigBit, uint32_t bitWidth, uint32_t value)
{
	uint32_t maxBits = 31;
	uint32_t leastSig = leastSigBit;
	//uint32_t bitwidth = bitWidth;
	uint32_t mostSig = 0;
	uint32_t rightHandMostSig = leastSig + 1;
	uint32_t rightHandLeastSig = 31;
	
	//uint32_t value=dest;
	// value = dest;
	uint32_t shifts = maxBits - bitWidth+1;
	value = value << shifts;
	//	value = value << shifts;
	//value = value >> shifts;
	//uint32_t mask = 0xFFFFFFFF << shifts;
	if (rightHandLeastSig == rightHandMostSig)
	{
		return;
	}
	for (uint32_t j = rightHandMostSig; j < maxBits + 1; j++)
	{
		if (getuBits(dest, j) != 0)
		{
			value = value | (1 << (maxBits - j));
		}
	}
	dest = value;
}
//I want this function to preserve the left hand side. of the destination and change the right side
void setSBitsTest(int32_t& dest, uint32_t leastSigBit, uint32_t bitWidth, int32_t value)
{
	uint32_t maxBits = 31;
	uint32_t leastSig = leastSigBit;
	//uint32_t bitwidth = bitWidth;
	uint32_t mostSig = leastSig - bitWidth + 1;
	uint32_t rightHandMostSig = leastSig + 1;
	uint32_t rightHandLeastSig = 31;
	//uint32_t value=dest;
	/*if (mostSig > 0)
	{

	preservedLeastSig = mostSig - 1;
	}*/
	// value = dest;
	uint32_t shifts = maxBits - bitWidth;
	//	value = value << shifts;
	//value = value >> shifts;
	//uint32_t mask = 0xFFFFFFFF << shifts;
	if (rightHandLeastSig == rightHandMostSig)
	{
		return;
	}
	for (uint32_t j = 0; j < leastSig + 1; j++)
	{
		if (getuBits(dest, j) != 0)
		{
			value = value | (1 << (maxBits - j));
		}
	}
	dest = value;
}
void serializeStruct(foo) 
{

}
#endif	