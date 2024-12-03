#ifndef READFILECLASS_H_
#define READFILECLASS_H_
#include "Evaluation.h"
#include <sstream>
#include <fstream>
class ReadFile{
    public:

    void ReadDataFromFile(std::string, std::vector<Node>& DataToBeGained);
    void NormalizeData(std::vector<Node>& DataToBeGained);

};


#endif