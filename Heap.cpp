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
	while (someIndex > 0 && this->queue[GetParent(someIndex).GetArrivalT()] < this->queue[someIndex].GetArrivalT())
	{
		swap(((someIndex - 1) / 2), someIndex);

		someIndex = ((someIndex - 1) / 2);
	}
}

void Heap::MoveDown(int someIndex)
{

}

Customer* Heap::GetParent(int someIndex)
{
	return this->queue[(i - 1) / 2];
}

Customer* Heap::GetLeft(int someIndex)
{
	return this->queue[(2 * someIndex) + 1];
}

Customer* Heap::GetRight(int someIndex)
{
	return return this->queue[2 * (index + 1)];
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
