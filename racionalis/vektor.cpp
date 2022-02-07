#include "vektor.h"
#include <iostream>

using namespace std;

vektor::vektor(std::vector<racionalis> kordinatak1)
{
	while (kordinatak1.size() < 2)
	{
		kordinatak1.push_back(0);
	}
	
	kordinatak = kordinatak1;
}

std::vector<racionalis> vektor::GetKordinatak()
{
	return kordinatak;
}

void vektor::PrintAllCoordinatesl()
{
	for (int i = 0; i < kordinatak.size(); i++)
	{
		cout << i + 1 << ". kordinata: " << kordinatak.at(i).ertek() << "    ";
	}
	cout << endl;
}

vektor vektor::Add(vektor v)
{
	std::vector<racionalis> kordinatak_t;

	for (int i = 0; i < kordinatak.size(); i++)
	{
		racionalis r = kordinatak.at(i) + v.GetKordinatak().at(i);
		kordinatak_t.push_back(r);
	}
	
	return vektor(kordinatak_t);
}

vektor vektor::Minusz(vektor v)
{
	std::vector<racionalis> kordinatak_t;

	for (int i = 0; i < kordinatak.size(); i++)
	{
		racionalis r = kordinatak.at(i) - v.GetKordinatak().at(i);
		kordinatak_t.push_back(r);
	}

	return vektor(kordinatak_t);
}

racionalis vektor::SkallarSzorzat(vektor v)
{
	racionalis eredmeny = 0;

	for (int i = 0; i < kordinatak.size(); i++)
	{
		racionalis r = kordinatak.at(i) * v.GetKordinatak().at(i);
		eredmeny = eredmeny + r;
	}
	return eredmeny;
}

vektor vektor::operator+(vektor b)
{
	return Add(b);
}

vektor vektor::operator-(vektor b)
{
	return Minusz(b);
}

racionalis vektor::operator*(vektor b)
{
	return SkallarSzorzat(b);
}

tervektor tervektor::operator%(tervektor b)
{
	return VektorialisSzorzat(b);
}

tervektor::tervektor(std::vector<racionalis> kordinatak1) : vektor(kordinatak1)
{
}

tervektor::tervektor(vektor v) : vektor(v.GetKordinatak())
{
	if (v.GetKordinatak().size() == 2)
	{
		kordinatak.push_back(0);
	}
}

tervektor tervektor::VektorialisSzorzat(tervektor v)
{
	// this = a; b = b 
	std::vector<racionalis> a = GetKordinatak();
	std::vector<racionalis> b = v.GetKordinatak();

	std::vector<racionalis> k;
	racionalis c1 = a.at(1) * b.at(2) - a.at(2) * b.at(1);
	racionalis c2 = a.at(2) * b.at(0) - a.at(0) * b.at(2);
	racionalis c3 = a.at(0) * b.at(1) - a.at(1) * b.at(0);

	k.push_back(c1);
	k.push_back(c2);
	k.push_back(c3);

	tervektor eredmeny = tervektor(k);
	return eredmeny;
}