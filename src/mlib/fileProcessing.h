#ifndef FILE_PROCESSING_H_
#define FILE_PROCESSING_H_

#include <fstream>
#include <iostream>

#include "Settings.h"

void ShowDump();
void OpenFile();
void CloseFile();
std::vector<char> GetModel(int index);
std::vector<std::string> GetDumpFile();
std::vector<std::string> GetShapesNames();
void FindModelIndex(std::string nameModel);
void ShowCollectionShapesName(std::vector<std::string> collectionModelsName);

#endif //  FILE_PROCESSING_H_