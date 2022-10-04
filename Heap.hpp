#ifndef HEAP_HPP
#define HEAP_HPP

/***************************************************************
 *      Student Name: Wilver Santos
 *      File Name: Heap.hpp
 *      Assignment number: Project 2
 *
 *      Other comments regarding the file - Heap.hpp defines methods and variables
 *      for a complete binary tree to be used in a priority queue.
 *
 ***************************************************************/
#include <iostream>
#include "Customer.hpp"

class Heap
{
	private:
	static const int MAX_QUEUE_SIZE = 200; //Max size of queue according to project specs.
	Customer* queue[MAX_QUEUE_SIZE];
	int numElements;
	void MoveUp(int someIndex);
	void MoveDown(int someIndex);
	int GetParent(int someIndex);
	int GetLeft(int someIndex);
	int GetRight(int someIndex);
	void Swap(int indexA, int indexB);

	public:
	Heap();
	~Heap();
	void Insert(Customer* someCust);
	Customer* Pop();
};

#endif
