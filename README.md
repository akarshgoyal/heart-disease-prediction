# heart-disease-prediction
using data mining to predict the prevalence of a heart disease 
Methods
A. Data Mining
Although data mining has been around for more than two decades, its potential is only being realized now. Data mining combines statistical analysis, machine learning and database technology to extract hidden patterns and relationships from large databases. Fayyad defines data mining as “a process of nontrivial extraction of implicit, previously unknown and potentially useful information from the data stored in a database”. Giudici defines it as “a process of selection, exploration and modeling of large quantities of data to discover regularities or relations that are at first unknown with the aim of obtaining clear and useful results for the owner of database”. Data mining uses two strategies: supervised and unsupervised learning. In supervised learning, a training set is used to learn model parameters whereas in unsupervised learning no training set is used (e.g., k- means clustering is unsupervised).
Each data mining technique serves a different purpose depending on the modeling objective. The two most common modeling objectives are classification and prediction. Classification models predict categorical labels (discrete, unordered) while prediction models predict continuous-valued functions. Decision Trees and Neural Networks use classification algorithms while Regression, Association Rules and Clustering use prediction algorithms.
Naive Bayes or Bayes‟ Rule is the basis for many machine- learning and data mining methods. The rule (algorithm) is used to create models with predictive capabilities. It provides new ways of exploring and understanding data. It
learns from the “evidence” by calculating the correlation between the target (i.e., dependent) and other (i.e., independent) variables.
In Weighted Associative Classifier (WAC), different weights are assigned to different attributes according to their predicting capability. Weighted Associative Classifier (WAC) is a new concept that uses Weighted Association Rule for classification. Weighted ARM uses Weighted Support and Confidence Framework to extract Association rule from data repository. The WAC has been proposed as a new Technique to get the significant rule instead of flooded with insignificant relation.
B. Classification Concepts
Classification is a classic data mining task, with roots in machine learning. A typical application is: "Given past records of customers who switched to another supplier, predict which current customers are likely to do the same." This specific application is known as Churn Prediction, but there are very many other applications such as predicting response to a direct marketing campaign, separating good products from faulty ones etc.
The "Classification Problem" involves data which is divided into two or more groups, or classes. In our example above, the two classes are "switched supplier" and "didn't switch". The data mining software is asked to tell us which of the groups a new example falls into. So, we might train the software using customer records from the last year, divided into our two groups. We then ask the software to predict which of our customers we're likely to lose. Of course, to ensure we can trust the predictions, there is generally a testing or validation stage as well.
C. CRISP-DM Methodology
This system uses the CRISP-DM (cross industry standard process for data mining) methodology to build the mining models. It consists of six major phases: business understanding, data understanding, data preparation, modeling, evaluation, and deployment. Business understanding phase focuses on understanding the objectives and requirements from a business perspective, converting this knowledge into a data mining problem definition, and designing a preliminary plan to achieve the objectives. Data understanding phase uses the raw the data and proceeds to understand the data, identify its quality, gain preliminary insights, and detect interesting subsets to form hypotheses for hidden information.


Concepts used for computation
a.	Naive Bayes:
1. Each data sample is represented by an n dimensional feature vector, X = (x1, x2….. xn), depicting n measurements made on the sample from n attributes, respectively A1, A2, An.  
2. Suppose that there are m classes, C1, C2……Cm. Given an unknown data sample, X (i.e., having no class label), the classifier will predict that X belongs to the class having the highest posterior probability, conditioned on X. That is, the naive probability assigns an unknown sample X to the class Ci   
if and only if: P(Ci/X)>P(Cj/X)  for all  1< = j< = m and j!= i  
Thus we maximize P(Ci|X). The class Ci for which P(Ci|X) is maximized is called the maximum posteriori hypothesis. By Bayes theorem: 
P(Ci/X)= (P(X/Ci)P(Ci))/P(X)  
3. As P(X) is constant for all classes, only P(X|Ci)P(Ci) need be maximized. If the class prior probabilities are not known, then it is commonly assumed that the classes are equally likely, i.e. P(C1) = P(C2) = …..= P(Cm), and we would therefore maximize P(X|Ci). Otherwise, we maximize P(X|Ci)P(Ci). Note that the class prior probabilities may be estimated by P(Ci) = si/s , where Si is the number of training samples of class Ci, and s is the total number of training samples.

b. Weighted association classifier
 It is a new concept that uses Weighted Association Rule for classification. Weighted ARM uses Weighted Support and Confidence Framework to extract Association rule from data repository. The WAC has been proposed as a new Technique to get the significant rule instead of flooded with insignificant relation. The major steps are as follows.  
1) Initially, the heart disease data warehouse is pre -processed in order to make it suitable for the mining process.  
2) Each attribute is assigned a weight ranging from o to 1 to reflect their importance in prediction model .Attributes that have more impact will be assigned a high weight(nearly 0.9)and attributes having less impact are assigned low weight(nearly 0.1)  
3) Once the preprocessing gets over, Weighted Association Rule Mining (WARM) algorithm is applied to generate interesting pattern. This algorithm uses the concept of Weighted Support and Confidence framework instead of tradition support and confidence. Rules generated in this step are known as CAR (Classification Association Rule) and is represented as X Class label where X is set of symptoms for the disease. Example of such rules are (Hypertension, “yes”) _Heart_Disease=”yes” and {(Age,” >62”), (Smoking_habits,“yes”),(Hypertension,“yes”)}Heart_Diseas e=”yes”.
4) These rules will be stored in Rule Base.  
5) Whenever a new patient‟s record is provide, the CAR rule from the rule base is used to predict the class label.  
 Weighted associative classifiers consist of training dataset T= {r1, r2, r3…. ri…} with set of weight associated with each {attribute, attribute value} pair. Each ith record ri is a set of attribute value and a weight wi attached to each attribute of ri tuple / record. In a weighted framework each record is set of triple {ai, vi, wi} where attribute ai is having value vi and weight wi, 0<wj<=1. Weight is used to show the importance of the item.  

b.1. Attribute Weight: 
Attribute weight is assigned depending upon the domain. For example item in supermarket can be assigned weight based on the profit on per unit sale of an item. In web mining visitor page dwelling time can be used to assign weight in medical domain symptoms can be assigned weight by expert doctor.    
b.2. Attribute set weight: 
 Weight of attribute set X is denoted by W(X) and is calculated as the average of weights of enclosing attribute. And is given by:
 W(X) = (   weight (ai))/ Number of attributes in X  i =1to |X|  
b.3. Record weight/Tuple Weight:  
 Consider the data in relational table, the tuple weight or record weight can be defined as type of attribute weight. It is average weight of attributes in the tuple. If the relational table is having n number of attribute then Record weight is denoted by W (rk) and given by   : 
W (rk) = (   weight (rk))/ No. of attributes in a record  i =1to | rk |  
b.4. Weighted Support:  
In associative classification rule mining, the association rules are not of the form XY rather they are subset of these rules where Y is the class label. Weighted support WSP of rule XClass_label, where X is set of non empty subsets of attribute-value set, is fraction of weight of the record  that contain above attribute-value set relative to the weight of all transactions. This can be given as :
 WSP (XClass_label) = (   Weight (rk))/ (   weight (rk))                 i =1to | rk | k=1 to |n| Here n is the total number of records.  
b.5. Weighted Confidence:  
Weighted Confidence of a rule X Y where Y represents the Class label can be defined as the ratio of Weighted Support of (X Y) and the Weighted Support of (X).  
Weighted Confidence =    Weighted support(x * y)/Weighted support(x)  

