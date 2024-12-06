#include <iostream>
#include <vector>
#include <set>
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random
#include "../header/Evaluation.h"
#include "../header/NNClassifier.h"
#include "../header/ReadFileClass.h"
#include "../header/Validator.h"

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

    std::clock_t start = clock();
    float predictedClass = nn.Test(testNode);
    std::clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "time took to find: " << duration << " seconds"<< endl;

    cout << "Test Node: ";
    for (float value : testNode.featureValues) {
        cout << value << " ";
    }
    cout << "\nfeatures: {2, 4, 6}" << endl; 
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

    cout << "start to find class of NODE" << endl;
    start = clock();
    predictedClass = nn.Test(testNode);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time took to find: " << duration << " seconds"<< endl;
    cout << "Test Node: ";
    for (float value : testNode.featureValues) {
        cout << value << " ";
    }
    cout << "\nfeatures: {0, 14, 26}" << endl; 
    cout << "\nPredicted Class: " << predictedClass << endl;
    cout << "Actual Class: " << testNode.NodeClassification << endl;

    cout << "End of Nearest Neighbor Test\n";
}

// Function to test ClassifierEvaluation
void testClassifierEvaluation() {
    cout << "\nTesting Validator with LOOCV on Small and Large Datasets\n";

    string smallFileName = "../DataFiles/small-test-dataset.txt";
    string largeFileName = "../DataFiles/large-test-dataset.txt";

    vector<Node> smallData, largeData;
    ReadFile readFile;
    Validator validator;
    NNClassifier nnClassifier;

    // Load and normalize small dataset
    readFile.ReadDataFromFile(smallFileName, smallData);
    readFile.NormalizeData(smallData);

    // Define feature subset for small dataset
    set<int> smallFeatureSubset = {2, 4, 6};
    cout << "features: {2, 4, 6}" << endl; 
    // Evaluate accuracy using LOOCV on small dataset

    
    cout << "Time to find accuracy" << endl;
    std::clock_t start = clock();
    double smallAccuracy = validator.ClassifierEvaluation(smallFeatureSubset, smallData, nnClassifier);
    std::clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "time took to find: " << duration << " seconds"<< endl;
    cout << "Small Dataset LOOCV Accuracy: " << smallAccuracy * 100 << "%" << endl;


    // Load and normalize large dataset
    readFile.ReadDataFromFile(largeFileName, largeData);
    readFile.NormalizeData(largeData);

    // Define feature subset for large dataset
    set<int> largeFeatureSubset = {0, 14, 26};
    cout << "features: {0, 14, 26}" << endl; 

    // Evaluate accuracy using LOOCV on large dataset
    cout << "Time to find accuracy" << endl;
    start = clock();
    double largeAccuracy = validator.ClassifierEvaluation(largeFeatureSubset, largeData, nnClassifier);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "time took to find: " << duration << " seconds"<< endl;
    cout << "Large Dataset LOOCV Accuracy: " << largeAccuracy * 100 << "%" << endl;

    cout << "End of Validator Test\n";
}

int main() {

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    //TESTING NEAREST NEIGHBOR CLASSIFIER
    //testNNClassifier();
    //testClassifierEvaluation();
    string FileNameSmall = "../DataFiles/small-test-dataset.txt";
    string FileNameLarge = "../DataFiles/large-test-dataset.txt";
    string FileNameTitanic = "../DataFiles/titanic_clean.txt";
    string FileToSelect;
    ReadFile TextDataRead;
    vector<Node> Data;
    TextDataRead.ReadDataFromFile(FileNameSmall, Data);

    int FileChoice = 0;
    cout<< "1. Small data" << endl;
    cout<< "2. Large data" << endl;
    cout<< "3. Titanic data" << endl;
    cout << "Select File to readFrom: ";

    cin >> FileChoice;
    switch(FileChoice)
    {
        case 1:
        FileToSelect = FileNameSmall;
        break;
        case 2:
        FileToSelect = FileNameLarge;
        break;
        case 3:
        FileToSelect = FileNameTitanic;
        break;
        default:
        FileToSelect = FileNameSmall; 
    }

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
    for (int i = 0; i < totalFeatures; ++i) {
        features.insert(i);
    }

    vector<FeaturesAndAccuracy> trace;
    FeaturesAndAccuracy result;

    // Step 3: Execute selected algorithm
    switch (choice) {
        case 1:
            cout << "Using no features and \"random\" evaluation, I get an accuracy of "
                 << GetAccurracy({}, Data) << "%" << endl;
            cout << "Beginning search." << endl;

            result = Forward_Selection(features, trace, Data);
            printTrace(trace);

            //printing out the final accuracy and best set
            cout << "Finished search!! The best feature subset is {";
            for (int feature : result._features) {
                cout << feature << " ";
            }
            cout << "}, which has an accuracy of " << result._accuracy << "%" << endl;
            break;

        case 2:
            cout << "Using all features and \"random\" evaluation, I get an accuracy of "
                 << GetAccurracy({features, 0}, Data) << "%" << endl;
            cout << "Beginning search." << endl;

            result = Backwards_Elimination(features, trace, Data);
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


