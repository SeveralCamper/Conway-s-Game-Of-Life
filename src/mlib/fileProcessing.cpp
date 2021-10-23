#include <fileProcessing.h>
#include <Settings.h>

std::ifstream myfile;

void fileProcessing::openFile() {
    myfile.open(PATH_TO_MODELS);

    if (!myfile.is_open()) {
        std::cout << "Ошибка открытия файла" << std::endl;
    } else {
        std::cout << "Файл открыт" <<  std:: endl;
    }
}

void fileProcessing::closeFile() {
    myfile.close();
}