#include "models.h"

std::ifstream myfile("input/models.txt");
std::string line;
std::string search = "flasher";
std::vector<std::string> modelsName;

int arr[13][13];

int count = 0;

void TestInput()
{
    std::fstream myfile("input/models.txt");
    if (myfile) {
        while (getline(myfile, line)) {
            count++;

            if (line.find("flasher") != std::string::npos) {
                break;
            }
        }

    } else
        std::cout << "Error!" << std::endl;

    std::cout << "----" << count << std::endl;

    std::fstream myfile1("input/models.txt");
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

void GetShapesNamesInArr()
{
    std::string line;

    std::ifstream myfile;
    myfile.open("input/models.txt");
    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            modelsName.push_back(line);
        }
    }
    modelsName.push_back(line);
}
