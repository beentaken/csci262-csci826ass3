#ifndef STATS_H
#define STATS_H
#include "Road.h"
#include "VehicleType.h"

struct Data
{
    vehicleType Types; //!< Member variable "Types"
    float mean;
    float standardDeviation;
    float speedMean;
    float speedStandardDeviation;
};

class Stats
{
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

        /** Access VehicleTypesMonitored
         * \return The current value of VehicleTypesMonitored
         */
        int GetVehicleTypesMonitored() { return VehicleTypesMonitored; }
        /** Set VehicleTypesMonitored
         * \param val New value to set
         */
        void SetVehicleTypesMonitored(int val) { VehicleTypesMonitored = val; }
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
        void InitializeData(int);
        void SetData(Data, int);

    protected:

    private:
        int VehicleTypesMonitored; //!< Member variable "VehicleTypesMonitored"
        road Stretch; //!< Member variable "Stretch"
        Data* StatData;
};

#endif // STATS_H
