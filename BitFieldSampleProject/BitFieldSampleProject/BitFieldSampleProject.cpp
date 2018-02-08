#include "BitFieldSampleProject.h"

//use look up table. index is -1 of the bitwidth.
uint32_t lookUpTable[15] =
{
0x01, //index 0
0x03,
0x07,
/*0x0C,0x0E*/0x0F,
0x1F,
0x3F,
0x7F,
/*0xCF,0xEF*/0xFF
};
///little endian bit ordering 7,6,5,4,3,2,1,0

bool getBit(const uint8_t src, const uint32_t bitPosition)
{
	uint8_t mask = 1 << bitPosition;
	uint8_t masked = mask & src;
	uint8_t shifted = masked >> bitPosition;
	return shifted != 0;
}

uint8_t& setBit(uint8_t& dest, const bool value, const uint32_t bitPosition)
{
	uint8_t mask = 1 << bitPosition;
	uint8_t inverseMask = ~mask;
	uint8_t masked = mask & (value << bitPosition);
	uint8_t destMasked = inverseMask & dest;
	dest = destMasked | masked;
	return dest;
}
//sets the leftside
uint8_t& setBitL(uint8_t& dest, const uint32_t leastSig, const uint32_t bitWidth, const uint32_t value)
{
	uint8_t mask = lookUpTable[bitWidth-1] << leastSig;
	uint8_t invMask = ~mask;
	uint8_t masked= invMask&dest;
	uint8_t copyOfValue = value << leastSig;
	const uint8_t maxBits = 8;
	uint8_t shift = maxBits - bitWidth;
	uint8_t rightShift = shift - leastSig;
	//copyOfValue = copyOfValue>>rightShift;//
	uint8_t destMasked = copyOfValue | masked;
	dest = destMasked;
	return dest;
}

//sets any bit in an 8 bit field
uint8_t& setBitU(uint8_t& dest, const uint32_t leastSig, const uint32_t bitWidth, const uint32_t value)
{
	const uint8_t maxBits = 7;
	uint8_t mask = lookUpTable[bitWidth - 1] << leastSig;
	uint8_t invMask = ~mask;
	uint8_t masked = invMask&dest;
	uint8_t copyOfValue = value << leastSig;
	uint8_t additionalLeftShift = maxBits - (leastSig + bitWidth - 1);
	copyOfValue = copyOfValue << additionalLeftShift;
	copyOfValue = copyOfValue >> additionalLeftShift;
	uint8_t destMasked = copyOfValue | masked;
	dest = destMasked;
	return dest;
}
