// templateBitFieldProjectUnitTest.cpp : Defines the entry point for the console application.
//
#include "gtest/gtest.h"
#include "stdafx.h"
#include "../templateBitFieldProject/templateBitFieldProject.h"

TEST(case1, setBit)
{
	uint8_t	dest1 = 0x00;
	uint32_t leastSigBit1 = 1;
	uint32_t bitWidth1 = 1;
	uint32_t	value1 = 1;
	templateBitFieldProject tester;
	EXPECT_EQ(tester.templateSetBitUAnySize<uint8_t>(dest1, leastSigBit1, bitWidth1, value1), 0x02);
}

TEST(caseS14, set32BitSVersioncase14)
{
	int32_t	dest = 0xFFFFFFFF;
	uint32_t leastSigBit = 2;
	uint32_t bitWidth = 4;
	int32_t	value = 0;
	templateBitFieldProject tester;
	EXPECT_EQ(tester.templateSetBitSAnySize<int32_t>(dest, leastSigBit, bitWidth, value), -61);// check expected answer
	//printf("%d", tester.templateSetBitSAnySize<int32_t>(dest, leastSigBit, bitWidth, value));
}