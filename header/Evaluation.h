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
struct featureNode
{
    std::set<int>_features;
};

//adjust functions in part 2 to do k fold validation and to deal with classifiers
double GetAccurracy(featureNode); //adjust in part 2 to do k fold validation
const std::vector<FeaturesAndAccuracy> Forward_Selection(const std::set<int>&, int numberOfFeatures);
const std::vector<FeaturesAndAccuracy> Backwards_Elimination(const std::set<int>&, int numberOfFeatures, int size_of_set);

#endif