#include "idopont.h"
#include "racionalis.h"
#include <iomanip>

idopont::idopont() :o(0), p(0), m(0) {}

idopont::idopont(int sec)
{
    sec = sec % 86400;

    if (sec < 0)
    {
        sec += 86400;
    }
    o = sec / 3600;
    p = (sec % 3600) / 60;
    m = sec % 60;
}

idopont::idopont(int ora, int perc)
{
    o = ora;
    p = perc;
    m = 0;
}

idopont::idopont(int ora, int perc, int masodperc)
{
    o = ora;
    p = perc;
    m = masodperc;
}

ostream& operator<<(ostream& os, idopont p)
{
    //00:00:23
    os << setfill('0') << setw(2) << p.o << ":";
    os << setfill('0') << setw(2) << p.p << ":"; 
    os << setfill('0') << setw(2) << p.m;

    return os;
}

idotartam idopont::operator-(idopont i)
{
    idotartam idotartam(GetSec() - i.GetSec());
    return idotartam;
}

/*idopont idopont::operator+(idopont i)
{
    return idopont(i.GetSec() + GetSec());
}*/

idopont idopont::operator+(idotartam i)
{
    return idopont(i.GetTartam() + GetSec());
}

idopont idopont::operator-(idotartam i)
{
    return idopont(GetSec() - i.GetTartam());
}

int idopont::GetSec()
{
    return o * 3600 + p * 60 + m;
}