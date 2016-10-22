/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 14/10/2016
-------------------------------------------------------------*/
#include <iostream>
#include "time.h"
using namespace std;
Time::Time()// Constructor
{
	hour = 0;
	min = 0;
}
Time::~Time()
{
	hour = 0;
	min = 0;
}
int Time::getHour() const
{
	return hour;
}
int Time::getMin() const
{
	return min;
}
void Time::setHour(int hour)
{
	this->hour = hour;
	return;
}
void Time::setMin(int min)
{
	this->min = min;
	return;
}
ostream& operator << (ostream& out, const Time& data)
{
	out << "HH-MM: " <<data.getHour();
        out << "-";
	out << data.getMin();
        return out;
}
bool Time::operator < (const Time& rhs)
{
	if (hour < rhs.hour)
		return true;
	else if(hour == rhs.hour)
	{
		if (min == rhs.min)
			return false;
		else if (min < rhs.min)
			return true;
		else
			return false;
	}
	return false;
}
bool Time::operator == (const Time& rhs)
{
	if (hour == rhs.hour && min == rhs.min)
		return true;
	return false;
}
