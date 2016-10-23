/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 15/10/2016
-------------------------------------------------------------*/
#ifndef VEHICLE_H
#define VEHICLE_H
#include<iostream>
#include <string>
#include "time.h"
using namespace std;
class vehicle
{
	friend ostream& operator << (ostream&, const vehicle&);
	protected:
		string type;
		Time arriveTime;
		string regisration;
		float currentPosition;
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
		float getCurrentPosition() const;
		float getCurrentSpeed() const;
		bool getParked() const;
		string getThisAction() const;
		string getPreviousAction() const;
		
		void setType(string);
		void setArriveTime(Time);
		void setArriveTimeMin(int);
		void setRegisration(string);
		void setCurrentPosition(float);
		void setCurrentSpeed(float);
		void setParked(bool);
		void setThisAction(string);
		void setPreviousAction(string);
		bool operator< (const vehicle&);
		bool operator == (const vehicle&);
		
};
#endif
