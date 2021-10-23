#include <fileProcessing.h>
#include <Settings.h>

int arr[13][13];

std::ifstream myfile;
std::string line;
std::string search = "flasher";
std::vector<std::string> collectionModelsName;
std::vector<std::string> dumpFile;

void OpenFile() {
    myfile.open(PATH_TO_MODELS);

    if (myfile.is_open()) {
        std::cout << "Succsess" << std::endl;
    } else {
        std::cout << "Error2!" <<  std:: endl;
    }
}

void CloseFile() {
    myfile.close();
}

void FindModelIndex(std::string nameModel) {
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

void ShowCollectionShapesName(std::vector<std::string> collectionModelsName) {
    for (int i = 0; i < (int) collectionModelsName.size(); i++) {
        std::cout << collectionModelsName[i] << std::endl;
    }
}

std::vector<char> GetModel(int index) {
    std::vector<char> matrixInLine;
    if (myfile.is_open()) {
        std::cout << "Вывод дампа файла" << std::endl;
    }
        //matrixInLine.push_back(myfile.get(symbol));
    return matrixInLine;
}

std::vector<std::string> GetDumpFile() {
    std::string line;
    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            std::cout << line << std::endl;
            dumpFile.push_back(line);
        }
    }
    return dumpFile;
}

void ShowDump() {
    for (int i = 0; i < (int) dumpFile.size(); i++) {
        std::cout << dumpFile[i] << std::endl;
    }
}

std::vector<std::string> GetShapesNames() {
    int count = 0;
    std::cout << "GetShapesNames" << std::endl;
    for (int i = 0; i < (int)dumpFile.size(); i++) {
        if (i % 15 == 0) {

            collectionModelsName.push_back(dumpFile[i]);
            count++;
        }
    }
    std::cout << "COunbt "<< count << std::endl;
    return collectionModelsName;
}
