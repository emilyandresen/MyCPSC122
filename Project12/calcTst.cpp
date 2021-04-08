#include <iostream>
using namespace std;

#include "calc.h"

int main(int argc, char* argv[])
{
 Calc* C = new Calc(argv[1]);
 C->DisplayInFix();

 delete C;
 return 0;
}
