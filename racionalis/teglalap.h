#pragma once
#include <iostream>
#include "racionalis.h"

class teglalap
{
    private:
        racionalis a;
        racionalis b;

    public:
        teglalap(racionalis a, racionalis b);
        racionalis GetKerulet();
        racionalis GetTerulet();
};

