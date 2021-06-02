#include "logic.h"

void LifeAlgorithm::CreateUniverse()
{
    std::cout << "debug2" << std::endl;
    for (int i = 0; i < Widht; i++) {
        for (int j = 0; j < Height; j++) {
            fieldArray[i][j] = CellStatus::DIE;
        }
    }
}

void LifeAlgorithm::RandFillUniverse()
{
    srand(time(NULL));
    std::cout << "007" << std::endl;
    for (int i = 1; i < Widht - 1; i++) {
        for (int j = 1; j < Height - 1; j++) {
            fieldArray[i][j] = CellStatus(rand() % 3);
        }
    }
}

int a = 0;

void LifeAlgorithm::Step()
{
    a++;
    std::cout << a << std::endl;
    for (int i = 1; i < Widht - 1; i++) {
        for (int j = 1; j < Height - 1;
             j++) { // первый проход: вычисляем будущее состоянее

            int numNeigbours = 0;
            CellStatus isAlive = fieldArray[i][j];

            for (int ii = i - 1; ii < i + 2; ii++) {
                for (int jj = j - 1; jj < j + 2; jj++) {
                    {
                        if (fieldArray[ii][jj] == CellStatus::LIVE
                            || fieldArray[ii][jj] == CellStatus::BORN)
                            numNeigbours++;
                    }
                }
            }

            if (fieldArray[i][j] == CellStatus::LIVE
                || fieldArray[i][j] == CellStatus::BORN) {
                numNeigbours--;
            }

            bool keepAlive = (isAlive == CellStatus::LIVE
                              || isAlive == CellStatus::BORN)
                    && (numNeigbours == 2 || numNeigbours == 3);
            bool makeNewLive = isAlive == CellStatus::DIE && numNeigbours == 3;

            if (fieldArray[i][j] == CellStatus::LIVE && keepAlive) {
                tempArray[i][j] = CellStatus::LIVE;
            }

            if (fieldArray[i][j] == CellStatus::LIVE && !keepAlive) {
                tempArray[i][j] = CellStatus::DIE;
            }

            if (fieldArray[i][j] == CellStatus::DIE && makeNewLive) {
                tempArray[i][j] = CellStatus::BORN;
            }

            if (fieldArray[i][j] == CellStatus::DIE && !makeNewLive) {
                tempArray[i][j] = CellStatus::DIE;
            }

            if (fieldArray[i][j] == CellStatus::BORN && keepAlive) {
                tempArray[i][j] = CellStatus::LIVE;
            }

            if (fieldArray[i][j] == CellStatus::BORN && !keepAlive) {
                tempArray[i][j] = CellStatus::DIE;
            }
        }
    }
    for (int i = 1; i < Widht - 1; i++)
        for (int j = 1; j < Height - 1; j++)
            // второй проход: копируем вычисленное состояние в текущее
            fieldArray[i][j] = tempArray[i][j];
}

