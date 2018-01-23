// bitFieldUnitTest.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
//
//
//int main()
//{
//    return 0;
//}
//


#include "gtest/gtest.h"
#include "../Bit_Field_project/Bit_Field_project.h"
//#include "../MyProject/arithmetic.h"

TEST(DestTests, Dest)
{
	//EXPECT_EQ(0, square(0));
	//EXPECT_EQ(-4, square(-2));

	uint32_t destCase1 = 0x00000000;
	uint32_t destCase2 = 0xFFFFFFFF;
	uint32_t destCase3 = 0x00000000;
	uint32_t destCase4 = 0xFFFFFFFF;


	//setUBitsTestR(destCase1, 1, 1, 1); // works
	//setUBitsTestL(destCase2, 31, 1, 0); // works
	//	setUBitsTestL(destCase3, 28, 3, 13); //works
	setUBitsTestR(destCase4, 8, 7, 0x55555555); //wrong answer


	EXPECT_NE(1, 1);
	//   {ASSERT|EXPECT}_TRUE() macro to assert that two objects are
	//   equal.
	ASSERT_EQ(1, 1);
	EXPECT_EQ(readFrom(destCase1, 2), 3);
	EXPECT_NE(setUBitsTestR(destCase4, 8, 7, 0x55555555), 1)
//	EXPECT_EQ(1,setL(0, 2, 2));
//	EXPECT_EQ(setUBitsTestR(destCase4, 8, 7, 0x55555555),   1);
}