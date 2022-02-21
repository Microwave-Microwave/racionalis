#include <iostream>
#include "racionalis.h"
#include "teglalap.h"
#include "vektor.h"
#include "idopont.h"
#include "OwnFunction.h"
#include "binary_number.h"
#include "BigInt.h"
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <list>
#include <string>
#include <chrono> 
#include <cstdlib>

using namespace std;

int main()
{
    racionalis a = 10;
    racionalis b = 2;
    teglalap t = teglalap(a, b);
    /*racionalis* r = new racionalis(3, 4);
    int* pi = new int;
    delete pi;
    delete r;*/


    cout << "kerulet: " << t.GetKerulet().ertek() << endl;
    cout << "terulet: " << t.GetTerulet().ertek() << endl;



    racionalis x = racionalis(1, 1);
    racionalis y = racionalis(9, 1);
    racionalis z = 7;
    std::vector<racionalis> list;
    list.push_back(x);
    list.push_back(y);
    list.push_back(z);

    vektor v = vektor(list);
    v.PrintAllCoordinatesl();


    racionalis x1 = racionalis(2, 1);
    racionalis y1 = racionalis(-8, 1);
    racionalis z1 = 7;
    std::vector<racionalis> list1;
    list1.push_back(x1);
    list1.push_back(y1);
    list1.push_back(z1);

    vektor v1 = vektor(list1);
    v1.PrintAllCoordinatesl();
    
    cout << "osszeadas eredmenye:" << endl;
    v.Add(v1).PrintAllCoordinatesl();

    cout << "kivonas eredmenye:" << endl;
    v.Minusz(v1).PrintAllCoordinatesl();

    cout << "skallar szorzat eredmenye:" << v.SkallarSzorzat(v1) << endl;


    racionalis x2 = racionalis(1, 1);
    racionalis y2 = racionalis(9, 1);
    racionalis z2 = 7;
    std::vector<racionalis> list2;
    list2.push_back(x2);
    list2.push_back(y2);
    list2.push_back(z2);

    tervektor tervektor1(list2);
    tervektor1.PrintAllCoordinatesl();


    racionalis x3 = racionalis(5, 1);
    racionalis y3 = racionalis(9, 1);
    racionalis z3 = -7;
    std::vector<racionalis> list3;
    list3.push_back(x3);
    list3.push_back(y3);
    list3.push_back(z3);

    tervektor tervektor2(list3);
    tervektor2.PrintAllCoordinatesl();

    cout << "vektorialis szorzat: ";
    //tervektor1.VektorialisSzorzat(tervektor2).PrintAllCoordinatesl();
    (tervektor1 % tervektor2).PrintAllCoordinatesl();
    cout << endl;

    tervektor cel = tervektor1.Add(tervektor2);
    cel.PrintAllCoordinatesl();

    std::vector<racionalis> list4;
    list4.push_back(x3);
    list4.push_back(y3);
    vektor vv(list4);
    tervektor tv(vv);
    tv.PrintAllCoordinatesl();

    tervektor cel2 = tv.VektorialisSzorzat(tervektor2);
    cel2.PrintAllCoordinatesl();


    idopont p;
    cout << p << endl;

    idopont p1(2, 4, 0);
    cout << p1 << endl;

    int sz = -86399;
    sz = sz % 86400;
    cout << sz << endl;

    //cout << "a * b = " << a * b;
    

    //idopontok
    idopont idop(8, 3);
    idotartam idot(0, 45, 12);
    idopont idop2 = idop + idot;
    cout << idop2 << endl;
    idot = idop2 - idop;
    cout << idot << endl;


    //bitek
    //
    binary_number binaris = binary_number(14);
    cout << "binaris: " << binaris << endl;
    cout << "decimalis: " << binaris.GetIntValue() << endl;

    cout << "string binary::::::" << endl;
    string s = "";
    for (int i = 0; i < 10; i++)
    {
        s += "9";
    }
    string s2 = "";
    for (int i = 0; i < 100; i++)
    {
        s2 += "9";
    }
    binary_number binaris_string = binary_number(s);
    cout << "binaris: " << binaris_string << endl;
    //cout << "decimalis: " << binaris_string.GetIntValue() << endl;

    binary_number binary_sum = binaris + binaris_string;
    cout << "binary1 + binary 2 = " << binary_sum << endl;


    //BIGINT

    BigInt test = BigInt("3");
    cout << endl;

    BigInt aa = BigInt("10");
    //cout << "aa = + 1 = 11: " << (aa + 1) << endl;

    test.TestCases();

    BigInt sqrt_test = BigInt("100");
    //cout << "sqrt of " << sqrt_test << " = " << sqrt(sqrt_test) << endl;

    /*
    cout << "Prime numbers:" << endl;
    for (int i = 3; i < 1000000; i+=2)
    {
        test = BigInt(std::to_string(i));
        if (test.IsPrime())
        {
            cout << test << endl;
        }
    }
    */

    
    cout << endl << "Calibration" << endl;
    

    double computation_size = 6000;
    //double calibration_size = computation_size/1;

    
    //OwnFunction f = CalibratePrimeTimer(calibration_size);
    OwnFunction f = CalibrateFromFile("test");

    cout << endl << "This is going to take: " << f.GetValue(computation_size) << "seconds" << endl;


    
    cout << "prime test super new. (" << NumberComma(computation_size) << " numbers)" << endl;
    double profiling0 = Profiler(PrimeSearcherTestNew, computation_size);
    
    


    //double profiling2 = ProfilerSilent(PrimeSearcherTestNew, 100);
    //cout << "runtime: " << profiling2 << " secs" << endl;

    

    //PrimeSpeed(100);
    
    //PrimeSpeed(5);
    
    //test
    /*
    string nagy_string = "";
    for (BigInt i = "0"; i++; i <= 1000)
    {
        //cout << (rand() % 10);
        nagy_string += "" + to_string(rand() % 10000);
    }

    BigInt n1 = BigInt(nagy_string);
    BigInt n2 = BigInt(nagy_string);

    cout << "n1 + n2 = " << n1 + n2 << endl;
    cout << "nagystring = " << (sizeof(nagy_string) * nagy_string.capacity()) / 1000000 << "MB" << endl;
    */
    //PROFILING
    //Creation Test
    //AddRandomBigIntToItself(100000000);
    //StringCreationTest(1000000);
    
 




    //double profiling1 = Profiler(osszeados, size);
    
    //cout << "p2 is " << (profiling1/profiling2) << "x times faster." << endl;

    

    /*
    cout << "Prime numbers:" << endl;
    for (int i = 2; i < 100000; i++)
    {
        test = BigInt(std::to_string(i));
        if (test.IsPrime())
        {
            cout << test << endl;
        }
    }
    */
    

    /*
    string nagy_string = "";
    for (int i = 0; i < 1000000; i++)
    {
        //cout << (rand() % 10);
        nagy_string += "" + to_string(rand() % 10000);
    }
    
    BigInt n1 = BigInt(nagy_string);
    BigInt n2 = BigInt(nagy_string);

    cout << "n1 + n2 = " << n1 + n2 << endl;
    cout << "nagystring = " << (sizeof(nagy_string) * nagy_string.capacity()) / 1000000 << "MB" << endl;
    */

    //BigInt nagy = BigInt("875398759847398573498794623874638746328764387");
    //BigInt masik_nagy = BigInt("374687264876878764326876676766688423786876284");
    //cout << "nagy + masik nagy = " << nagy + masik_nagy << endl;

    /*
    cout << "Prime numbers:" << endl;
    for (int i = 2; i < 100000; i++)
    {
        test = BigInt(std::to_string(i));
        if (test.IsPrime())
        {
            cout << test << endl;
        }
    }
    */

    /*
    if (test.IsPrime())
    {
        cout << "is prime";
    }
    else
    {
        cout << "isnt prime";
    }
    */

    /*
    cout << endl << "division" << endl;
    BigInt bi_a = BigInt("12");
    BigInt bi_b = BigInt("3");
    cout << "bi_a: " << bi_a << endl;
    cout << "bi_b: " << bi_b << endl;
    cout << "division baby: " << (bi_a / bi_b) << endl;
    
    */
    //cout << test << endl;

    /*
    //BigINT

    BigInt bi = BigInt("9875984375943798798473987985999933");
    cout << bi.GetString() << endl;
    //bi++;
    cout << bi.GetString() << endl;

    bi.Duplazas();
    cout << "duplazas: " << bi.GetString() << endl;

    BigInt bi_a = BigInt("1065640");
    BigInt bi_b = BigInt("9656500");

    cout << "BIG +++ REVEAL::: " << endl;
    cout << (bi_a + bi_b).GetString() << endl;

    BigInt bi_c = BigInt("140");
    cout << "/////////////////small * REVEAL::: " << endl;
    cout << "bi_c: " << bi_c.GetString() << endl;
    cout << (bi_c * 2).GetString() << endl;

    //BIGINT SZORZAS
    bi_a = BigInt("140");
    bi_b = BigInt("12");
    cout << "bi_a: " << bi_a.GetString() << endl;
    cout << "bi_b: " << bi_b.GetString() << endl;
    cout << "BIG *** REVEAL::: " << endl;
    cout << "syoryaseredmeny " << (bi_a * bi_b).GetString() << endl;

    //BIGINT OSSZEADAS
    BigInt bi_k = BigInt("280");
    BigInt bi_l = BigInt("1400");
    cout << "bi_a: " << bi_k.GetString() << endl;
    cout << "bi_b: " << bi_l.GetString() << endl;
    //cout << "++ test " << endl;
    bi_k = bi_k + bi_l;
    //cout << "++ test " << (bi_k + bi_l).GetString() << endl;
    cout << "++ test " << bi_k.GetString() << endl;

    
    BigInt bi_x = BigInt("2789");
    BigInt bi_y = BigInt("56");
    cout << "bi_x: " << bi_x.GetString() << endl;
    cout << "bi_y: " << bi_y.GetString() << endl;
    //cout << "++ test " << endl;
    cout << "////////////Osztas reveal " << endl;
    cout << (bi_x / bi_y).GetString() << endl;



    bi_x = BigInt("281");
    bi_y = BigInt("29");
    cout << "igaza hamis teszt: " << endl;
    cout << "bi_x: " << bi_x.GetString() << endl;
    cout << "bi_y: " << bi_y.GetString() << endl;
    if (bi_x <= bi_y)
    {
        cout << "x is <= than y" << endl;
    }
    else
    {
        cout << "x is not smaller than y" << endl;
    }

    cout << "////////////Kivonas teszt " << endl;
    bi_x = BigInt("5346");
    bi_y = BigInt("1237");
    cout << "bi_x: " << bi_x.GetString() << endl;
    cout << "bi_y: " << bi_y.GetString() << endl;
    cout << (bi_x - bi_y).GetString() << endl;

    cout << endl << "Substraction" << endl;
    BigInt bi_u = BigInt("9");
    BigInt bi_i = BigInt("3");
    cout << "bi_u: " << bi_u.GetString() << endl;
    cout << "bi_i: " << bi_i.GetString() << endl;
    cout << "division baby: " << (bi_u / bi_i).GetString() << endl;

    */

    /*
    racionalis a = racionalis(1, 2);
    racionalis b(2, 3);0

    a.kiir();
    b.kiir();

    cout << a.ertek() << endl;
    cout << b.ertek() << endl;

    cout << "reciprokok: " << endl;
    a.reciprok().kiir();
    b.reciprok().kiir();

    cout << "szorzat: " << endl;
    a.szorzas(b).kiir();

    cout << "osztasok: " << endl;
    a.osztas(b).kiir();
    b.osztas(a).kiir();

    racionalis c = 2;
    racionalis d; // 0/1
    c.kiir();
    d.kiir();

    racionalis e = b * c; // racionalis e = b.operator*(c);
    e.kiir();

    racionalis e1 = b / c; // racionalis e = operator/(b,c);
    e1.kiir();

    racionalis eci = 1 / a; // 1.operator/(a) nem lehet --> operator/(1, a);
    // 1 --> racionalis(1) --> racionalis objektum, operator/(racionalis, racionalis) OK
    // "implicit" konstruktorhívás
    //racionalis f = 2 * a; operator*(int, racionalis);
    racionalis f2 = a * 2;
    cout << f2 << endl;
    // operator<<(cout, f2);

    racionalis test_1 = racionalis(-1, 2);
    test_1.kiir();
    racionalis test_2 = racionalis(1, 20);
    racionalis eredmeny = test_1 + test_2;
    cout << "eredmeny:";
    eredmeny.kiir();

    */

    return 0;
}
/*
racionalis::racionalis()
{
    szamlalo = 0;
    nevezo = 1;
}
*/
/*racionalis::racionalis(int n)
{
    szamlalo = n;
    nevezo = 1;
}*/

void racionalis::kiir()
{
    if (minusz)
    {
        std::cout << "-" << szamlalo << "/" << nevezo << endl;
    }
    {
        std::cout << szamlalo << "/" << nevezo << endl;
    }
}

string NumberComma(int i)
{
    string s = std::to_string(i);
    int n = s.length() - 3;
    while (n > 0)
    {
        s.insert(n, ",");
        n -= 3;
    }
    return s;
}

racionalis racionalis::operator+(racionalis jobb)
{
    int esz_bal = szamlalo;
    int esz_jobb = jobb.szamlalo;
    if (minusz)
    {
        esz_bal = szamlalo * -1;
    }
    if (jobb.minusz)
    {
        esz_jobb = jobb.szamlalo * -1;
    }
    racionalis r = racionalis(esz_bal * jobb.nevezo + esz_jobb * nevezo, jobb.nevezo * nevezo);
    r.clean();
    return r;
}

racionalis racionalis::operator-(racionalis jobb)
{
    //elojelszamlalo_bal
    int esz_bal = szamlalo;
    int esz_jobb = jobb.szamlalo;
    if (minusz)
    {
        esz_bal = szamlalo * -1;
    }
    if (jobb.minusz)
    {
        esz_jobb = jobb.szamlalo * -1;
    }
    racionalis r = racionalis(esz_bal * jobb.nevezo - esz_jobb * nevezo, jobb.nevezo * nevezo);
    r.clean();
    return r;
}

void racionalis::clean()
{
    if (szamlalo < 0 && nevezo < 0)
    {
        abszolut();
    }
    else if (szamlalo < 0 || nevezo < 0)
    {
        abszolut();
        minusz = true;
    }
}

double racionalis::ertek()
{
    //std::cout << " jaj ne> " << szamlalo << "/" << nevezo << endl;
    if (minusz)
    {
        return (double)szamlalo / (double)nevezo * -1;
    }
    else
    {
        return (double)szamlalo / (double)nevezo;
    }
}

void racionalis::abszolut()
{
    szamlalo = abs(szamlalo);
    nevezo = abs(nevezo);
    minusz = false;
}

racionalis racionalis::reciprok()
{
    return racionalis(nevezo, szamlalo);
}

racionalis racionalis::szorzas(racionalis jobb)
{
    return racionalis(szamlalo * jobb.szamlalo, nevezo * jobb.nevezo);
}

racionalis racionalis::osztas(racionalis jobb)
{
    return racionalis(szamlalo * jobb.nevezo, nevezo * jobb.szamlalo);
}

racionalis racionalis::operator*(racionalis jobb)
{
    racionalis r = racionalis(szamlalo * jobb.szamlalo, nevezo * jobb.nevezo);
    r.minusz = (minusz != jobb.minusz);
    return r;
}
/*racionalis racionalis::operator/(racionalis jobb)
{
    return racionalis(szamlalo * jobb.nevezo, nevezo * jobb.szamlalo);
}*/

racionalis operator*(int bal, racionalis jobb)
{
    racionalis r = racionalis(jobb.szamlalo * bal, jobb.nevezo);
    bool b = bal < 0;
    r.minusz = (b != jobb.minusz);
    return r;
}

racionalis operator/(racionalis bal, racionalis jobb)
{
    racionalis r = racionalis(bal.szamlalo * jobb.nevezo, bal.nevezo * jobb.szamlalo);
    r.minusz = (bal.minusz != jobb.minusz);
    return r;
}

ostream& operator<<(ostream& os, racionalis jobb)
{
    if (jobb.minusz)
    {
        os << "-" << jobb.szamlalo << "/" << jobb.nevezo;
    }
    else
    {
        os << jobb.szamlalo << "/" << jobb.nevezo;
    }
    return os;
}

bool racionalis::IsNull()
{
    return (szamlalo == 0);
}

void AddTest(int size)
{
    string nagy_string = egybol(size);
    BigInt n1 = BigInt(nagy_string);
    BigInt n2 = BigInt(nagy_string);
    BigInt n3 = n1 + n2;
    //cout << "n1 + n2 = " << n1 + n2 << endl;
    //cout << "nagystring = " << (sizeof(nagy_string) * nagy_string.capacity()) / 1000000 << "MB" << endl;
}

double Profiler(void (*fv)(void))
{
    auto start = std::chrono::system_clock::now();
    fv();
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "finished computation at elapsed time: " << elapsed_seconds.count() << "s\n";

    return elapsed_seconds.count();
}

double Profiler(void (*fv)(int), int size)
{
    double elapsed_seconds = ProfilerSilent(fv, size);
    std::cout << "finished computation at elapsed time: " << elapsed_seconds << "s\n";

    return elapsed_seconds;
}

double ProfilerSilent(void (*fv)(int), int size)
{
    auto start = std::chrono::system_clock::now();
    fv(size);
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    return elapsed_seconds.count();
}

string osszeados(int size)
{
    string nagy_string = "";

    for (int i = 0; i < size; i++)
    {
        nagy_string += "" + to_string(rand() % 10);
    }

    //cout << "nagystring = " << (nagy_string.capacity()) / 1000000 << "MB" << endl;
    return nagy_string;
}

void osszeados_test(int size)
{
    osszeados(size);
}

string egybol(int size)
{
    char* chartomb = new char[size + 1];
    chartomb[size] = '\0';

    for (int i = 0; i < size; i++)
    {
        chartomb[i] = rand() % 10 + '0';
    }
    string nagy_string(chartomb);
    delete chartomb;

    //cout << "nagystring = " << (nagy_string.capacity()) / 1000000 << "MB" << endl;

    return nagy_string;
}

void egybol_test(int size)
{
    egybol(size);
}

void AddRandomBigIntToItself(int n)
{
    //Creation Test
    const int size = n;

    cout << endl << "ADD RANDOM INT TO ITSELF TEST" << endl;
    cout << "String creation test. (" << NumberComma(size) << " char long)" << endl;
    cout << "This is going to take: " << ProfilerSilent(egybol_test, size / 100) * 100 << " seconds" << endl;
    double profiling1 = Profiler(egybol_test, size);

    //add test
    cout << endl << "BigInt n + BigInt n addition test. (" << NumberComma(size) << " x 2 digits long)" << endl;
    cout << "This is going to take: " << ProfilerSilent(AddTest, size / 100) * 100 - profiling1 / 100 << " seconds" << endl;
    double profiling2 = Profiler(AddTest, size) - profiling1;
}

void StringCreationTest(int n)
{
    cout << endl << "STRING CREATION TEST" << endl;
    int size = n;
    cout << "String creation test1. (" << NumberComma(size) << " char long)" << endl;
    cout << "This is going to take: " << ProfilerSilent(egybol_test, size / 100) * 100 << " seconds" << endl;
    double profiling1 = Profiler(egybol_test, size);

    cout << endl << "String creation test2. (" << NumberComma(size) << " char long)" << endl;
    cout << "This is going to take: " << ProfilerSilent(osszeados_test, size / 100) * 100 << " seconds" << endl;
    double profiling2 = Profiler(osszeados_test, size);

    cout << endl << "method 1 is " << profiling2 / profiling1 << "x times faster." << endl;
}

void PrimeSpeed(int n)
{
    cout << endl << "PRIME TEST" << endl;
    int size = n;

    cout << endl << "prime test super new. (" << NumberComma(size) << " numbers)" << endl;
    double profiling0 = Profiler(PrimeSearcherTestNew, size);

    cout << endl << "prime test new. (" << NumberComma(size) << " numbers)" << endl;
    double profiling1 = Profiler(PrimeSearcherTest, size);

    cout << endl << "prime test old. (" << NumberComma(size) << " numbers)" << endl;
    double profiling2 = Profiler(PrimeSearcherTestOld, size);

    cout << endl << "prime test old bad. (" << NumberComma(size) << " numbers)" << endl;
    double profiling3 = Profiler(PrimeSearcherTestOldBad, size);

    cout << endl << "method 1 is " << profiling2 / profiling0 << "x times faster." << endl;
}

void PrimeSearcherTestNew(int n2)
{
    for (int i = 3; i < n2; i += 2)
    {
        BigInt test(std::to_string(i));
        if (test.IsPrimeNew())
        {
            //cout << i << endl;
        }
    }
}

void PrimeSearcherTest(int n2)
{
    BigInt test = BigInt("3");
    for (int i = 3; i < n2; i += 2)
    {
        test = BigInt(std::to_string(i));
        if (test.IsPrime())
        {
            //cout << test << endl;
        }
    }
}

void PrimeSearcherTestOld(int n2)
{
    BigInt test = BigInt("3");
    for (int i = 3; i < n2; i += 2)
    {
        test = BigInt(std::to_string(i));
        if (test.IsPrimeOld())
        {
            //cout << test << endl;
        }
    }
}

void PrimeSearcherTestOldBad(int n2)
{
    BigInt test = BigInt("3");
    for (int i = 3; i < n2; i ++)
    {
        test = BigInt(std::to_string(i));
        if (test.IsPrimeOld())
        {
            //cout << test << endl;
        }
    }
}

void PrimeTimeToFile(int n2, string name)
{
    ofstream myfile;
    int number = 100;
    myfile.open("C:/Users/Felvea/Documents/Prime/" + name + ".txt");
    myfile << "Prime Numbers To " << (n2 * number) << endl;

    BigInt test = BigInt("4");
    
    cout << "<";
    for (int i = 0; i < n2; i++)
    {
        cout << "-";
    }
    cout << ">" << endl;
    
    cout << "<";
    for (int j = 0; j <= n2 - 1; j++)
    {
        cout << "=";
        myfile << j*number << "\t";
        auto start = std::chrono::system_clock::now();
        for (int i = (j-1)*100; i < j * 100; i++)
        {
           
            test = BigInt(std::to_string(i));
            if (test.IsPrimeNew())
            {
            }
           
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        myfile << elapsed_seconds.count() << endl;
    }
    cout << ">" << endl;

    myfile.close();
}

void PrimeTimeToFileAddative(int n2, string name)
{
    ofstream myfile;
    int number = 100;
    myfile.open("C:/Users/Felvea/Documents/Prime/" + name + ".txt");
    myfile << "Prime Numbers To " << (n2 * number) << endl;

    BigInt test = BigInt("4");

    cout << "<";
    for (int i = 0; i < n2; i++)
    {
        cout << "-";
    }
    cout << ">" << endl;

    cout << "<";
    
    double commulative_seconds = 0;
    for (int j = 0; j <= n2; j++)
    {
        cout << "=";
        myfile << j * number << "\t";
        auto start = std::chrono::system_clock::now();
        for (int i = (j) * 100; i < (j + 1) * 100; i++)
        {

            test = BigInt(std::to_string(i));
            if (test.IsPrimeNew())
            {
            }

        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        commulative_seconds += elapsed_seconds.count();
        myfile << commulative_seconds << endl;
    }
    cout << ">" << endl;

    myfile.close();
}

bool IsPrimeInt(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (i * (n / i) == n)
        {
            return false;
        }
    }
    return true;
}

OwnFunction CalibratePrimeTimer(int size)
{

    cout << endl << "Calibrating using prime test super new. (" << NumberComma(size) << " numbers)" << endl;
    
    auto start = std::chrono::system_clock::now();
    PrimeTimeToFileAddative(size/100, "test");
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    cout << "This took: " << elapsed_seconds.count() << " seconds" << endl;


    vector<double> x_values;
    vector<double> y_values;

    string filename = "C:/Users/Felvea/Documents/Prime/test.txt";
    
    ifstream file(filename);
    string line;
    vector<string> lines;

    bool first_line = true;
    while (getline(file, line))
    {
        istringstream iss(line);
        string token;

        int counter = 0;
        while (getline(iss, token, '\t'))   // but we can specify a different one
        {
            if (first_line)
            {
                first_line = false;
            }
            else
            {
                if (counter == 0)
                {
                    x_values.push_back(stold(token));
                    counter++;
                }
                else
                {
                    y_values.push_back(stold(token));
                }
                //cout << token << endl;
            }
        }
        
    }
    OwnFunction f = OwnFunction(x_values, y_values);
    f.ThreePointFunction();
    return f;
    //f.GetFunctionVertex();
    //cout << "Function value at: " << f.GetValue(100) << endl;
}

OwnFunction CalibrateFromFile(string name)
{

    cout << endl << "Calibrating using file: " << name << ".txt" << endl;

    vector<double> x_values;
    vector<double> y_values;

    string filename = "C:/Users/Felvea/Documents/Prime/" + name + ".txt";

    ifstream file(filename);
    string line;
    vector<string> lines;

    bool first_line = true;
    while (getline(file, line))
    {
        istringstream iss(line);
        string token;

        int counter = 0;
        while (getline(iss, token, '\t'))   // but we can specify a different one
        {
            if (first_line)
            {
                first_line = false;
            }
            else
            {
                if (counter == 0)
                {
                    x_values.push_back(stold(token));
                    counter++;
                }
                else
                {
                    y_values.push_back(stold(token));
                }
                //cout << token << endl;
            }
        }

    }
    OwnFunction f = OwnFunction(x_values, y_values);
    f.ThreePointFunction();
    return f;
    //f.GetFunctionVertex();
    //cout << "Function value at: " << f.GetValue(100) << endl;
}

//HF
//összedás, kionán, előjelváltás (egyparamétrees minusz), abszolútértéket, double-é konvertálás
//egyszerűsítés
// téglalap osztály ahol az a és b adattagok racionálisok és legyen Terület és Kerület
//kövi óra[cin felüldefiniálása jobbranyíl]

// síkvektor és műveletei: ideértve a skalárszorzatot
// térvektor és műveletei: ideértve a skalárszorzatot és a vektoriális szorzatot
// 10 dimenziós vektor és műveletei
// n dimenziós vektor és műveletei, new, delete
// double *tomb = new double[n]; --> létrehozod
// delete[] tomb; kitörlése --> ~vektor() { delete[] tomb; } // destuktor
// időtartam osztály 0:45:00 0:10:00 +, - (egymással és egész számmal, ami másodpercet jelent), kiirni
// lehet pozitív is, és negatív is.
// időpont osztály: két időpont különbsége egy időtartam. (az előző osztály)