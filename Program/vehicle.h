/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 15/10/2016
-------------------------------------------------------------*/
#ifndef VEHICLE_H
#define VEHICLE_H
#include<iostream>
#include <string>
using namespace std;
struct Time
{
	int hour;
	int min;
};
class vehicle
{
	friend ostream& operator << (ostream&, const vehicle&);
	private:
		string type;
		Time arriveTime;
		string regisration;
		int currentPosition;
		float currentSpeed;
		bool parked;
		string thisAction;
		string previousAction;
	public:	
		vehicle();	// Constructor
		~vehicle();	// destructor
		string getType() const;
		Time getArriveTime() const;
		int getArriveTimeHour() const;
		int getArriveTimeMin() const;
		string getRegisration() const;
		int getCurrentPosition() const;
		int getCurrentSpeed() const;
		bool getParked() const;
		string getThisAction() const;
		string getPreviousAction() const;
		
		void setType(string);
		void setArriveTime(Time);
		void setRegisration(string);
		void setCurrentPosition(int);
		void setCurrentSpeed(int);
		void setParked(bool);
		void setThisAction(string);
		void setPreviousAction(string);
		
		bool operator< (const vehicle&);
		
};

#endif
