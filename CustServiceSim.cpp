#include "CustServiceSim.hpp"

/***************************************************************
 *      Student Name: Wilver Santos
 *      File Name: CustServiceSim.cpp
 *      Assignment number: Project 2
 *
 *      Other comments regarding the file - CustServiceSim.cpp implements methods and variables
 *      for a simulation of a customer service center, and calculating runtime statistics
 *      defined in CustServiceSim.hpp.
 *
 ***************************************************************/

CustServiceSim::CustServiceSim(int arrivals, int someM, int someMu, int someL)
{	
	this->totalEvents = arrivals;
	this->eventsRemaining = totalEvents - 200;

	this->m = someM;
	this->mu = someMu;
	this->l = someL;

	this->lastArrivalTime = GetNextRandomInterval((l * 1.0));

	for(int i = 0; i < 200; ++i)
	{
		this->eventQueue.Insert(new Customer(this->lastArrivalTime));
		this->lastArrivalTime += GetNextRandomInterval((l * 1.0));
	}
	this->serverAvailableCnt = m;

	while(this->eventQueue.GetNumInQueue() != 0)
	{
		ProcessNextEvent();

		cout << "event processed!" << endl;

		if( (this->eventsRemaining != 0) && (this->eventQueue.GetNumInQueue() <= (m + 1) ))
		{
			this->eventsRemaining -= (200 - this->eventQueue.GetNumInQueue());
			for(int i = 0; i < (200 - this->eventQueue.GetNumInQueue() - 1); ++i)
			{
				this->eventQueue.Insert(new Customer(this->lastArrivalTime));
				this->lastArrivalTime += GetNextRandomInterval((l * 1.0));
			}
		}
	}
	
	PrintResults();
}

void CustServiceSim::ProcessNextEvent()
{
	Customer* eventHandler = this->eventQueue.Pop();
	cout << "Cust popped!" << endl;
	cout << this->eventQueue.GetNumInQueue() << endl;
	if(eventHandler->GetArrivalT() > 0 && eventHandler->GetStartOfServT() < 0) //process arrival
	{
		if(this->serverAvailableCnt > 0)
		{
			--this->serverAvailableCnt;
			float arrive = eventHandler->GetArrivalT();
			eventHandler->SetStartOfServT(arrive);
			float interval = GetNextRandomInterval((mu * 1.0));
			cout << "boop preDepart" << endl;
			eventHandler->SetDepartT((arrive + interval));
			cout << "boop arrival" << endl;
			this->lastDepartureTime = eventHandler->GetDepartT();
			this->eventQueue.Insert(eventHandler);
			cout << "event processed" << endl;
			eventHandler = nullptr;
		}

		else
		{
			this->overflowStack.Insert(eventHandler);
			eventHandler = nullptr;
		}
	}

	else //process departure 
	{
		++this->serverAvailableCnt;
		ProcessStatistics(eventHandler);
		if(!overflowStack.IsEmpty())
		{
			eventHandler = this->overflowStack.PopHeader();
			eventHandler->SetStartOfServT(this->lastDepartureTime);
			float interval = GetNextRandomInterval((mu * 1.0));
			eventHandler->SetDepartT((eventHandler->GetStartOfServT() + interval));
			this->lastDepartureTime = eventHandler->GetDepartT();
			eventQueue.Insert(eventHandler);
			--this->serverAvailableCnt;
		}
		eventHandler = nullptr;
	}
	eventHandler = nullptr;
}

float CustServiceSim::GetNextRandomInterval(float avg)
{
	std::random_device rand;
	std::mt19937 gen(rand());
	std::uniform_real_distribution<float> distribute(0.0, 1.0);

	return (-1 * (1.0/avg) * log(distribute(gen)));
}

void CustServiceSim::ProcessStatistics(Customer* leavingCustomer)
{
	if(this->currentWaitTime > 0)
	{
		++this->customerWaitedCnt;
		this->totalWaitTime += this->currentWaitTime;
		this->serviceTime += (leavingCustomer->GetDepartT() - leavingCustomer->GetStartOfServT());
		if(this->serverAvailableCnt == m)
		{
			this->idleTime += (leavingCustomer->GetStartOfServT() - this->lastDepartureTime);
		}
	}
}

void CustServiceSim::PrintResults()
{
	cout << "Analytical Model:" << endl;
	cout << "Percent idle time (Po) = "; 
	cout << this->idleTime << endl;

	cout << "Average time a customer spends in the system (W) = ";
	cout << this->serviceTime + this->totalWaitTime << endl;

	cout << "Average time a customer spends in the queue (Wq) = ";
	cout << (this->serviceTime + this->totalWaitTime) - (1/(this->mu * 1.0)) << endl;

	cout << "Utilization Factor (ρ) = ";
	cout << this->l/(this->m * (mu*1.0)) << endl;
	
	cout << "Probability of having to wait =";
	cout << this->customerWaitedCnt/this->totalEvents << endl;
}
