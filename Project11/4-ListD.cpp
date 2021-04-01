#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

   
template <typename T>
ListD<T>::ListD()
{
 ConstructList();
}

template <typename T>
ListD<T>::ListD(ListD<T>* lst)
{
 ConstructList();

 //returns pointer to the first node, which is what we want here
 doubleNode<T>* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  Insert(cur->item,i);
  cur = cur->next;
 }
}

template <typename T>
ListD<T>::~ListD()
{
  //loop as many times as there are nodes in the list, deleting the first node each time
  for (int i = 0; i < length; i++)
   Delete(1);
   
  //delete dummy nodes and reset length
  delete head;
  delete tail;
  length = 0;
  
}

template <typename T>
doubleNode<T>* ListD<T>::FindPosition(int pos)
{
 //Inserting at the tail is a special case.  It can be made much more efficient than
 //this.
 doubleNode<T>* cur = head;
 int i = 0;  //begin at the dummy node
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 
  
template <typename T>
void ListD<T>::Insert(T item, int pos)
{
 //new node goes between these two nodes
 doubleNode<T>* insertPtA = FindPosition(pos);  
 doubleNode<T>* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode<T>* tmp = new doubleNode<T>; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

template <typename T>
void ListD<T>::PrintForward()
{
 //start at first non-dummy node
 doubleNode<T>*  cur = head->next;

 //traverse array forward and print each node item
 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}
 
template <typename T>
void ListD<T>::PrintBackward()
{
 //start at last non-dummy node
 doubleNode<T>* cur = tail->prev;
 
 //traverse array backward and print each node item
 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->prev;
  i++;
  }
}

template <typename T>
void ListD<T>::Delete(const int pos)
{
 //node to be deleted, its predecessor, and its successor
 doubleNode<T>* toDelete = FindPosition(pos + 1);  
 doubleNode<T>* deletePtA = toDelete->prev;
 doubleNode<T>* deletePtB = toDelete->next;
 
 //set pointers for nodes before and after the insertion point
 deletePtA->next = deletePtB;
 deletePtB->prev = deletePtA;

 //delete node and decrement length
 delete toDelete;
 length--;
}

template <typename T>
int ListD<T>::DeleteAll(T target)
{
 int counter = 0;
 
 //start at first non-dummy node
 doubleNode<T>*  cur = head->next;

 //traverse array forward and print each node item
 int i = 1;
 while (i <= length)
 {
  cur = FindPosition(i + 1);
  
  if (cur->item == target)
  {
   Delete(i);
   counter++;
  }
  
  else
   i++;
 }
 return counter;
}

template <typename T>
void ListD<T>::ConstructList()
{
 length = 0; 
 
 //create dummy nodes;
 head = new doubleNode<T>;
 tail = new doubleNode<T>;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}

template <typename T>
void ListD<T>::Sort()
{
 //creates new array to store node items
 int nodeVals[length];
 
 //start at first non-dummy node
 doubleNode<T>*  cur = head->next;

 //traverse array forward and save each node item to array
 int i = 0;
 while (i < length)
 {
  nodeVals[i] = cur->item;
  cur = cur->next;
  i++;
 }
 
 SelectionSort(nodeVals, length);
 
 //restarts at first non-dummy node
 cur = FindPosition(2);
 for (int i = 0; i < length; i++)
 {
  cur->item = nodeVals[i];
  cur = cur->next;
 }
 
}
 
template <typename T>
void ListD<T>::SelectionSort(int arr[], int len)
{
 int pass = 0;
 int start = 0;
 int idx_small; 

 while(pass < len - 1 ) 
 {
  int idx_small = FindSmall(start, arr, len);
  Swap(start,idx_small,arr);
  start++;
  pass++; 
 }
}

template <typename T>
int ListD<T>::FindSmall(int start, int arr[], int len)
{
 int idx_small = start;  //candidate smallest
 int next = start + 1;    //start searching here
 while(next < len)         
 {
  if (arr[next] < arr[idx_small]) //new smallest integer found
     idx_small = next;
  next++;                        //look at the next position
 }
 return idx_small;
}

template <typename T>
void ListD<T>::Swap(int pos, int idx_small, int arr[])
{
 int tmp = arr[pos];
 arr[pos] = arr[idx_small];
 arr[idx_small] = tmp;
}
