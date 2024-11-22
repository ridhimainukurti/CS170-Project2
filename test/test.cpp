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

int main(int argc, char **argv) {
    srand(17);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
