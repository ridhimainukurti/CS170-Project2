#include "../header/Validator.h"
#include "../header/NNClassifier.h"
#include <iostream>
#include <vector>
#include <set>

// Implementation of ClassifierEvaluation using leave one out validation method
double Validator::ClassifierEvaluation(std::set<int> featureSubset, std::vector<Node>& nodes, NNClassifier classifier) {
    double totalCorrect = 0.0;
    double totalEvaluated = nodes.size();

    // Iterate over each instance as the test instance
    for (size_t testIndex = 0; testIndex < nodes.size(); ++testIndex) {
        // Create training data by excluding the test instance
        std::vector<Node> trainingData;
        for (size_t i = 0; i < nodes.size(); ++i) {
            if (i != testIndex) {
                trainingData.push_back(nodes[i]);
            }
        }

        // Train the classifier on the training data
        classifier.Train(trainingData, featureSubset);

        // Classify the left-out test instance
        Node& testInstance = nodes[testIndex];
        int predictedLabel = classifier.Test(testInstance);
        int actualLabel = testInstance.NodeClassification;

        // Check if the classification is correct
        if (predictedLabel == actualLabel) {
            totalCorrect++;
        }
    }

    // Calculate and return the accuracy
    return totalEvaluated > 0 ? (totalCorrect / totalEvaluated) : 0.0;
}
