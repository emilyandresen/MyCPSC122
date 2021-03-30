/*
Name: Emily Andresen
Class: CPSC 122, Section 2
Date: February 12, 2021
Assignment: Project 6
Description: This script can perform three different tasks using an affine cipher: 
			(1) generate random alpha and beta keys to an output file
			(2) given a plain text file and key file, encrypt text and write to an output file
			(3) given an encrypted text file and key file, decrypt text and write to an output file
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
using namespace std;

//initialize functions for later use
void keyGen(string);
char encrypt(char, int, int);
char decrypt(char, int, int, int[]);
void fileOpen(fstream&, string, char);
void fileControl(string, string, string, int);

int main(int argc, char* argv[])
{
  int mode = atoi(argv[1]); //stores whether user wants to generate key, encrypt file, or decrypt file

  if (mode == 0)
    keyGen(argv[2]); //generate key
  else
    fileControl(argv[2], argv[3], argv[4], mode); //encrypt or decrypt file
  return 0;
}

/*
Description: Randomly generates and stores alpha and beta values.
The alpha value is randomly drawn from the the set:  {1,3,5,7,11,15,17,19,21,23,25}
The beta value is randomly drawn from the range: [1..25]  
Output: alpha and beta values on subsequent lines of keyFile
*/
void keyGen(string keyFile)
{
  srand(time(0));
  fstream fout;

  int idx = rand() % 12; //generates random position
  int possibleAlphas[] = {1,3,5,7,9,11,15,17,19,21,23,25}; //values under 26 that can be alpha
  int alpha = possibleAlphas[idx]; //assigns values at the random position to alpha
  
  int beta = rand() % 25 + 1; //generates random value [0..25]

  //writes keys to file
  fileOpen(fout, keyFile, 'w');
  fout << alpha << endl;
  fout << beta << endl;
  fout.close();
}

/*
Description: Encrypts an upper case alphabetic character using the affine cipher
Input: upper case alphabetic character, valid alpha and beta values
Returns: encrypted version of ch
*/
char encrypt(char ch, int alpha, int beta)
{
  ch = ch - 'A';
  ch = (alpha * ch + beta) % 26; //encrypt with equation (a*ch + b) % 26
  ch = ch + 'A';
  return ch;
}

/*
Description: Decrypts an upper case alphabetic character using the affine cipher
Input: upper case alphabetic character, valid alpha and beta values. Dictionary of multiplicative inverse values mod 26
Returns: decrypted version of input
*/
char decrypt(char ch, int alpha, int beta, int MI[])
{
  ch = ch - 'A';
  ch = (MI[alpha] * ch - MI[alpha] * beta + 650) % 26; //decrypt with equation (a^-1*ch - a^-1b + p*26) % 26 where p = 25
  ch = ch + 'A';
  return ch;
}

/*
Description: invokes fileOpen on all files. Closes all files. Reads key file. Reads the input file and either invokes encrypt or decrypt, depending on the value of mode. Writes to the output file. 
Input: names of key file, input file and output file. mode value of 1 or 2
Output: writes to the output file
*/
void fileControl(string keyFile, string inputFile, string outputFile, int mode)
{
  fstream fin;
  fstream fout;

  fileOpen(fin, keyFile, 'r'); //open key file
  
  //store alpha and beta key values
  int alpha, beta;
  fin >> alpha;
  fin >> beta;
  
  fin.close(); //close key file

  fileOpen(fin, inputFile, 'r'); //open text input file
  fileOpen(fout, outputFile,'w'); //open text output file
  
  char ch;
  while(fin.peek() != EOF) //read characters in input file one by one
  {
    ch = fin.get();
    if (isalpha(ch)) //skip over non-alphabetic characters
    {
      if (mode == 1) //encrypt mode
      {  
        ch = toupper(ch); //capitalize if necessary
        ch = encrypt(ch,alpha,beta); //encrypt character
      }
    
      if (mode == 2) //decrypt mode
      {
        int MI[] = {0,1,0,9,0,21,0,15,0,3,0,19,0,0,0,7,0,23,0,11,0,5,0,17,0,25}; //multiplicative inverses
        ch = decrypt(ch,alpha,beta, MI); //decrypt character
      } 
    }
    
    fout.put(ch); //write character to output file
  }
	
  fin.close(); //close text input file  
  fout.close(); //close text output file
}

/*
Description: function opens a file 
Input: file stream object reference, name of the file, mode of open
Output: void function, but at exit, file stream object is tied to 
the input file name. 
*/ 
void fileOpen(fstream& file, string name, char mode)
{
  string fileType;

  if (mode == 'r')
    fileType = "input";
  if (mode == 'w')
    fileType = "output";

  if (mode == 'r')
    file.open(name, ios::in);  //available through fstream
  if (mode == 'w')
    file.open(name, ios::out);  //available through fstream;

  if (file.fail()) //error condition 
  {
    cout << "Error opening " << fileType << " file" << endl; 
    exit(EXIT_FAILURE);
  }
}

