#include <iostream>
#include <vector>
#include <set>
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random
#include "../header/Evaluation.h"
#include "../header/NNClassifier.h"
#include "../header/ReadFileClass.h"

using namespace std;

void displayMenu() {
    cout << "Welcome to [Your Name]'s Feature Selection Algorithm." << endl;
    cout << "Please enter total number of features: ";
}


void testNNClassifier() {
    cout << "\nTesting Nearest Neighbor Classifier Small Data\n";
    vector<Node> trainingData; 
    string fileName = "../DataFiles/small-test-dataset.txt";
    ReadFile ReadInData;
    ReadInData.ReadDataFromFile(fileName, trainingData);
    ReadInData.NormalizeData(trainingData);
    set<int> featureIndices = {2, 4, 6}; 
    Node testNode = trainingData.at(47); 
    trainingData.erase(trainingData.begin() + 47);
    NNClassifier nn;
    nn.Train(trainingData, featureIndices);

    float predictedClass = nn.Test(testNode);
    cout << "Test Node: ";
    for (float value : testNode.featureValues) {
        cout << value << " ";
    }
    cout << "\nPredicted Class: " << predictedClass << endl;
    cout << "Actual Class: " << testNode.NodeClassification << endl;

    fileName = "../DataFiles/large-test-dataset.txt";
    trainingData.clear();
    ReadInData.ReadDataFromFile(fileName, trainingData);
    ReadInData.NormalizeData(trainingData);
    featureIndices.clear();
    featureIndices = {0, 14, 26}; 
    testNode = trainingData.at(470); 
    trainingData.erase(trainingData.begin() + 470);

    nn.Train(trainingData, featureIndices);

    predictedClass = nn.Test(testNode);
    cout << "Test Node: ";
    for (float value : testNode.featureValues) {
        cout << value << " ";
    }
    cout << "\nPredicted Class: " << predictedClass << endl;
    cout << "Actual Class: " << testNode.NodeClassification << endl;

    cout << "End of Nearest Neighbor Test\n";
}

int main() {

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    //TESTING NEAREST NEIGHBOR CLASSIFIER
    testNNClassifier();


    // Step 1: User Input
    int totalFeatures;
    displayMenu();
    cin >> totalFeatures;

    cout << "Type the number of the algorithm you want to run:" << endl;
    cout << "1) Forward Selection" << endl;
    cout << "2) Backward Elimination" << endl;
    cout << "3) [Your Name]'s Special Algorithm" << endl;

    int choice;
    cin >> choice;

    // Step 2: Initialize necessary variables
    set<int> features;
    for (int i = 1; i <= totalFeatures; ++i) {
        features.insert(i);
    }

    vector<FeaturesAndAccuracy> trace;
    FeaturesAndAccuracy result;

    // Step 3: Execute selected algorithm
    switch (choice) {
        case 1:
            cout << "Using no features and \"random\" evaluation, I get an accuracy of "
                 << GetAccurracy({}) << "%" << endl;
            cout << "Beginning search." << endl;

            result = Forward_Selection(features, trace);
            //printTrace(trace);

            //printing out the final accuracy and best set
            cout << "Finished search!! The best feature subset is {";
            for (int feature : result._features) {
                cout << feature << " ";
            }
            cout << "}, which has an accuracy of " << result._accuracy << "%" << endl;
            break;

        case 2:
            cout << "Using all features and \"random\" evaluation, I get an accuracy of "
                 << GetAccurracy({features, 0}) << "%" << endl;
            cout << "Beginning search." << endl;

            result = Backwards_Elimination(features, trace);
            printTrace(trace); // Reusing forward trace printing for simplicity
            cout << "Finished search!! The best feature subset is {";
            for (int feature : result._features) {
                cout << feature << " ";
            }
            cout << "}, which has an accuracy of " << result._accuracy << "%" << endl;
            break;

        case 3:
            cout << "[Your Name]'s Special Algorithm is not implemented yet." << endl;
            break;

        default:
            cout << "Invalid choice! Please select a valid algorithm." << endl;
            break;
    }
    //cout << trace.size() << endl;

    return 0;
}