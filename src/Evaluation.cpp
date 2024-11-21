#include "../header/Evaluation.h"

double GetAccurracy(FeaturesAndAccuracy) //adjust in part 2 to do k fold validation
{
    return (rand() % 100);
}
FeaturesAndAccuracy Forward_Selection(const std::set<int>& givenFeatures,std::vector<FeaturesAndAccuracy> trace)
{


}
FeaturesAndAccuracy Backwards_Elimination(const std::set<int>& givenFeatures, std::vector<FeaturesAndAccuracy> trace)
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
}
FeaturesAndAccuracy BE_Expand( FeaturesAndAccuracy currentSet, std::vector<FeaturesAndAccuracy>& trace)
{
    FeaturesAndAccuracy ExpandedNode = currentSet;
    FeaturesAndAccuracy BestNodeToExpand;
    BestNodeToExpand._accuracy = -1;
    for(int i = 0; i < currentSet._features.size(); ++i )
    {
        auto it = currentSet._features.begin(); //get iterator at begining
        std::advance(it, i);  //get item j from begining
        ExpandedNode._features.erase(it); //remove it from set
        ExpandedNode._accuracy = GetAccurracy(ExpandedNode); //get accuracy
        trace.push_back(ExpandedNode);  //put it in trace
        if(BestNodeToExpand._accuracy > ExpandedNode._accuracy)
        {
            BestNodeToExpand = ExpandedNode;
        }
    }
}
