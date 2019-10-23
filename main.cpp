/*
Author: Matt Loera
Date: 10/23/2019
Program Name: County Fair Admission Calculator v2
Description: This program takes the ages of multiple people in a group and calculates the
cost of admission for the whole group at the County Fair

Outside Sources: CS161 Programming Assignment PDF
*/

#include <iostream>
#include <iomanip>

using namespace std;

/*Constants*/
const double taxRate = 1.07;
const double seniorDiscount = 1.09;

int main()
{

	/*Variables*/
	int age = -1;
	double admission = 0;
	double groupCostSoFar = 0; 

	/*Initial Output*/
	cout << "This program calculates the cost of admission of the group to the county fair." << endl;
	cout << "When you are finished inputting members of the group, enter 0 for the age." << endl;
	cout << fixed << setprecision(2); // initialize formatting for variables of type double

	while (age != 0) //checking for sentinel value of age = 0
	{
		/*User Input*/
		do
		{
			cout << "What is your age (in years)? ";
			cin >> age;

			cout << "Let me check..." << endl;
		} while (age < 0); //repeatedly asks user for input to get a valid age value

		/*Calculation*/
		if (age == 0) 
		{
			break;
		}
		else if (age < 2)
		{
			admission = 1;
		}
		else if (age > 2 && age < 10)
		{
			admission = 10;
		}
		else if (age >= 10)
		{
			admission = 20;
			if (age >= 60)		//Apply senior discount if necessary.
			{
				cout << "You qualify for the senior discount!" << endl;
				admission *= seniorDiscount;
			}
		}

		admission *= taxRate;		//Apply 7% tax
		groupCostSoFar += admission; //adds the current person's admission to the group cost so far

		/*Output*/
		cout << "Your cost with tax is $" << admission << endl;
		cout << "The group's cost so far is: $" << groupCostSoFar << endl;
	}
	
	cout << "Your group's total cost is: $" << groupCostSoFar << endl;
	return 0;
}