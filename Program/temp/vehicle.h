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
class vehicle
{
	private:
		string regisration;
		int currentPosition;
		int currentSpeed;
		bool parked;
		string thisAction;
		string previousAction;
	public:	
		vehicle();	// Constructor
		~vehicle();	// destructor
		string getRegisration() const;
		int getCurrentPosition() const;
		int getCurrentSpeed() const;
		bool getParked() const;
		string getThisAction() const;
		string getPreviousAction() const;
		
		void setRegisration(string);
		void setCurrentPosition(int);
		void setCurrentSpeed(int);
		void setParked(bool);
		void setThisAction(string);
		void setPreviousAction(string);
		
};

#endif
