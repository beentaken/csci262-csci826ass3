/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 14/10/2016
-------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <random>
#include "activityEngine.h"
//#include "heap.h"
//#include "heap.cpp"
#include "vehicle.h"
#include "Stats.h"
#include "queue.h"
#include "queue.cpp"
using namespace std;
activityEngine::activityEngine()
{

}
activityEngine::activityEngine(int days, Stats *&Statistics, int NumStatistics)//by days
{
	//set number of type
	numberOfType = NumStatistics;
        //calculate each Day Flow Each Type
        eachDayFlowEachTypeNumber = new int*[days];
        for (int i = 0; i < days; i++)
        	eachDayFlowEachTypeNumber[i] = new int(numberOfType);
	for (int m = 0; m < days; m++)
	{
		for (int i = 0; i < numberOfType; i++)
		{
			double numberMean = Statistics[i].getNumberMean();
			double numberStandardDeviation = Statistics[i].getNumberStandardDeviation();
			eachDayFlowEachTypeNumber[m][i] = static_cast<int>(norDistribution(numberMean, numberStandardDeviation));
		}
	}
        //calculate one Day total Flow
        int *totalFlowEachDay = new int[days];
        for (int m = 0; m < days; m++)
        {
        	totalFlowEachDay[m] = 0;
        	for (int i = 0; i < numberOfType; i++)
        		totalFlowEachDay[m] += eachDayFlowEachTypeNumber[m][i];
        }
        //allocate member for each Day Activity
        eachDayActivity = new Queue<vehicle>*[days];
        for (int i = 0; i < days; i++)
        	eachDayActivity[i] = new Queue<vehicle>(totalFlowEachDay[i]+1);
        //allocate days
	this->days = days;
	//delete totalFlowEachDay
	delete [] totalFlowEachDay;
}
activityEngine::~activityEngine()
{
	for(int i = 0; i < days; i++)
		delete eachDayActivity[i];
	delete [] eachDayActivity;
}
double activityEngine::norDistribution(double mean, double standardDeviation)
{
	normal_distribution<double> normalDistribution (mean, standardDeviation);
	std::random_device rd;
	std::default_random_engine generator( rd() );
	return normalDistribution(generator);
}
void activityEngine::initQueue(Stats *&Statistics)
{	
	//get vehicle Type
	string *vehicleType = new string[numberOfType];
	for (int m = 0; m < numberOfType; m++)
		vehicleType[m] = Statistics[m].getType();
	//get speed Mean
	double *speedMean = new double[numberOfType];
	for (int m = 0; m < numberOfType; m++)
		speedMean[m] = Statistics[m].getSpeedMean();
	
	//get speed Standard Deviation
	double *speedStandardDeviation = new double[numberOfType];
	for (int m = 0; m < numberOfType; m++)
		speedStandardDeviation[m] = Statistics[m].getSpeedStandardDeviation();
	// Intializes random number generator
	srand((unsigned) time(NULL));
	for (int i = 0; i < days; i++)
	{	
		for (int m = 0; m < numberOfType; m++)
		{			
			for (int n = 0; n < eachDayFlowEachTypeNumber[i][m]; n++)
			{
				vehicle newVehicle;
				Time arriveTime;
				
				//set hour
				arriveTime.hour = rand() % 24;
				//set min
				arriveTime.min = rand() % 60;
				//set arrive Time
				newVehicle.setArriveTime(arriveTime);
				//set type
				newVehicle.setType(vehicleType[m]);
				//set current Position
				newVehicle.setCurrentPosition(0);
				//set parked
				newVehicle.setParked(false);
				//set this Action
				newVehicle.setThisAction("arrive");
				// set previousAction
				newVehicle.setPreviousAction("NULL");
				//set speed
				
				int speed = static_cast<int>(norDistribution(speedMean[m], speedStandardDeviation[m]));
				newVehicle.setCurrentSpeed(speed);
				
				//set each Day Activity
				eachDayActivity[i]->Enqueue(newVehicle);	
			}			
		}		
	}
	delete [] vehicleType;
	delete [] speedMean;
	delete [] speedStandardDeviation;
	//sort queue
	for (int i = 0; i < days; i++)
		eachDayActivity[i]->BubbleSort();
	return;
}
//generate regisration number
string activityEngine::generateRegisration(string type)
{
	
}
int activityEngine::getDays() const
{
	return days;
}
Queue<vehicle> * activityEngine::getEachDayActivity(int days) const
{
	return eachDayActivity[days];
}
ostream& operator << (ostream& out, const activityEngine& data)
{
	for (int i = 0; i < data.getDays(); i++)
		out << *data.getEachDayActivity(i);
        return out;
}
