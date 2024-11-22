#include "../header/Evaluation.h"

#include <iostream>
#include <cmath>
using namespace std;

double GetAccurracy(FeaturesAndAccuracy x) //adjust in part 2 to do k fold validation
{
    return (fmod(rand(), 100));
}


FeaturesAndAccuracy Forward_Selection(const set<int>& givenFeatures, vector<FeaturesAndAccuracy> trace) {
    set<int> selectedFeatures;
    double finalAccuracy = -1.0;
    FeaturesAndAccuracy bestSet; 
    set<int> tempFeatures = givenFeatures; 

    //checks if the givenFeatures set is empty
    while (!tempFeatures.empty()) {
        //variables to keep track of the best accuracy and which feature gives that bestAccuracy
        double bestAccuracy = -1.0;
        int bestFeature = -1;
        FeaturesAndAccuracy currentSet; 

        //checking the accuracy for each feature 
        for (int feature : tempFeatures) {
            FeaturesAndAccuracy tempSet; 

            tempSet._features = selectedFeatures; 
            tempSet._features.insert(feature);
            double currentAccuracy = GetAccurracy(tempSet);
            selectedFeatures.erase(feature);

            //checks to see if currentAccuracy is the bestAccuracy
            if (currentAccuracy > bestAccuracy) {
                bestAccuracy = currentAccuracy; 
                bestFeature = feature; 
                currentSet = tempSet; 
            }

        }

        //like in hypothetical ex: F4 is now selection out of all F1, F2, F3, F4, F5
        selectedFeatures.insert(bestFeature);
        trace.push_back(currentSet); 

        //checking if the iteration accuracy is the overall best accuracy
        if (bestAccuracy > finalAccuracy) {
            finalAccuracy = bestAccuracy; 
            bestSet = currentSet; 
        }


        //remove the selected feature from the given features
        tempFeatures.erase(bestFeature);
    }
    return bestSet; 

}

void printForwardTrace(vector<FeaturesAndAccuracy>& trace) {
    for (const FeaturesAndAccuracy& entry : trace) {
        cout << "Using feature(s) {"; 
        for (int feature : entry._features) {
            cout << feature << " ";
        }
        cout << "} accuracy is " << entry._accuracy << "%" << endl;
    }
}

FeaturesAndAccuracy Backwards_Elimination(const std::set<int>& givenFeatures, std::vector<FeaturesAndAccuracy>& trace)
{
    FeaturesAndAccuracy currentSet;
    currentSet._features = givenFeatures; 
    currentSet._accuracy = GetAccurracy(currentSet);
    trace.push_back(currentSet);
     
    FeaturesAndAccuracy BestSet;
    BestSet._features = givenFeatures; 
    BestSet._accuracy = -1; 
    //for the the the number of features
    for(int i = 0; i < givenFeatures.size(); ++i)
    {
        currentSet = BE_Expand(currentSet, trace);
        
        if(currentSet._accuracy > BestSet._accuracy)
        {
            BestSet = currentSet;
        }
    }
    return BestSet;
}
FeaturesAndAccuracy BE_Expand( FeaturesAndAccuracy currentSet, std::vector<FeaturesAndAccuracy>& trace)
{
    FeaturesAndAccuracy ExpandedNode = currentSet;
    FeaturesAndAccuracy BestNodeToExpand;
    BestNodeToExpand._accuracy = -1;
    for(int i = 0; i < currentSet._features.size(); ++i ){
        set<int>::iterator it = ExpandedNode._features.begin();
        for(int j = 0; j < i; ++j)
        {
            ++it;
        }
        ExpandedNode._features.erase(it);
        ExpandedNode._accuracy = GetAccurracy(ExpandedNode); //get accuracy
        trace.push_back(ExpandedNode);  //put it in trace
        if(BestNodeToExpand._accuracy < ExpandedNode._accuracy)
        {
            BestNodeToExpand = ExpandedNode;
        }
        ExpandedNode = currentSet;
    }
    

    return BestNodeToExpand;
}
