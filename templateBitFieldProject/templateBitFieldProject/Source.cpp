#include "templateBitFieldProject.h"
#include <iostream>

using namespace std;


int main()
{
	uint32_t a = 0xFF;
	int32_t dest = 0xAA;

	uint32_t b = 0xFFFFFFFF;
	
	templateBitFieldProject project;
	
//	 cout<<project.setBitU(a, 7, 1, 0)<<endl;
//	cout<<project.setBitS(dest, 0, 5, -5)<<endl;
//	cout << project.setBitUAnySize(b, 31, 1, 0) << endl;
 cout << project.templateSetBitUAnySize(a, 7, 1, 0) << endl;
	return 0;
}