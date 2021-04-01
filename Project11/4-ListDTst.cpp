#include <iostream>
using namespace std;

#include "4-ListD.cpp"

int main()
{
 ListD<int>* lst = new ListD<int>;
 
 for (int i = 1; i <= 10; i++)
   lst->Insert(i % 4,i);  
   
 ListD<int>* lst1 = new ListD<int>(lst);
 
 /*
 cout << "Print Forward 1 of 2" << endl;
 
 lst->PrintForward();

 cout << endl;
 
 cout << "Print Forward 2 of 2" << endl;
 
 lst1->PrintForward();

 cout << endl;
 
 cout << "Print Backward" << endl;
 
 lst->PrintBackward();

 cout << endl;
 
 cout << "Delete Position 6" << endl;
 
 lst->Delete(6);
 lst->PrintForward();
 
 cout << endl;
 
 cout << "Delete All 2s" << endl;
 
 cout << lst->DeleteAll(2) <<  " node(s) deleted" << endl;
 lst->PrintForward();
 
 cout << endl; 
 
 cout << "Sort" << endl;
 
 lst->Sort();
 lst->PrintForward();
 
 cout << endl;
 */
 
 delete lst;
 delete lst1;
 
 return 0;
}
