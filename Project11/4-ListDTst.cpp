#include <iostream>
using namespace std;

#include "4-ListD.h"


int main()
{
 ListD* lst = new ListD;
 
 for (int i = 1; i <= 10; i++)
   lst->Insert(i,i);

 lst->PrintForward();

 cout << endl;

 lst->PrintBackward();

 cout << endl;
  
 ListD* lst1 = new ListD(lst);

 lst1->PrintForward();

 cout << endl;

 lst1->PrintBackward();

 return 0;
}
