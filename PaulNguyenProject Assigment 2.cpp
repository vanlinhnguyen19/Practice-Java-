/*My name is : Van Linh Nguyen
Student number is 100362238
Date: Feb 2, 2021 
Assignment 2 */

#include <iostream> // stand for input output stream
#include <string> // use for manipulating null-terminated
#include <iomanip> // defines the manipulator functions
using namespace std;

int main() // start function
{
	// name variables 
	string Name1, ticketnum, phonenum;
	int number1;
	char choice, letter, number, answear;
	int day, month, year, last2digit;
	const pricebook = $89.00;


	// Get the full name 
	cout << "Enter your full name: ";
	cin >> Name1;//input answear
// get student number 
	cout << "Enter your student number: ";
	cin >> number1;//input answear
// display message 
	cout << "For the following question answer Y(for Yes) or N(for No). \n";
	cout << "Are you or anyone in tour houesehold have travelled outside of Canada within the past 14 days?"
		<< " or have you had contact with any person with, or under investigation for COVID-19 in the last 14 days?" << endl;
	cin >> answear; //input answear
	// switch statement to choose Y and N 
	if (answear == 'N') // Choose N will display messages below
	{
		cout << "Are you experiencing any of the following? \n";
		cout << setw(102) << "-Severe difficulty breathing (e.g. struggling to breathe or speaking in single words) \n" // use setw to get space before it and run the statements with cout 
			<< setw(35) << "-Severe chest pain \n"
			<< setw(51) << "-Having a very hard time waking up \n"
			<< setw(34) << "-Feeling confused \n"
			<< setw(38) << "-Losing consciousness \n";
	}

	if (answear == 'y') // choose y will display message below 
	{
		cout << "Call 911 or visit the nearest emeregency department and end the program";
		return 0;
	}
	else if (answear == 'Y')// choose answear Y will display message below{ 
	{
		cout << "We apologize, you are nor allowed to enter the campus. \n";
		return 0; //finishes excecution
	}

	cin >> answear; //input answear
	if (answear == 'n') //continue to answear a new question, choose n to display message below
	{
		cout << "Are you experiencing any of the following? \n";
		cout << setw(54) << "-Mild to moderate shortness of breath \n" // use setw to get space before it and run the satements with cout
			<< setw(71) << "-Inability to lie down because of difficulty breathing \n"
			<< setw(114) << "-Chronic health conditions that you are having difficulty managing because of difficult breathing \n";
	}
	cin >> answear; //input answear
	if (answear == 'y') // choose y will display message below 
	{
		cout << "Call 911 or visit the nearest emeregency department and end the program"; // run the statements
		return 0; // end of programs 
	}

	else if (answear == 'n') // use else if to continue another situation if choose n 
	{
		cout << "Welcome " << Name1 << " to KPU, please select where you want to go (enter the first letter of the option): \n" // run the statements 
			<< "Bookstore \n"
			<< "IT Helpdesk Service \n"
			<< "Library \n";
	}
	cin >> choice; //input choice
	switch (choice)
	{ //use Switch to run every single situation 
	case 'I': cout << "Enter you ticket Number that you receive from email : "; //choose first letter of IT service 
		cin >> ticketnum; //enter ticketnum
		cout << "Enter your phone Number : ";
		cin >> phonenum; //enter phonenum
		cout << "\n********************************** " << ticketnum << " *****************************" << endl;
		cout << Name1 << ", you are in the line. A message will be sent to \"" << phonenum << "\" to tell you when it is your turn." << endl;
		cout << "\n***********************************************************************" << endl;
		break; // use the end of the case 
	case 'L': cout << "Enter today's day: " << endl; // choose L to run Library section
		cout << "\nday :"; // display day
		cin >> day; // enter day
		cout << "\nmonth :"; //display month
		cin >> month; //enter month
		cout << "\nyear :"; //display year
		cin >> year; // enter year
		cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;// run statements
		cout << "&" << setw(64) << "&" << endl;
		cout << "& XXXXXX      Kwantlen Polytechnic University" << setw(20) << "&" << endl;
		cout << "& XXXXXX      Student Name   : " << Name1 << setw(31) << " &" << endl;
		cout << "& XXXXXX      Student Number : " << number1 << setw(31) << " &" << endl;
		cout << "&             Expires        : " << day << "/" << month << "/" << year + 4 << setw(23) << " &" << endl;
		cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
		break; // use the end of the case 
	case 'B':
		last2digit = number1 % 100; //use to find last 2 digits
		if (last2digit >= 0 && last2digit <= 47) // use If to specify condition and change if when is false 
		{
			letter = 'K'; // use Ascii to intitalize char letter 
		}
		if (last2digit >= 48 && last2digit <= 57) // follow table on topic 
		{
			letter = (char)last2digit;
		}
		if (last2digit >= 58 && last2digit <= 64) // follow table on topic 
		{
			last2digit = last2digit + 20;
			letter = (char)last2digit;
		}
		if (last2digit >= 65 && last2digit <= 90) // follow table on topic 
		{
			letter = (char)last2digit;
		}
		if (last2digit >= 91 && last2digit <= 99) // follow table on topic 
		{
			last2digit = last2digit - 9;
			letter = (char)last2digit;
		}
		int third, fifth;

		third = number1 / 100 % 10; //we divide it for 100 to take a third digits and then take that number % 10 to take last digit from it 
		fifth = number1 / 10000 % 10; // same thing with third take it divide to 10000 to take fifth digit and then module it to 10 to take last digit from it 
		cout << "Student Name " << setw(30) << "Student Number " << setw(19) << "Price" << setw(31) << "Access Code " << endl; // run stastements cout and use setw to get space between them 
		cout << "############" << setw(30) << "##############" << setw(20) << "#####" << setw(30) << "###########" << endl;
		cout << Name1 << setw(29) << number1 << setw(21) << pricebook << setw(27) << letter << third << fifth << endl; 
		break; // use the end of the case 
	default: cout << "Not access to any places" << endl;

	}

	system("pause");
	return 0;
}