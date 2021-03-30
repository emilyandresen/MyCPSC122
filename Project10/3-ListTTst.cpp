#include <iostream>
using namespace std;

#include "3-ListT.h"

int main()
{
 //Use of a static ListT 
 ListT lst;
 for (int i = 1; i < 5; i++) 
   lst.PutItemH(i);
 for (int i = 3; i > 0; i--) 
   lst.PutItemH(i);
 //Use of a dynamic ListT
 ListT* lst1 = new ListT;
 for (int i = 0; i < 6; i++)
   lst1->PutItemH(10*i);
 
 /*
 //Test of Print
 cout << "***************************************" << endl;
 cout << "*****Test 1 Print*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 1 2 3 4 3 2 1, each on separate lines" << endl;
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
 ListT* lst2 = new ListT;
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
 cout << "output should be 7" << endl;
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
 cout << "output should be 5 1 2 3 4 3 2 1, each on separate lines" << endl;
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
 cout << "output should be 1" << endl;
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
 cout << "output should be 2 3 4 3 2 1, each on separate lines" << endl;
 lst.DeleteItemH();
 lst.Print();
 cout << endl;
 lst.PutItemH(1);
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
 //Test of PutItemT
 cout << "***************************************" << endl;
 cout << "*****Test 1 PutItemT*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 1 2 3 4 3 2 1 5, each on separate lines" << endl;
 lst.PutItemT(5);
 lst.Print();
 cout << endl;
 lst.DeleteItemT();
 cout << "*****Test 2 PutItemT*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be 50 40 30 20 10 0 60, each on separate lines" << endl;
 lst1->PutItemT(60);
 lst1->Print();
 lst1->DeleteItemT();
 cout << "***************************************" << endl;
 cout << endl;
 //End Test of PutItemT
 */   

 /* 
 //Test of GetItemT
 cout << "***************************************" << endl;
 cout << "*****Test 1 GetItemT*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 1" << endl;
 cout << lst.GetItemT() << endl;
 cout << endl;
 cout << "*****Test 2 GetItemT*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be 0" << endl;
 cout << lst1->GetItemT() << endl;
 cout << "***************************************" << endl;
 cout << endl;
 //End Test of GetItemT
 */   

 /*
 //Test of DeleteItemT
 cout << "***************************************" << endl;
 cout << "*****Test 1 DeleteItemT*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 1 2 3 4 3 2, each on separate lines" << endl;
 lst.DeleteItemT();
 lst.Print();
 cout << endl;
 lst.PutItemT(1);
 cout << "*****Test 2 DeleteItemT*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be 50 40 30 20 10, each on separate lines" << endl;
 lst1->DeleteItemT();
 lst1->Print();
 lst1->PutItemT(0);
 cout << "***************************************" << endl;
 cout << endl;
 //End Test of DeleteItemT
 */

 /* 
 //Test of FindItem
 cout << "***************************************" << endl;
 cout << "*****Test 1 FindItem*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 2" << endl;
 cout << lst.FindItem(1) << endl;
 cout << endl;
 cout << "*****Test 2 FindItem*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be 1" << endl;
 cout << lst1->FindItem(20) << endl;
 cout << "***************************************" << endl;
 cout << endl;
 //End Test of FindItem
 */   
 
 /*
 //Test of DeleteItem  
 cout << "***************************************" << endl;
 cout << "*****Test 1 DeleteItem*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 1 3 4 3 1, each on separate lines, followed by '2 node(s) deleted'" << endl;
 //create and fill static list for testing
 ListT lst3;
 for (int i = 1; i < 5; i++) 
   lst3.PutItemH(i);
 for (int i = 3; i > 0; i--) 
   lst3.PutItemH(i);
 //perform static test
 int num = lst3.DeleteItem(2);
 lst3.Print();
 cout << num << " node(s) deleted." << endl;
 cout << endl;
 cout << "*****Test 2 DeleteItem*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be 50 40 30 20 0, each on separate lines, followed by '1 node(s) deleted'" << endl;
 //create and fill dynamic list for testing
 ListT* lst4 = new ListT;
 for (int i = 0; i < 6; i++)
   lst4->PutItemH(10*i); 
 //perform dynamic test
 num = lst4->DeleteItem(10);
 lst4->Print();
 cout << num << " node(s) deleted." << endl;
 cout << "***************************************" << endl;
 cout << endl;
 delete lst4;
 //End Test of DeleteItem
 */
 
 delete lst1; //invoke destructor on dynamic ListT
 return 0;
}
