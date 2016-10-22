/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 14/10/2016
-------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <random>
#include "activityEngine.h"
#include "heap.h"
#include "heap.cpp"
#include <unordered_map>
#include "vehicle.h"
#include "Stats.h"
#include "queue.h"
#include "queue.cpp"
#include "vehicleType.h"
#include "time.h"
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
	//set crrent time
	currentTime.setHour(0);
	currentTime.setMin(0);
	//init vehicle On Road State
	vehicleOnRoadState = new Heap<vehicle>(100);
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
void activityEngine::initQueue(Stats *&Statistics, std::unordered_map<std::string, vehicleType>& vehicleTypeInfo)
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
				arriveTime.setHour(rand() % 24);
				//set min
				arriveTime.setMin(rand() % 60);
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
				//set regisration number
				newVehicle.setRegisration(generateRegisration(vehicleType[m], vehicleTypeInfo));
				//set each Day Activity
				eachDayActivity[i]->Enqueue(newVehicle);	
			}			
		}		
	}
	delete [] vehicleType;
	delete [] speedMean;
	delete [] speedStandardDeviation;
	//sort queue and check Regisration are not same
	for (int i = 0; i < days; i++)
	{
		eachDayActivity[i]->BubbleSort();
		int whichSame = eachDayActivity[i]->checkElementSame();
		while (whichSame != -1)
		{
			vehicle newVehicle = eachDayActivity[i]->getElement(whichSame);
			string sameElementType = newVehicle.getType();
			string newRegisration = generateRegisration(sameElementType, vehicleTypeInfo);
			newVehicle.setRegisration(newRegisration);
			
			eachDayActivity[i]->setElement(whichSame, newVehicle);
			
			whichSame = eachDayActivity[i]->checkElementSame();
		}
	}
	return;
}
//generate regisration number
string activityEngine::activityEngine::generateRegisration(string type, std::unordered_map<std::string, vehicleType>& vehicleTypeInfo)
{
	string output;
	string regisration = vehicleTypeInfo[type].getRegisration();
	for (int i = 0; i < regisration.length(); i++)
	{
		int temp = 0;
		if (regisration[i] == 'L')
		{
			temp = rand()%(90-65 + 1) + 65;
			output.insert(output.end(), 1, temp);			
		}
		else if (regisration[i] == 'D')
		{
			temp = rand()%(57-48 + 1) + 48;
			output.insert(output.end(), 1, temp);
		}		
	}
	return output;
}
void activityEngine::simulation(std::unordered_map<std::string, vehicleType> &Types)
{
	int currentMin;
	int currentHour;
	for (int i = 0; i < days; i++)
	{
		cout << "Day: " << i + 1 << endl;
		for (int m = 0; m < 24 * 60; m++)
		{
			//print out current time
			//cout << "current Time " << currentTime;
			
			vehicle newVehicle = eachDayActivity[i]->Front();
			if (currentTime == newVehicle.getArriveTime())
			{
				eachDayActivity[day]->Dequeue();	// Removes an element in Queue from front end.
				//put into heap
				vehicleOnRoadState->insert(newVehicle);
			}
			else if(newVehicle.getArriveTime() < currentTime)//solve if have two same arrive in the queue
			{
				int min = currentTime.getMin();
				newVehicle.setArriveTimeMin(min++);
				eachDayActivity[day]->Dequeue();	// Removes an element in Queue from front end.
				//put into heap
				vehicleOnRoadState->insert(newVehicle);
				//cout << "newVehicle: " << newVehicle << endl;
				//cout << "Heap: " << *vehicleOnRoadState << endl;
			}
			//change vehicle State in the heap
			for ()
			{
			
			}
			currentMin = currentTime.getMin();
			currentMin++;
			if (currentMin >= 60)
			{
				currentHour = currentTime.getHour();			
				currentTime.setMin(0);
				currentTime.setHour(++currentHour);
			}
			else
				currentTime.setMin(currentMin);
			
			
		}		
	}
	return;
}
void activityEngine::vehicleChangeState(vehicle &newVehicle, int day, std::unordered_map<std::string, vehicleType> &VehicleTypeInfo)
{
	float random = rand() / float(RAND_MAX);
	
	string newVehicleType = newVehicle.getType();
	float continuingDrivingProbability = VehicleTypeInfo[newVehicleType].getContinuingDrivingProbability();
	float turnProbability = VehicleTypeInfo[newVehicleType].getTurnProbability();
	float parkProbability = VehicleTypeInfo[newVehicleType].getParkProbability();
	float speedUpProbability = VehicleTypeInfo[newVehicleType].getSpeedUpProbability();
	float speedDownProbability = VehicleTypeInfo[newVehicleType].getSpeedDownProbability();
	
	float levelOne = continuingDrivingProbability;
	float levelTwo = continuingDrivingProbability + turnProbability;
	float levelThree = continuingDrivingProbability + turnProbability + parkProbability;
	float levelFour = continuingDrivingProbability + turnProbability + parkProbability + speedUpProbability;
	float levelFifty = continuingDrivingProbability + turnProbability + parkProbability + speedUpProbability + speedDownProbability;
	
	if (levelFifty != 1)
		cout << "Probability error, sum are not equal 1" << endl;
	if (random < levelOne)//continuingDriving
	{
		
	}
	else if (random >= levelOne && random < levelTwo)//turn
	{
	
	}
	else if (random >= levelTwo && random < levelThree)//parking
	{
	
	}
	else if (random >= levelThree && random < levelFour)//speed up
	{
	
	}
	else if (random >= levelFour && random < levelFifty)//speed down
	{
	
	}
	
	
	return;
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
