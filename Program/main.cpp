#include <iostream>
#include <fstream>
using namespace std;
bool checkRunProgramFormat(int);
int main(int argc, char *argv[])
{
	if (!checkRunProgramFormat(argc))
		return 0;
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
