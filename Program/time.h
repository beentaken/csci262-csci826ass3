/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 15/10/2016
-------------------------------------------------------------*/
#ifndef TIME_H
#define TIME_H
#include<iostream>
#include <string>
using namespace std;
class Time
{
	friend ostream& operator << (ostream&, const Time&);
	private:
		int hour;
		int min;
	public:
		Time();
		~Time();
		int getHour() const;
		int getMin() const;
		void setHour(int);
		void setMin(int);
		bool operator< (const Time&);
		bool operator == (const Time&);
};

#endif
