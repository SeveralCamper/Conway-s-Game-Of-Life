#ifndef LOGIC_H_
#define LOGIC_H_

#include <SFML/Graphics.hpp>

#include <array>
#include <cstdlib>
#include <iostream>

#include "Settings.h"

enum class CellStatus { BORN = 0, LIVE = 1, DIE = 2 };

class LifeAlgorithm {
private:
    int step = 0;

public:
    bool pause = false;

    void SetStep(int step);

    int GetStep();

    CellStatus fieldArray[ARR_WIDTH][ARR_HEIGHT];
    CellStatus tempArray[ARR_WIDTH][ARR_HEIGHT];

    void CreateUniverse();

    void RandFillUniverse();

    void CustomCreateUniverse(int x, int y);

    void Step();

    void initLife();

    void RunLife();
};

#endif
