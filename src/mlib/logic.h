#ifndef LOGIC_H_
#define LOGIC_H_

#include <array>
#include <cstdlib>
#include <iostream>

enum class CellStatus { BORN = 0, LIVE = 1, DIE = 2 };
class LifeAlgorithm {
public:
    int static constexpr Widht = 65;  // ширина массива/поля
    int static constexpr Height = 40; // высота массива/поля

    CellStatus fieldArray[Widht][Height];
    CellStatus tempArray[Widht][Height];

    void CreateUniverse();

    void RandFillUniverse();

    void Step();

    void initLife();

    void RunLife();
};

#endif
