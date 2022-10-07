#include "Heap.hpp"

/***************************************************************
 *      Student Name: Wilver Santos
 *      File Name: Heap.cpp
 *      Assignment number: Project 2
 *
 *      Other comments regarding the file - Heap.cpp implements  methods and variables
 *      defined in Heap.hpp.
 *
 ***************************************************************/

Heap::Heap()
{ 
	this->numElements = 0; 
	for(int i = 0; i < this->numElements; ++i)
	{
		this->queue[i] = nullptr;
	}
}

Heap::~Heap()
{
	if(this->numElements > 0)
	{
		for(int i = 0; i < this->MAX_QUEUE_SIZE; ++i)
		{
			if(this->queue[i] != nullptr)
			{
				delete this->queue[i];
			}
			else
			{
				continue;
			}
		}
	}
}

void Heap::MoveUp(int someIndex)
{

	int parentIndex = GetParent(someIndex); 
	while( parentIndex >= 0)
	{
		if (this->queue[someIndex]->GetArrivalT() < this->queue[parentIndex]->GetArrivalT())
		{
			Swap(someIndex, parentIndex);
			someIndex = parentIndex;
			parentIndex = GetParent(someIndex);
		}
		else
		{
			break;
		}
	}
}

void Heap::MoveDown(int someIndex)
{
	int leftIndex = GetLeft(someIndex);
	int rightIndex = GetRight(someIndex);

	if(leftIndex < this->numElements)
	{
		//compares chosen customer to its children
		if(this->queue[someIndex]->GetArrivalT() > this->queue[leftIndex]->GetArrivalT() 
		   || this->queue[someIndex]->GetArrivalT() > this->queue[rightIndex]->GetArrivalT())
		{
			if (this->queue[rightIndex]->GetArrivalT() < this->queue[leftIndex]->GetArrivalT())
			{
				Swap(someIndex, rightIndex);
				MoveDown(rightIndex);
			}
			else
			{
				Swap(someIndex, leftIndex);
				MoveDown(leftIndex);
			}
		}
		else
		{
			if (this->queue[someIndex]->GetArrivalT() > this->queue[leftIndex]->GetArrivalT())
			{
				Swap(someIndex, leftIndex);
				//only has a left child, cant have grand children.
			}
		}
	}
	else
	{
		//has no children, do nothing.
	}
}


int Heap::GetParent(int someIndex)
{ 
	if(someIndex <= 0) //beginning check
	{
		return -1;
	}
	else
	{
		return (someIndex - 1) / 2; 
	}
}

int Heap::GetLeft(int someIndex)
{ return (2 * someIndex) + 1; }

int Heap::GetRight(int someIndex)
{ return 2 * (someIndex + 1); }

int Heap::GetNumInQueue()
{ return this->numElements; }

void Heap::Swap(int indexA, int indexB)
{
	Customer* holder = this->queue[indexA];
	this->queue[indexA] = this->queue[indexB];
	this->queue[indexB] = holder;
}

void Heap::Insert(Customer* someCust)
{
	if(this->numElements  != this->MAX_QUEUE_SIZE)
	{
		this->queue[this->numElements] = someCust;
		MoveUp(this->numElements);

		this->numElements++;
	}
}

Customer* Heap::Pop()
{
	if (this->numElements <= 0)
	{
		throw "No elements in Heap.";
	}
	
	Customer* poppedVal = this->queue[0];

	this->queue[0] = this->queue[this->numElements - 1];
	--this->numElements;

	MoveDown(0);

	return poppedVal;
}
