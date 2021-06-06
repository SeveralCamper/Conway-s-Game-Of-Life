#include "models.h"

#include <SFML/Graphics.hpp>


void TestInput()
{
    std::string line;
    std::vector<std::string> modelsName;

    std::ifstream myfile;
    myfile.open("input/models.txt");
    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            modelsName.push_back(line);
        }
    }

    int vector_size = modelsName.size();

    modelsName.push_back(line);

    for (int i = 0; i < vector_size; i++) {
        std::cout << modelsName[i] << std::endl;
    }
}