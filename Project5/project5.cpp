/*
Name: Emily Andresen
Class: CPSC 122, Section 2
Date: February 5, 2021
Assignment: Project 5
Description: This script can perform three different tasks: 
			(1) generate a random key to an output file
			(2) given a plain text file and key file, encrypt text and write to an output file
			(3) given an encrypted text file and key file, decrypt text and write to an output file
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
using namespace std;

//initialize functions for later use
int keyGen();
char encrypt(char, int);
char decrypt(char, int);
void fileOpen(fstream&, string, char);
void generateKey(string);
void encryptFile(string, string, string);
void decryptFile(string, string, string);

int main(int argc, char* argv[])
{
	int mode = atoi(argv[1]); //stores whether user wants to generate key, encrypt file, or decrypt file
	
	if (mode == 0)
		generateKey(argv[2]); //generate key
	else if (mode == 1)
		encryptFile(argv[2], argv[3], argv[4]); //encrypt file
	else if (mode == 2)
		decryptFile(argv[2], argv[3], argv[4]); //decrypt file	
	return 0;
}


/*
Description: Randomly generates an integer in the range: [1..25]
Input: None
Output: returns a randomly generated integer in the range [1..25]
*/
int keyGen()
{
	return (rand() % 25 + 1);
}

/*
Description: Encrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: encrypted version of ch
*/
char encrypt(char ch, int key)
{
	if (ch == ' ' || ch == '\n') //skip over spaces and ends of lines
		return ch;
		
	ch = ch - 'A';
	ch = (ch + key) % 26;
	ch = ch + 'A';
	return ch;
}

/*
Description: Decrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: decrypted version of input
*/
char decrypt(char ch, int key)
{
	if (ch == ' ' || ch == '\n') //skip over spaces and ends of lines
		return ch;
	
	ch = ch - 'A';
	ch = (ch - key + 26) % 26;
	ch = ch + 'A';
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
Description: Randomly generates an integer in the range: [1..25]
Input: reference to keyFile
Output: writes a randomly generated integer in the range [1..25] to keyFile 
*/
void generateKey(string keyFile)
{
	srand(time(0));
	fstream fout;
	
	fileOpen(fout, keyFile, 'w');
	fout << keyGen();
	fout.close();
}

/*
Description: function encrypts the text of inputFile using the key from keyFile
Input: name of key file, name of input file, name of output file
Output: writes encrypted text to outputFile
*/
void encryptFile(string keyFile, string inputFile, string outputFile)
{
	fstream fin;
	fstream fout;
	
	fileOpen(fin, keyFile, 'r'); //open key file
	string keycode;
 		
 	while (fin.peek() != EOF)
 		getline(fin,keycode, '\n');	//store key as string
		
	fin.close(); //close key file
		
	int keyVal = stoi(keycode); //convert key to int
	
	fileOpen(fin, inputFile, 'r'); //open text input file
 	string line;
 	string text;
 	
 	while (fin.peek() != EOF)
 	{
 		getline(fin,line, '\n'); //store file contents as string
 		text += (line + '\n');
 	}
		
	fin.close(); //close text input file
	
	fileOpen(fout, outputFile,'w'); //open text output file
	
	for (int i = 0; i < text.length(); i++)
		fout << encrypt(text[i],keyVal); //write encrypted text to output file
	
	fout.close(); //close text output file
}

/*
Description: function decrypts the text of inputFile using the key from keyFile
Input: name of key file, name of input file, name of output file
Output: writes decrypted text to outputFile
*/
void decryptFile(string keyFile, string inputFile, string outputFile)
{
	fstream fin;
	fstream fout;
	
	fileOpen(fin, keyFile, 'r'); //open key file
	string keycode;
 		
 	while (fin.peek() != EOF)
 		getline(fin,keycode, '\n');	//store key as string
		
	fin.close(); //close key file
		
	int keyVal = stoi(keycode); //convert key to int
	
	fileOpen(fin, inputFile, 'r'); //open text input file
 	string line;
 	string text;
 	
 	while (fin.peek() != EOF)
 	{
 		getline(fin,line, '\n'); //store file contents as string
 		text += (line + '\n');
 	}
		
	fin.close(); //close text input file
	
	fileOpen(fout, outputFile,'w'); //open text output file
	
	for (int i = 0; i < text.length(); i++)
		fout << decrypt(text[i],keyVal); //write decrypted text to output file
	
	fout.close(); //close text output file
}
