#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>


//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char* argvIn)
{
 inFix = new char[strlen(argvIn + 1)];
 strcpy(inFix, argvIn);
 stk = new Stack;
 
 if (!CheckTokens())
 {
  cout << "Invalid String" << endl;
  exit(EXIT_FAILURE);
 }
 
 if (!CheckParens())
 {
  cout << "Invalid or Mismatched Parentheses" << endl;
  exit(EXIT_FAILURE);
 }
 
 MakeValueTbl();
 Parse(); 
}

Calc::~Calc()
{
 delete stk;
 delete inFix;
}

bool Calc::CheckTokens()
{
 for (int i = 0; i < strlen(inFix); i++)
 {
  if ((inFix[i] != '(') && (inFix[i] != ')') && (inFix[i] != '+') && (inFix[i] != '-') && (inFix[i] != '*') && (inFix[i] != '/') && (!isdigit(inFix[i])))
   return false;
 }
 return true;
}

void Calc::MakeValueTbl()
{
 valueTbl = new int[26];
 valueIdx = 0;
}

void Calc::Parse()
{
 char* newArr = new char[26];
 int pos = 0;
 int i = 0;
 while (i <= strlen(inFix))
 {
  if (isdigit(inFix[i]))
  {
   int j = FindLast(i);
   string num = string(inFix).substr(i, j - i);
   valueTbl[valueIdx] = stoi(num);
   newArr[pos] = 'A' + valueIdx;
   pos++;
   i = j;
   valueIdx++;
  }
  
  else
  {
   newArr[pos] = inFix[i];
   pos++;
   i++;
  }
 }

 inFix = new char[pos + 1];
 strcpy(inFix, newArr); 
}

bool Calc::CheckParens()
{
 char ch;
 for (int i = 0; i < strlen(inFix); i++)
 {
  ch = inFix[i];
  
  if (ch == '(')
   stk->Push(ch);
  
  if (ch == ')')
  {
  
   if (inFix[i - 1] == '(')
    return false; 
    
   if (stk->IsEmpty())
    return false;
    
   stk->Pop();
  }
 }
  
 if (stk->IsEmpty())
  return true;
 
 return false;
}

void Calc::DisplayInFix()
{
 cout << inFix << endl;
}

int Calc::FindLast(int cur)
{
 while((inFix[cur] >= '0') && (inFix[cur] <= '9'))
  cur++;
 return cur;
}
