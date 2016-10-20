#ifndef STATS_H
#define STATS_H
//#include "road.h"
//#include "vehicleType.h"
#include <iostream>
#include <string>
using namespace std;
struct Data
{
        string type;
        float numberMean;
        float numberStandardDeviation;
        float speedMean;
        float speedStandardDeviation;
};
class Stats
{
	friend ostream& operator << (ostream&, const Stats&);
        friend istream& operator >> (istream&, Stats&);
    public:
        Stats();// Default constructor
        virtual ~Stats();// Default destructor
       // Stats(const Stats& other); // Copy constructor param other Object to copy from
 
        Stats& operator=(const Stats& other);//Assignment operator param other Object to assign from return A reference to this
       // int GetvehicleTypesMonitored() const;
        //void SetvehicleTypesMonitored(int);
        /** Access Stretch
         * \return The current value of Stretch
         */
       /* road GetStretch() { return Stretch; }//Set Stretch
         //param val New value to set
        void SetStretch(road val) { Stretch = val; }*/
        /** Access Types
         * \return The current value of Types
         */
       /* vehicleType* GetTypes() { return Types; }*/
        /** Set Types
         * \param val New value to set
         */
        //void SetTypes(vehicleType* val) { Types = val; }
        //void InitializeTypes(int);
        
        string getType() const;
        float getNumberMean() const;
        float getNumberStandardDeviation() const;
        float getSpeedMean() const;
        float getSpeedStandardDeviation() const;
        
        void setType(string);
        void setNumberMean(float);
        void setNumberStandardDeviation(float);
        void setSpeedMean(float);
        void setSpeedStandardDeviation(float);

    protected:

    private:
       // int vehicleTypesMonitored; //!< Member variable "vehicleTypesMonitored"
       // road Stretch; //!< Member variable "Stretch"
        //vehicleType* Types; //!< Member variable "Types"
        Data data;
    
};

#endif // STATS_H
