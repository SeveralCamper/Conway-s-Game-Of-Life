/* #include "logic.h"

void LifeAlgorithm::CreateUniverse()
{
    for (int i = 0; i < Widht; i++) {
        for (int j = 0; j < Height; j++) {
            fieldArray[i][j] = 0;
        }
    }
}

void LifeAlgorithm::FillUniverse()
{
    for (int i = 1; i < Widht - 1; i++) {
        for (int j = 1; j < Height - 1; j++) {
            fieldArray[i][j] = rand() % 2;
        }
    }
}

void LifeAlgorithm::PrintUniverse()
{
    for (int i = 0; i < Widht; i++) {
        for (int j = 0; j < Height; j++) {
            if (fieldArray[i][j] == 1)
                std::cout << "#";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
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
            bool keepAlive = isAlive && (numNeigbours == 2 || numNeigbours == 3);
            bool makeNewLive = !isAlive && numNeigbours == 3;

            fieldArray[i][j] = keepAlive | makeNewLive;
        }
    }
}

void LifeAlgorithm::RunLife()
{
    LifeAlgorithm::FillUniverse();
    LifeAlgorithm::PrintUniverse();
    system("pause");
    system("cls");
    while (true) {
        LifeAlgorithm::Step();
        LifeAlgorithm::PrintUniverse();
        system("pause");
        system("cls");
    }
}
 */