#ifndef LOGIC_H_
#define LOGIC_H_

#include <ctime>
#include <cstdlib>
#include <array>
#include <cmath>
#include <iostream>
#include <time.h>
#include <vector>
#include <iomanip>

class LifeAlgorithm {
public:
    int static constexpr Widht = 5;  // ширина массива/поля
    int static constexpr Height = 5; // высота массива/поля

    int fieldArray[Widht][Height];

    void fillUniverse ();
    void printUniverse ();
    int lifeGenerate();
    int runLife();
};

#endif
