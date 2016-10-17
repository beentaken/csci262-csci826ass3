#include <iostream>
<<<<<<< HEAD
#include <string>
#include <sstream>
#include "Utility.h"
=======
#include <fstream>
>>>>>>> origin/master
using namespace std;

int main(int argc, char *argv[])
{
	if (!checkRunProgramFormat(argc))
		return 0;
<<<<<<< HEAD

    int Traffic;
    int Days;
    string Vfilename = argv[2];
    string Sfilename = argv[3];

    stringstream ss;
    ss << argv[1];
    ss >> Traffic;
    ss.str("");
    ss.clear();
    ss << argv[4];
    ss >> Days;

    VehicleType * Types = NULL;
    int NumVehicleTypes;
    Stats Statistics;
    int NumStatistics;

    if (!readVehicleTypes(Vfilename, Types, NumVehicleTypes))
        return 0;

cout << "MEME" << endl;

    if (!readStats(Sfilename, Statistics, NumStatistics))
        return 0;



	return 0;
}
=======
	vehicleType *type;
	readVehicleType(type, argc);
	delete type;	
	return 0;
}
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
void readVehicleType(vehicleType *& type, char *[]& argc)
{
	ifstream file(argc[1]);
	int numberOfTypeOfVehicle = 0;
	if (file.is_open())
	{
		file >> numberOfTypeOfVehicle;
		type = new vehicleType[numberOfTypeOfVehicle];
		int count = 0;
		while ( !file.eof())
		{
			file >> type[count];
			if (!file.good())
			{
				return;
			}
			count++;			
		}
    		file.close();
	}
	else cout << "Unable to open file" << endl;
	return;
}


#include <iostream>

using namespace std;
void readFile(int, char *[]);
int main(int argc, char *argv[])
{
	readFile(argc, argv);
	return 0;
}
void readFile(int argc, char *argv[])
{
	string fileName;
	cout << "please input file name for open: ";
	cin >> fileName;
	
}
>>>>>>> origin/master
