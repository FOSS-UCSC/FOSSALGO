/* Program to implement linear regression using C */

/*
Linear Regression refers to an approach/algorithm that helps establish a linear relationship 
between the dependant and the independent variable.

We have approached the problem using Least Square method to find the linear equation of best fit.
*/

/*
The Hypothesis function of linear regression is : y = a + bx
where, 
x: input training data (univariate – one input variable(parameter))
y: labels to data (supervised learning)
a: intercept
b: coefficient of x

Once we find the best a and b values, we get the best fit line.
 So when we are finally using our model for prediction, it will predict the value of y for the input value of x.
*/

#include <stdio.h>
#include <stdlib.h>

#define S 50

int main()
{
 int n, i;
 float x[S], y[S], sumX=0, sumX2=0, sumY=0, sumXY=0, a, b;

 /* Input : Read n as the number of data points */
 printf("How many data points?\n");
 scanf("%d", &n);
 printf("Enter data:\n");
 for(i=1;i<=n;i++)
 {
  printf("x[%d]=",i);
  scanf("%f", &x[i]);
  printf("y[%d]=",i);
  scanf("%f", &y[i]);
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
 printf("The values are: a=%0.2f and b = %0.2f",a,b);
 printf("\nEquation of best fit is: y = %0.2f + %0.2fx",a,b);
 return(0);
}