#include <iostream>
#include <vector>
#include <set>
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random
#include "../header/Evaluation.h"
#include "../header/NNClassifier.h"

using namespace std;

void displayMenu() {
    cout << "Welcome to [Your Name]'s Feature Selection Algorithm." << endl;
    cout << "Please enter total number of features: ";
}


void testNNClassifier() {
    cout << "\nTesting Nearest Neighbor Classifier\n";
    vector<Node> trainingData = {
        {{1.0, 2.0, 3.0}, 0},  // Node 1: Class 0
        {{4.0, 5.0, 6.0}, 1},  // Node 2: Class 1
        {{7.0, 8.0, 9.0}, 1},  // Node 3: Class 1
        {{1.1, 2.1, 3.1}, 0}   // Node 4: Class 0
    };

    set<int> featureIndices = {0, 1, 2}; 

    NNClassifier nn;
    nn.Train(trainingData, featureIndices);
    Node testNode = {{1.2, 2.2, 3.2}, -1}; 

    float predictedClass = nn.Test(testNode);
    cout << "Test Node: ";
    for (float value : testNode.featureValues) {
        cout << value << " ";
    }
    cout << "\nPredicted Class: " << predictedClass << endl;

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