#ifndef NNClassifier_H_
#define NNCLassifier_H_
#include "Evaluation.h"


class NNClassifier{
    public:
    virtual void Train(const std::vector<Node>&, std::set<int>);
    virtual void Test(const Node);
    private:
    std::vector<Node> GivenData;
    std::set<int> setOfFeatures;
};


#endif