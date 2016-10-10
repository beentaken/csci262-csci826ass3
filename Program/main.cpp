#include <iostream>
using namespace std;
bool checkRunProgramFormat(int);
int main(int argc, char *argv[])
{
	if (!checkRunProgramFormat(argc))
		return 0;
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
