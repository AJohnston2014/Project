#ifndef SETGETBITS_H
#define SETGETBITS_H
#include <type_traits>
using namespace std;

template<typename uIntType>
uIntType& setBitU(uIntType& dest, uIntType bitPosition, const bool value)
{
	static_assert(is_unsigned<uIntType>::value, "uIntType isn't an unsigned integer type");
	uIntType mask = 1 << bitPosition;
	uIntType inverseMask = ~mask;
	uIntType masked = mask & (value << bitPosition);
	uIntType destMasked = inverseMask & dest;
	dest = destMasked | masked;
	return dest;
}

template<typename uIntType>
uIntType& setBitsU(uIntType& dest, uIntType leastSig, uIntType bitWidth, uIntType value)
{
	static_assert(is_unsigned<uIntType>::value,"uIntType isn't an unsigned integer type");
	uIntType uMaxBits = sizeof(dest)*8;
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
template<typename uIntType>
uIntType& setBitsUReduced(uIntType& dest, uIntType leastSig, uIntType bitWidth, uIntType value)
{
	static_assert(is_unsigned<uIntType>::value, "uIntType isn't an unsigned integer type");
	uIntType uMaxBits = sizeof(dest) * 8;
	uIntType zero = 0;
	uIntType invZero = ~zero;
	uIntType mask = invZero << (uMaxBits - bitWidth);
	mask = mask >> (uMaxBits - bitWidth);
	mask = mask << leastSig;
	uIntType masked = ~mask & dest;
	uIntType destMasked = ((value<<leastSig)&mask)| masked;
	dest = destMasked;
	return dest;
}
template<typename uIntType, typename sIntType>
uIntType& setBitsS(uIntType& dest, uIntType leastSig, uIntType bitWidth, sIntType value )
{
	static_assert(is_unsigned<uIntType>::value, "uIntType isn't an unsigned integer type");
	static_assert(is_signed<sIntType>::value, "sIntType isn't an signed integer type");
	static_assert(sizeof(uIntType) == sizeof(sIntType), "uIntType and sIntType aren't the same size one of them is larger than the other");
	uIntType uMaxBits = sizeof(dest)*8;
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
	static_assert(is_unsigned<uIntType>::value, "uIntType isn't an unsigned integer type");
	uIntType mask = 1 << bitPosition;
	uIntType masked = mask & src;
	uIntType shifted = masked >> bitPosition;
	return shifted != 0;
}
template<typename uIntType>
uIntType getBitsU(uIntType src, uint32_t leastSig, uint32_t bitWidth)
{
	static_assert(is_unsigned<uIntType>::value, "uIntType isn't an unsigned integer type");
	uIntType zero = 0;
	uIntType uBytes = sizeof(src);
	uIntType uMaxBits = (uBytes * 8);
	uIntType invZero = ~zero;
	uIntType mask = invZero << (uMaxBits-bitWidth);
	mask = mask >> (uMaxBits - bitWidth);
	mask = mask << leastSig;
	uIntType masked = mask & src;
	return masked;
}
/////incorrect getBitsS
//template<typename uIntType,typename sIntType>
//sIntType getBitsS(sIntType src, uIntType leastSig, uIntType bitWidth)
//{
//	static_assert(sizeof(uIntType) == sizeof(sIntType), "numbers aren't the same size one of them is larger than the other");
//	static_assert(is_unsigned<uIntType>::value, "uIntType isn't an unsigned integer type");
//	static_assert(is_signed<sIntType>::value, "sIntType isn't an signed integer type");
//	uIntType zero = 0;
//	uIntType mask = ~zero;
//	uIntType uBytes = sizeof(src);
//	uIntType uMaxBits = (uBytes * 8);
//	mask = mask << (uMaxBits - bitWidth);
//	mask = mask >> (uMaxBits - bitWidth);
//	mask = mask << leastSig;
//	uIntType invMask = ~mask;
//	sIntType signExtended = invMask | src;
//	sIntType masked = invMask & src;
//	return signExtended;
//}
template<typename sIntType, typename uIntType>
sIntType getBitsS(sIntType src, const uIntType leastSig, const uIntType bitWidth)
{
	static_assert(sizeof(uIntType) == sizeof(sIntType), "numbers aren't the same size one of them is larger than the other");
	uIntType mask = ~0;
	uIntType uBytes = sizeof(src);
	uIntType uMaxBits = (uBytes * 8);
	mask = mask << (uMaxBits - bitWidth);
	mask = mask >> (uMaxBits - bitWidth);
	mask = mask << leastSig;
	uIntType test = mask & src;
	test = test >> leastSig;
	uIntType signExtend = ~0 << (uMaxBits - bitWidth);
	sIntType signExtended = signExtend | test;
	return signExtended;
}

#endif