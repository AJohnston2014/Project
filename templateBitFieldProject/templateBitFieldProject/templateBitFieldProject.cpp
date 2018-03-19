#include "templateBitFieldProject.h"

bool templateBitFieldProject::getBitsU(uint32_t src, uint32_t bitPosition, uint32_t bitWidth)
{
	uint32_t zero = 0;
	uint32_t maxBits = 32;
	uint32_t invZero = ~zero;
	uint32_t mask = invZero<< bitPosition;
	uint32_t masked = mask & src;
	uint32_t shifted = masked >> bitPosition;
	return shifted != 0;
}
//template<typename t>
//t& templateBitFieldProject::setBitU(t& dest, uint32_t leastSig, uint32_t bitWidth, uint32_t value)
//{
//	uint8_t mask = 0xFF >> leastSig;
//	mask = mask << leastSig;
//    uint8_t invMask = ~mask;
//	uint8_t masked = invMask & dest;
//	int8_t copyOfValue = value << leastSig;
//    uint8_t mask1 = mask & copyOfValue;
//    int8_t destMasked = mask1 | masked;
//	dest = destMasked;
//	return dest;
//}