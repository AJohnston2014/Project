//*****************************************************************************************************
// P R O G R A M  H E A D E R
//
//	
//	
//	Instructor: Dr. Bullard
//	Class: Data Structures
//	Term: Summer 2014
//	Assignment #5 QUECES
//	Due Date: July 9, 2014
//	Due Time: 11:00 PM
//	Points: 100
//	
//	Description: 
//	(1) manipulate pointers, (2) allocate memory dynamically, (3) implement a default constructor, 
//	copy constructor and destructor, (4) use only one pointer to add to the back and to dequeue 
//	from the front of the queue
//	
//	
//	
//
//
//****************************************************************************************************************
#include <iostream>
#include "BQUEUE.h"

using namespace std;

int main()
{
	BQUEUE  k;

	k.Enqueue(60);
	k.Print();
	k.Enqueue(20);
	k.Enqueue(30);
	k.Print();
	k.Enqueue(10);
	k.Print();
	k.Enqueue(50);
	k.Enqueue(40);
	k.Print();
	k.Dequeue();
	k.Print();

	BQUEUE j = k;

	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();

	return 0;
}
