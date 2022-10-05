#include "ServiceCenter.hpp"

/***************************************************************
 *      Student Name: Wilver Santos
 *      File Name: ServiceCenter.cpp
 *      Assignment number: Project 2
 *
 *      Other comments regarding the file - ServiceCenter.cpp implements methods and variables
 *      defined in the ServiceCenter.hpp
 *
 ***************************************************************/

int ServiceCenter::run()
{
	cout << "Starting system...\n\nQUEUE SIMULATION ENVIORNMENT V 1.0" << endl << endl;
        cout << "Please enter the number of arrivals to simulate (this mus be within the range of 1000-5000): ";
	cin >> this->numArrivals;

	if(this->numArrivals < 1000 || this->numArrivals > 5000)
	{
		cout << "\nERROR: Sample size is invalid." << endl;
		return -1;
	}

	cout << "\n\nPlease enter the average arrivals in a time period: ";
	cin >> this->avgArrivalsInTPeriod;

	if(this->avgArrivalsInTPeriod < 1)
	{
		cout << "\nERROR: invalid input." << endl;
	}

	cout << "\n\nPlease enter the average number served in a time period: ";
	cin >> this->avgNumServedInTPeriod;
	if(this->avgArrivalsInTPeriod < 1)
	{
		cout << "\nERROR: invalid input." << endl;
	}
	
	cout << "\n\nPlease enter the number of service channels(must be within the range 1-10): ";
	cin >> this->numServChannel;
	
	if(this->numServChannel < 1 || this->numServChannel > 10)
	{
		cout << "\nERROR: invalid input." << endl;
							       
	}

	cout << "Data gathered, calculating data..." << endl << endl;

	return 0;
}
