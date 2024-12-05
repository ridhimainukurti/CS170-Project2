#include "../header/NNClassifier.h"
#include <cmath>    // For sqrt
#include <limits>   // For numeric_limits

using namespace std;

//store training data and feature indices
void NNClassifier::Train(const vector<Node>& data, const set<int>& features) {
    GivenData = data;
    setOfFeatures = features;
}

//classify the test node using nearest neighbor
float NNClassifier::Test(const Node& testNode) const {
    float minDistance = numeric_limits<float>::max();  //starting off with a large distance
    const Node* nearestNode = nullptr;                

    for (const Node& trainNode : GivenData) {
        float distance = 0.0;

        for (int featureIndex : setOfFeatures) {
            float diff = testNode.featureValues[featureIndex] - trainNode.featureValues[featureIndex];
            distance += diff * diff; 
        }
        distance = sqrt(distance); 

        // update nearest neighbor if a closer one is found
        if (distance < minDistance) {
            minDistance = distance;
            nearestNode = &trainNode;  
        }
    }

    //returning the class identification
    if (nearestNode != nullptr) {
        return nearestNode->NodeClassification;
    } else {
        return -1;  
    }
}
