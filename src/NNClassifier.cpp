#include "../header/NNClassifier.h"
#include <cmath>    // For sqrt and pow
#include <limits>   // For std::numeric_limits

using namespace std:

// Virtual Train method implementation: Store the training data and selected features
void NNClassifier::Train(const vector<Node>& data, const set<int>& features) {
    trainingData = data;        
    featureIndices = features; 
}

// Virtual Test method implementation: Classify a test instance using nearest neighbor rule
float NNClassifier::Test(const Node& testNode) const {
    float minDistance = std::numeric_limits<float>::max();  // Initialize with a very large value
    float predictedClass = -1;                              // Placeholder for predicted class label

    // Iterate over all training instances
    for (const Node& trainNode : trainingData) {
        // Compute the Euclidean distance between the test node and the current training node
        float distance = 0.0;
        for (int featureIndex : featureIndices) {
            // Sum up the squared differences for the selected features
            float diff = testNode.featureValues[featureIndex] - trainNode.featureValues[featureIndex];
            distance += diff * diff;
        }
        distance = std::sqrt(distance);  // Take the square root for final Euclidean distance

        // If this is the nearest neighbor so far, update the minimum distance and class label
        if (distance < minDistance) {
            minDistance = distance;
            predictedClass = trainNode.NodeClassification;  // Update the predicted class label
        }
    }

    return predictedClass;  // Return the class label of the nearest neighbor
}
