/* 
  A simple synthetic division C++ program
  Created by Elijah Wilson. 2013.

  The variables are based off of the following table:

  divNum|numX4  numX3  numX2  numX1  numX0
        |       num3   num2   num1   num0
        -----------------------------------
         numX4  num3x  num2x  num1x  num0x
*/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;

const string version = "1.2.2";

void printHeading(double& divNum);      //Prints the heading text to the screen and gets divNum
void getX4(double& numX4);              //Gets numX4
void getX3(double& numX3);              //Gets numX3
void getX2(double& numX2);              //Gets numX2
void getX1(double& numX1);              //Gets numX1
void getX0(double& numX0);              //Gets numX0
void doMath(double& num3, double& num3x, double& num2, double& num2x, double& num1, 
            double& num1x, double& num0, double& num0x, double divNum, double numX4,
            double numX3, double numX2, double numX1, double numX0);  //Does the math
void checkSolution(double num0x, double divNum, double numX4, 
                   double num3x, double num2x, double num1x);   //Checks to see if divNum is a solution
void printEndMsg();    //Prints end message
void getSign(double x, double y); //Gets the sign to print based on if there is a preceding number and the
                                  //value of the following number (positive/negative)

int main()
{
 //User input variables
 double divNum, numX4, numX3, numX2, numX1, numX0;

 //Changing varaibles within program and not user defined
 double num3, num2, num1, num0, num3x, num2x, num1x, num0x;

 printHeading(divNum);

 cout << "OK!" << endl << endl;
 cout << "Now time to enter the leading coefficients. If they are a fraction, enter the decimal equivalent. (not 100% accurate)" << endl;

 getX4(numX4);
 getX3(numX3);
 getX2(numX2);
 getX1(numX1);
 getX0(numX0);
 //End getting numbers

 //Does math, duh
 doMath(num3,  num3x,  num2,  num2x,  num1, num1x,  num0,  num0x,  divNum,  numX4, numX3,  numX2,  numX1,  numX0);

 //Check to see if what you are dividing is a solution
 checkSolution(num0x, divNum, numX4, num3x, num2x, num1x);

 printEndMsg();

 return 0;
}

void printHeading(double& divNum)
{
 cout << "Welcome to the synthetic division program!" << endl;
 cout << "Created by Elijah Wilson. 2013. Version " << version << endl << endl;
 cout << "In order for this program to work correctly you must have an equation like the following:" << endl;
 cout << "3x^4 + 2x^3 + 1x^2 + 0x^1 + 5x^0 || commonly written as: 3x^4 + 2x^3 + 1x^2 + 5" << endl << endl;
 cout << "This program will only work with equations up to the 4th power." << endl;
 cout << "Now with the other equation, likely in the form (x+a) where a is a number. Solve for x and type that number here: ";
 cin >> divNum;
 cout << endl;
}

void getX4(double& numX4)
{
 cout << endl;
 cout << "Enter x^4 coefficient: ";
 cin >> numX4;
}

void getX3(double& numX3)
{
 cout << "Enter x^3 coefficient: ";
 cin >> numX3;
}

void getX2(double& numX2)
{
 cout << "Enter x^2 coefficient: ";
 cin >> numX2;
}

void getX1(double& numX1)
{
 cout << "Enter x^1 coefficient: ";
 cin >> numX1;
}
void getX0(double& numX0)
{
 cout << "Enter x^0 coefficient: ";
 cin >> numX0;
}

void doMath(double& num3, double& num3x, double& num2, double& num2x, double& num1, 
            double& num1x, double& num0, double& num0x, double divNum, double numX4,
            double numX3, double numX2, double numX1, double numX0)
{
 num3 = divNum * numX4;
 num3x = numX3 + num3;

 num2 = divNum * num3x;
 num2x = numX2 + num2;

 num1 = divNum * num2x;
 num1x = numX1 + num1;

 num0 = divNum * num1x;
 num0x = numX0 + num0;
}

void checkSolution(double num0x, double divNum, double numX4, double num3x, double num2x, double num1x)
{
 if(num0x == 0)
 {
  cout << endl;
  cout << divNum << " is a solution!" << endl << endl;

  cout << "The solution:" << endl;

  if(numX4 != 0)
  {
    if(numX4 == 1)
      cout << "x^3";
    else if(numX4 == -1)
      cout << "-x^3";
    else
      cout << numX4 << "x^3";
  }
  getSign(numX4, num3x);

  if(num3x != 0)
  {
    if(num3x == 1)
      cout << "x^2";
    else if(numX4 == -1)
      cout << "- x^2";
    else
      cout << num3x << "x^2";
  }
  getSign(num3x, num2x);

  if(num2x != 0)
  {
    if(num2x == 1)
      cout << "x";
    else if(numX4 == -1)
      cout << "- x";
    else
      cout << num2x << "x";
  }
  getSign(num2x, num1x);
  
  if(num1x != 0)
  {
    if(num1x == -1)
      cout << "- 1" << endl;
    else
      cout << num1x << endl;
  }
 } //end if perfect solution
 else
 {
  cout << endl;
  cout << divNum << " is not a [perfect] solution!" << endl << endl;

  cout << "However the answer with remainder is:" << endl;

  if(numX4 != 0)
  {
    if(numX4 == 1)
      cout << "x^3";
    else if(numX4 == -1)
      cout << "-x^3";
    else
      cout << numX4 << "x^3";
  }
  getSign(numX4, num3x);

  if(num3x != 0)
  {
    if(num3x == 1)
      cout << "x^2";
    else if(numX4 == -1)
      cout << "- x^2";
    else
      cout << num3x << "x^2";
  }
  getSign(num3x, num2x);

  if(num2x != 0)
  {
    if(num2x == 1)
      cout << "x";
    else if(numX4 == -1)
      cout << "- x";
    else
      cout << num2x << "x";
  }
  getSign(num2x, num1x);
  
  if(num1x != 0)
  {
    if(num1x == -1)
      cout << "- 1" << endl;
    else
      cout << num1x << endl;
  }

  cout << "With a remainder of: " << num0x << endl; 
 } //end else
}
void printEndMsg()
{
 cout << endl;
 cout << "DONE!" << endl;
}
void getSign(double x, double y)
//where x is the number before and y is the number after
{
  if (x != 0 && y > 0)
   cout << " + ";
 else
    cout << " ";
}