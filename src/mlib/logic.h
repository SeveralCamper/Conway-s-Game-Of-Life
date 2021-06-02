#ifndef LOGIC_H_
#define LOGIC_H_

#include <SFML/Graphics.hpp>

#include <array>
#include <cstdlib>
#include <iostream>

enum class CellStatus { BORN = 0, LIVE = 1, DIE = 2 };
class LifeAlgorithm {
public:
    int static constexpr Widht = 63;  // ширина массива/поля
    int static constexpr Height = 43; // высота массива/поля

    CellStatus fieldArray[Widht][Height];
    CellStatus tempArray[Widht][Height];

    void CreateUniverse();

    void RandFillUniverse();

    void CustomCreateUniverse(int x, int y);

    void Step();

    void initLife();

    void RunLife();
};

#endif
