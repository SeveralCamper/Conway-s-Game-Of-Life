#include "models.h"

std::string line;
std::vector<std::string> modelsName;
std::ifstream myfile("input/models.txt");
std::string search = "flasher";

int arr[13][13];

int count = 0;

void TestInput()
{
    /* myfile.open("input/models.txt");
    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            modelsName.push_back(line);
        }
    }  */

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

    /*
            int flag = 0;

            while (getline(myfile, line)) {


                if (flag == 14) {
                    std::cout << line << std::endl;
                }
                flag++;
            } */

    /* myfile.open("input/models.txt");
    if (myfile.is_open()) {
        int i = 0;

        std::cout << "23" << std::endl;

        while (std::getline(myfile, line)) {
            std::cout << "33" << std::endl;

            for (int j = 0; j < 13; j++) {
                arr[i][j] = stoi(line.substr(j, j + 1));
                std::cout << line.substr(j, j + 1) << std::endl;
            }
            i++;
        }
    }

    int vector_size = modelsName.size();

    modelsName.push_back(line);

    for (int i = 0; i < vector_size; i += 15) {
        std::cout << modelsName[i] << std::endl;
    }

    for (int i = 0; i < 13; i++) {
        std::cout << std::endl;
        for (int j = 0; j < 13; j++)
            std::cout << arr[i][j];
    } */
}