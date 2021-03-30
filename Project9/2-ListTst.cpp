#include <iostream>
using namespace std;

#include "2-List.h"

int main()
{
 //Use of a static list 
 List lst;
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 //Use of a dynamic list
 List* lst1 = new List;
 for (int i = 0; i < 6; i++)
   lst1->PutItemH(10*i);
 
 /*
 //Test of Print
 cout << "***************************************" << endl;
 cout << "*****Test 1 Print*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 4 3 2 1 0, each on separate lines" << endl;
 lst.Print();
 cout << endl;
 cout << "*****Test 2 Print*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be 50 40 30 20 10 0, each on separate lines" << endl;
 lst1->Print();
 cout << "***************************************" << endl;
 cout << endl;
 //End Test of Print
 */

 /*
 //Test of IsEmpty
 cout << "***************************************" << endl;
 cout << "*****Test 1 IsEmpty*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 0" << endl;
 cout << lst.IsEmpty() << endl;
 cout << endl;
 cout << "*****Test 2 IsEmpty*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be 1" << endl;
 List* lst2 = new List;
 cout << lst2->IsEmpty() << endl;
 delete lst2;
 cout << "***************************************" << endl;
 cout << endl;
 //End Test of IsEmpty
 */   

 /* 
 //Test of GetLength
 cout << "***************************************" << endl;
 cout << "*****Test 1 GetLength*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 5" << endl;
 cout << lst.GetLength() << endl;
 cout << endl;
 cout << "*****Test 2 GetLength*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be 6" << endl;
 cout << lst1->GetLength() << endl;
 cout << "***************************************" << endl;
 cout << endl;
 //End Test of GetLength
 */   

 /* 
 //Test of PutItemH
 cout << "***************************************" << endl;
 cout << "*****Test 1 PutItemH*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 5 4 3 2 1 0, each on separate lines" << endl;
 lst.PutItemH(5);
 lst.Print();
 cout << endl;
 lst.DeleteItemH();
 cout << "*****Test 2 PutItemH*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be 60 50 40 30 20 10 0, each on separate lines" << endl;
 lst1->PutItemH(60);
 lst1->Print();
 lst1->DeleteItemH();
 cout << "***************************************" << endl;
 cout << endl;
 //End Test of PutItemH
 */   

 /* 
 //Test of GetItemH
 cout << "***************************************" << endl;
 cout << "*****Test 1 GetItemH*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 4" << endl;
 cout << lst.GetItemH() << endl;
 cout << endl;
 cout << "*****Test 2 GetItemH*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be 50" << endl;
 cout << lst1->GetItemH() << endl;
 cout << "***************************************" << endl;
 cout << endl;
 //End Test of GetItemH
 */   

 /* 
 //Test of DeleteItemH
 cout << "***************************************" << endl;
 cout << "*****Test 1 DeleteItemH*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 3 2 1 0, each on separate lines" << endl;
 lst.DeleteItemH();
 lst.Print();
 cout << endl;
 lst.PutItemH(4);
 cout << "*****Test 2 DeleteItemH*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be 40 30 20 10 0, each on separate lines" << endl;
 lst1->DeleteItemH();
 lst1->Print();
 lst1->PutItemH(50);
 cout << "***************************************" << endl;
 cout << endl;
 //End Test of DeleteItemH
 */   

 /* 
 //Test of Find
 cout << "***************************************" << endl;
 cout << "*****Test 1 Find*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 1" << endl;
 cout << lst.Find(3) << endl;
 cout << endl;
 cout << "*****Test 2 Find*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be 3" << endl;
 cout << lst1->Find(20) << endl;
 cout << "***************************************" << endl;
 cout << endl;
 //End Test of Find
 */   
 
 /* 
 //Test of DeleteItem
 cout << "***************************************" << endl;
 cout << "*****Test 1 DeleteItem*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 4 3 1 0, each on separate lines" << endl;
 lst.DeleteItem(2);
 lst.Print();
 cout << endl;
 cout << "*****Test 2 DeleteItem*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be 50 40 30 20 0, each on separate lines" << endl;
 lst1->DeleteItem(4);
 lst1->Print();
 cout << "***************************************" << endl;
 cout << endl;
 //End Test of DeleteItem
 */    
 
 delete lst1; //necessary to invoke destructor on dynamic list
 return 0;
}
