#include "BigInt.h"
#include <vector>
#include <string>

BigInt::BigInt(string s)
{
	ertek = s;
}

BigInt::BigInt(int x)
{
	ertek = std::to_string(x);
}

string BigInt::GetString()
{
	return ertek;
}

BigInt BigInt::operator++()
{
	string ertek2 = ertek;
	for (int i = ertek.size() - 1; i >= 0; i--)
	{
		if (ertek[i] != '9')
		{
			ertek[i] = ertek[i] + 1;//*
			//cout << "MEOW MEOW MEOW!" << endl;
			for (int j = i + 1; j < ertek.size(); j++)
			{
				ertek[j] = '0';
			}
			i = -1;
		}
	}
	if (ertek == ertek2)
	{
		ertek = "1";
		for (int i = 0; i < ertek2.size(); i++)
		{
			ertek += "0";
		}
	}
	return *this;
}

BigInt BigInt::operator++(int)
{
	BigInt ret = *this;
	this->operator++();
	return ret;
}

void BigInt::Duplazas()
{
	string ertek2 = ertek;
	int maradek = 0;
	for (int i = ertek.size() - 1; i >= 0; i--)
	{
		int szam = ertek[i] - '0';
		if (szam * 2 + maradek < 10)
		{ 
			ertek[i] = szam * 2 + maradek + '0';
			maradek = 0;
		}
		else
		{
			ertek[i] = szam * 2 + maradek - 10 +  '0';
			maradek = 1;
		}
	}
	if (maradek == 1)
	{
		ertek = "1" + ertek;
	}
}

BigInt BigInt::operator+(BigInt i)
{
	//cout << "i.get: " << i.GetString() << endl;
	int maradek = 0;
	string ertek1 = StringStretcher(i.GetString(), ertek);
	//cout << "stretcher1: " << ertek1 << endl;
	string ertek2 = StringStretcher(ertek, i.GetString());
	//cout << "stretcher2: " << ertek2 << endl;

	string eredmeny = "";
	//cout << "ertek1: " << ertek1 <<endl;
	//cout << "ertek2: " << ertek2 << endl;

	for (int j = ertek1.size() - 1; j >= 0; j--)
	{
		int szam1 = ertek1[j] - '0';
		int szam2 = ertek2[j] - '0';

		//cout << "syam1: " << szam1 << endl;
		//cout << "szam2: " << szam2 << endl;
		//cout << "ossyeadas: " << szam1 + szam2 + maradek << endl;

		if (szam1 + szam2 + maradek < 10)
		{
			eredmeny += (szam1 + szam2 + maradek + '0');
			
			maradek = 0;
		}
		else
		{
			eredmeny += (szam1 + szam2 + maradek - 10 + '0');
			maradek = 1;
		}
		//cout << "maradek: " << maradek << " ";
		//cout << "eredmenz: " << eredmeny << endl;
	}
	if (maradek == 1)
	{
		//cout << "jaj ne";
		eredmeny += "1";
	}
	//cout << eredmeny << endl;
	return BigInt(ReverseString(eredmeny));
	//return BigInt("9999");
}
BigInt BigInt::operator+(int i)
{
	//cout << std::to_string(1) << " " << BigInt(std::to_string(1)) << endl;
	return (BigInt(ertek) + BigInt(std::to_string(i)));
}

BigInt BigInt::operator-(BigInt i)
{
	//(this - i)
	//(ertek1 - ertek2)
	//956
	//012
	//944
	int maradek = 0;
	string ertek1 = StringStretcher(ertek, i.GetString());
	//cout << "stretcher1: " << ertek1 << endl;
	string ertek2 = StringStretcher(i.GetString(), ertek);
		
	//cout << "stretcher2: " << ertek2 << endl;
	if (ertek1 == ertek2)
	{
		return BigInt("0");
	}
	string eredmeny = "";
	for (int j = ertek1.length()-1; j >= 0; j--)
	{
		//2				6
		if (ertek2[j] + maradek <= ertek1[j])
		{
			eredmeny = (char)(ertek1[j] - (ertek2[j] + maradek) + '0') + eredmeny;
			maradek = 0;
		}
		else
		{
			eredmeny = (char)(10 + ertek1[j] - (ertek2[j] + maradek) + '0') + eredmeny;
			maradek = 1;
		}

	}
	if (eredmeny[0] == '0')
	{
		eredmeny = eredmeny.substr(1, eredmeny.length() - 1);
	}

	return BigInt(eredmeny);
}

BigInt BigInt::operator*(BigInt i)
{
	int maradek = 0;
	string ertek1 = ertek;
	string ertek2 = i.GetString();

	//cout << "ertek1: " << ertek1 << endl;
	//cout << "ertek2: " << ertek2 << endl;

	//string eredmeny = "";
	
	std::vector<BigInt> eredmeny_vektor;

	for (int j = ertek2.length() - 1; j >= 0; j--)
	{
		BigInt reszeredmeny = BigInt(ertek1) * (int)(ertek2[j] - '0');
		//cout << "reszeredmeny::::" << (int)(ertek2[j] - '0') << endl;
		string add = "";
		for (int k = 0; k < ertek2.length() - 1 - j; k++)
		{
			add += "0";
		}
		reszeredmeny = BigInt(reszeredmeny.GetString() + add);
		eredmeny_vektor.push_back(reszeredmeny);
		//cout << "(ertek2[j] - '0') ---> " << (ertek2[j]) << endl;
		//cout << "reszeredmeny: " << reszeredmeny.GetString() << endl;
	}
	BigInt eredmeny = eredmeny_vektor[0];
	for (int j = 1; j < eredmeny_vektor.size(); j++)
	{
		//cout << "smilez: " << eredmeny_vektor[j].GetString() << endl;
		//cout << "+: " << (eredmeny + eredmeny_vektor[j]).GetString() << endl;
		eredmeny = eredmeny + eredmeny_vektor[j];
		//cout << "eredmeny: " << eredmeny.GetString() << endl;
	}
	

	return eredmeny;
}
BigInt BigInt::operator*(int i)
{
	if (i == 0 || ertek == "0")
	{
		return BigInt("0");
	}
	BigInt original_ertek(ertek);
	BigInt eredmeny(ertek);
	for (int j = 1; j < i; j++)
	{
		//cout << "megtortent" << endl;
		//cout << eredmeny.GetString() << endl;
		//cout << original_ertek.GetString() << endl;

		eredmeny = eredmeny + original_ertek;
	}
	return eredmeny;
}

BigInt BigInt::operator/(BigInt i)
{
	int maradek = 0;
	string osztando = ertek;
	string oszto = i.GetString();

	//cout << "ertek1: " << osztando << endl;
	//cout << "ertek2: " << oszto << endl;

	string resz_osztando = "";
	string eredmeny = "";

	for (int j = 0; j < osztando.length(); j++)
	{
		bool without_is_big = true;
		resz_osztando += ertek[j];
		//cout << "reszosztando: " << resz_osztando << endl; //3
		if (resz_osztando[0] == '0')
		{
			string without = resz_osztando.substr(1, resz_osztando.length() - 1);
			if (BigInt(oszto) <= BigInt(without))
			{
				resz_osztando = without;
			}
			else
			{
				without_is_big = false;
				eredmeny += "0";
				resz_osztando = without;
			}
			
		}
		if (BigInt(oszto) <= BigInt(resz_osztando) && without_is_big)
		{
			int kis_eredmeny = BigInt(resz_osztando).SimpleDivision(BigInt(oszto)); //3
			//cout << "kis eredmény: " << kis_eredmeny << endl;
			eredmeny += (char)(BigInt(resz_osztando).SimpleDivision(BigInt(oszto)) + '0');
			resz_osztando = (BigInt(resz_osztando) - (BigInt(oszto) * kis_eredmeny)).GetString();
		}
	}
	return BigInt(eredmeny);
}

BigInt BigInt::operator%(BigInt i)
{
	int maradek = 0;
	string osztando = ertek;
	string oszto = i.GetString();

	//cout << "ertek1: " << osztando << endl;
	//cout << "ertek2: " << oszto << endl;

	string resz_osztando = "";
	string eredmeny = "";

	for (int j = 0; j < osztando.length(); j++)
	{
		resz_osztando += ertek[j];
		if (BigInt(oszto) <= BigInt(resz_osztando))
		{
			int kis_eredmeny = BigInt(resz_osztando).SimpleDivision(BigInt(oszto));
			eredmeny += (char)(BigInt(resz_osztando).SimpleDivision(BigInt(oszto)) + '0');
			resz_osztando = (BigInt(resz_osztando) - (BigInt(oszto) * kis_eredmeny)).GetString();
		}
	}
	return BigInt(resz_osztando);
}

BigInt BigInt::Plusz10Szazalek()
{
	string s = this->GetString();
	if (2 <= s.length())
	{
		return BigInt(s.substr(0, s.length() - 1)) + *this;
	}
	else
	{
		return *this;
	}
}

BigInt sqrt(BigInt num)
{
	//BigInt valasz = num;

	//9
	//min 1 max 9
	//proba 1 + 9 ) / 2 = 5
	//1 min max 4
	// proba 3

	if (num <= 1000000000)
	{
		return (int)ceil(sqrt(atoi(num.GetString().c_str())));
	}
	else
	{
		BigInt min = BigInt("1");
		BigInt max = num;
		BigInt proba = (min + max) / 2;

		BigInt numplusz10szazalek = num.Plusz10Szazalek();

		BigInt product = proba * proba;
		while (!(num <= product + 1 && product <= numplusz10szazalek) && min <= max)
		{
			//cout << "min, max, proba, num, num10: " << min << " " << max << " " << proba << " " << num << " " << numplusz10szazalek << endl;
			if (product <= num)
			{
				min = proba + 1;
			}
			else
			{
				max = proba - 1;
			}
			proba = (min + max) / 2;
			product = proba * proba;
		}
		if (max <= min + 1)
		{
			return min;
		}
		return proba;
	}
}

BigInt sqrtOld(BigInt num)
{
	BigInt valasz = num;
	BigInt valasz_kicsi = BigInt("0");
	BigInt valasz_nagy = BigInt("0");

	for (BigInt i = BigInt("0"); i <= num; i++)
	{
		if (num <= i * i)
		{
			valasz_nagy = i;
			valasz_kicsi = i - BigInt("1");
			i = num + BigInt("1");
		}
	}

	if (valasz_nagy * valasz_nagy - num <= num - valasz_kicsi * valasz_kicsi)
	{
		valasz = valasz_nagy;
	}
	else
	{
		valasz = valasz_kicsi;
	}

	return valasz;
}

bool BigInt::IsPrimeNew()
{
	if ((*this / BigInt("2") * BigInt("2") == *this))
	{
		return false;
	}
	BigInt sqrtNum = sqrt(*this);
	for (BigInt i = BigInt("3"); i <= sqrtNum; i = BigInt("2") + i)
	{
		//cout << "i: " << i << " this/i: " << *this / i << " *this: " << *this << endl;
		if (i * (*this / i) == *this)
		{
			return false;
		}
	}
	return true;
}

bool BigInt::IsPrime()
{
	for (BigInt i = BigInt("2"); i <= sqrt(*this); i++)
	{
		if (i * (*this / i) == *this)
		{
			return false;
		}
	}
	return true;
}

bool BigInt::IsPrimeOld()
{
	for (BigInt i = BigInt("2"); i <= *this/BigInt("2"); i++)
	{
		if (i * (*this / i) == *this)
		{
			return false;
		}
	}
	return true;
}

string BigInt::StringStretcher2(string s1, string s2)
{
	const int s1_len = s1.length();
	const int s2_len = s2.length();

	if (s1_len < s2_len)
	{
		string a = "";
		for (int i = 0; i < s2_len - s1_len; i++)
		{
			a += "0";
		}
		s1 = a + s1;
	}
	return s1;
}

string BigInt::StringStretcher(string s1, string s2)
{
	const int s1_len = s1.length();
	const int s2_len = s2.length();

	if (s1_len < s2_len)
	{
		s1.insert(0, s2_len - s1_len, '0');
	}
	return s1;
}

string BigInt::StringStretcher3(string s1, string s2)
{
	const int s1_len = s1.length();
	const int s2_len = s2.length();
	//cout << "s1 len " << s1_len << " s1: " << s1 << endl;
	//cout << "s2 len " << s2_len << " s2: " << s2 << endl;

	if (s1_len < s2_len)
	{
		//cout << ":(((" << endl;
		//cout << ":)))" << endl;

		string a = "";
		for (int i = 0; i < s2_len - s1_len; i++)
		{
			a += "0";
		}
		s1 = a + s1;

	}
	//cout << "nice: " << s1 << endl;
	return s1;
}

string BigInt::ReverseString(string s)
{
	string s1 = "";
	for (int i = s.length()-1; i >= 0; i--)
	{
		s1 += s[i];
	}
	return s1;
}

bool BigInt::operator<=(BigInt i)
{
	string ertek1 = ertek;
	string ertek2 = i.GetString();

	if (ertek1.length() < ertek2.length())
	{
		return true;
	}
	else if (ertek1.length() > ertek2.length())
	{
		return false;
	}
	else //egyenlo hosszuak
	{
		//cout << "ertek1: [" << ertek1 << "] ertek2: [" << ertek2 << "]" << (ertek1<=ertek2) << endl;
		return ertek1 <= ertek2;
		/*
		for (int i = 0; i < ertek1.length(); i++)
		{
			if (ertek1[i] < ertek2[i])
			{
				return true;
			}
			if (ertek1[i] > ertek2[i])
			{
				return false;
			}
		}
		return true;
		*/
	}
}

bool BigInt::operator==(BigInt i)
{
	string ertek1 = ertek;
	string ertek2 = i.GetString();
	
	if (ertek1.length() == ertek2.length())
	{
		for (int j = 0; j < ertek1.length(); j++)
		{
			if (ertek1[j] != ertek2[j])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

int BigInt::SimpleDivision(BigInt i)
{
	int eredmeny = 0;
	int oszto = atoi(i.GetString().c_str());
	int osztando = atoi(this->GetString().c_str());

	/*
	for (int j = 1; j < 10; j++)
	{
		//cout << *this << " <= " << i << " * " << j << endl;
		if (*this <= i * j)
		{
			if (i * j == *this)
			{
				eredmeny = j;
			}
			return eredmeny;
		}
		eredmeny = j;
	}
	*/
	eredmeny = osztando / oszto;
	return eredmeny;
}

void BigInt::TestCases()
{
	int loop = 100;

	//ADDITION
	cout << "///Addition Test///" << endl;
	BigInt a = BigInt("1");
	BigInt b = BigInt("1");
	bool addition_test = true;

	for (int i = 0; i < loop; i++)
	{
		int a_ = i;
		int b_ = i * 3;
		a = BigInt(std::to_string(a_));
		b = BigInt(std::to_string(b_));
		if ((a + b).GetString() != to_string(a_ + b_))
		{
			cout << "Addition Failed because:" << endl;
			cout << a_ << " + " << b_ << " = " << a_ + b_ << endl;
			cout << a << " + " << b << " = " << a + b << endl;
			addition_test = false;
			i = loop;
		}
	}
	if (addition_test)
		cout << "-succsessful" << endl;
	else
		cout << "-failed" << endl;

	//SUBTRACTION
	cout << "///Subtraction Test//" << endl;
	a = BigInt("1");
	b = BigInt("1");
	bool subtraction_test = true;

	for (int i = 0; i < loop; i++)
	{
		int a_ = i * 3;
		int b_ = i;
		a = BigInt(std::to_string(a_));
		b = BigInt(std::to_string(b_));
		if ((a - b).GetString() != to_string(a_ - b_))
		{
			cout << "Subtraction Failed because:" << endl;
			cout << a_ << " - " << b_ << " = " << a_ - b_ << endl;
			cout << a << " - " << b << " = " << a - b << endl;
			subtraction_test = false;
			i = loop;
		}
	}
	if (subtraction_test)
		cout << "-succsessful" << endl;
	else
		cout << "-failed" << endl;

	//MULTIPLICATION
	cout << "///Multiplication Test//" << endl;
	a = BigInt("1");
	b = BigInt("1");
	bool multiplication_test = true;

	for (int i = 0; i < loop; i++)
	{
		int a_ = i * 3;
		int b_ = i;
		a = BigInt(std::to_string(a_));
		b = BigInt(std::to_string(b_));
		if ((a * b).GetString() != to_string(a_ * b_))
		{
			cout << "Multiplication Failed because:" << endl;
			cout << a_ << " * " << b_ << " = " << a_ * b_ << endl;
			cout << a << " * " << b << " = " << a * b << endl;
			multiplication_test = false;
			i = loop;
		}
	}
	if (multiplication_test)
		cout << "-succsessful" << endl;
	else
		cout << "-failed" << endl;

	
	//DIVISION
	cout << "///Division Test//" << endl;
	a = BigInt("1");
	b = BigInt("1");
	bool division_test = true;

	for (int i = 3; i < loop; i++)
	{
		int a_ = i;
		int b_ = 3;
		a = BigInt(std::to_string(a_));
		b = BigInt(std::to_string(b_));
		if ((a / b).GetString() != to_string(a_ / b_))
		{
			cout << "Division Failed because:" << endl;
			cout << "int: " << a_ << " / " << b_ << " = " << a_ / b_ << endl;
			cout << "BigInt: " << a << " / " << b << " = " << a / b << endl;
			division_test = false;
			i = loop;
		}
	}
	if (division_test)
		cout << "-succsessful" << endl;
	else
		cout << "-failed" << endl;
		
	//SQRT
	cout << "///SQRT Test//" << endl;
	a = BigInt("1");
	bool sqrt_test = true;

	for (int i = 3; i < loop; i++)
	{
		int a_ = i;
		a = BigInt(std::to_string(a_));
		BigInt string_1 = BigInt(to_string((int)(round(sqrt(a_)))));
		BigInt string_2 = sqrt((a));
		if (!(string_1 <= string_2))
		{
			cout << "SQRT Failed because:" << endl;
			cout << "int: " << a_ << " sqrt = [" << string_1 << "]" << endl;
			cout << "BigInt: " << a << " sqrt = [" << string_2 << "]" << endl;
			sqrt_test = false;
			i = loop;
		}
	}
	if (sqrt_test)
		cout << "-succsessful" << endl;
	else
		cout << "-failed" << endl;
}

ostream& operator<<(ostream& os, BigInt bi)
{
	os << bi.GetString();

	return os;
}