#ifndef LOGIC_H_
#define LOGIC_H_

#include <array>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <time.h>
#include <vector>
#include <windows.h>

class LifeAlgorithm {
public:
    int static constexpr Widht = 5;  // ширина массива/поля
    int static constexpr Height = 5; // высота массива/поля

    int fieldArray[Widht][Height];

    void fillUniverse();
    void printUniverse();
    int lifeGenerate();
    int runLife();
    void Step();
};

#endif
