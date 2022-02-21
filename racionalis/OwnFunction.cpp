#include "OwnFunction.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

OwnFunction::OwnFunction(vector<double> x, vector<double> y)
{
	x_values = x;
	y_values = y;
}

OwnFunction::OwnFunction(double x1, double x2, double x3, double y1, double y2, double y3)
{
	x_values.push_back(x1);
	x_values.push_back(x2);
	x_values.push_back(x3);
	y_values.push_back(y1);
	y_values.push_back(y2);
	y_values.push_back(y3);

}

void OwnFunction::ThreePointFunction()
{
	vector<double> x_values2;
	vector<double> y_values2;

	x_values2.push_back(x_values[0]);
	x_values2.push_back(x_values[x_values.size()/2]);
	x_values2.push_back(x_values[x_values.size() - 1]);

	y_values2.push_back(y_values[0]);
	y_values2.push_back(y_values[y_values.size() / 2]);
	y_values2.push_back(y_values[y_values.size() - 1]);

	x_values = x_values2;
	y_values = y_values2;
}

void OwnFunction::GetFunctionVertex()
{
	double x1 = x_values[0];
	double x2 = x_values[1];
	double x3 = x_values[2];

	double y1 = y_values[0];
	double y2 = y_values[1];
	double y3 = y_values[2];

	double denom = (x1 - x2) * (x1 - x3) * (x2 - x3);
	double A = (x3 * (y2 - y1) + x2 * (y1 - y3) + x1 * (y3 - y2)) / denom;
	double B = (x3 * x3 * (y1 - y2) + x2 * x2 * (y3 - y1) + x1 * x1 * (y2 - y3)) / denom;
	double C = (x2 * x3 * (x2 - x3) * y1 + x3 * x1 * (x3 - x1) * y2 + x1 * x2 * (x1 - x2) * y3) / denom;

	double xv = -B / (2 * A);
	double yv = C - B * B / (4 * A);

	cout << "xv = " << xv << "    yv = " << yv << endl;
	//return 1;


}

vector<double> OwnFunction::GetABC()
{
	double x1 = x_values[0];
	double x2 = x_values[1];
	double x3 = x_values[2];

	double y1 = y_values[0];
	double y2 = y_values[1];
	double y3 = y_values[2];

	double denom = (x1 - x2) * (x1 - x3) * (x2 - x3);
	double A = (x3 * (y2 - y1) + x2 * (y1 - y3) + x1 * (y3 - y2)) / denom;
	double B = (x3 * x3 * (y1 - y2) + x2 * x2 * (y3 - y1) + x1 * x1 * (y2 - y3)) / denom;
	double C = (x2 * x3 * (x2 - x3) * y1 + x3 * x1 * (x3 - x1) * y2 + x1 * x2 * (x1 - x2) * y3) / denom;

	//cout << "A: " << A << " B: " << B << " C: " << C << endl;

	return vector<double> {A, B, C};
}

double OwnFunction::GetValue(double x)
{
	vector<double> abc = GetABC();
	double A = abc[0];
	double B = abc[1];
	double C = abc[2];

	return A * (x * x) + B * x + C;
}