#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

/***************************************************************
 *	Student Name: Wilver Santos
 *	File Name: Customer.hpp
 *	Assignment number: Project 2
 *
 *      Other comments regarding the file - Customer.hpp defines variables
 *      and methods used to record information about customers for storage
 *      in a heap.
 *
 ***************************************************************/

class Customer
{
	private:
	float arrivalTime;
	float startOfServiceTime;
	float departureTime;
	Customer* nextCustomer;

	public:
	Customer(float someTime);
	void SetArrivalT(float someTime);
	void SetStartOfServT(float someTime);
	void SetDepartT(float someTime);
	void SetNext(Customer* someCust);
	float GetArrivalT();
	float GetStartOfServT();
	float GetDepartT();
	Customer* GetNext();
};

#endif
