#ifndef foo_h
#define foo_h
#include <iostream>
 
class templateBitFieldProject
{
public:
 template<typename t> 
 t& setBitU(t& dest, uint32_t leastSig, uint32_t bitWidth, uint32_t value)
{
	 uint8_t maxBits = 8;
	 uint8_t mask = 0xFF << (maxBits - bitWidth);
	 mask = mask >> (maxBits - bitWidth);
	 mask = mask << leastSig;
	 uint8_t invMask = ~mask;
	 uint8_t masked = invMask & dest;
	 int8_t copyOfValue = value << leastSig;
	 uint8_t mask1 = mask & copyOfValue;
	 int8_t destMasked = mask1 | masked;
	 dest = destMasked;
	 return dest;
}
 template<typename t>
 t& setBitUAnySize(t& dest, uint32_t leastSig, uint32_t bitWidth, uint32_t value)
 {
	 t uMaxBits= sizeof(dest);
	 uMaxBits = uMaxBits * 8;
	 //const uint32_t MAXBITS = 32;
	 uint32_t zero = 0;
	 uint32_t invZero = ~zero;
	 uint32_t mask = invZero << (uMaxBits - bitWidth);
	 mask = mask >> (uMaxBits - bitWidth);
	 mask = mask << leastSig;
	 uint32_t invMask = ~mask;
	 uint32_t masked = invMask & dest;
	 uint32_t copyOfValue = value << leastSig;
	 uint32_t mask1 = mask & copyOfValue;
	 uint32_t destMasked = mask1 | masked;
	 dest = destMasked;
	 return dest;
 }
 template<typename t>
 t& templateSetBitUAnySize(t& dest,t leastSig, t bitWidth,t value)
 {
	 t uMaxBits = sizeof(dest);
	 uMaxBits = uMaxBits * 8;
	 //const uint32_t MAXBITS = 32;
	 t zero = 0;
	 t invZero = ~zero;
	 t mask = invZero << (uMaxBits - bitWidth);
	 mask = mask >> (uMaxBits - bitWidth);
	 mask = mask << leastSig;
	 t invMask = ~mask;
	 t masked = invMask & dest;
	 t copyOfValue = value << leastSig;
	 t mask1 = mask & copyOfValue;
	 t destMasked = mask1 | masked;
	 dest = destMasked;
	 return dest;
 }
 template<typename t>
 t& setBitS(t& dest, uint32_t leastSig, uint32_t bitWidth, int32_t value)
 {
	// uint8_t mask = lookUpTable[bitWidth] << leastSig;
	 uint8_t mask = 0xFF >> leastSig;
	 uint8_t invMask = ~mask;
	 int8_t masked = invMask & dest;
	 int8_t copyOfValue = value << leastSig;
	 int8_t mask1 = mask & copyOfValue;
	 int8_t destMasked = mask1 | masked;
	 dest = destMasked;
	 return dest;
 }
 template<typename t>
 t& setBitSAnySizeTest(t& dest, t leastSig, t bitWidth, t value)
 {
	 t uMaxBits = sizeof(dest);
	 uMaxBits = uMaxBits * 8;
	 uint32_t z
	 return dest;
 }
 bool getBitsU(uint32_t src, uint32_t bitPosition, uint32_t bitWidth);
	 
// bool getBitsS(int32_t src, const uint32_t bitPosition, const uint32_t bitWidth);
};



#endif