#ifndef LOGIC_H_
#define LOGIC_H_

#include <array>
#include <cstdlib>
//#include <iomanip>
#include <iostream>

class LifeAlgorithm {
public:
    int static constexpr Widht = 40;  // ширина массива/поля
    int static constexpr Height = 40; // высота массива/поля

    bool fieldArray[Widht][Height];
    bool tempArray[Widht][Height];

    void CreateUniverse()
    {
        for (int i = 0; i < Widht; i++) {
            for (int j = 0; j < Height; j++) {
                fieldArray[i][j] = false;
            }
        }
    }

    void RandFillUniverse()
    {
        for (int i = 1; i < Widht - 1; i++) {
            for (int j = 1; j < Height - 1; j++) {
                fieldArray[i][j] = rand() % 2;
            }
        }
    }

    void Step()
    {
        for (int i = 1; i < Widht - 1; i++) {
            for (int j = 1; j < Height - 1;
                 j++) { // первый проход: вычисляем будущее состоянее

                int numNeigbours = 0;
                bool isAlive = fieldArray[i][j];

                if (fieldArray[i - 1][j - 1])
                    numNeigbours++;
                if (fieldArray[i - 1][j])
                    numNeigbours++;
                if (fieldArray[i - 1][j + 1])
                    numNeigbours++;
                if (fieldArray[i][j - 1])
                    numNeigbours++;
                if (fieldArray[i][j + 1])
                    numNeigbours++;
                if (fieldArray[i + 1][j - 1])
                    numNeigbours++;
                if (fieldArray[i + 1][j])
                    numNeigbours++;
                if (fieldArray[i + 1][j + 1])
                    numNeigbours++;
                bool keepAlive
                        = isAlive && (numNeigbours == 2 || numNeigbours == 3);
                bool makeNewLive = !isAlive && numNeigbours == 3;
                tempArray[i][j] = keepAlive | makeNewLive;
            }
        }
        for (int i = 1; i < Widht - 1; i++)
            for (int j = 1; j < Height - 1; j++)
                // второй проход: копируем вычисленное состояние в текущее
                fieldArray[i][j] = tempArray[i][j];
    }

    void initLife()
    {
        LifeAlgorithm::CreateUniverse();
        LifeAlgorithm::RandFillUniverse();
    }

    void RunLife()
    {
        LifeAlgorithm::Step();
    }
};

#endif
