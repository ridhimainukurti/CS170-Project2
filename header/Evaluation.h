#ifndef _EVALUATION_H
#define _EVALUATION_H

#include<vector> 
#include<set>
#include <cstdlib>

struct FeaturesAndAccuracy
{
    std::set<int> _features;
    double _accuracy;
};

struct Node
{
    std::vector<float> featureValues;
    float NodeClassification;
};

//adjust functions in part 2 to do k fold validation and to deal with classifiers
double GetAccurracy(FeaturesAndAccuracy, std::vector<Node>&); //adjust in part 2 to do k fold validation
void printForwardTrace(std::vector<FeaturesAndAccuracy>& trace); //print the trace for each of the iterations in the forward selection algorithm
FeaturesAndAccuracy Forward_Selection(const std::set<int>& givenFeatures, std::vector<FeaturesAndAccuracy>& trace, std::vector<Node>&);
FeaturesAndAccuracy Backwards_Elimination(const std::set<int>& givenFeatures, std::vector<FeaturesAndAccuracy>& trace, std::vector<Node>&);
void printTrace(std::vector<FeaturesAndAccuracy> trace); //print the trace for each of the iterations in the forward selection algorithm
FeaturesAndAccuracy BE_Expand( FeaturesAndAccuracy currentSet, std::vector<FeaturesAndAccuracy>& trace, std::vector<Node>&);
//FeaturesAndAccuracy FS_Expand( FeaturesAndAccuracy currentSet, std::vector<FeaturesAndAccuracy>& trace, const std::set<int>&);




#endif