#ifndef SETGETBITS_H
#define SETGETBITS_H
#include <iostream>
#include <type_traits>
using namespace std;


template<typename uIntType>
uIntType& SetBitUAnySize(uIntType& dest, uIntType leastSig, uIntType bitWidth, uIntType value)
{
	static_assert(is_unsigned<uIntType>::value,"number isn't an unsigned");
	uIntType uMaxBits = sizeof(dest);
	uMaxBits = (uMaxBits * 8);
	uIntType zero = 0;
	uIntType invZero = ~zero;
	uIntType mask = invZero << (uMaxBits - bitWidth);
	mask = mask >> (uMaxBits - bitWidth);
	mask = mask << leastSig;
	uIntType invMask = ~mask;
	uIntType masked = invMask & dest;
	uIntType copyOfValue = value << leastSig;
	uIntType mask1 = mask & copyOfValue;
	uIntType destMasked = mask1 | masked;
	dest = destMasked;
	return dest;
}

template<typename uIntType, typename sIntType>
uIntType& SetBitSAnySize(uIntType& dest, uIntType leastSig, uIntType bitWidth, sIntType value )
{
	static_assert(is_unsigned<uIntType>::value, "number isn't an unsigned number");
	static_assert(is_signed<sIntType>::value, "number isn't a signed number");
	uIntType uMaxBits = sizeof(dest);
	uMaxBits = (uMaxBits * 8);
	uIntType zero = 0; //uint8_t
	uIntType invZero = ~zero;//uint8_t
	uIntType mask = invZero << (uMaxBits - bitWidth);//uint8_t
	mask = mask >> (uMaxBits - bitWidth);
	mask = mask << leastSig;
	sIntType invMask = ~mask;
	sIntType masked = invMask & dest;
	sIntType copyOfValue = value << leastSig;
	sIntType mask1 = mask & copyOfValue;
	sIntType destMasked = mask1 | masked;
	memcpy(&dest, &destMasked, sizeof(dest));
	return dest;
}
template<typename uIntType>
bool getBitU(uIntType src, uint32_t bitPosition)
{
	uIntType mask = 1 << bitPosition;
	uIntType masked = mask & src;
	uIntType shifted = masked >> bitPosition;
	return shifted != 0;
}
template<typename uIntType>
uIntType getBitsU(uIntType src, uint32_t leastSig, uint32_t bitWidth)
{
	static_assert(is_unsigned<uIntType>::value, "number isn't an unsigned number");
	uIntType zero = 0;
	uIntType uBytes = sizeof(src);
	uIntType uMaxBits = (uBytes * 8);
	uIntType invZero = ~zero;
	uIntType mask = invZero << (uMaxBits-bitWidth);
	mask = mask >> (uMaxBits - bitWidth);
	mask = mask << leastSig;
	uIntType masked = mask & src;
	uIntType shifted = masked >> leastSig;
	return shifted != 0;
}

template<typename sIntType,typename uIntType>
sIntType getBitsS(sIntType src, const uIntType leastSig, const uIntType bitWidth)
{
	static_assert(sizeof(uIntType) == sizeof(sIntType), "numbers aren't the same size one of them is larger than the other");
	uIntType zero = 0;
	uIntType mask = ~zero;
	uIntType uBytes = sizeof(src);
	uIntType uMaxBits = (uBytes * 8);
	mask = mask << (uMaxBits - bitWidth);
	mask = mask >> (uMaxBits - bitWidth);
	mask = mask << leastSig;
	uIntType invMask = ~mask;
	sIntType signExtended = invMask | src;
	sIntType masked = invMask & src;
	return signExtended;
}

#endif