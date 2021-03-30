/*
Name: Emily Andresen
Class: CPSC 122, Section 2
Date Submitted: March 5, 2021
Assignment: Project 8
Description: Program illustrates using class MyString 
*/

#include "8-MyStr.h"
#include <iostream> 
using namespace std;


int main(int argc, char* argv[])
{
 MyString str1(argv[1]);
 MyString* str2 = new MyString(argv[1]);

 /*
 //Test of myDisplay
 cout << "***************************************" << endl;
 cout << "*****Test 1 myDisplay*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the command line input" << endl;
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 2 myDisplay*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the command line input" << endl;
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myDisplay
 */
 
  
 //Test of myStrcpy
 cout << "***************************************" << endl;
 cout << "*****Test 1 myStrcpy*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the 'Test 1 Successful'" << endl;
 str1.myStrcpy("Test 1 Successful");
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 2 myStrcpy*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the 'Test 2 Successful'" << endl;
 str2->myStrcpy("Test 2 Successful");
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myStrcpy
 

 /* 
 //Test of myStrlen
 cout << "***************************************" << endl;
 cout << "*****Test 1 myStrlen*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the command line input length" << endl;
 cout << str1.myStrlen() << endl;
 cout << endl;
 cout << "*****Test 2 myStrlen*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the command line input length" << endl;
 cout << str2->myStrlen() << endl;
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myStrlen
 */
 
 /*
 //Test of isEqual
 cout << "***************************************" << endl;
 cout << "*****Test 1 isEqual*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 1 if the command line input is 'singers make music', 0 otherwise" << endl;
 cout << str1.isEqual("singers make music") << endl;
 cout << endl;
 cout << "*****Test 2 isEqual*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be 1 if the command line input is 'good food mood', 0 otherwise" << endl;
 cout << str2->isEqual("good food mood") << endl;
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of isEqual
 */
 
 /*
 //Test of find
 cout << "***************************************" << endl;
 cout << "*****Test 1 find*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the position of the first substring 'oo' if it is a substring of the command line input, -1 otherwise" << endl;
 cout << str1.find("oo") << endl;
 cout << endl;
 cout << "*****Test 2 find*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the position of the first substring 'ing' if it is a substring of the command line input, -1 otherwise" << endl;
 cout << str2->find("ing") << endl;
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of find
 */
 
 /*
 //Test of concat
 cout << "***************************************" << endl;
 cout << "*****Test 1 concat*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the command line input followed by 'tubular'" << endl;
 str1.concat("tubular");
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 2 concat*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the command line input followed by 'groovy" << endl;
 str2->concat("groovy");
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of concat
 */
 
 delete str2;
 return 0;  
}
   
  
