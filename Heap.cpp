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
	int parentIndex = GetParentInd(someIndex);

	while(parentIndex >= 0)
	{
		if(this->queue[someIndex].GetArrivalT() > this->queue[parentIndex].GetArrivalT())
		{
			Swap(someIndex, parentIndex);
			someIndex = parentIndex;
			parentIndex = GetParentInd(someIndex);
		}
		else
		{
			break;
		}
	}
}

void Heap::MoveDown(int someIndex)
{
	int leftIndex = GetLeftInd(someIndex);
	int rightIndex = GetRightInd(someIndex);

	if(this->numElements < leftIndex)
	{
		if(this->numeElements < rightIndex)
		{
			if (this->queue[someIndex].GetArrivalT() < this->queue[leftChildIndex].GetArrivalT()
					|| this->queue[index].GetArrivalT() < this->queue[GetRightInd(someIndex)].GetArrivalT())
			{
				if (this->queue[rightIndex].GetArrivalT() > this->queue[leftIndex].GetArrivalT())
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
			if (this->queue[someIndex].GetArrivalT() < this->data[leftIndex].GetArrivalT())
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
	return this->queue[:GetParentInd(someIndex)];
} 

Customer* Heap::GetLeft(int someIndex)
{
	return this->queue[GetLeftInd(SomeIndex)];
}

Customer* Heap::GetRight(int someIndex)
{
	return return this->queue[GetRightInd(someIndex)];
}


int Heap::GetParentInd(int someIndex)
{ return (someIndex - 1) / 2; }

int Heap::GetLeftInd(int someIndex)
{ return (2 * someIndex) + 1; }

int Heap::GetRightInd(int someIndex)
{ return 2 * (index + 1); }


void Heap::Swap(int indexA, int indexB)
{
	Customer* holder = this->queue[indexA];
	this->queue[indexA] = this->queue[indexB];
	this->queue[indexB] = holder;
}

void Heap::Insert(Customer* someCust)
{

}

Customer* Heap::Peek()
{

}

Customer* Heap::Pop()
{

}
