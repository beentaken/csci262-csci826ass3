#ifndef STATS_H
#define STATS_H
#include "road.h"
#include "vehicleType.h"

class Stats
{
	friend ostream& operator<<(ostream&, Stats);
        friend istream& operator>>(istream&, Stats&);
    public:
        /** Default constructor */
        Stats();
        /** Default destructor */
        virtual ~Stats();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Stats(const Stats& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Stats& operator=(const Stats& other);

        /** Access vehicleTypesMonitored
         * \return The current value of vehicleTypesMonitored
         */
        int GetvehicleTypesMonitored() { return vehicleTypesMonitored; }
        /** Set vehicleTypesMonitored
         * \param val New value to set
         */
        void SetvehicleTypesMonitored(int val) { vehicleTypesMonitored = val; }
        /** Access Stretch
         * \return The current value of Stretch
         */
        road GetStretch() { return Stretch; }
        /** Set Stretch
         * \param val New value to set
         */
        void SetStretch(road val) { Stretch = val; }
        /** Access Types
         * \return The current value of Types
         */
        vehicleType* GetTypes() { return Types; }
        /** Set Types
         * \param val New value to set
         */
        void SetTypes(vehicleType* val) { Types = val; }
        void InitializeTypes(int);
        
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
        int vehicleTypesMonitored; //!< Member variable "vehicleTypesMonitored"
        road Stretch; //!< Member variable "Stretch"
        vehicleType* Types; //!< Member variable "Types"
        
        string type;
        float numberMean;
        float numberStandardDeviation;
        float speedMean;
        float speedStandardDeviation;
};

#endif // STATS_H
