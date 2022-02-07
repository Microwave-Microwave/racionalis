#include "teglalap.h"

using namespace std;

teglalap::teglalap(racionalis a1, racionalis b1)
{
	a = a1;
	b = b1;
}

racionalis teglalap::GetKerulet()
{
	return a * 2 + b * 2;
}

racionalis teglalap::GetTerulet()
{
	return a * b;
}