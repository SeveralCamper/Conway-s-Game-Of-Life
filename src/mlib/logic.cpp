#include "logic.h"

    int LifeAlgorithm::lifeGenerate()
    {
        for (int i = 0; i < Widht; i++) 
        {
            for (int j = 0; j < Height; j++) 
            {
                fieldArray[i][j] = 0;
            }
        }
    }

        int LifeAlgorithm::~lifeGenerate()
    {
        return 0;
    }

    void LifeAlgorithm::fillUniverse ()
    {
        for (int i = 1; i < Widht - 1; i++) 
        {
            for (int j = 1; j < Height - 1; j++) 
            {
                fieldArray[i][j] = rand() % 2;
            }
        }
    }

    void LifeAlgorithm::printUniverse ()
    {
        for (int i = 0; i < Widht; i++) 
        {
            for (int j = 0; j < Height; j++) 
            {
               if (fieldArray[i][j] == 1)
                    std::cout << "#";
                else
                    std::cout << " ";
            }
            std::cout << std::endl;
        }
    }

    int LifeAlgorithm::runLife()
    { 
        LifeAlgorithm::lifeGenerate();
        LifeAlgorithm::fillUniverse();
        LifeAlgorithm::printUniverse();

    }
    
   void LifeAlgorithm::Step()
    {
        for (int i = 1; i < Widht - 1; i++) {
            for (int j = 1; j < Height - 1;
                 j++) { // первый проход: вычисляем будущее состоянее
                std::cout << "[i][j] эл. = " << fieldArray[i][j] << std::endl;
                std::cout << "[i]= " << i << "[j]= " << j << std::endl;

                bool isAlive = fieldArray[i][j];
                int numNeigbours = 0;
                {
                    for (int q = i - 1; q < i + 2; q++) {
                        for (int v = j - 1; v < j + 2; v++) {
                            numNeigbours = numNeigbours + fieldArray[q][v];
                            std::cout << "[q][v] = " << q << v << std::endl;
                            std::cout << "[q][v] эл. = " << fieldArray[q][v]
                                      << std::endl;
                        }
                    numNeigbours = numNeigbours - fieldArray[i][j];   
                    }
                }
                std::cout << "numNeigbours = " << numNeigbours << std::endl;
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