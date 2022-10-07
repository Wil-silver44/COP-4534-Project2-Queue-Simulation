#ifndef SERVICECENTER_HPP
#define SERVICECENTER_HPP
#include <iostream>
#include "AnalyticalModel.hpp"
#include "CustServiceSim.hpp"

/***************************************************************
 *      Student Name: Wilver Santos
 *      File Name: ServiceCenter.hpp
 *      Assignment number: Project 2
 *
 *      Other comments regarding the file - ServiceCenter.hpp implements methods and variables
 *      to run the classes created for simulating a customer service queue system.
 *
 ***************************************************************/

using std::cout;
using std::cin;
using std::endl;

class ServiceCenter
{
	private:
	AnalyticalModel simulationAnalyzer;
	int numArrivals;
	int avgArrivalsInTPeriod;
	int avgNumServedInTPeriod;
	int numServChannel;

	public:
	int run();

};

#endif
