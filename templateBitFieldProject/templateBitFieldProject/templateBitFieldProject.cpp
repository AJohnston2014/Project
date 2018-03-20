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
bool templateBitFieldProject::getBitsS(int32_t src, const uint32_t bitPosition, const uint32_t bitWidth)
{
	uint32_t zero = 0;
	uint32_t mask =~zero ;
	const uint32_t maxBits = 32;
	mask = mask <<(maxBits-bitWidth) ;
	mask = mask >> (maxBits - bitWidth);
    uint32_t invMask = ~mask;
	uint32_t masked = invMask & src;
	return masked!=0;
}