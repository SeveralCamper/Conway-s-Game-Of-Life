#ifndef LOGIC_H_
#define LOGIC_H_

#include <array>
#include <cstdlib>
//#include <iomanip>
#include <iostream>

class LifeAlgorithm {
public:
    int static constexpr Widht = 5;  // ширина массива/поля
    int static constexpr Height = 5; // высота массива/поля

    int fieldArray[Widht][Height];

    void CreateUniverse()
    {
        for (int i = 0; i < Widht; i++) {
            for (int j = 0; j < Height; j++) {
                fieldArray[i][j] = 0;
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

    void PrintUniverse()
    {
        for (int i = 0; i < Widht; i++) {
            for (int j = 0; j < Height; j++) {
                if (fieldArray[i][j] == 1)
                    std::cout << "#";
                else
                    std::cout << "*";
            }
            std::cout << std::endl;
        }
    }

    void Step()
    {
        for (int i = 1; i < Widht - 1; i++) {
            for (int j = 1; j < Height - 1;
                 j++) { // первый проход: вычисляем будущее состоянее

                std::cout << "[" << i << "][" << j << "] = " << fieldArray[i][j] << std::endl;

                int numNeigbours = 0;

                for (int ii = i - 1; ii < i + 2; ii++) {
                    for (int jj = j - 1; jj < j + 2; jj++) {

                        numNeigbours = numNeigbours + fieldArray[ii][jj]; 

                        std::cout << "[" << ii << "][" << jj << "]" << fieldArray[ii][jj] << std::endl;
                    }
                }
                
                numNeigbours = numNeigbours - fieldArray[i][j];

                if (numNeigbours == 3 && fieldArray[i][j] == 0)
                    fieldArray[i][j] = 1;

                if ((numNeigbours < 2 || numNeigbours > 3) && fieldArray[i][j] == 1)
                    fieldArray[i][j] = 0;
                
                std::cout << "numNeigbours = " << numNeigbours << "\n" << std::endl;
            }
        }
    }

    void RunLife()
    {
        LifeAlgorithm::CreateUniverse();
        LifeAlgorithm::RandFillUniverse();
        LifeAlgorithm::PrintUniverse();
        LifeAlgorithm::Step();
        LifeAlgorithm::PrintUniverse();
    }
};

#endif
