#include<iostream>


#define S 50

using namespace std;
int main()
{
 int n, i;
 float x[S], y[S], sumX=0, sumX2=0, sumY=0, sumXY=0, a, b;

 /* Input */
 cout<<"How many data points? ";
 cin>>n;

 cout<<"Enter data:"<< endl;

 for(i=1;i<=n;i++)
 {
  cout<<"x["<< i <<"] = ";
  cin>>x[i];
  cout<<"y["<< i <<"] = ";
  cin>>y[i];
 }

 /* Calculating Required Sum */
 for(i=1;i<=n;i++)
 {
  sumX = sumX + x[i];
  sumX2 = sumX2 + x[i]*x[i];
  sumY = sumY + y[i];
  sumXY = sumXY + x[i]*y[i];
 }
 /* Calculating a and b */
 b = (n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
 a = (sumY - b*sumX)/n;

 /* Displaying value of a and b */
 cout<<"Calculated value of a is "<< a << "and b is "<< b << endl;
 cout<<"Equation of best fit is: y = "<< a <<" + "<< b<<"x";

 return(0);
}
