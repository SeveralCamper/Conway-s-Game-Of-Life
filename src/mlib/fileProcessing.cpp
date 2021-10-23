#include <Settings.h>
#include <fileProcessing.h>

std::ifstream myfile;
std::string line;
std::string search = "flasher";
std::vector<std::string> collectionModelsName;
std::vector<std::string> dumpFile;

void OpenFile()
{
    myfile.open(PATH_TO_MODELS);

    if (myfile.is_open()) {
        std::cout << "Succsess" << std::endl;
    } else {
        std::cout << "Error2!" << std::endl;
    }
}

void CloseFile()
{
    myfile.close();
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

void ShowCollectionShapesName(std::vector<std::string> collectionModelsName)
{
    for (int i = 0; i < (int)collectionModelsName.size(); i++) {
        std::cout << collectionModelsName[i] << std::endl;
    }
}

std::vector<char> GetModel(int index)
{
    std::vector<char> matrixInLine;
    if (myfile.is_open()) {
        std::cout << "Вывод дампа файла" << std::endl;
    }
    // matrixInLine.push_back(myfile.get(symbol));
    return matrixInLine;
}

std::vector<std::string> GetDumpFile()
{
    std::string line;
    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            std::cout << line << std::endl;
            dumpFile.push_back(line);
        }
    }
    return dumpFile;
}

void ShowDump()
{
    for (int i = 0; i < (int)dumpFile.size(); i++) {
        std::cout << dumpFile[i] << std::endl;
    }
}

char GetShape(int index)
{
    char arrayShape[13][13];
    int ii = 0;
    for (int i = index * 15 + 1; i < (int)index * 15 + 14; i++) {
        for (int j = 0; j < (int)dumpFile[i].size(); j++) {
            arrayShape[ii][j] = (dumpFile[i])[j];
/* 
            std::cout << "arrayShape[" << ii << "][" << j << "]= " << (dumpFile[i])[j] << std::endl; */
        }
        ii++;
    }

    return arrayShape[0][0];
}

std::vector<std::string> GetShapesNames()
{
    int count = 0;
    std::cout << "GetShapesNames" << std::endl;
    for (int i = 0; i < (int)dumpFile.size(); i++) {
        if (i % 15 == 0) {
            collectionModelsName.push_back(dumpFile[i]);
            count++;
        }
    }
    std::cout << "COunbt " << count << std::endl;
    return collectionModelsName;
}
