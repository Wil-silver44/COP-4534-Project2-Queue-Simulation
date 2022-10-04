#include "Customer.hpp"

/***************************************************************
 *	Student Name: Wilver Santos
 *	File Name: Customer.cpp
 *	Assignment number: Project 2
 *
 *      Other comments regarding the file - Customer.cpp implements the variables and methods
 *	defined by the Customer class.
 *
 ***************************************************************/

Customer::Customer(float someTime)
{
	SetArrivalT(someTime);
	this->startOfServiceTime = -333;
	this->departureTime = -333;	
}

void Customer::SetArrivalT(float someTime)
{ this->arrivalTime = someTime; }

void Customer::SetStartOfServT(float someTime)
{ this->startOfServiceTime = someTime; }

void Customer::SetDepartT(float someTime)
{ this->departureTime = someTime; }

float Customer::GetArrivalT()
{ return this->arrivalTime; }

float Customer::GetStartOfServT()
{ return this->startOfServiceTime; }

float Customer::GetDepartT()
{ return this->departureTime; }


