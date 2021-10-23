#ifndef FILE_PROCESSING_H_
#define FILE_PROCESSING_H_

#include <fstream>
#include <iostream>

#include "Settings.h"


void openFile();
void closeFile();
std::vector<char> getModel(int index);
std::vector<std::string> getShapesNames();
void findModelIndex(std::string nameModel);
void printCollectionModelsName(std::vector<std::string> collectionModelsName);

#endif //  FILE_PROCESSING_H_