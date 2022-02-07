#pragma once
#include <iostream>
#include "racionalis.h"
#include <list>
#include "idotartam.h"
#include <vector>
using namespace std;

class idotartam;

class idopont
{
	private:
		int o;
		int p;
		int m;

	public:
		idopont();
		idopont(int sec);
		idopont(int ora, int perc);
		idopont(int ora, int perc, int masodperc);
		friend ostream& operator<<(ostream& os, idopont p);
		//idopont operator+(idopont i);
		idotartam operator-(idopont i);
		idopont operator+(idotartam i);
		idopont operator-(idotartam i);
		int GetSec();
};

//print operator overload
ostream& operator<<(ostream& os, idopont p);