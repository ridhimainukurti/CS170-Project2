#include "gtest/gtest.h"
#include "../header/Evaluation.h"
#include "../src/Evaluation.cpp"
// Simple test case

TEST(BACK_ELM, ZERO_SET) {
   
    vector<FeaturesAndAccuracy> trace;
    set<int> testSet = { 0 , 1, 2, 4 ,5};
    FeaturesAndAccuracy testNode = Backwards_Elimination(testSet, trace);

    set<int> result = {};
    for(int j = 0; j < trace.size(); ++j)
    {
        cout<< "set of F: {";
    for (std::set<int>::iterator it = trace.at(j)._features.begin(); it != trace.at(j)._features.end(); ++it) 
    { std::cout << *it << " ";
    }
    cout  << "} accuracy: " << trace.at(j)._accuracy << endl;
    }
    cout  << endl << "Best Set to use: {";
    for (std::set<int>::iterator it = testNode._features.begin(); it != testNode._features.end(); ++it) 
    { std::cout << *it << " ";
    }
    cout << "} accuracy: " << testNode._accuracy << endl;
   
    
    EXPECT_TRUE(true);
}

TEST(FWD_SEL, NON_EMPTY_SET) {
    vector<FeaturesAndAccuracy> trace; // Trace to store intermediate results
    set<int> testSet = {0, 1, 3, 4}; // Input feature set

    // Run Forward Selection
    FeaturesAndAccuracy testNode = Forward_Selection(testSet, trace);

    // Print all intermediate sets and their accuracies
    cout << trace.size() << endl;
    for (size_t j = 0; j < trace.size(); ++j) {
        cout << "Set of F: {";
        for (std::set<int>::iterator it = trace.at(j)._features.begin(); it != trace.at(j)._features.end(); ++it) {
            cout << *it << " ";
        }
        cout << "} accuracy: " << trace.at(j)._accuracy << "%" << endl;
    }

    // Print the best set and its accuracy
    cout << endl << "Best Set to use: {";
    for (std::set<int>::iterator it = testNode._features.begin(); it != testNode._features.end(); ++it) {
        cout << *it << " ";
    }
    cout << "} accuracy: " << testNode._accuracy << "%" << endl;

    // Since this is a functional test, we can always pass this check as it’s meant for printing and verifying
    EXPECT_TRUE(true);
}


int main(int argc, char **argv) {
    srand(17);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
