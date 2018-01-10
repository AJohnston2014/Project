#include <iostream>
#include <stdio.h>
#include "bitField.h"
using namespace std;

const uint32_t max = 31;
int  numOfBits;
uint32_t arr[max];
uint32_t input[max];



int* add(int* x, int* w)
{
	*x = *w + *x;
	int d = *x + *w;
	int *p = x;
	return x;
}

uint32_t* readSetBit(uint32_t* dest, bool value, __int32 bit)
{
	uint32_t maxBits = 31;
	uint32_t Shift = maxBits - bit;
	uint32_t invMask = 1 << Shift; //-8 or 8>>Shift
	uint32_t unMask = invMask >> Shift;
	uint32_t mask = ~unMask;
	uint32_t shifted = ~((uint32_t)value) << Shift; // needs a 1 on the left side then shift it
	uint32_t masked = mask | shifted;
	(*dest) = (*dest)& masked;
	cout << *dest << endl;
	return dest;
}
//uint32_t* deserializeSetBit(uint32_t *dest, bool value, _int32 bit,_int32 width)
//{
//	uint32_t maxBits = 31;
//	uint32_t leastSig = bit;
//	//uint32_t bitWidth = width;
//	uint32_t bitWidth = 5;
//	uint32_t mostsig = bitWidth + leastSig - 1;
//	uint32_t leftShift = maxBits - mostsig;
//	uint32_t rightShift = leftShift + leastSig;
//	uint32_t leftShifted=value<<leftShift;
//	uint32_t rightShifted = leftShifted >> rightShift;
//	*dest = *dest&rightShifted;
//	return dest;
//}

uint32_t* setBits(uint32_t* dest, bool value, uint32_t* bits)
{
	uint32_t maxShifts = 31;
	//uint32_t invMask = 1 << Shift;
	uint32_t bitNumb = numOfBits;
	uint32_t counter = 0;
	uint32_t masked = 0;
	while (bitNumb != 0)
	{
		input[counter] = maxShifts - input[counter]; //shift
		counter++;
		bitNumb--;
	}
	for (int i = 0; i < numOfBits; i++)
	{
		uint32_t l = input[i];
		uint32_t problem = 1 << l;
		arr[i] = problem;//invmask
		if (i >= 1)
		{
			arr[i] |= arr[i - 1];
		}
	}
	uint32_t mask = ~arr[numOfBits - 1];//mask
	bitNumb = numOfBits;
	counter = 0;
	while (bitNumb != 0)
	{
		input[counter] = ((uint32_t)value) << input[counter];
		masked = mask | input[counter] | masked;
		counter++;
		bitNumb--;
	}
	(*dest) = (*dest)&masked;
	cout << *dest<<endl;
	return dest;
}
//big endian approach 0,1,2.. bit ordering
//struct foo
//{
//	bool b1;
//
//	bool b2;
//
//	int32_t n1;
//
//	uint32_t n2;
//
//}me;
int main()
{
	/*cout << "Please Enter the number of Bits that you want to change " << endl;
	cin >> numOfBits;
	cout << "Enter the bits " << endl;
	for (int i = 0; i < numOfBits; i++)
	{
		cin >> input[i];
	}*/
	//x.me.n2 = 1;
	//uint32_t people = x.me.n2;
	uint32_t j = 0xFF010000;
	uint8_t x = 0xF0;
	uint32_t *kp = &j;
	uint32_t me = 0xFF010000;
	int32_t kk = 1;
	int32_t pp = 2;
	//cout << fiveBit(&kk, true, &pp);
	//cout << setBit(&people, x.me.b1 = false, 29) << endl;
	cout << endl;
	//cout << setBits(&me, x.me.b1 = false, input) << endl;
	//printf("%d", sizeof(x));
	//bitField z;
	int32_t integer = 7;
	int32_t bit = -1;
	int32_t *p = &integer;
	int32_t number = 0xFF010000;
	setBit(kp, true, 31);
	fiveBit(p, false, 31);
	//z.x.me.n2 = j;
	buffer[1] = 0; 
	//getuBits(x, 3);
	setUBitsTest(me, 31, 16, 1);//works
	setUBitsTestL( me,3, 4,7);//works
	setSBitsTest(number, 3, 4, 15);
}