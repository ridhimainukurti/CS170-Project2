#include "../header/ReadFileClass.h"
#include <exception>
#include <iostream>
#include <cmath>

void ReadFile::ReadDataFromFile(std::string TextFileWithData, std::vector<Node>& DataToBeGained)
{
    std::ifstream DataStream(TextFileWithData);
    if(!DataStream.is_open())
    {
        throw std::runtime_error("File cannot be open");
    }
    std::string LineFromFile;
    
    while(getline(DataStream, LineFromFile))
    {
        std::stringstream NodeClassAndValues(LineFromFile);
        float values = 0;
        bool readClass = false;
        Node Current;
        while(NodeClassAndValues >> values)
        {
            if(readClass == false)
            {
                Current.NodeClassification = values;
                readClass = true;
            }
            else
            {
                Current.featureValues.push_back(values);
            }
        }
        /*std::cout << Current.NodeClassification << " ";
        for(int k = 0; k < Current.featureValues.size(); ++k)
        {
            std::cout << Current.featureValues.at(k) << " ";
        }
        std::cout << std::endl;*/
        DataToBeGained.push_back(Current);
    }
    DataStream.close();

}
void ReadFile::NormalizeData(std::vector<Node>& DataToBeGained)
{
    std::vector<float> meanValues;
    int NumberOfFeatures = DataToBeGained.at(0).featureValues.size();
    meanValues.resize(NumberOfFeatures);
    for(int i = 0; i < NumberOfFeatures; ++i)
    {   
        float meanOfFeatures = 0;
        for(int j = 0; j < DataToBeGained.size(); ++j)
        {
            meanOfFeatures = meanOfFeatures + DataToBeGained.at(j).featureValues.at(i);
        }
        meanValues.at(i) = meanOfFeatures/DataToBeGained.size();
    }
    /*for(int i = 0; i < meanValues.size(); ++i)
    {
        std::cout << meanValues.at(i) << std::endl;
    }*/
   std::vector<float> stdValues;
   stdValues.resize(NumberOfFeatures);
   for(int i = 0; i < NumberOfFeatures; ++i)
    {   
        float stDeviation = 0;
        for(int j = 0; j < DataToBeGained.size(); ++j)
        {
            stDeviation = stDeviation + pow(DataToBeGained.at(j).featureValues.at(i) - meanValues.at(i), 2);
        }
        stdValues.at(i) = sqrt(stDeviation/DataToBeGained.size());
    }
    /*std::cout<< std::endl;
    for(int i = 0; i < stdValues.size(); ++i)
    {
        std::cout << stdValues.at(i) << std::endl;
    }*/
   for(int i = 0; i < NumberOfFeatures; ++i)
    {   
        for(int j = 0; j < DataToBeGained.size(); ++j)
        {
            DataToBeGained.at(j).featureValues.at(i) = (DataToBeGained.at(j).featureValues.at(i) - meanValues.at(i))/stdValues.at(i);
        }
    }
}