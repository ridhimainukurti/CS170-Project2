#ifndef NNClassifier_H_
#define NNClassifier_H_
#include "Evaluation.h"
#include <vector>
#include <set>

using namespace std;

class NNClassifier{
    public:
    NNClassifier() {
        this->GivenData.clear();  
        this->setOfFeatures.clear();
    }
    ~NNClassifier() {};
    void Train(const vector<Node>& data, const set<int>& features);
    float Test(const Node& testNode) const;
    //float Test(const Node);
    private:
    std::vector<Node> GivenData;
    std::set<int> setOfFeatures;
};


#endif