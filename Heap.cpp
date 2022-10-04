#include "Heap.hpp"


Heap::Heap()
{ 
	this->numElements = 0; 
	for(int i = 0; i < this->MAX_QUEUE_SIZE; ++i)
	{
		this->queue[i] = nullptr;
	}
}

Heap::~Heap()
{

}

void Heap::MoveUp(int someIndex)
{

}

void Heap::MoveDown(int someIndex)
{
	int leftIndex = GetLeftInd(someIndex);
	int rightIndex = GetRightInd(someIndex);

	if(this->numElements < leftIndex)
	{
		if(this->numElements < rightIndex)
		{
			if (this->queue[someIndex]->GetArrivalT() < this->queue[leftIndex]->GetArrivalT()
					|| this->queue[someIndex]->GetArrivalT() < this->queue[GetRightInd(someIndex)]->GetArrivalT())
			{
				if (this->queue[rightIndex]->GetArrivalT() > this->queue[leftIndex]->GetArrivalT())
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
		}
		else
		{
			if (this->queue[someIndex]->GetArrivalT() < this->queue[leftIndex]->GetArrivalT())
			{ this->Swap(someIndex, leftIndex); }
		}
	}
	else
	{
		break;
	}

}


Customer* Heap::GetParent(int someIndex)
{
	return this->queue[GetParentInd(someIndex)];
} 

Customer* Heap::GetLeft(int someIndex)
{
	return this->queue[GetLeftInd(someIndex)];
}

Customer* Heap::GetRight(int someIndex)
{
	return this->queue[GetRightInd(someIndex)];
}


int Heap::GetParentInd(int someIndex)
{ return (someIndex - 1) / 2; }

int Heap::GetLeftInd(int someIndex)
{ return (2 * someIndex) + 1; }

int Heap::GetRightInd(int someIndex)
{ return 2 * (someIndex + 1); }


void Heap::Swap(int indexA, int indexB)
{
	Customer* holder = this->queue[indexA];
	this->queue[indexA] = this->queue[indexB];
	this->queue[indexB] = holder;
}

void Heap::Insert(Customer* someCust)
{
	this->queue[this->numElements] = someCust;
	MoveUp(this->numElements);

	++this->numElements;
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
}
