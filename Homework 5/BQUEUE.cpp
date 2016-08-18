#include "BQUEUE.h"
#include <iostream>

using namespace std;
/*
*Function Name:BQUEUE
Precondition: state of class has not be initialized
Postcondition: state has been initialized
Description: default constructor sets back to 0.*/
BQUEUE::BQUEUE()
{
	back = 0;
}

/*Function Name:~BQUEUE
Precondition: checks to see if back is equal to 0.
Postcondition: nodes are going to get destroyed
Description: Destructor destroys nodes by calling dequeue */
BQUEUE::~BQUEUE()
{
		if (back == 0)
		{
			return;
		}
		else if (back->next == back)
		{
			delete back;
			back = 0;
			return;
		}
		else
		{
			bqnode *p = back->next;
			p->next->prev = back;
			back->next = p->next;
			delete p;
		}
}
/*Function Name:Print
Precondition: Print function gets called.
Postcondition: the integers in the nodes are cout
Description: if back is equal to 0. the queue is empty
			if the queue is not empty the integers starting from
			the front of the list is cout.*/
void BQUEUE::Print()
{
	if (back == 0)
	{
		cout << "Queue is Empty" << endl;
	}
	else
	{
		bqnode *p = back->next;
		while (p != back)
		{
			cout << p->time << endl;
			p = p->next;
		}
		bqnode *w = back;
		cout << w->time << endl;
		cout << endl;
	}
}
/*Function name: Enqueue
Precondition: There aren't any nodes
Postcondition:Nodes get created
Description: function gets called with an integer. 
function checks to see if back==0. if back is equal to a new back is created.
	if not  a pointer p is created with a new node and it gets assigned to the back 
	
*/
void BQUEUE::Enqueue(int me)
{
	if (back == 0)
	{
		back = new bqnode;
		back->time = me;
		back->next = back;
		back->prev = back;
	}
	else
	{
		bqnode *p = new bqnode;
		p->prev = back;
		p->next = back->next;
		p->time = me;
		back->next->prev = p;
		back->next = p;
		back = p;

	}
}
/*Function name: Dequeue
Precondition: dequeue gets called
Postcondition: back is deleted.
Description: back gets deleted by checking if there aren't any nodes then return gets called, 1 node if back->next=back then it gets deleted. then 2 or more
			 and it deletes back
*/
void BQUEUE::Dequeue()
{
	// if its empty
	if (back==0)
		return;
	//for one node
	if (back->next == back)
	{
		delete back;
		back = 0;
		return;
	}
	//code for 2 or more nodes
		bqnode *me = back->next;
		me->next->prev = back;
		back->next = me->next;
		delete me;
}
/*
Function: BQUEUE
Precondition: State of class has not been initialized.
Postcondition: State has been initialize
Description: Copy constructor makes a deep copy.
*/
BQUEUE::BQUEUE(const BQUEUE &me)
{
	/*bqnode *p = me.back->next;
	(*this).back = 0;
	do
	{
		(*this).Enqueue(p->time);
		p = p->next;
	} while (p != me.back->next);
*/
	back = 0;
	bqnode *q = me.back->next;
	do{
		if (back == 0)
		{
			back = new bqnode;
			back->time = q->time;
			back->next = back;
			back->prev = back;
		}
		else
		{
			bqnode *p = new bqnode;
			p->time = q->time;
			p->next = back->next;
			p->prev = back;
			back->next->prev = p;
			back->next = p;
			back = p;
		}
		q = q->next;
	} while (q != me.back->next);
}