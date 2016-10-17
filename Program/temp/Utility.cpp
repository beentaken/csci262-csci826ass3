#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
#include "Utility.h"

bool checkRunProgramFormat(int argc)
{
	if (argc != 5)
	{
		cout << "Run program method is wrong!!!" << endl;
		cout << "run format: Traffic Vehicles.txt Stats.txt Days" << endl;
		return false;
	}
	return true;
}

bool readVehicleTypes(string filename, vehicleType*& Types, int& Count)
{
    string line;
    stringstream converter;
    ifstream myfile;
    myfile.open(filename.c_str());

    if (myfile.good()) {
        if (myfile.is_open()) {
            /**< Til end of file */
            getline(myfile, line, '\n');
            converter << line;
            converter >> Count;
            converter.str("");
            converter.clear();
            Types = new vehicleType[Count];
            int counter = 0;

            while (!myfile.eof()) {
                getline(myfile, line, '\n');
                if (counter > Count) {
                    myfile.close();
                    cout << "Number of vehicle types stated is not equal to the number read in!" << endl;
                    return false;
                }

                if (!line.empty()) {
                    string* tokens = Tokenizer(line, ':');

                    /**< Name */
                    Types[counter].setName(tokens[0]);

                    /**< Parking Flag */
                    int flag;
                    converter << tokens[1];
                    converter >> flag;
                    converter.str("");
                    converter.clear();
                    if (flag == 0)
                        Types[counter].setParkable(false);
                    else
                        Types[counter].setParkable(true);

                    /**< Registration Format */
                    Types[counter].setRegisrationFormat(tokens[2]);

                    /**< Volume Weight */
                    int VW;
                    converter << tokens[3];
                    converter >> VW;
                    converter.str("");
                    converter.clear();
                    Types[counter].setWeightVolume(VW);

                    /**< Speed Weight */
                    int SW;
                    converter << tokens[4];
                    converter >> SW;
                    converter.str("");
                    converter.clear();
                    Types[counter].setWeightSpeed(SW);

                    delete [] tokens;
                }

                counter++;
            }

            myfile.close();
        } else {
            cout << filename << " cannot be opened!" << endl;
            return false;
        }

    } else {
        cout << filename << " not found!" << endl;
        return false;
    }

    return true;
}

bool readStats(string filename, Stats Statistics, int& Count, vehicleType* Ts, int VehicleCount)
{
    string line;
    stringstream converter;
    ifstream myfile;
    myfile.open(filename.c_str());

    if (myfile.good()) {
        if (myfile.is_open()) {
            /**< Til end of file */
            getline(myfile, line, '\n');
            string* nums = Tokenizer(line, ' ');
            Count = nums[0];
            Statistics

            Statistics.InitializeData(Count);
            int counter = 0;
            while (!myfile.eof()) {
                getline(myfile, line, '\n');
                if (counter > Count) {
                    myfile.close();
                    cout << "Number of vehicle types stated is not equal to the number read in!" << endl;
                    return false;
                }

                string* tokens = Tokenizer(line, ':');
                Data Node;

                /**< Name */
                int position = (-1);
                if (VehicleTypeExist(Ts, VehicleCount, tokens[0], position)) {
                    Node.Types = Ts[position];
                } else {
                    cout << "Files not the same!\nTerminating the program!" << endl;
                    return false;
                }

                /**< Parking Flag */
                int flag;
                converter << tokens[1];
                converter >> flag;
                converter.str("");
                converter.clear();
                if (flag == 0)
                    Types[counter].SetParkable(false);
                else
                    Types[counter].SetParkable(true);

                /**< Registration Format */
                Types[counter].SetRegistration_Format(tokens[2]);

                /**< Volume Weight */
                int VW;
                converter << tokens[3];
                converter >> VW;
                converter.str("");
                converter.clear();
                Types[counter].SetVolumeWeight(VW);

                /**< Speed Weight */
                int SW;
                converter << tokens[4];
                converter >> SW;
                converter.str("");
                converter.clear();
                Types[counter].SetSpeedWeight(SW);

                counter++;
            }

            myfile.close();
        } else {
            cout << filename << " cannot be opened!" << endl;
            return false;
        }

    } else {
        cout << filename << " not found!" << endl;
        return false;
    }

    return true;
*/
}

string* Tokenizer(string line, char delimeter)
{
    int tokencount = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == delimeter) {
            tokencount++;
        }
    }

    string * retval = new string[tokencount];
    stringstream ss;
    ss << line;

    for (int i = 0; i < tokencount; i++) {
        string temp;
        getline(ss, temp, delimeter);
        retval[i] = temp;
    }

    return retval;
}

bool VehicleTypeExist(vehicleType* temp, int Total, string Name, int& position)
{
    for (int i = 0; i < Total; i++) {
        if (temp[i].getName() != Name) {
            position = i;
            return true;
        }
    }

    return false;
}
