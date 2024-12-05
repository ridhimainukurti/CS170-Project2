#ifndef VALIDATOR_H_
#define VALIDATOR_H_
#include <set>
#include <vector>
#include "Evaluation.h"
#include "NNClassifier.h"


class Validator{
public:
    double ClassifierEvaluation(std::set<int>, std::vector<Node>&, NNClassifier);
};

#endif