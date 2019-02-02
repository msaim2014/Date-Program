#include "date.h"
//*********************************************************************************************
// D A T E . C P P
//This stub (for now) should be implemented in date.cpp
//*************************************************************************************
//Name: Date
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to today's date
//Description: This is the default constructor which will be called automatically when
//an object is declared. It will initialize the state of the class
//*************************************************************************************
Date::Date()
{
	cout << "Default constructor has been invoked" << endl;
	//initializing the variables
	myDay = 01;
	myMonth = 01;
	myYear = 0001;
	cout << setfill('0') << setw(2) << myMonth << "/" << setw(2) << myDay << "/" << setw(4) << myYear;
	cout << endl << endl;

}

//*************************************************************************************
//Name: Date
//Precondition: Day,Month, and Year have not been set
//Postcondition: Day,Month, and Year have been set by the values user sent in through 
//				 the explicit value constructor
//Description: The user's values are set with the explicit value constructor and 
//				prints a message if the year is a leap year.
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
	cout << "Explicit Value constructor has been invoked" << endl;

	myDay = d;
	myMonth = m;
	myYear = y;

	//displaying the user input
	display();

	//setting the variables and checking for valid entries
	setMonth(m);
	setDay(d);
	setYear(y);

	//Check if the year is divisible by 4 or is divisible by 400 
	if ((y % 400 == 0 || y % 100 != 0) && (y % 4 == 0) && (y != 0)){

		cout << "Year= " << y << " is a leap year" << endl;
	}
	else{

		cout << endl;
	}

	cout << endl;
}
//*************************************************************************************
//Name: Display
//Precondition: The values of myMonth, myDay, and myYear are filled 
//Postcondition: The values myMonth, myDay, and myYear will be printed after leaving the function
//Description: This function displays the date of the user inputed values. 
//*************************************************************************************
void Date::display()
{
	//displays the values with the right spacing
	cout << setfill('0') << setw(2) << myMonth <<"/" ;
	cout << setfill('0') << setw(2) << myDay <<"/";
	cout << setfill('0') << setw(4) << myYear << endl;
}
//*************************************************************************************
//Name: getMonth
//Precondition: Month has a legal value
//Postcondition: When you exit, Month has been returned to the calling function
//Description: This function returns the legal month. It is an accessor to output the month.
//*************************************************************************************
int Date::getMonth()
{
	return myMonth;
}
//*************************************************************************************
//Name: getDay
//Precondition: Day has a legal value
//Postcondition: When you exit, day has been returned to the calling function.
//Description: This function returns the legal day. It is an accessor to output the day.
//*************************************************************************************
int Date::getDay()
{ 
	return myDay;
}
//*************************************************************************************
//Name: getYear
//Precondition: Year has a legal value
//Postcondition: When You exit, Year has been returned to the calling function. 
//Description: This function returns a legal Year. It is an accessor to output the year
//*************************************************************************************
int Date::getYear()
{
	return myYear;
}
//*************************************************************************************
//Name: setMonth
//Precondition: Month may be initialized or not.
//Postcondition: Month has been set to user value.
//Description: This function sets month to the user value if it is a legal value,
//			    otherwise the function prints that the month is incorrect. It is a 
//				mutator to change the month.
//*************************************************************************************
void Date::setMonth(unsigned m)
{
	//checks to see if the users month is within 12.
	if (m <= 12){

		myMonth = m;
	}
	else {
		//prints if the month is incorrect
		cout << "Month= " << setfill('0') << setw(2) << m << " is incorrect" << endl;
	}
}
//*************************************************************************************
//Name: setDay
//Precondition: Day may be initialized or not
//Postcondition: Day has been set to user value
//Description: This function sets day to the user value if it is a legal value,
//				otherwise the function prints that the day is incorrect.
//				It is a mutator to change the day.
//*************************************************************************************
void Date::setDay(unsigned d)
{
	//array of the last days of the month
	int lastDay[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31};

	//checks to see if the day is less than the last day of the month
	if(d<=myMonth[lastDay]){

		myDay = d;
	}
	else{
		//otherwise error message is printed
		cout << "Day= " << setfill('0') << setw(2) << d << " is incorrect" << endl;
	}
}
//*************************************************************************************
//Name: setYear
//Precondition: Year may be initialized or not.
//Postcondition: Year has been set to user value
//Description: This function sets year to the user value if it is a legal value,
//				otherwise the function prints that the day is incorrect.
//				It is a mutator to change the year.
//*************************************************************************************
void Date::setYear(unsigned y)
{
	//checks to see if the year is greater than 0
	if (y >= 1){

		myYear = y;
	}
	else {
		//prints an error message if it's wrong.
		cout << "Year= " << setfill('0') << setw(4) << y << " is incorrect" << endl;
	}
}
/****************************************************************************************
//Name: Operator<<
//Precondition: All the values for the lab have already been set.
//Postcondition: The results of the object will be available for the user to see. 
//Decription: Overloading operator<< as a friend function with chaining. Prints every field
//	   		of the object month, day, and year formatted to the screen.
*****************************************************************************************/
ostream & operator<<(ostream & out, const Date & dateObj)
{
	//prints the object's month, day and year
	out << setfill('0') << setw(2) << dateObj.myMonth << "/";
	out << setfill('0') << setw(2) << dateObj.myDay << "/";
	out << setfill('0') << setw(4) << dateObj.myYear;

	return out;
}
//*********************************************************************************************