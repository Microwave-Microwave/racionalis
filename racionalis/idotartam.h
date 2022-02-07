#pragma once
#include <iostream>
#include "racionalis.h"
#include <list>
#include <vector>
#include "idopont.h"
using namespace std;

class idopont;

class idotartam
{
	private:
		//idopont kezdet;
		int tartam;
	public:
		idotartam(int t);
		idotartam(int o, int p);
		idotartam(int o, int p, int m);
		//idopont GetKezdet();
		int GetTartam();
		int GetOra();
		int GetPerc();
		int GetMasodperc();
		idotartam operator+(idotartam i);
		idotartam operator-(idotartam i);
		idopont operator+(idopont i);
		//idopont operator-(idopont i);
		friend ostream& operator<<(ostream& os, idotartam p);
};

ostream& operator<<(ostream& os, idotartam p);