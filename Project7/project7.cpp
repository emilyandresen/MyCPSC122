/*
Name: Emily Andresen
Class: CPSC 122, Section 2
Date: February 20, 2021
Assignment: Project 7
Description: This script can perform three different tasks using an transposition cipher: 
			(1) generate random keys to an output file
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
void fileOpen(fstream&, string, char);
void fileControl(string, string, string, int);
char transform(char, int[][2], int);
void selection_sort(int[][2], int);
int find_small(int, int[][2], int);
void swap(int, int, int[][2]);

const int SIZE = 26;

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
Description: Opens key file for writing.  Generates and stores encrypt and decrypt keys in the key file.   This can be stored any way that you like as long as two arrays can be constructed from the file, one for encryption and one for decryption. 
Input: name of the file in which to store generated keys
Output: file holds generated encryption and decryption keys 
*/
void keyGen(string keyFile)
{
  srand(time(0));
  fstream fout;
  
  
  int enc[SIZE]; //initialize encrypt key array
  
  bool validate[SIZE] = {false};
  int pos = 0;
  while(pos < SIZE) //fill encrypt key array
  {
    while (true)
    {
      int k = rand() % SIZE; //generates random value [0..25]
      if (!validate[k])
      {
        enc[pos] = k;
        validate[k] = true; //this number has been used
        pos++;
        break;
      }
    }
  }

  int key[SIZE][2];
  //set up 2D array
  for (int i = 0; i < SIZE; i++)
  {
  	key[i][0] = enc[i];
  	key[i][1] = i;
  }
  
  selection_sort(key, SIZE); //sort column 1 and bring column 2 along
  
  //initialize and fill decrypt key
  int dec[SIZE];
  for (int i = 0; i < SIZE; i++)
  	dec[i] = key[i][1];
  
  //writes keys to file
  fileOpen(fout, keyFile, 'w');
  
  for (int j = 0; j < SIZE; j++) //write encrypt key
    fout << enc[j] << ' ';
  
  fout << '\n';
  
  for (int j = 0; j < SIZE; j++) //write decrypt key
    fout << dec[j] << ' ';
    
  fout.close();
}

/*
Description: invokes fileOpen on all files. Closes all files. Reads key file. Constructs arrays for encryption/decryption. Reads the input file and either invokes encrypt or decrypt, depending on the value of mode. Writes to the output file. 
Input: names of key file, input file and output file. mode value of 1 or 2
Output: writes to the output file
*/

void fileControl(string keyFile, string inputFile, string outputFile, int mode)
{
  fstream fin;
  fstream fout;

  fileOpen(fin, keyFile, 'r'); //open key file
  
  //store key values
  int encDec[SIZE][2];
  while(fin.peek() != EOF) //read keys into 2D array
  {
    for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < SIZE; j++)
        fin >> encDec[j][i];
  	 }
  }
  
  fin.close(); //close key file
    
  fileOpen(fin, inputFile, 'r'); //open text input file
  fileOpen(fout, outputFile,'w'); //open text output file

  char ch;
  while(fin.peek() != EOF) //read characters in input file one by one
  {
    ch = fin.get();
    if (isalpha(ch)) //skip over non-alphabetic characters
    {
      ch = toupper(ch); //capitalize if necessary
      ch = transform(ch, encDec, mode); //encrypt/decrypt character
    }
    
    fout.put(ch); //write character to output file
  }
	
  fin.close(); //close text input file  
  fout.close(); //close text output file
  
}

/*
Description: Encrypts/Decrypts an upper case alphabetic character using the transposition cipher. Operation depends on whether it is sent the encrypt or decrypt key
Input: upper case alphabetic character, 2-D encryption or decryption array
Returns: encrypted or decrypted  version of ch
*/
char transform(char ch, int key[][2], int mode)
{
	ch = ch - 'A';
	ch = key[ch][mode - 1] + 'A'; //encrypt for mode = 1 and decrypt for mode = 2
	 
	return ch;
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

/*
Description: sorts an array using the selection sort method
Input: arr is an integer of length, length, filled with integers
     in no particular order
Output: the intgers in arr are in sorted order, smallest to largest 
*/
void selection_sort(int arr[][2], int length)
{
 int pass = 0;
 int start = 0;
 int idx_small; 

 while(pass < length - 1 )      
 {
  int idx_small = find_small(start, arr, length);
  swap(start,idx_small,arr);
  start++;
  pass++; 
 }
}

/*
Description: finds the index of the smallest value in an array
Input: start is the positon from which we begin searching for the smallest integer
     arr is an integer of length, length, filled with integers
Output: returns the smallest integer in the array, from start to the bottom 
*/

int find_small(int start, int arr[][2], int length)
{
 int idx_small = start;  //candidate smallest
 int next = start + 1;    //start searching here
 while(next < length)         
 {
  if (arr[next][0] < arr[idx_small][0]) //we've found a new smallest integer
     idx_small = next;
  next++;                        //look at the next position whether or not
                                //we've found a new smallest 
 }
 return idx_small;
}

/*
Description: swaps two rows in a 2D array with 2 columns
Inputs: two indices, pos1 and pos2, and a 2D array
Output: the rows are swapped
*/
void swap(int pos1, int pos2, int arr[][2])
{
 int temp0 = arr[pos1][0];
 arr[pos1][0] = arr[pos2][0];
 arr[pos2][0] = temp0;
 
 int temp1 = arr[pos1][1];
 arr[pos1][1] = arr[pos2][1];
 arr[pos2][1] = temp1;
}


