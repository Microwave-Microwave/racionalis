#include "idotartam.h"
#include <iomanip>

idotartam::idotartam(int t)
{
	tartam = t;
}

idotartam::idotartam(int o, int p)
{
	tartam = o * 3600 + p * 60;
}

idotartam::idotartam(int o, int p, int m)
{
	tartam = o * 3600 + p * 60 + m;
}



/*idopont idotartam::GetKezdet()
{
	return kezdet;
}*/

int idotartam::GetTartam()
{
	return tartam;
}

int idotartam::GetOra()
{
	return tartam / 3600;
}

int idotartam::GetPerc()
{
	return tartam % 3600 / 60;
}

int idotartam::GetMasodperc()
{
	return tartam % 60;
}

idotartam idotartam::operator+(idotartam i)
{
	
	idotartam osszeg(i.GetTartam() + tartam);
	return osszeg;
}

idotartam idotartam::operator-(idotartam i)
{
	idotartam kulonbseg(i.GetTartam() - tartam);
	return kulonbseg;
}

idopont idotartam::operator+(idopont i)
{
	return idopont(i.GetSec() + tartam);
}

/*idopont idotartam::operator-(idopont i)
{
	return idopont(i.GetSec() - tartam);
}*/

ostream& operator<<(ostream& os, idotartam p)
{
	//00:00:23
	os << setfill('0') << setw(2) << p.GetOra() << ":";
	os << setfill('0') << setw(2) << p.GetPerc() << ":";
	os << setfill('0') << setw(2) << p.GetMasodperc();

	return os;
}

