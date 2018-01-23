#include "Bit_Field_project.h"


int main()
{
	
	uint32_t destCase1= 0x00000000;
	uint32_t destCase2 = 0xFFFFFFFF;
	uint32_t destCase3 = 0x00000000;
	uint32_t destCase4 = 0xFFFFFFFF;


	//setUBitsTestR(destCase1, 1, 1, 1); // works
	//setUBitsTestL(destCase2, 31, 1, 0); // works
//	setUBitsTestL(destCase3, 28, 3, 13); //works
	setUBitsTestR(destCase4, 8, 7, 0x55555555); //wrong answer
	


	return 0;

}