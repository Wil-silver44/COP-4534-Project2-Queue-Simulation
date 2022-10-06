#ifndef STACKQUEUE_HPP
#define STACKQUEUE_HPP
#include "Customer.hpp"

/***************************************************************
 *      Student Name: Wilver Santos
 *      File Name: StackQueue.hpp
 *      Assignment number: Project 2
 *
 *      Other comments regarding the file - StackQueue.hpp defines methods and variables
 *      for a FIFO queue for use in the customer service simulation.
 *
 ***************************************************************/

class StackQueue
{
	private:
	Customer* header;
	public:
	StackQueue();
	~StackQueue();
	void Insert(Customer* someCust);
	Customer* PopHeader();
	bool IsEmpty();
};

#endif
