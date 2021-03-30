#include <iostream>
using namespace std;

#include "3-ListT.h"

ListT::ListT()
{
  //create head and tail nodes
  head = new node;
  tail = new node;
  length = 0;
}

ListT::~ListT()
{
  for (int i = 0; i < length; i++)
    DeleteItemH(); //delete each node from the list
  delete tail;
  length = 0;
}

bool ListT::IsEmpty() const
{
 if (length != 0)
   return false; //return false if length is 0
 
 return true; //otherwise return true
}

int ListT::GetLength() const
{
 return length;
}

void ListT::PutItemH(const itemType newItem)
{
  node* temp = new node;
  temp->item = newItem; //fill temp
  temp->next = head; //point temp to head
  head = temp;
  if (length == 0) //special case for empty list
    tail = temp;
  length++; //increment length
  temp = NULL;
}

itemType ListT::GetItemH() const
{
  return head->item;
}

void ListT::DeleteItemH()
{
  node* temp = head; //save first node
  head = head->next; //redirect head
  delete temp; //delete first node
  length--; //decrement length
}

void ListT::PutItemT(const itemType itemIn)
{
  node* temp = new node;
  temp->item = itemIn; //fill temp
  temp->next = NULL; //point temp to null
  if (length == 0) //special case for empty list
    head = temp;   
  tail->next = temp; //point last node to temp
  tail = temp; //point tail to temp
  length++; //increment length
  temp = NULL;
}

itemType ListT::GetItemT() const
{
  return tail->item;
}

void ListT::DeleteItemT()
{
  node* temp = tail; //save last node
  tail = PtrTo(); //redirect tail
  PtrTo()->next = NULL;
  delete temp; //delete last node
  length--; //decrement length
}
	
void ListT::Print() const
{
  node* cur = head; //start at head
  for (int i = 0; i < length; i++) //traverse list
  {
    cout << cur->item << endl; //print item
    cur = cur->next; //advance
  }
  cur = NULL;  
}

int ListT::FindItem(const itemType target) const
{
 node* cur = head; //start at head
 int count = 0; //initialize counter
 for (int i = 0; i < length; i++) //traverse list
 {
   if (cur->item == target) //increment counter when target is found
     count++;
   cur = cur->next; //advance
 }
 cur = NULL;
 return count;
}

int ListT::DeleteItem(const itemType target)
{
  int numDeleted = FindItem(target); //count for all items to be deleted
  
  node* cur1 = head; //start at head
  node* cur2 = head->next; //keep track of next position
  
  for (int i = 0; i < length; i++) //traverse list
  {
    if (cur2->item == target) //when target is found
    {
      cur1->next = cur2->next; //redirect pointet
      delete cur2; //delete target
      length--; //decrement length
      cur2 = cur1->next; //redirect position
    }
    
    cur1 = cur1->next; //advance
    cur2 = cur2->next;
  }
  
  cur1 = cur2 = NULL;
  return numDeleted;
}

node* ListT::PtrTo()
{
  node* cur = head; //start at head
  for (int i = 0; i < length - 2; i++) //traverse to second to last node
  {
    cur = cur->next;
  } 
  return cur; //return pointer to second to last node
}

