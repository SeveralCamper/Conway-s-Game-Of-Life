#include <Settings.h>
#include <fileProcessing.h>

std::vector<std::string> collectionModelsName;

std::ifstream myfile;
std::string line;
std::string search = "flasher";
std::vector<std::string> dumpFile;

void OpenFile()
{
    myfile.open(PATH_TO_MODELS);

    if (myfile.is_open()) {
        std::cout << "File opened successfully" << std::endl;
    } else {
        std::cout << "Error! File can't be open" << std::endl;
    }
}

void CloseFile()
{
    myfile.close();
}

void ShowCollectionShapesName(std::vector<std::string> collectionModelsName)
{
    for (int i = 0; i < (int)collectionModelsName.size(); i++) {
        std::cout << i << ". " << collectionModelsName[i] << std::endl;
    }
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

char GetShape(char arrayShape[13][13], int index)
{
    int ii = 0;
    for (int i = index * 15 + 1; i < (int)index * 15 + 14; i++) {
        for (int j = 0; j < (int)dumpFile[i].size(); j++) {
            arrayShape[ii][j] = (dumpFile[i])[j]; 
            std::cout << "arrayShape[" << ii << "][" << j << "]= " << (dumpFile[i])[j] << std::endl; 
        }
        ii++;
    }
    return arrayShape[0][0];
}

std::vector<std::string> GetShapesNames()
{
    return collectionModelsName;
}

std::vector<std::string> SetShapesNames()
{
    for (int i = 0; i < (int)dumpFile.size(); i++) {
        if (i % 15 == 0) {
            collectionModelsName.push_back(dumpFile[i]);
        }
    }
    
    return collectionModelsName;
}
