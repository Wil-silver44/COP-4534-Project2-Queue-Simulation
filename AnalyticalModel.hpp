#ifndef ANALYTICALMODEL_HPP
#define ANALYTICALMODEL_HPP
#include <cmath>

/***************************************************************
 *      Student Name: Wilver Santos
 *      File Name: AnalyticalModel.hpp
 *      Assignment number: Project 2
 *
 *      Other comments regarding the file - AnalyticalModel.hpp defines methods and variables
 *      for calculating data regarding service in the simulation.
 *
 ***************************************************************/

class AnalyticalModel
{
	private:
		float CalcFactorial(int someNum);
	
	public:
		float CalcPo(int m, int mu, int l);
		float CalcAvgCustInSys(int m, int mu, int l);
		float CalcAvgCustTInSys(int m, int mu, int l);
		float CalcAvgCustInQueue(int m, int mu, int l);
		float CalcAvgCustTInQueue(int m, int mu, int l);
		float CalcUtilFactor(int m, int mu, int l);

};

#endif
