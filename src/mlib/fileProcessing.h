#ifndef FILE_PROCESSING_H_
#define FILE_PROCESSING_H_

#include <fstream>
#include <iostream>

#include "Settings.h"

std::vector<char> GetModel(int index);
std::vector<std::string> GetDumpFile();
std::vector<std::string> GetShapesNames();

char GetShape(int index);

void ShowDump();
void OpenFile();
void CloseFile();
void FindModelIndex(std::string nameModel);
void ShowCollectionShapesName(std::vector<std::string> collectionModelsName);


#endif //  FILE_PROCESSING_H_