
#ifndef date_hpp
#define date_hpp

#include <stdio.h>
#include <fstream>

using namespace std;

class Date
{
public:
Date(); //default constructor; sets m=01, d=01, y=0001
Date(unsigned m, unsigned d, unsigned y); //explicit-value constructor to set date equal to today's date. Use 2-digits for month (m) and day (d), and 4-digits for year (y); this function should
//print a message if a leap year.
void display();//output Date object to the screen
int getMonth();//accessor to output the month
int getDay();//accessor to output the day
int getYear();//accessor to output the year
void setMonth(unsigned m);//mutator to change the month
void setDay(unsigned d);//mutator to change the day
void setYear(unsigned y);//mutation to change the year
friend ostream & operator<<(ostream & out, Date & dateObj);//overloaded operator<< as a friend
 //function with chaining
    
//My added functions
void calcMonth();   //calculates the month
void calcDay();     //calculates the day
void calcYear();    //calculates the year

    
private:
int myMonth, myDay, myYear; //month, day, and year of a Date obj respectively
};
#endif /* date_hpp */
