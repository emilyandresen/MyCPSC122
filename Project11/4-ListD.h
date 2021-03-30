/*
Name: Emily Andresen
Class: CPSC 122, Section 2
Date Submitted: March 20, 2021
Assignment: Project 10
Description: header file for a doubly linked list with dummy notes at head and tail
*/

#ifndef LIST_H
#define LIST_H

typedef int itemType;

struct doubleNode
{
 doubleNode* prev;
 itemType item;
 doubleNode* next;
};

class ListD
{
 public:
   
   ListD();

   /*
   Comment: When invoked from the test file with an existing object of type ListD,
   this function will create an exact copy of the object.
   pre:  lst points to an object of type ListD
   post: The current object is an exact and deep copy of what lst points
         to.
   */
   ListD(ListD* lst);

   ~ListD();
  
   /*
   pre: ListD exists, pos is in the range [1..length+1].
   post: new node is inserted at postion pos. 
   */
   void Insert(itemType item, int pos);   

   /*
   pre: ListD exists, pos is in the range [1..length].
   post: node at postion, pos, is deleted 
   */
   void Delete(int pos);   

   /*
   pre: ListD exists
   post: All nodes containing item have been deleted.  Returns the
         number of nodes that have been deleted. 
   */
   int DeleteAll(itemType item);   

   /*
   pre: ListD exists.
   post: The item value of each node, from head to tail,
         is displayed on the screen, excluding the dummy nodes. 
   */
   void PrintForward();
   
   /*
   pre: List exists.
   post: The item value of each node, from tail to head,
         is displayed on the screen, excluding dummy nodes.
   */
   void PrintBackward();

   /*
   pre:  List exists
   post: Nodes in the list are in ascending order.  The algorithm used
         to put nodes in order is selection sort. 
   */
   void Sort();
  
 private:
   /*
   Comment: Used in conjunction with functions that insert and delete   
   pre:  List exists, pos is the position where the new node is to be
         inserted. pos is in the range [1..length+1].
   Post: Returns insertion point A (see the implemention of insert)
         used in inserting a node in a list 
   */
   doubleNode* FindPosition(int pos);

   int length;         //length of the list
   doubleNode* head;   //points to the first dummy node 
   doubleNode* tail;   //points to the last dummy node  
};
#endif

