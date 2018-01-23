#ifndef foo_h
#define foo_h
#include <iostream>
using namespace std;


struct foo
{
	bool b1;

	bool b2;

	int32_t n1;

	uint32_t n2;
};
const int MAXBITSLOOP = 32;
const int MOSTSIG = 0;

void setL(int x, int p, int s);
//Code uses little endian bit order 5,4,3,2,1,0

bool readFrom(uint32_t src, uint32_t bitPosition)
{
	bool returnValue = 0;
	int maxShifts = 31;
	int shifts = maxShifts - bitPosition;
	uint32_t copy = (src << bitPosition);
	uint32_t rightShift = copy >> bitPosition;
	uint32_t zero = rightShift >> shifts;
	uint32_t regular = zero << shifts;
	uint32_t clone = regular&(1 << shifts);
	if (regular == clone)
	{
		if (regular == 0)
		{
			//cout << "The bit is found at " << bitPosition << endl;
			return returnValue = 0; // The bit is 0.
		}
	//	cout << "The bit is found at " << bitPosition << endl;
		return returnValue = 1; // The bit is 1.
	}
	else {
	//	cout << "The bit isn't found at " << bitPosition << " position" << endl;
		return returnValue = 0;
	}

}
void writeTo(uint32_t &src, uint32_t bitPosition)
{
	src = src | (1 << bitPosition);
}
int getuBits(uint32_t src, uint32_t bitPosition)
{
	int returnValue = 0;
	int maxShifts = 31;
	int shifts = maxShifts - bitPosition;
	uint32_t copy = (src << bitPosition);
	uint32_t rightShift = copy >> bitPosition;
	uint32_t zero = rightShift >> shifts;
	uint32_t regular = zero << shifts;
	uint32_t clone = regular&(1 << shifts);
	if (regular == clone)
	{
		if (regular == 0)
		{
			cout << "The bit is found at " << bitPosition << endl;
			return returnValue = 0; // The bit is 0.
		}
		cout << "The bit is found at " << bitPosition << endl;
		return returnValue = 1; // The bit is 1.
	}
	else {
		cout << "The bit isn't found at " << bitPosition << " position" << endl;
		return returnValue = 0;
	}

	//uint32_t zero=src>>
}



//I want this function to change the leftside of the destination and preserve the right side of the destination
void setUBitsTestL(uint32_t& dest, uint32_t leastSigBit, uint32_t bitWidth, uint32_t value)
{
	uint32_t maxBits = 31;
	uint32_t leastSig = leastSigBit;

	uint32_t shifts = maxBits - bitWidth + 1;
	value = value << shifts;
	
	
	for (uint32_t j = MOSTSIG; j < leastSig; j++)
	{
		bool b = readFrom(dest, j);
		if(b)
		{
			writeTo(value,j);
		}
	}
	dest = value;
}

//I want this function to preserve the left hand side. of the destination and change the right side
void setUBitsTestR(uint32_t &dest, uint32_t leastSigBit, uint32_t bitWidth, uint32_t value)
{
	uint32_t maxBits = 31;
	uint32_t leastSig = leastSigBit;
	
	uint32_t mostSig = leastSig - bitWidth + 1;
	//uint32_t rightHandMostSig = leastSig + 1;
	//uint32_t rightHandLeastSig = 31;
	
	uint32_t shifts = leastSig+bitWidth;
	//value = value << shifts;

	for (uint32_t j = leastSig; j < MAXBITSLOOP; j++)// j=leastsig+bitwidth
	{
		bool b = (readFrom(dest, j));
		if(b)
		{
			writeTo(value, j);
		}
	}
	int trickCase = leastSig - bitWidth + 1;
	if (trickCase!= 0)
	{
		for (int k = 0; k < trickCase; k++)
		{
			bool b = (readFrom(dest, k));
			if (b)
			{
				writeTo(value, k);
			}
		}
	}
 	dest = value;
}



#endif	