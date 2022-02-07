#pragma once
#include <iostream>

using namespace std;

class racionalis
{
private:
    int nevezo;
    int szamlalo;
    bool minusz = false;
    
public:
    //racionalis();
    //racionalis(int n);
    racionalis(int sz = 0, int n = 1) : szamlalo(sz), nevezo(n)
    {
        clean();
    }
    void kiir();
    
    double ertek();
    racionalis reciprok();
    racionalis szorzas(racionalis jobb);
    racionalis osztas(racionalis jobb);
    void abszolut();
    void elojelvaltas();
    racionalis operator*(racionalis jobb);
    friend racionalis operator*(int bal, racionalis jobb);
    racionalis operator+(racionalis jobb);
    racionalis operator-(racionalis jobb);
    //racionalis operator/(racionalis jobb);
    friend racionalis operator/(racionalis bal, racionalis jobb);
    friend ostream& operator<<(ostream& os, racionalis jobb);
    bool IsNull();

    

private:
    void clean();
};

racionalis operator/(racionalis bal, racionalis jobb);
racionalis operator*(int bal, racionalis jobb);
ostream& operator<<(ostream& os, racionalis jobb);
void AddTest(int size);
double Profiler(void (*fv)(void));
double Profiler(void (*fv)(int), int size);
double ProfilerSilent(void (*fv)(int), int size);
string osszeados(int size);
void osszeados_test(int size);
string egybol(int size);
void egybol_test(int size);
string NumberComma(int i);

//Special Tests
void AddRandomBigIntToItself(int n); //n = digits of random numbers
void StringCreationTest(int n);
void PrimeSpeed(int n);
void PrimeSearcherTestNew(int n2);
void PrimeSearcherTest(int n2);
void PrimeSearcherTestOld(int n2);
void PrimeSearcherTestOldBad(int n2);

void PrimeTimeToFile(int n2);
bool IsPrimeInt(int n2);