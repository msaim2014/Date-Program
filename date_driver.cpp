#include "date.h"
//*********************************************************************************************
// D A T E D R I V E R . C P P
//EXAMPLE OF PROGRAM HEADER
/********************************************************************************************
Name: Muhammad Saim Z#: 23306519
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: Due Time: Monday 11:59pm
Total Points: 25
Assignment 2: Date program
Description: This program takes date inputs hard coded into main and checks to see if they are valid
dates. The default constructor initializes month, day, and year. The explicit value constructor
takes in each date and sets the variables and checks if it is a leap year. The get functions 
are accessors to output the variable. The set functions are mutators that change the function.
The display outputs the date while the operator<< overloads as friend function with chaining.
*********************************************************************************************/
int main()
{
	Date myDate;
	Date yourDate(12,31, 1957);
	Date test1Date(15, 1, 1962); //should generate error message that bad month
	Date test2Date(2, 29, 1956); //ok, should say leep year
	Date test3Date(2, 30, 1956); //should generate error message that bad day
	Date test4Date(12,31,0000); //should generate error message that bad year
	Date test5Date(80,40,0000); //should generate error message that bad month, day and year

	yourDate.display();
	cout << endl;
	cout<<yourDate.getMonth()<<endl;
	cout<<yourDate.getDay()<<endl;
	cout<<yourDate.getYear()<<endl;
	myDate.setMonth(11);
	myDate.setDay(12);
	myDate.setYear(2015);
	cout<<"myDate: "<<myDate<<" test2Date: "<<test2Date<<" yourDate: "<<yourDate<<endl;

	return 0;
}