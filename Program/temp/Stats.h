#ifndef STATS_H
#define STATS_H
#include "Road.h"
#include "VehicleType.h"

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
        Road GetStretch() { return Stretch; }
        /** Set Stretch
         * \param val New value to set
         */
        void SetStretch(Road val) { Stretch = val; }
        /** Access Types
         * \return The current value of Types
         */
        VehicleType* GetTypes() { return Types; }
        /** Set Types
         * \param val New value to set
         */
        void SetTypes(VehicleType* val) { Types = val; }
        void InitializeTypes(int);

    protected:

    private:
        int VehicleTypesMonitored; //!< Member variable "VehicleTypesMonitored"
        Road Stretch; //!< Member variable "Stretch"
        VehicleType* Types; //!< Member variable "Types"
};

#endif // STATS_H
