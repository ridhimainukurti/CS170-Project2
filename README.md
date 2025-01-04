# CS170-Project2

Final Report for Project 2
By: Ananya Sood, Ridhima Inukurti, and Jesus Montes 

Link to release (part 3): https://github.com/ridhimainukurti/CS170-Project2/releases 

## Our Findings: Brief Comparison of Forwards Selection and Backwards Elimination:
The purpose of forwards selection and backwards elimination feature selection techniques is to identify the most relevant features for a predictive model. Essentially forwards selection starts with an empty set of features and then iteratively adds the more significant feature at each step. What forwards selection does is that it evaluates the features that have not been selected (in this case evaluates based on accuracy), and then determines which feature improves the models performance, and then adds that feature to the feature subset, calculating the accuracy of those subsets of features. It will continue this process until adding new features no longer significantly improves the model, or if the desired number of features is selected. On the other hand, backwards selection starts with all of the available features and then iteratively removes the least significant feature. At each step, what backwards selection does is that it sees the accuracy of the model based on removing one of the features, and then will get rid of the feature that contributes the least to the performach of the model. Backwards selection will continue this process until removing additional features harms the performance or when the desired feature subset is reached. Essentially, forwards selection builds up the feature in each step, while backwards selection prunes the feature subset.
  
## Forwards Selection: Small DataSet (Forward):
[![Screenshot](./desktop/Screenshot 2025-01-04 at 12.01.54 PM.png)]
 

The forward selection method incrementally evaluates feature subsets and uses the five features that were selected in the beginning. Starting with individual features, it selects the subset that maximizes accuracy. The process reveals that the subset {2,4} achieves the best accuracy.
Large DataSet (Forward):

The large dataset undergoes the same forward selection. The best feature subset identified is {1}, showing that one feature is sufficient to achieve optimal accuracy for this dataset

Titanic DataSet (Forward):

The forward selection on the Titanic dataset shows a progressive improvement in accuracy. The final optimal subset {1} achieves the highest accuracy among the subsets.

Backward Elimination:
Small DataSet (Backward):

Starting with all features, the backward elimination removes the least significant features iteratively. The final subset {2,4} achieves the best accuracy, consistent with the forward selection results.

Large DataSet (Backward):

Similar to the forward approach, backward elimination identifies {1} as the optimal subset, demonstrating consistency in results for the large dataset.

Titanic (Backward):

Backward elimination results align with forward selection, identifying {1} as the optimal subset for accuracy in the Titanic dataset.

**(Additionally videos for Forwards Selection and Backwards Elimination): 
Forward Selection: Selected all 40 features:
FS Trace On YouTube
Backwards Elimination: Selected all 40 features:
BE Trace On YouTube

Comparison of the Images (For Forwards Selection and Backward Elimination for each Dataset):
Across all three datasets, both forward selection and backward elimination yield identical results, demonstrating the reliability of these algorithms. While the methods use opposing strategies, forward selection builds up from no features and backward elimination starts with all features-their convergence on the same optimal subsets validates their ability to get the most significant features. The small datasets benefit from a combination of two features reflecting a more evenly distributed relevance. The large dataset and the titanic dataset are dominated by one key feature emphasizing the limited importance of additional features. 

Contribution of Each Student In the Group:
Part 1: Forward Selection and Test (to ensure functionality) - Ridhima
	Backwards Elimination and Test (to ensure functionality)  - Jesus 
	Main Implementation - Ananya 
Part 2:  NN-Classifier and Test (to ensure functionality) - Ridhima 
	Evaluation (leave-on-out validator) and Test (to ensure functionality) - Ananya 
	ReadFile and Normalize Methods - Jesus
Part 3:  Putting it All Together - Jesus
Report: Everyone :)


Challenges:
At the start of this project in part 1, there were some issues in the development of greedy searches, forward selection and backwards elimination. There was some confusion among the group in how forward selection and backwards elimination worked. Forward Selection had some implementation issues on the initial try, but issues were able to be solved. For Part 2 the most challenging portion was just understanding implementation and how it should be designed. Once a plan and design was made, the implementation went relatively smoothly with minor bug fixes in print out statements. We also created test functions within the main with test data in order to check whether our NN-Classifier and validator methods were working efficiently. For part 3, an unseen issue in part 1 Forward Selection arose and took a bit to adjust in order to get a consistent trace but it wasn't a massive issue. In the combination of part 1 and 2, due to the required validator being O(n^2) the large data set took a while to get the best features of. 

Design (objects and methods):  


Our design follows an object-oriented approach, where the four main classes used are: ReaderFileClass, NNClassifer, Validator, and Evaluation. The ReaderFileClass is responsible for reading data from the specified file, normalizing it and returning a vector of Node objects. This class simplifies the process of data acquisition and ensures that the data is prepared for further processing. The NNClassifer class contains a set of features and a vector of Node objects used for training and testing. The train method initializes the classifier by accepting a set of features while the test method is responsible for determining the class of a given Node based on its features. We use these methods to perform the nearest neighbor classifier. The Validator class evaluates the performance of the nearest neighbor classifier. It includes a validation method which calculates the accuracy of the classifier by testing it on a given dataset and using a specified set of features. The Evaluation class’s main functionality is to manage the feature selection algorithms such as forward selection and backward elimination. The getAccuracy function is responsible for calculating the accuracy of a given feature set by utilizing the NNclassifer and validator methods and classes. The forward selection iteratively selects the best features from a given set of features maximizing the classification accuracy at each step. The backward elimination works in a similar way but in reverse where it starts with all features and then removes the least relevant ones continually evaluating the accuracy after each feature removal. 
 
Optimizing Code: 
To optimize our code we made a strategic use of sets. The sets were useful because they automatically ensured that the feature indices are unique and they allowed for fast lookups, insertions and deletions which were all within the time complexity of O(1). This was critical during the training and testing phases where we needed to efficiently select and access subsets of features. Additionally the use of sets for feature subsets ensured that there were no duplicate features that were processes which reduced redundant calculations making the algorithm more efficient

Another important data structure used was a vector which helped extensively store the training data as well as hold the features values for each of the nodes. The structure allowed for fast random access which is essential when iterating through data during the training and evaluation steps. Moreover, vectors are memory efficient in terms of store as they allocate contiguous memory blocks. 

Also to enhance efficiency we implemented the leave one out cross validation method which ensures that we are testing the model on each data point while training it on all other points providing an evaluation of model accuracy without excessive memory usage. We also minimize memory footprint by creating temporary training sets within each iteration. 

By using these techniques, vectors and sets we strike a good balance between fast lookups and memory efficient data stores and ultimately improving the speed and scalability of our classifier. 

Plots for Features:
Figure 1.1

Best Feature Deemed by FS Features{1,27} for the large data set with a 95% accuracy (Plot above). The Red plots are of class 1 and the blue plots are of class 2.

Figure 1.2

Best Feature Deemed by FS Features{3,5} for the small set, with a 92% accuracy :(Plot Above)The Red plots are of class 1 and the blue plots are of class 2.
Figure 1.3


Not the best set of features {2, 7} for Small data set with a 54% accuracy (Plot Above) The Red plots are of class 1 and the blue plots are of class 2.


Figure 1.4

Not the best set of features {24, 27} for Large data set with a 81.2% accuracy (Plot Above)
The Red plots are of class 1 and the blue plots are of class 2.
Figure 1.5

Best set of features {2} for titanic data set with a 78% accuracy (Bar Graph Above) Since there's only one feature (Male and Female) as the best we used a stacked bar chart to differentiate between the ratio who lived or not.  Red means they did survive and black means they didn’t.
Figure 1.5

Non optimal of features {4, 5} for titanic data set with a 42% accuracy (Plot above) Red means they didn't survive and blue means they did, however this graph is slightly skewed because these plots are overlapping, there are smudged labels due to these overlapping plots of different classes.

Analysis of the Plots:
For Figure 1.1 we have a plot for the large data set using the features {1, 27}. Our Program deduced via KOOCV that the model has an accuracy of 95%. Plotting these features on a graph as shown above makes the great accuracy evident. Class 1 shown by the red plot are grouped together near the center of the plane, to be a bit more precise for Feature 1, if an unknown class’s feature 1 falls in the domain between approximately (-1, 1) it will fall into class 1, otherwise if its domain falls between approx (-inf, -1,) U (1, inf). Likewise for Feature 27, for an unknown class, if their feature falls in the approximate range of (0, 1) then it is of class 1, otherwise if it's in the range (-inf , 0) U (1, inf) then it will be of class 2. 

For Figure 1.2 we have a plot for the small data set using the features {3, 5}. Our Program deduced via KOOCV that the model has an accuracy of 92%. Plotting these features on a graph as shown above makes it evident of its accuracy. Class 1 shown by the red plot are grouped together near the center of the plane, to be a bit more precise for Feature 3, if an unknown class’s feature 3 falls in the domain between approximately (-1, 1) it will fall into class 1, otherwise if its domain falls between approx (-inf, -1,) U (1, inf). Likewise for Feature 27, for an unknown class, if their feature falls in the approximate range of (0, .75) then it is of class 1, otherwise if it's in the range (-inf , 0) U (.75, inf) then it will be of class 2. 

For Figure 1.3 we have a plot for the small data set using the features {2, 7}. Our Program deduced via KOOCV that the model has an accuracy of 54%. Plotting these features on a graph as shown above makes the subpar accuracy visible. Class 1 shown by the red plots on the plane have no real groups or locations in which they converge. They mix in with class 2 denoted by blue, The Nearest neighbor of class 1 could either be class 1 or class 2 given how there's no real convergence or threshold between them using the features {2,7}

For Figure 1.4 we have a plot for the small data set using the features {24, 27}. Our Program deduced via KOOCV that the model has an accuracy of 82%. Plotting these features on a graph as shown above demonstrates the mediocre accuracy of the model with these features.  Class 1 is shown by the red plot and it appears at first glance that there is a pattern. Class 1’s domain for feature 27, Class one’s range is from (0,1), which can be seen by the red bar it appears to make, however looking at it further, class 2 range also crosses that boundary from (0,1) with blue collections within the red bar. This explains its mediocre accuracy, while the range of (0,1) for feature 27 can differentiate between the 2, the blue spots within the bar A.) does not completely differentiate between classes, and B.) can miss classify an unseen instance because its nearest neighbor can be blue. 

For Figure 1.5 we have a plot for the titanic data set using the features {2}. Our Program deduced via KOOCV that the model has an accuracy of 78%. Using the stacked bar chart we can see why we have a 78% accuracy. If we break down the data we have the following: Tot Death = 424, Tot Survive 290, Tot Females: 261 Female Death: 64, Female Survival: 197, Tot Male: 453, Male Death: 360, Male Survival: 93. Taking the ratio of total female passengers to their survival we have 197/261 = 0.755, and for their male counterparts is 93/453 =0.205. We can make the same ratio expect with there deaths which result in 
360/453= 0.795 for Male Death to Total and 64/261 =0.245 Female Death to total. So When the NN classifier finds their nearest neighbor based on their gender, if their NN is male they are more likely to be dead and if they are female they are more likely to have survived. 
For Figure 1.6 we have a plot for the titanic data set using the features {4, 5}. Our Program deduced via KOOCV that the model has an accuracy of 42%. Using the stacked bar chart we can see the why we have a 42% accuracy.It initially looks like we have a distinct pattern based on the color, that under a certain threshold of parent child relationships and siblings spouses relationships we can find a pattern in survival rate, however looking closer at the graph there are smudges for the labels, because some plots have overlappings of survival and non survival cases with the same values for both features. Having an instance of the survival class with the same feature values as an instance of the non survival class effectively makes their euclidean distance the same, so in essence is a random 50-50 to know if they survived based on parch and Sibsp. 

Effect of Normalizing the Data:
Normalization is crucial for improving classification accuracy by ensuring that all features are scaled uniformly. Without normalization, features with larger numerical ranges, such as age or fare in the Titanic dataset, can dominate distance calculations in k-NN, skewing results and reducing the classifier’s effectiveness. By rescaling features to a similar range, normalization ensures that each feature contributes equally to the model's decisions. This process is particularly important for algorithms that rely on distance metrics, as it enhances their ability to accurately compare data points and identify patterns across features with varying scales.

Comparison of Different Algorithms:
Backward Elimination vs. Forward Selection:
Runtime: Both will use the same Validator and Classifier themselves so they will be the same in that regard, so they'll take the same run time in that regard. However Forward Selection is faster, and that is due to the implementation of it Backward elimination, using a helper function containing a nested loop, it uses more time to come to a solution than Forward Selection
Space:
Again Both use the same validator and Classifier, however once again Forward Selection is better in the regard of space once again due to backward elimination implementation, adding more lines of code to the stack than Forward selection due to several function calls and nested loops.
Accuracy: 
Finally Forward Selection is more accurate, in ML only a few features are really needed to classify unseen instances in supervised learning situations. Adding more features in most cases is overfitting and less accurate in the long run. So with Forward Selection it starts with none and adds the best it can find, and will most likely find the most accurate route. But for BE, it starts with a set of nonoptimal features and slowly removes them and may be set on a poorer set of features based on what greedy deems is best.  

Conclusion:
Our project demonstrates the effectiveness of both forward selection and backward elimination as feature selection techniques, yielding consistent results across various datasets, including small, large and Titanic data. Both methods, through opposite approaches, identified the same optimal feature subsets, validating their reliability. The use of normalization proved crucial in improving classifier accuracy by ensuring uniform contribution of features. Additionally, the design of our project with classes like ReaderFileClass, NNClassifer, Validator, and Evaluation facilitate modularity and maintainability. While the implementation faced some initial challenges the results highlight the importance of efficient feature selection and data normalization in achieving high accuracy. Overall the project underscores the value of using both forward selection and backward elimination to enhance model performance. 
