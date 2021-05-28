#ifndef LOGIC_H_
#define LOGIC_H_

#include <array>
#include <cstdlib>
#include <iostream>

class LifeAlgorithm {
public:
    int static constexpr Widht = 55;  // ширина массива/поля
    int static constexpr Height = 55; // высота массива/поля

    bool fieldArray[Widht][Height];
    bool tempArray[Widht][Height];

    void CreateUniverse();

    void RandFillUniverse();

    void Step();

    void initLife();

    void RunLife();
};

#endif
