#include "Logic.h"

void LifeAlgorithm::CreateUniverse()
{
    for (int i = 0; i < ARR_WIDTH; i++) {
        for (int j = 0; j < ARR_HEIGHT; j++) {
            fieldArray[i][j] = CellStatus::DIE;
        }
    }
}

void LifeAlgorithm::RandFillUniverse()
{
    srand(time(NULL));
    for (int i = 1; i < ARR_WIDTH - 1; i++) {
        for (int j = 1; j < ARR_HEIGHT - 1; j++) {
            fieldArray[i][j] = CellStatus(rand() % 3);
        }
    }
}

void LifeAlgorithm::LoadModels() {
    char tmpArrayShape[13][13];

    CreateUniverse();

    OpenFile();
    GetDumpFile();
    CloseFile();

    GetShape(tmpArrayShape, 3);
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            if (tmpArrayShape[i][j] == '0') {
                fieldArray[i+1][j+1] = CellStatus::DIE;
            } else if (tmpArrayShape[i][j] == '1') {
                fieldArray[i+1][j+1] = CellStatus::BORN;
            } else if (tmpArrayShape[i][j] == '2') {
                fieldArray[i+1][j+1] = CellStatus::LIVE;
            }
            //std::cout << arrayShape[i][j] << " ";
        }
    }

    for (int i = 0; i < 13; i++) {
        std::cout << std::endl;
        for (int j = 0; j < 13; j++) {
            std::cout << tmpArrayShape[i][j] << " ";
        }
    }
    //ShowCollectionShapesName(GetShapesNames());
}

void LifeAlgorithm::SetStep(int step)
{
    this->step = step;
}

int LifeAlgorithm::GetStep()
{
    return step;
}

void LifeAlgorithm::SetArray(int x, int y)
{
    if (fieldArray[x][y] == CellStatus::DIE) {
        fieldArray[x][y] = CellStatus::BORN;
    } else if (fieldArray[x][y] != CellStatus::DIE) {
        fieldArray[x][y] = CellStatus::DIE;
    }
}

void LifeAlgorithm::Step()
{
    step++;
    for (int i = 1; i < ARR_WIDTH - 1; i++) {
        for (int j = 1; j < ARR_HEIGHT - 1;
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
    for (int i = 1; i < ARR_WIDTH - 1; i++)
        for (int j = 1; j < ARR_HEIGHT - 1; j++)
            // второй проход: копируем вычисленное состояние в текущее
            fieldArray[i][j] = tempArray[i][j];
}
