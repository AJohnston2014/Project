#include "templateBitFieldProject.h"
#include <iostream>

using namespace std;


int main()
{
	uint32_t a = 0xFF;
	int32_t dest = 0xAA;

	uint32_t b = 0xFFFFFFFF;
	uint8_t x = 0x00;
	
	int8_t destSig = 0xAA;
	templateBitFieldProject project;
	
//	 cout<<project.setBitU(a, 7, 1, 0)<<endl;
//	cout<<project.setBitS(dest, 0, 5, -5)<<endl;
//	cout << project.setBitUAnySize(b, 31, 1, 0) << endl;
// cout << project.templateSetBitUAnySize(a, 7, 1, 0) << endl;
//	cout <<(uint32_t) project.templateSetBitUAnySize<uint8_t>(x, 4, 3, 13) << endl;
	cout <<(int8_t) project.templateSetBitSAnySize<int8_t>(destSig, 0, 5, -5);
	return 0;
}