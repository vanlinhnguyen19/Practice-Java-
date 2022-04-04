/* Name:Van Linh Nguyen
Student number:100362238
Assignment 4
Date: 26 March
My teamates: Harshdeep Sharma 100405265*/

#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include<fstream>

using namespace std;

//function readfile
void readFile(string fileName, string Braille[], int& countBra)
{
	ifstream fileInput(fileName);


	if (fileInput.fail()) // if cant open file or file Error
	{
		cout << "Failed to open this file!" << endl;
		system("pause");
		return;
	}
	countBra = 0;
	while (!fileInput.eof())
	{
		fileInput >> Braille[countBra];
		countBra++;
	}
	fileInput.close();
	cout << "Read file successfully!\n";
}


// string funtion ask user
string inputString() {
	string input = {};
	cout << "Please enter a sentence (use letters, comma, period and space) " << endl;
	getline(cin, input);
	return input;
}

//function ask the user to enter a sentence and return string where sentence is saved
void Output(string Braille[], int cntBra) { //function to print Braille from a file
	for (int i = 0; i < cntBra; i++)
		cout << Braille[i] << endl;
}



//function convert Braille 
string BrailleConverts(string Braille[], int countBra, char key)
{
	string temp = {};
	for (int i = 0; i < countBra; i += 2)
	{
		char keyBra = Braille[i][0]; // set keybar = 0 
		if (key == ' ')
			temp = Braille[countBra - 2]; // because space in array doensn read so braille of space need -2 
		else if (key == keyBra)
			temp += Braille[i + 1]; //plus 1 when char = keybar ( example: char=a(~=1) cout 2)
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
	else
		return;
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



//funtion  that accepts array of integers and prints a bar chart that shows how many times each character repeated
void countCharacter(int cntchr[], string str)
{
	for (int i = 0; i < str.size(); i++) //set size for str 
	{
		char key = str[i];
		changeChar(key);
		int intkey = (int)key;
		for (int j = 0; j < 30; j++) // set array is 30 
		{
			if ((intkey - 97) == j) // save to array a-z :97 - 122
			{
				cntchr[j]++;
			}
			else if ((intkey - 18) == j) // save to ,
			{
				cntchr[j]++;
				cntchr[25]--;
			}
			else if ((intkey - 19) == j) //save to . 
			{
				cntchr[j]++;
			}
			else if ((intkey - 4) == j) // save to (space) 
			{
				cntchr[j]++;
				cntchr[13]--;
				cntchr[14]--;
			}
		}
	}
}
//function to print * 
void printChart(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "*";
	}
	cout << endl;
}

//count how many times letters appear in sentence.
void PrintCntChar(int cntchr[])
{
	cout << "\nThe entered characters are" << endl;
	for (int i = 0; i < 26; i++) // count character in sentence
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
		printChart(cntchr[26]); // count , in sentence
	}
	if (cntchr[27] > 0)
	{
		cntchr[28] -= cntchr[27];
		cout << ". ";
		printChart(cntchr[27]); // count . from sentence
	}
	if (cntchr[28] > 0)
	{
		cout << "space ";
		printChart(cntchr[28]); //count space from sentence
	}
	cout << setfill('-')<<setw(20)<<endl; //use setfill and setw like as topic 
}

//function to ask do it again. 
bool checkCondition(char check)
{
	if (check == 'Y' || check == 'y')
	{
		cin.ignore();
		return 1;
	}
	else return 0; // N/n or any key -> exit
}

// main function 
int main()
{
	int countBra{};
	string Braille[100] = {}; //set array Braille 100 
	int countChar[30] = {}; //set array countChar 30
	Output(Braille, countBra); //call function string output
	readFile("braille.txt", Braille, countBra); // call readFile function from above 

	char check; //intialize check by char 
	do {
		cout << setfill('-') << setw(50) << " " << endl; //use setfill and setw to let the line of - as same topic
		string input = {};
		input = inputString();// call function string inpu


		TranslateBrailleAll(Braille, countBra, input); // call function TranslateBrailleAll
		countCharacter(countChar, input); //call function countCharacter
		cout << "\nWould you like to enter another sentence Y/y or N/n?: ";
		cin >> check;

	} while (checkCondition(check));// call function to check Y/N question

	PrintCntChar(countChar); // call funtion count character 

	return 0;
}