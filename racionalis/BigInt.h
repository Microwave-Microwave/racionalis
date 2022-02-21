#pragma once
#include <iostream>
#include <vector>

using namespace std;

class BigInt
{
	//szorzas balrol jobbrol
	// ++ muvelet
	//
	private:
		string ertek;
	public:
		BigInt(string s);
		BigInt(int x);
		string GetString();
		BigInt operator++(); // prefix: ++a
		BigInt operator++(int); // postfix: a++
		void Duplazas();
		int StringToInt(string s);

		BigInt operator+(BigInt i);
		BigInt operator+(int i);
		BigInt operator-(BigInt i);
		BigInt operator*(BigInt i);
		BigInt operator*(int digit); //kicsi szorzas
		BigInt operator/(BigInt i);
		BigInt operator%(BigInt i);
		BigInt Plusz10Szazalek();
		friend BigInt sqrt(BigInt num);
		friend BigInt sqrtOld(BigInt num);
		bool IsPrime();
		bool IsPrimeNew();
		bool IsPrimeOld();
		string StringStretcher(string s1, string s2);
		string StringStretcher2(string s1, string s2);
		string StringStretcher3(string s1, string s2);
		string ReverseString(string s);
		bool operator<=(BigInt i);
		bool operator==(BigInt i);
		int SimpleDivision(BigInt i);

		//TESTS
		void TestCases();


		friend ostream& operator<<(ostream& os, BigInt bi);
};

BigInt approxsqrt(BigInt num);
ostream& operator<<(ostream& os, BigInt bi);

/*int tomb[10];
int x = 4;
tomb[x++] = 6;
tomb[++x] = 6;*/