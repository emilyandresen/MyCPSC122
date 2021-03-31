#include <iostream>
using namespace std;

#include "4-ListD.h"


int main()
{
 ListD* lst = new ListD;
 
 for (int i = 1; i <= 10; i++)
   lst->Insert(i % 4,i);  
   
 ListD* lst1 = new ListD(lst);
 
 
 cout << "Print Forward 1 of 2" << endl;
 
 lst->PrintForward();

 cout << endl;
 /*
 cout << "Print Forward 2 of 2" << endl;
 
 lst1->PrintForward();

 cout << endl;
 
 cout << "Print Backward" << endl;
 
 lst->PrintBackward();

 cout << endl;
 
 cout << "Delete" << endl;
 
 lst->Delete(10);
 lst->PrintForward();
 
 cout << endl;
 
 cout << "Delete All" << endl;
 
 cout << lst->DeleteAll(1) <<  " node(s) deleted" << endl;
 lst->PrintForward();
 
 cout << endl; 
 */
 
 cout << "Sort" << endl;
 
 lst->Sort();
 lst->PrintForward();
 
 cout << endl;
 
 delete lst;
 delete lst1;
 
 return 0;
}
