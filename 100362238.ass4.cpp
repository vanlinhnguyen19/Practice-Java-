/* Name:Van Linh Nguyen
Student number:100362238
Assignment 4 
Date: 26 March */

#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include<fstream>

using namespace std;

/* STEP 1 */ 
void readfile(string fillname, string Braille[], int &countBra)
{
	ifstream inputFile; //input file
	inputFile.open("braille.txt"); //open the file 
	if (inputFile.fail()) // check this file  can open or not 
	{
		cout << "Fail to open this file" << endl;
		return;
	}
	int i = 0;
	while (!inputFile.eof()) {// return a true value when no data can read from an input file stream 
		inputFile >> Braille[countBra];
		i++;
	}
	inputFile.close(); // close the file
	cout << "Read file successfully\n"; 
}

/* STEP 2 */
// string funtion ask user
string inputString() {
	string input = {};
	cout << "Please enter a sentence (use letters, comma, period and space) " << endl;
	getline(cin, input);
	return input;
}

//function ask the user to enter a sentence and return string where sentence is saved
void Output(string Braille[], int cntBra) { //function to print Braille from a file
	for (int i = 0; i < 10; i++)
		cout << Braille[i] << endl;
}


/* STEP 3 */
//function convert Braille 
string BrailleConverts(string Braille[], int countBra, char key)
{
	string temp = {};
	for (int i = 0; i < countBra; i += 2)
	{
		char keyBra = Braille[i][0];
		if (key == ' ')
			temp = Braille[countBra - 2];
		else if (key == keyBra)
			temp += Braille[i + 1];
	}
	return temp;
}

// void function to annouce char(key) letter from a to z in alphebet
void changeChar(char& key)
{
	if (key >= 65 && key <= 90)
	{
		key += 32;
	}
	else return;
}

//void function translate braille when all brailles are converted 
void TranslateBrailleAll(string Braille[], int countBra, string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		char key = str[i];
		string temp = {};
		changeChar(key);
		temp = BrailleConverts(Braille, countBra, key);
		for (int j = 0; j < temp.size(); j++)
		{
			cout << temp[j] << temp[j++] << endl;
		}
		cout << setfill('_') << setw(10) << " " << endl;
	}
}


/* STEP 4 */
//funtion  that accepts array of integers and prints a bar chart that shows how many times each character repeated
void countCharacter(int cntchr[], string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		char key = str[i];
		changeChar(key);
		int intkey = (int)key;
		for (int j = 0; j < 30; j++)
		{
			if ((intkey - 97) == j) // a-z :97 - 122
			{
				cntchr[j]++;
			}
			else if ((intkey - 18) == j) // , 44
			{
				cntchr[j]++;
				cntchr[25]--;
			}
			else if ((intkey - 19) == j) // . 46
			{
				cntchr[j]++;
			}
			else if ((intkey - 4) == j) // space 32
			{
				cntchr[j]++;
				cntchr[13]--;
				cntchr[14]--;
			}
		}
	}
}
//set value = * same as topic
void printChart(int n)
{
	cout << setfill('*') << setw(n) << "";
	cout << endl;
}

//count how many times letters appear in sentence.
void PrintCntChar(int cntchr[])
{
	cout << "\nThe entered characters area *******\n";
	for (int i = 0; i < 26; i++)
	{
		if (cntchr[i] > 0)
		{
			cout << (char)(i + 97) << " ";
			printChart(cntchr[i]);
		}
	}
	if (cntchr[26] > 0)
	{
		cout << ", ";
		printChart(cntchr[26]);
	}
	if (cntchr[27] > 0)
	{
		cntchr[28] -= cntchr[27];
		cout << ". ";
		printChart(cntchr[27]);
	}
	if (cntchr[28] > 0)
	{
		cout << "space ";
		printChart(cntchr[28]);
	}
	cout << "-------------------\n\n";
}

/* STEP 5 */
// main function 
int main ()
{
	int countBra{}; 
	string Braille[100] = {}; //set array Braille 100 
	int countChar[30] = {}; //set array countChar 30
	Output(Braille, countBra); //call function string output

	char check;
	do {
		cout << setfill('-') << setw(50) << " " << endl;
		string input = {}; 
		input = inputString();// call function string input


		TranslateBrailleAll(Braille, countBra, input); // call function TranslateBrailleAll
		countCharacter(countChar, input); //call function countCharacter
		cout << "\nWould you like to enter another sentence Y/y or N/n?: ";
		cin >> check;
		if (check == 'Y' || check == 'y')
		{
			cin.ignore();
			return 1;
		}
		else return 0;
	} while (true);

		PrintCntChar(countChar);
	
	return 0;
}