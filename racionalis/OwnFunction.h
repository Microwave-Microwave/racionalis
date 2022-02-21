#pragma once
#include <vector>
#include <iostream>
using std::vector;

class OwnFunction
{
	vector<double> x_values;
	vector<double> y_values;

public:
	OwnFunction(vector<double> x, vector<double> y);
	OwnFunction(double x1, double x2, double x3, double y1, double y2, double y3);

	void GetFunctionVertex();
	void ThreePointFunction();
	vector<double> GetABC();
	double GetValue(double x);
};