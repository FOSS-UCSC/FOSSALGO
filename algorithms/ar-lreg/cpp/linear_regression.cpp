/**
 * One-dimensional Linear Regression implementation in C++.
 * The generalized formula is target = weight * Variance(data) + bias.
 * Above formula helps us to find the regression line by finding coefficent
 * We can then find the target value to make a prediction based on given value of data.
 */
#include<iostream>
#include<vector>

using namespace std;
/**
 *  Generic class to contain one-dimensional
 *  continous data and the target value.
 */
template<class T, class U>
class DataPoint{
public:
// constructors
DataPoint(T feature,U target);
explicit DataPoint(T feature);
// accessors and mutators
void setFeature(const T feature);
void setTarget(const U target);
T getFeature() const;
U getTarget() const;
// destructors
~DataPoint();
private:
  T feature;
  U target;
};
// DataPoint Interface implementation
template<class T, class U>
DataPoint<T,U>::DataPoint(T feature, U target): feature(feature), target(target){}

template<class T, class U>
DataPoint<T,U>::DataPoint(T feature): feature(feature){}

template<class T, class U>
DataPoint<T,U>::~DataPoint(){}

template<class T, class U>
void DataPoint<T,U>::setFeature(const T feature){
    this->feature = feature;
}

template<class T, class U>
T DataPoint<T,U>::getFeature() const {
    return feature;
}

template<class T, class U>
void DataPoint<T,U>::setTarget(const U target){
    this->target = target;
}

template<class T, class U>
U DataPoint<T,U>::getTarget() const{
    return this->target;
}

/**
 * Linear Regression Interface.
 * This interface takes DataPoint object in association. 
 */
template<typename T, typename U>
class LinearRegression{
public:
   // Constructor
  explicit LinearRegression(const vector<DataPoint<T,U>> &);
   // Predicting the continous target value for the test-point.
   DataPoint<T,U> fit(DataPoint<T,U> testPoint);
   // Accessors
   double inline getWeight() const;
   double inline getBias() const;
   // Destructors
   ~LinearRegression();
private:
  LinearRegression();
  vector<DataPoint<T,U>> dataset;
  enum MEAN_TYPE{FEATURE=1,TARGET=2};
  double weight;
  double bias;
  // Predicate helpers to calculate weight and bias
  double calculateMean(const MEAN_TYPE) const; 
  double calculateWeight() const;
  double calculateBias() const;
  // Mutators
  void setWeight(const double weight);
  void setBias(const double bias);
};
/**
 *  LinearRegression Interface implementation.
 */

template<typename T, typename U>
LinearRegression<T,U>::LinearRegression():weight(0.0),bias(0.0){}

template<typename T, typename U>
LinearRegression<T,U>::LinearRegression(const vector<DataPoint<T, U>> &data): dataset(data){}


template<typename T, typename U>
LinearRegression<T,U>::~LinearRegression(){}

template<typename T, typename U>
void LinearRegression<T,U>::setWeight(const double weight){
   this->weight = weight;
}

template<typename T, typename U>
double LinearRegression<T,U>::getWeight() const{
    return this->weight;
}

template<typename T, typename U>
void LinearRegression<T,U>::setBias(const double bias){
    this->bias = bias;
}

template<typename T, typename U>
double LinearRegression<T,U>::getBias() const{
    return this->bias;
}

template<typename T, typename U>
double LinearRegression<T,U>::calculateMean(const MEAN_TYPE meanType) const {
    double mean = 0.0;
    if(meanType == FEATURE){
        for(int i = 0; i < this->dataset.size(); ++i){
            mean += dataset[i].getFeature();
        }       
    }else if(meanType == TARGET){
        for(int i = 0; i < this->dataset.size(); ++i) {
            mean += dataset[i].getTarget();
        }
    }
    return mean;
}

template<typename T, typename U>
double LinearRegression<T,U>::calculateWeight() const{
    double targetMean = calculateMean(FEATURE);
    double featureMean = calculateMean(TARGET);
    T featureSumSquared  = static_cast<T>(0);
    U targetSum = static_cast<U>(0); //(xi-xa)*(xi-xa)
    for(int i = 0; i < dataset.size(); ++i){
        featureSumSquared += (dataset[i].getFeature() - featureMean)*(dataset[i].getFeature() - featureMean);
    }
    for(int i = 0; i < dataset.size(); ++i) {
        targetSum += (dataset[i].getFeature() - featureMean)*(dataset[i].getTarget()-targetMean);
    }
     return targetSum/featureSumSquared;
 }
template<typename T, typename U>
double LinearRegression<T,U>::calculateBias() const{
    return calculateMean(TARGET) - (getWeight()*calculateMean(FEATURE));
}

template<typename T, typename U>
DataPoint<T,U> LinearRegression<T,U>::fit(DataPoint<T,U> testPoint){
    setWeight(calculateWeight());
    setBias(calculateBias());
    testPoint.setTarget((getWeight()*testPoint.getFeature()+ getBias()));
    return testPoint;
}

// Driver Program

int main(){
    // Test for the simple student marks and grade
    vector<DataPoint<int,int>> dataset;
    dataset.push_back(DataPoint<int,int>(95,85));
    dataset.push_back(DataPoint<int,int>(85,95));
    dataset.push_back(DataPoint<int,int>(80,70));
    dataset.push_back(DataPoint<int,int>(70,65));
    dataset.push_back(DataPoint<int,int>(60,70));
    
    DataPoint<int,int> test(80);
    LinearRegression<int, int> lr(dataset);
    test = lr.fit(test);
    cout<<test.getTarget()<<endl;
    return 0;
}