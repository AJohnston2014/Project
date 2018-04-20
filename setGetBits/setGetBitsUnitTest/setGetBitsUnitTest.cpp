// setGetBitsUnitTest.cpp : Defines the entry point for the console application.
//
#include "gtest/gtest.h"
#include "stdafx.h"
#include "../setGetBits/setGetBIts.h"

TEST(get, GetBits)
{
	uint8_t	src = 0x01;
	uint32_t bitPosition = 0;
	EXPECT_EQ(getBitU(src, bitPosition), true);
}
TEST(get, GetBitCase2)
{
	uint8_t src1 = 0x7F;
	uint8_t	bitPosition1 = 7;
	EXPECT_EQ(getBitU(src1, bitPosition1), false);
}

TEST(case1, set8Bit)
{
	uint8_t	dest1 = 0x00;
	uint32_t bitPosition = 1;
	uint32_t bitWidth1 = 1;
	bool value1 = 1;
	EXPECT_EQ(setBitU<uint8_t>(dest1, bitPosition, value1), 0x02);
}
TEST(case2, set32BitVersionCase13)
{
	uint32_t dest0 = 0x00;
	uint32_t leastSigBit0 = 0;
	uint32_t bitWidth0 = 1;
	uint32_t value0 = 1;
	EXPECT_EQ(setBitsU<uint32_t>(dest0, leastSigBit0, bitWidth0, value0), 0x01);
}

TEST(set, SetBitsCase1)
{
	uint8_t	dest = 0;
	uint32_t bitPosition = 7;
	bool value = true;
	EXPECT_EQ(setBitU<uint8_t>(dest, bitPosition,value), 0x80);
}
TEST(set, SetBitsCase2)
{
	//setBit case 2:
	uint8_t	dest1 = 0xFF;
	uint32_t bitPosition1 = 0;
	bool value1 = false;
	EXPECT_EQ(setBitU<uint8_t>(dest1, bitPosition1,value1), 0xFE);
}
TEST(case0, set8BitVersionCase0)
{
	uint8_t dest0 = 0xAA;
	uint32_t leastSigBit0 = 0;
	uint32_t bitWidth0 = 5;
	uint32_t value0 = 3;
	EXPECT_EQ(setBitsU<uint8_t>(dest0, leastSigBit0, bitWidth0, value0), 163);
}
TEST(case1, set8BitVersionCase1)
{ 
	uint8_t dest0 = 0x00;
	uint32_t leastSigBit0 = 1;
	uint32_t bitWidth0 = 1;
	uint32_t value0 = 1;
	EXPECT_EQ(setBitsU<uint8_t>(dest0, leastSigBit0, bitWidth0, value0), 0x02);
}
TEST(case2, set8BitVersionCase2)
{
	uint8_t dest = 0xFF;
	uint32_t	leastSigBit = 7;
	uint32_t	bitWidth = 1;
	uint32_t	value = 0;
	EXPECT_EQ(setBitsU<uint8_t>(dest, leastSigBit, bitWidth, 0), 0x7F);
}
TEST(case13, set32BitVersionCase13)
{
	//Case1 
	uint32_t dest0 = 0x00;
	uint32_t leastSigBit0 = 1;
	uint32_t bitWidth0 = 1;
	uint32_t value0 = 1;
	EXPECT_EQ(setBitsU<uint32_t>(dest0, leastSigBit0, bitWidth0, value0), 0x02);
}
TEST(case3, set8BitVersionCase3)
{
	uint8_t	dest1 = 0x00;
	uint32_t leastSigBit1 = 5;
	uint32_t bitWidth1 = 3;
	uint32_t	value1 = 13;
	EXPECT_EQ(setBitsU<uint8_t>(dest1, leastSigBit1, bitWidth1, value1), 0xA0);
}
TEST(case11, set8BitVersionCase11)
{
	uint8_t dest0 = 0x00;
	uint32_t leastSigBit0 = 1;
	uint32_t bitWidth0 = 1;
	uint32_t value0 = 1;
	EXPECT_EQ(setBitsU<uint8_t>(dest0, leastSigBit0, bitWidth0, value0), 0x02);
}

TEST(casegetS1, 8itGets)
{
	int8_t dest = -3;
	uint8_t leastSigBit = 0;
	uint8_t bitWidth = 5;
	getBitsS<uint8_t, int8_t>(dest, leastSigBit, bitWidth);
}
TEST(case4, set8BitVersionCase4)
{
	uint8_t	dest2 = 0xFF;
	uint32_t leastSigBit2 = 0;
	uint32_t bitWidth2 = 7;
	uint32_t	value2 = 0x55;
	EXPECT_EQ(setBitsU<uint8_t>(dest2, leastSigBit2, bitWidth2, value2), 0xD5);
}
TEST(case5, set8BitVersionCase5)
{
	uint8_t	dest5 = 0x00;
	uint32_t leastSigBit5 = 4;
	uint32_t bitWidth5 = 3;
	uint32_t	value5 = 13;
	EXPECT_EQ(setBitsU<uint8_t>(dest5, leastSigBit5, bitWidth5, value5), 0x50);

}
TEST(caseS4, set32BitSVersioncase4)
{
	uint32_t dest = 0xAA;
	uint32_t leastSigBit = 0;
	uint32_t bitWidth = 5;
	int32_t	value = -5;
	EXPECT_EQ(setBitsS<>(dest, leastSigBit, bitWidth, value), 187);
}
TEST(caseS14, set32BitSVersioncase14)
{
	uint32_t	dest = 0xFFFFFFFF;
	uint32_t leastSigBit = 2;
	uint32_t bitWidth = 4;
	int32_t	value = 0;
	EXPECT_EQ(setBitsS<>(dest, leastSigBit, bitWidth, value), -61);
}
TEST(Case2, Set8BitSVersionCase2)
{
	uint32_t	dest2 = 0;
	uint32_t leastSigBit2 = 5;
	uint32_t bitWidth2 = 3;
	int32_t	value2 = -8;
	EXPECT_EQ(setBitsS<>(dest2, leastSigBit2, bitWidth2, value2), 0);
}
TEST(Case3, Set8BitSVersionCase3) 
{
	uint32_t dest = 0x55;
	uint32_t leastSigBit = 3;
	uint32_t bitWidth = 5;
	int32_t	value = -10;
	EXPECT_EQ(setBitsS<>(dest, leastSigBit, bitWidth, value), 181);
}
TEST(Case4, Set8BitSVersionCase4) 
{
	uint32_t	dest = 0xFF;
	uint32_t leastSigBit = 2;
	uint32_t bitWidth = 4;
	int32_t	value = 0;
	EXPECT_EQ(setBitsS<>(dest, leastSigBit, bitWidth, value), 195);
}

TEST(caseS18, set32BitSVersioncase18)
{
	uint32_t dest1 = 0xAAAAAAAA;
	uint32_t leastSigBit = 0;
	uint32_t bitWidth = 5;
	int32_t	value = -5;
	EXPECT_EQ(setBitsS<>(dest1, leastSigBit, bitWidth, value), -1431655749);
}
TEST(caseS15, set32BitSVersioncase15)
{
	uint32_t dest = 0x0;
	uint32_t leastSigBit = 0;
	uint32_t bitWidth = 5;
	int32_t	value = -5;
	EXPECT_EQ(setBitsS<>(dest, leastSigBit, bitWidth, value), 0x1B);
}