#include <iostream>
using namespace std;

#include "2-List.h"

List::List()
{
  head = new node;
  length = 0;
}

List::~List()
{
  delete[] head;
  length = 0;
}

bool List::IsEmpty() const
{
 if (length != 0)
   return false;
 
 return true;
}

int List::GetLength() const
{
 return length;
}

void List::PutItemH(const itemType newItem)
{
  node* temp = new node;
  temp->item = newItem;
  temp->next = head;
  head = temp;
  length++;
  temp = NULL;
}

itemType List::GetItemH() const
{
  return head->item;
}

void List::DeleteItemH()
{
  node* temp = head;
  head = head->next;
  delete temp;
}
	
void List::Print() const
{
  node* cur = head;
  while (cur->next != NULL)
  {
    cout << cur->item << endl;
    cur = cur->next;
  }
}

int List::Find(const itemType item) const
{
 node* cur = head;
 for (int i = 0; i < length; i++)
 {
   if (cur-> item == item)
     return i;
   cur = cur->next;
 }
 return -1;
}

void List::DeleteItem(const int pos)
{
  node* cur1 = head;
  node* cur2 = head->next;
  for (int i = 0; i < pos - 1; i++)
  {
    cur1 = cur1->next;
    cur2 = cur2->next;
  }
  cur1->next = cur2->next;
  delete cur2;
}

