#include "models.h"

std::ifstream myfile(PATH_TO_MODELS);
std::string line;
std::string search = "flasher";
std::vector<std::string> collectionModelsName;

int arr[13][13];

void FindModelIndex(std::string nameModel)
{
    int count = 0;

    std::fstream myfile(PATH_TO_MODELS);
    if (myfile) {
        while (getline(myfile, line)) {
            count++;

            if (line.find(nameModel) != std::string::npos) {
                break;
            }
        }

    } else
        std::cout << "Error!" << std::endl;
}

void TestInput()
{
    int count = 0;

    std::fstream myfile1(PATH_TO_MODELS);
    if (myfile1) {
        int flag = 0;

        while (getline(myfile1, line)) {
            std::cout << flag << std::endl;
            if (flag == count) {
                std::cout << line << std::endl;
                count++;
            }

            flag++;
        }

    } else
        std::cout << "Error!" << std::endl;

    int flag = 0;

    while (getline(myfile, line)) {
        if (flag == 14) {
            std::cout << line << std::endl;
        }
        flag++;
    }
}

std::vector<std::string> GetShapesNames()
{
    std::string line;

    std::ifstream myfile;
    myfile.open(PATH_TO_MODELS);

    int count = 0;

    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            if (count % 15 == 0) {
                collectionModelsName.push_back(line);
            }

            count++;
        }
    }

    return collectionModelsName;
}