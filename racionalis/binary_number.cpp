#include "binary_number.h"
#include "bit.h"
#include <iostream>

binary_number::binary_number(vector<bit> v)
{
	vect = v;
}

binary_number::binary_number(int r)
{
	vector<bit> v;
	int szam = r;

	while (szam != 0)
	{
		if (szam %2 == 0)
		{
			
			v.push_back(bit(false));
			//cout << "0";
		}
		else
		{
			v.push_back(bit(true));
			//cout << "1";
		}
		szam = szam / 2;
	}
	vect = v;
}

binary_number::binary_number(string s)
{
	//"89564823768472678"
	vector<bit> vect;
	int maradek = 0;
	string check = "";
	for (int i = 0; i < s.length(); i++)
	{
		check += "0";
	}
	while (s != check)
	{
		s = Felezes(s);
		//cout << "string s = " << s << endl;
	}
}
string binary_number::Felezes(string s)
{
	string output = "";
	int maradek = 0;
	for (int i = 0; i < s.size(); i++)
	{
		maradek *= 10;
		maradek += s[i] - '0';
		output += (char)( maradek / 2 + '0');
		maradek = maradek % 2;
	}
	//cout << "string: " << s << endl;
	//cout << "maradek: " << maradek << endl;
	vect.push_back(bit(maradek));
	return output;
}

vector<bit> binary_number::GetVect()
{
	return vect;
}

ostream& operator<<(ostream& os, binary_number b)
{
	//cout << "vector size :" << b.GetVect().size() << endl;
	for (int i = b.GetVect().size()-1; i >= 0; i--)
	{
		if (b.GetVect().at(i).GetValue())
		{
			
			os << "1";
		}
		else
		{
			os << "0";
		}
	}

	return os;
}

int binary_number::GetIntValue()
{
	int n = 0;
	//cout << "vect isize: " << vect.size() << endl;
	for (int i = 0; i < vect.size(); i++)
	{
		if (vect.at(i).GetValue())
		{
			n += pow(2, i);
			//cout << "no";
		}
	}
	return n;
}

binary_number binary_number::operator+(binary_number jobb)
{
	vector<bit> vect;
	int maradek = 0;
	int n;

	for (int i = 0; i < jobb.GetVect().size(); i++)
	{
		n = maradek + GetBit(i) + jobb.GetBit(i);
		if (n == 0)
		{
			vect.push_back(bit(0));
			maradek = 0;
		}
		else if (n == 1)
		{
			vect.push_back(bit(1));
			maradek = 0;
		}
		else if (n == 2)
		{
			vect.push_back(bit(0));
			maradek = 1;
		}
		else if (n == 3)
		{
			vect.push_back(bit(1));
			maradek = 1;
		}
	}
	vect.push_back(maradek);
	return binary_number(vect);
}

int binary_number::GetBit(int n)
{
	if (n >= vect.size())
	{
		return 0;
	}
	else
	{
		return vect[n].GetIntValue();
	}
}