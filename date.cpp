#include "date.hpp"
#include <fstream>
#include <iostream>

using namespace std;



// D A T E . C P P
//This stub (for now) should be implemented in date.cpp
//*************************************************************************************


//Name: Date
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to today's date
//Description: This is the default constructor which will be called automatically when
//an object is declared. It will initialize the state of the class
//
//*************************************************************************************
Date::Date()
{
    cout << "Default constructor has beenn called" << endl;
    myMonth = 1;
    myDay = 1;
    myYear = 1;
    
    calcMonth();
    calcDay();
    calcYear();
    
}
//*************************************************************************************
//Name: Date
//Precondition: Takes in month, day and year
//Postcondition: Information is outputed to the screen
//Description: Information is taken in and then outputes calculated info to screen
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
    enum month{jan,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec};
    
    cout << "Explicit constructor has been called" << endl;
    myMonth = m;
    myDay = d;
    myYear = y;
    

    //Months are incorrect
    calcMonth();
    calcDay();
    calcYear();
}
//*************************************************************************************
//Name: Display
//Precondition: Calculations have not been outputed to the screen.
//Postcondition: Calculations have been outputed to the screen.
//Description: Ouputs the calculations to the screen
//***************************************************************
void Date::display()
{
        cout << setfill('0') << setw(2) << myMonth << "/";
        cout << setfill('0') << setw(2) << myDay << "/";
        cout << setfill('0') << setw(4) << myYear << endl;
    
}
//*************************************************************************************
//Name: getMonth
//Precondition: Month has not been accessed
//Postcondition: Month has been accessed
//Description: Accesses the month
//*************************************************************************************
int Date::getMonth()
{

return myMonth;
    
}
//*************************************************************************************
//Name: getDay
//Precondition: Day has not been accessed
//Postcondition: Day has been accessed
//Description: Accesses the day
//
//
//*************************************************************************************
int Date::getDay()
{
    
return myDay;
    
}
//*************************************************************************************
//Name: getYear
//Precondition: Year has not been accessed
//Postcondition: Year has been accessed
//Description: Accesses the year
//
//
//*************************************************************************************
int Date::getYear()
{
    
return myYear;
    
}
//*************************************************************************************
//Name: setMonth
//Precondition: myMonth has not been set equal to m
//Postcondition: m has been checked and is incorrect or myMonth has been equal to m
//Description: Make sure m is correct before setting it equal to myMonth
//
//
//*************************************************************************************
void Date::setMonth(unsigned m)
{
    if(m < 1 || m > 12)
    {
        cout << "Month = " << m << " is incorrect" << endl;
    }
    myMonth = m;
}
//*************************************************************************************
//Name: setDay
//Precondition: myDay has not been set equal to d
//Postcondition:  d has been checked and is incorrect or myDay has been equal to d
//Description: Make sure d is correct before setting it equal to myDay
//
//
//*************************************************************************************
void Date::setDay(unsigned d)
{
    if((myMonth == 1 || myMonth == 3 || myMonth == 5 || myMonth == 7 || myMonth == 8 || myMonth == 10 || myMonth == 12) && myYear > 0)
    {
        if(myDay < 1 || myDay > 31)
        {
            cout << "Day = " << myDay << " is incorrect" << endl;
        }
        else
        {
            myDay = d;
        }
    }
    
    //Months that have 30 days are incorrect
    else if((myMonth == 4 || myMonth == 6 || myMonth == 9 || myMonth == 11) && myYear > 0)
    {
        if(myDay < 1 || myDay > 30)
        {
            cout << "Day = " << myDay << " is incorrect" << endl;
        }
        else
        {
           myDay = d;
        }
    }
    
    
    
    //Febuary is incorrect
    else if(myMonth == 2 && myYear > 0)
    {
        if((myYear % 4 == 0) && (myDay < 1 || myDay > 29))
        {
            cout << "Day = " << myDay << " is incorrect" << endl;
        }
        
        else if(myYear % 4 == 0)
        {
            myDay = d;
        }
        
        else if((myYear % 4 != 0) && (myDay < 1 || myDay > 28))
        {
            cout << "Day = " << myDay << " is incorrect" << endl;
        }
    }
    
    //Months that are above 12
    if(myMonth > 12)
    {
        if(myDay < 1 || myDay > 31 )
        {
            cout << "Day = " << myDay << " is incorrect" << endl;
        }
    }
    
}
//*************************************************************************************
//Name: getYear
//Precondition:  myYear has not been set equal to y
//Postcondition: y has been checked and is incorrect or myYear has been equal to y
//Description: Make sure y is correct before setting it equal to myYear
//
//
//*************************************************************************************
void Date::setYear(unsigned y)
{
    if(myYear <= 0)
    {
        cout << "Year = " << setfill('0') << setw(4) << myYear << " is incorrect" << endl;
    }
    myYear = y;
}

ostream & operator<<(ostream & out, Date& dateObj)
{
    out << setfill('0') << setw(2) << dateObj.myMonth << "/";
    out << setfill('0') << setw(2) << dateObj.myDay << "/";
    out << setfill('0') << setw(4) << dateObj.myYear;
    return out;
}

//My added functions
void Date::calcMonth()
{
    if(myMonth < 1 || myMonth > 12)
       {
           
           cout << "Month = " << myMonth << " is incorrect" << endl;
           cout << "\n"; // space the program out
       }
}

void Date::calcDay()
{
    //Months that have 31 days are incorrect
    if((myMonth == 1 || myMonth == 3 || myMonth == 5 || myMonth == 7 || myMonth == 8 || myMonth == 10 || myMonth == 12) && myYear > 0)
    {
        if(myDay < 1 || myDay > 31)
        {
            cout << "Day = " << myDay << " is incorrect" << endl;
            cout << "\n"; //space the program out
        }
        else
        {
            display();
            cout << "\n"; //space the program out
        }
    }
    
    //Months that have 30 days are incorrect
    else if((myMonth == 4 || myMonth == 6 || myMonth == 9 || myMonth == 11) && myYear > 0)
    {
        if(myDay < 1 || myDay > 30)
        {
            cout << "Day = " << myDay << " is incorrect" << endl;
            cout << "\n"; //space the program out
        }
        else
        {
            display();
            cout << "\n"; //space the program out
        }
    }
    
    
    
    //Febuary is incorrect
    else if(myMonth == 2 && myYear > 0)
    {
        if((myYear % 4 == 0) && (myDay < 1 || myDay > 29))
        {
            cout << "Day = " << myDay << " is incorrect" << endl;
            cout << "\n"; //space the program out
        }
        
        else if(myYear % 4 == 0)
        {
            display();
            cout << "This is a leap year" << endl;
            cout << "\n"; //space the program out
        }
        
        else if((myYear % 4 != 0) && (myDay < 1 || myDay > 28))
        {
            cout << "Day = " << myDay << " is incorrect" << endl;
            cout << "\n"; //space the program out
        }
    }
    
    //Months that are above 12
    if(myMonth > 12)
    {
        if(myDay < 1 || myDay > 31 )
        {
            cout << "Day = " << myDay << " is incorrect" << endl;
            cout << "\n"; //space the program out
        }
    }
}

void Date::calcYear()
{
    if(myYear <= 0)
    {
        cout << "Year = " << setfill('0') << setw(4) << myYear << " is incorrect" << endl;
        cout << "\n"; //space the program out
        
    }
}
