#ifndef LOGIC_H_
#define LOGIC_H_

#include <iostream>

class LifeAlgorithm {

public:

    int Widht = 100; // ширина массива/поля 
    int Height = 100; // высота массива/поля

    bool fieldArray[Widht][Height] = {false}; // массив, в кот. будут лежать исходные данные о состоянии клеток и в кот. состояния 
                                              // будут проверяться
    bool tempArray[Widht][Height] = {false};  // массив, в кот. будут записываться данные о состоянии клеток и перезаписываться в исходный

    void Step();
};

#endif
