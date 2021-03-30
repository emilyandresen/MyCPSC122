#include <iostream>
using namespace std;

#include "8-MyStr.h"
#include <cstring>

//Constructor function
MyString::MyString(char const* strIn)
{
  length = strlen(strIn);
  str = new char[length];
  for (int i = 0; i < length; i++)
    str[i] = strIn[i];
}

//Destructor function
MyString::~MyString()
{
  delete[] str;
  length = 0;  
}

//Display function
void MyString::myDisplay()
{
  cout << str << endl;
}

void MyString::myStrcpy(char const* strIn)
{
  int inLen = 0;
  while(strIn[inLen] != '\0')
    inLen++;
  
  length = inLen;
  delete str;
  str = new char[length];
  for (int i = 0; i < length; i++)
    str[i] = strIn[i];
}

int MyString::myStrlen()
{
  return length;
}

bool MyString::isEqual(char const* strIn)
{
  int inLen = 0;
  while(strIn[inLen] != '\0')
    inLen++;
  
  if (length != inLen)
    return false;
  
  else
  {
    for (int i = 0; i < length; i++)
    {
      if (str[i] != strIn[i])
        return false;
    }
  }
  
  return true;
}

bool MyString::isSub(char const* strIn, int idx)
{
  int len = strlen(strIn);
  
  for (int j = 0; j < len; j++)
  {
    if (str[j + idx] != strIn[j])
      return false;
  }
 
  return true;
}

int MyString::find(char const* strIn)
{
  int len = strlen(strIn);
  
  for (int i = 0; i <= length - len; i++)
  {
    if (isSub(strIn, i))
      return i;
  }
  
  return -1;
}

void MyString::concat(char const* strIn)
{
  char* temp = str;
  int len = strlen(strIn);
  length += len;
  str = new char[length];
  str = strcat(temp, strIn);
}
