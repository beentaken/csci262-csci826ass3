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

bool readVehicleTypes(string filename, VehicleType* Types, int& Count)
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
            Types = new VehicleType[Count];
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
                    Types[counter].SetName(tokens[0]);

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

bool readStats(string filename, Stats Statistics, int& Count)
{
/*    string line;
    stringstream converter;
    ifstream myfile;
    myfile.open(filename.c_str());

    if (myfile.good()) {
        if (myfile.is_open()) {
            /**< Til end of file */
/*            getline(myfile, line, '\n');
            string* nums = Tokenizer(line, ' ');


            Statistics.InitializeTypes(Count);
            int counter = 0;
            while (!myfile.eof()) {
                getline(myfile, line, '\n');
                if (counter > Count) {
                    myfile.close();
                    cout << "Number of vehicle types stated is not equal to the number read in!" << endl;
                    return false;
                }

                string* tokens = Tokenizer(line, ':');

                /**< Name */
/*                Statistics.Types[counter]->SetName(tokens[0]);

                /**< Parking Flag */
/*                int flag;
                converter << tokens[1];
                converter >> flag;
                converter.str("");
                converter.clear();
                if (flag == 0)
                    Types[counter].SetParkable(false);
                else
                    Types[counter].SetParkable(true);

                /**< Registration Format */
/*                Types[counter].SetRegistration_Format(tokens[2]);

                /**< Volume Weight */
/*                int VW;
                converter << tokens[3];
                converter >> VW;
                converter.str("");
                converter.clear();
                Types[counter].SetVolumeWeight(VW);

                /**< Speed Weight */
/*                int SW;
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
