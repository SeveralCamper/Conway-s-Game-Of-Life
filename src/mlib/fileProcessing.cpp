#include <fileProcessing.h>
#include <Settings.h>

int arr[13][13];

std::ifstream myfile;
std::string line;
std::string search = "flasher";
std::vector<std::string> collectionModelsName;

void openFile() {
    myfile.open(PATH_TO_MODELS);

    if (myfile.is_open()) {
        std::cout << "Succsess" << std::endl;
    } else {
        std::cout << "Error2!" <<  std:: endl;
    }
}

void closeFile() {
    myfile.close();
}

void findModelIndex(std::string nameModel) {
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
        std::cout << "Error4!" << std::endl;
}

/*void TestInput()
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
}*/

void printCollectionModelsName(std::vector<std::string> collectionModelsName) {
    for (int i = 0; i < (int) collectionModelsName.size(); i++) {
        std::cout << collectionModelsName[i] << std::endl;
    }
}

std::vector<char> getModel(int index) {
    std::vector<char> matrixInLine;
    char symbol;
    if (myfile.is_open()) {
        for (int i = index * 14 + 1; i < index * 14 + 13; i++) {
            while(myfile.get(symbol)){

            }
            std::cout << i << "=" << symbol << std::endl;
        }
    }
        //matrixInLine.push_back(myfile.get(symbol));
    return matrixInLine;
}

std::vector<std::string> getShapesNames() {
    std::string line;
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