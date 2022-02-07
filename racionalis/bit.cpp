#include <iostream>
#include "bit.h"

bit::bit(bool v)
{
	//cout << "jo constructor" << v << " ";
	value = v;
}

bit::bit(int v)
{
	//cout << "masik constructor" << v << " ";
	value = (v != 0);
}

bit::bit(racionalis v)
{
	value = !v.IsNull();
}

bool bit::GetValue()
{
	return value;
}

int bit::GetIntValue()
{
	if (value)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void bit::SetValue(bool v)
{
	value = v;
}

bit bit::operator&(bit b)
{
	return bit(b.GetValue() && value);
}

bit bit::operator|(bit b)
{
	return bit(b.GetValue() || value);
}

bit bit::operator~()
{
	return bit(!value);
}


bit bit::operator^(bit b)
{
	return bit(value != b.GetValue());
}