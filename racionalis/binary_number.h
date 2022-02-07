#pragma once
#include <iostream>
#include <vector>
#include "bit.h"
#include "racionalis.h"

class binary_number
{
	private:
		vector<bit> vect;
	public:
		binary_number(vector<bit> v);
		binary_number(int r);
		binary_number(string s);
		string Felezes(string s);
		vector<bit> GetVect();
		friend ostream& operator<<(ostream& os, racionalis jobb);
		int GetIntValue();
		int GetBit(int n);
		binary_number operator+(binary_number jobb);
		 
};

//print operator overload
ostream& operator<<(ostream& os, binary_number b);

//befejezés binary number strong, összeadás funkció, nagy decimális szorgalmi
//my_vector = ugyan az mint a vector int (pushback, lekéárdezni, size al megmondani a méretét)
//(kétszerezős tömb)