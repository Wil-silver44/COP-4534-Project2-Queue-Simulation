#include "StackQueue.hpp"

/***************************************************************
 *      Student Name: Wilver Santos
 *      File Name: Heap.hpp
 *      Assignment number: Project 2
 *
 *      Other comments regarding the file - Heap.hpp defines methods and variables
 *      for a complete binary tree to be used in a priority queue.
 *
 ***************************************************************/

StackQueue::StackQueue()
{
	this->header = nullptr;
}

StackQueue::~StackQueue()
{
	if(!IsEmpty())
	{
		while(this->header->GetNext() != nullptr)
		{
			Customer* helper = this->header->GetNext();
			if(helper->GetNext() != nullptr)
			{
				helper = helper->GetNext();
			}
			else
			{
				delete helper;
			}
		}

		delete this->header;
	}
}

void StackQueue::Insert(Customer* someCust)
{
	if(!IsEmpty())
	{
		Customer* temp = this->header;
		this->header = someCust;
		this->header->SetNext(temp);
	}
}

Customer* StackQueue::PopHeader()
{
	if(this->header != nullptr)
	{
		Customer* temp = this->header;
		this->header = temp->GetNext();

		return temp;
	}

	return nullptr;
}

bool StackQueue::IsEmpty()
{
	if(this->header != nullptr)
	{ return true; }
	else
	return false;
}
