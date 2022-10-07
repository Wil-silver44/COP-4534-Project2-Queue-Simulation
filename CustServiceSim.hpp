#ifndef CUSTSERVICESIM_HPP
#define CUSTSERVICESIM_HPP
#include <random>
#include <math.h>
#include "Customer.hpp"
#include "Heap.hpp"
#include "StackQueue.hpp"

/***************************************************************
 *	Student Name: Wilver Santos
 *	File Name: CustServiceSim.hpp
 *	Assignment number: Project 2
 *
 *      Other comments regarding the file - CustServiceSim.hpp implements the variables and methods
 *	defined by the Customer class.
 *
 ***************************************************************/

using std::cout;
using std::endl;

class CustServiceSim
{
	private:
	Heap eventQueue;
	StackQueue overflowStack;
	float totalWaitTime;
	float serviceTime;
	float lastArrivalTime;
	float lastDepartureTime;
	float currentWaitTime;
	float idleTime;
	int customerWaitedCnt;
	int serverAvailableCnt;
	int totalEvents;
	int eventsRemaining;
	int m;
	int mu;
	int l;
	float GetNextRandomInterval(float avg);
	void ProcessStatistics(Customer* leavingCustomer);
	public:
	CustServiceSim(int arrivals, int someM, int someMu, int someL);
	void ProcessNextEvent();
	void PrintResults();

};

#endif
