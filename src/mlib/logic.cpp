class LifeAlgorithm {

public:

    int Widht = 100; // ширина массива/поля 
    int Height = 100; // высота массива/поля

    bool fieldArray[Widht][Height] = {false}; // массив, в кот. будут лежать исходные данные о состоянии клеток и в кот. состояния 
                                              // будут проверяться
    bool tempArray[Widht][Height] = {false};  // массив, в кот. будут записываться данные о состоянии клеток и перезаписываться в исходный

    void Step()
    {
        for (int i = 1; i < WIDTH - 1; i++)
        {
            for (int j = 1; j < HEIGHT - 1; j++)
            {  // первый проход: вычисляем будущее состоянее
                bool isAlive = field[i, j];
                bool keepAlive = isAlive && (numNeigbours == 2 || numNeigbours == 3);
                bool makeNewLive = !isAlive && numNeigbours == 3;
                temp[i, j] = keepAlive | makeNewLive;
            }
};
