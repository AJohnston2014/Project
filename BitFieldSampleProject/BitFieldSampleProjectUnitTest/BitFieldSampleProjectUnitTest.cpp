// BitFieldSampleProjectUnitTest.cpp : Defines the entry point for the console application.
//
#include "gtest/gtest.h"
#include "stdafx.h"
#include "../BitFieldSampleProject/BitFieldSampleProject.h"

//TEST(get, GetBits)
//{
//	//getBit case 1:
//	uint8_t	src = 0x01;
//	uint32_t bitPosition = 0;
//	EXPECT_EQ(getBit(src, bitPosition), true);
//
//	//getBit case 2:
//	uint8_t src1 = 0x7F;
//	uint8_t	bitPosition1 = 7;
//	EXPECT_EQ(getBit(src1, bitPosition1), false);	
//
//}
//TEST(set, SetBits)
//{
//	//setBit case 1:
//	uint8_t	dest = 0;
//	uint32_t bitPosition = 7;
//	bool value = true;
//	EXPECT_EQ(setBit(dest, value, bitPosition), 0x80);
//		//	expected result = 0x80
//
//	//setBit case 2:
//	uint8_t	dest1 = 0xFF;
//	uint32_t bitPosition1 = 0;
//	bool value1 = false;
//	EXPECT_EQ(setBit(dest1, value1, bitPosition1), 0xFE);
//
//}

//8 bit test

//TEST(set, Set8BitVersion)
//{
//	//Case1 
//	uint8_t dest0 = 0x00;
//	uint32_t leastSigBit0 = 1;
//	uint32_t bitWidth0 = 1;
//	uint32_t value0 = 1;
//	EXPECT_EQ(setBitU(dest0, leastSigBit0, bitWidth0, value0), 0x01);
//
//	//Case2
//	uint8_t dest = 0xFF;
//	uint32_t	leastSigBit = 7;
//	uint32_t	bitWidth = 1;
//	uint32_t	value = 0;
//	EXPECT_EQ(setBitU(dest, leastSigBit, bitWidth, 0), 0x7F);
//
//	//	Case 3
//	uint8_t	dest1 = 0x00;
//	uint32_t leastSigBit1 = 5;
//	uint32_t bitWidth1 = 3;
//	uint32_t	value1 = 13;
//	EXPECT_EQ(setBitU(dest1, leastSigBit1, bitWidth1, value1), 0xA0);
//
//	//case 4
//	uint8_t	dest2 = 0xFF;
//	uint32_t leastSigBit2 = 0;
//	uint32_t bitWidth2 = 7;
//	uint32_t	value2 = 0x55;
//	EXPECT_EQ(setBitU(dest2, leastSigBit2, bitWidth2, value2), 0xD5);
//
//	//case 5 
//	uint8_t	dest5 = 0x00;
//	uint32_t leastSigBit5 = 4;
//	uint32_t bitWidth5 = 3;
//	uint32_t	value5 = 13;
//	EXPECT_EQ(setBitU(dest5, leastSigBit5, bitWidth5, value5), 0x50);
//
//}

TEST(case1, set8BitVersionCase1)
{
	//Case1 
	uint8_t dest0 = 0x00;
	uint32_t leastSigBit0 = 1;
	uint32_t bitWidth0 = 1;
	uint32_t value0 = 1;
	EXPECT_EQ(setBitU(dest0, leastSigBit0, bitWidth0, value0), 0x02);
}
TEST(case2, set8BitVersionCase2)
{
	//Case2
	uint8_t dest = 0xFF;
	uint32_t	leastSigBit = 7;
	uint32_t	bitWidth = 1;
	uint32_t	value = 0;
	EXPECT_EQ(setBitU(dest, leastSigBit, bitWidth, 0), 0x7F);
}
TEST(case3, set8BitVersionCase3)
{
	//	Case 3
	uint8_t	dest1 = 0x00;
	uint32_t leastSigBit1 = 5;
	uint32_t bitWidth1 = 3;
	uint32_t	value1 = 13;
	EXPECT_EQ(setBitU(dest1, leastSigBit1, bitWidth1, value1), 0xA0);
}
TEST(case4, set8BitVersionCase4)
{
	//case 4
	uint8_t	dest2 = 0xFF;
	uint32_t leastSigBit2 = 0;
	uint32_t bitWidth2 = 7;
	uint32_t	value2 = 0x55;
	EXPECT_EQ(setBitU(dest2, leastSigBit2, bitWidth2, value2), 0xD5);
}
TEST(case5, set8BitVersionCase5)
{
	//case 5 
	uint8_t	dest5 = 0x00;
	uint32_t leastSigBit5 = 4;
	uint32_t bitWidth5 = 3;
	uint32_t	value5 = 13;
	EXPECT_EQ(setBitU(dest5, leastSigBit5, bitWidth5, value5), 0x50);
}