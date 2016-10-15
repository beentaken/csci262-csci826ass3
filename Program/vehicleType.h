/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 15/10/2016
-------------------------------------------------------------*/
#ifndef VEHICLETYPE_H
#define VEHICLETYPE_H
#include<iostream>
#include <string>
using namespace std;
class vehicleType
{
	private:
		string name;
		bool parkable;
		string regisrationFormat;
		int weightVolume;
		int weightSpeed;
		float turnProbability;
		float parkProbability;
		float speedChangeProbability;
		float lawBreakerProbability;
	public:	
		vehicleType();	// Constructor
		~vehicleType();	// destructor
		
		string getName() const;
		bool getParkable() const;
		string getRegisrationFormat() const;
		int getWeightVolume() const;
		int getWeightSpeed() const;
		float getTurnProbability() const;
		float getParkProbability() const;
		float getSpeedChangeProbability() const;
		float getLawBreakerProbability() const;
		
		void setName(string);
		void setParkable(bool);
		void setRegisrationFormat(string);
		void setWeightVolume(int);
		void setWeightSpeed(int);
		void setTurnProbability(float);
		void setParkProbability(float);
		void setSpeedChangeProbability(float);
		void setLawBreakerProbability(float);
};

#endif
