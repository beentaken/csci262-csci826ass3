#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <stdlib.h>     /* atoi */
#include "Stats.h"
#include "vehicleType.h"
#include "Utility.h"
#include "road.h"
using namespace std;


bool checkRunProgramFormat(int argc)
{
	if (argc != 4)
	{
		cout << "Run program method is wrong!!!" << endl;
		cout << "run format: Traffic Vehicles.txt Stats.txt Days" << endl;
		return false;
	}
	return true;
}
bool readVehicleTypes(string filename, std::unordered_map<std::string, vehicleType>& type, int &numberOfTypeOfVehicle)
{
    ifstream file(filename.c_str());
	if (file.is_open())
	{
		string typeNum;
		getline(file, typeNum,'\n');
		numberOfTypeOfVehicle = atoi(typeNum.c_str());
		vehicleType * readVehicle = new vehicleType[numberOfTypeOfVehicle];
		std::pair <std::string,vehicleType> Pair;
		string readType;
		for (int count = 0; count < numberOfTypeOfVehicle; count++)
		{
			if (!file.good() )
				break;
			getline(file, readType,':');
			file >> readVehicle[count];
			Pair = std::make_pair (readType, readVehicle[count]);
			type.insert (Pair);
		}
    		
	}
	else
	{
		cout << "Unable to open file" << endl;
		return false;
	}
	file.close();
	return true;
}
/*
bool readVehicleTypes(string filename, vehicleType*& type, int &numberOfTypeOfVehicle)
{
    ifstream file(filename.c_str());
	if (file.is_open())
	{
		file >> numberOfTypeOfVehicle;
		type = new vehicleType[numberOfTypeOfVehicle];
		for (int count = 0; count < numberOfTypeOfVehicle; count++)
		{
			if (!file.good() )
				break;
			file >> type[count];			
		}
    		
	}
	else
    {
        cout << "Unable to open file" << endl;
        return false;
    }
	file.close();
    return true;
}*/

bool readStats(string filename, Stats*& Statistics, int& monitoredCount, road& roadInfo)
{
	string numberOfTypeMonitored;
	string roadLength;
	string speedLimit;
	string numberOfParkingAvailable;

	ifstream statFile(filename.c_str());
	if (statFile.is_open())
	{
		statFile >> numberOfTypeMonitored;
		statFile >> roadLength;
		roadInfo.setLength(atoi(roadLength.c_str()));

		statFile >> speedLimit;
		roadInfo.setSpeedLimit(atoi(speedLimit.c_str()));

		statFile >> numberOfParkingAvailable;
		roadInfo.setParkingSpaces(atoi(numberOfParkingAvailable.c_str()));

		monitoredCount = atoi(numberOfTypeMonitored.c_str());

		Statistics = new Stats[monitoredCount];
		for (int count = 0; count < monitoredCount; count++)
		{

			if (!statFile.good() )
				break;
			statFile >> Statistics[count];
		}
    		
	}
	else
	{
        	cout << "Unable to open file" << endl;
        	return false;
	}
	statFile.close();
    return true;
}
