#include "AnalyticalModel.hpp"

/***************************************************************
 *      Student Name: Wilver Santos
 *      File Name: AnalyticalModel.cpp
 *      Assignment number: Project 2
 *
 *      Other comments regarding the file - AnalyticalModel.cpp implements methods and variables
 *      defined in AnalyticalModel.hpp
 *
 ***************************************************************/


float AnalyticalModel::CalcFactorial(int sumNum)
{
	int result = -1111;
	if(sumNum > -1)
	{
		result = 1.0;

		for(int i = 1; i <= sumNum; ++i)
		{
			result *= i;
		}

	}

	return result;
}

float AnalyticalModel::CalcPo(int m, int mu, int l)
{
	float sum;
	float result;

	for(int i = 0; i < m; ++i)
	{
		sum += ((1 / CalcFactorial(i) ) * pow( l / mu, i) );
	}

	result = 1 / ( sum + ( (1 / CalcFactorial(m) ) * pow(l / mu,m) * ( (m * mu) / ( (m * mu) -l ))));

	return result;
}

float AnalyticalModel::CalcAvgCustInSys(int m, int mu, int l)
{
	float result;

	result = (( ( (l * mu) * pow(l / mu,m)) / (CalcFactorial(m - 1) * pow( (m * mu) - l, 2)) ) * CalcPo(m,mu,l)) + (l/mu);

	return result;
}

float AnalyticalModel::CalcAvgCustTInSys(int m, int mu, int l)
{
	return CalcAvgCustInSys(m,mu,l) / l;
}

float AnalyticalModel::CalcAvgCustInQueue(int m, int mu, int l)
{
	return CalcAvgCustInSys(m,mu,l) - (l / mu); 
}

float AnalyticalModel::CalcAvgCustTInQueue(int m, int mu, int l)
{
	return CalcAvgCustInQueue(m,mu,l) / l;
}

float AnalyticalModel::CalcUtilFactor(int m, int mu, int l)
{
	return l / (m * mu);
}
