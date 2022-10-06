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
	float castMu = (mu * 1.0);
	float sum;
	float result;

	for(int i = 0; i < m; ++i)
	{
		sum += ((1 / CalcFactorial(i) ) * pow( l / castMu, i) );
	}

	result = 1 / sum + ( ( (1 / CalcFactorial(m)) * pow((l / castMu),m) * ( (m * mu) / ( (m * castMu) -l ))));

	return result;
}

float AnalyticalModel::CalcAvgCustInSys(int m, int mu, int l)
{
	float result;
	float castMu = (mu * 1.0);
	float b = (l / castMu);
	float c = ((m * castMu) - l );

	result = (  ( (l * mu) * pow(b,m) ) / (CalcFactorial( (m - 1) ) *  pow(c,2)) ) * CalcPo(m, mu, l) + b;

	return result;
}

float AnalyticalModel::CalcAvgCustTInSys(int m, int mu, int l)
{
	return CalcAvgCustInSys(m,mu,l) / (l * 1.0);
}

float AnalyticalModel::CalcAvgCustInQueue(int m, int mu, int l)
{
	return CalcAvgCustInSys(m,mu,l) - (l / (mu * 1.0)); 
}

float AnalyticalModel::CalcAvgCustTInQueue(int m, int mu, int l)
{
	return CalcAvgCustInQueue(m,mu,l) / (l / 1.0);
}

float AnalyticalModel::CalcUtilFactor(int m, int mu, int l)
{
	return l / (m * (mu * 1.0));
}
