#pragma once
#include <iostream>
#include "racionalis.h"
#include <list>
#include <vector>
using namespace std;

class vektor
{
    private:
    protected:
        std::vector<racionalis> kordinatak;

    public:
        vektor(std::vector<racionalis> kordinatak);
        std::vector<racionalis> GetKordinatak();
        void PrintAllCoordinatesl();
        vektor Add(vektor v);
        vektor Minusz(vektor v);
        racionalis SkallarSzorzat(vektor v);
        vektor operator+(vektor b);
        vektor operator-(vektor b);
        racionalis operator*(vektor b);

};

class tervektor : public vektor
{
    public:
        tervektor VektorialisSzorzat(tervektor v);
        tervektor(std::vector<racionalis> kordinatak);
        tervektor(vektor v);
        tervektor operator%(tervektor b);
};