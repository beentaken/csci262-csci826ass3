#ifndef SIMULATION_H
#define SIMULATION_H
#include "Road.h"
#include "Vehicle.h"

class Simulation
{
    public:
        /** Default constructor */
        Simulation();
        /** Default destructor */
        virtual ~Simulation();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Simulation(const Simulation& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Simulation& operator=(const Simulation& other);

        /** Access Stretch
         * \return The current value of Stretch
         */
        road GetStretch() { return Stretch; }
        /** Set Stretch
         * \param val New value to set
         */
        void SetStretch(road val) { Stretch = val; }
        /** Access Automobiles
         * \return The current value of Automobiles
         */
        vehicle* GetAutomobiles() { return Automobiles; }
        /** Set Automobiles
         * \param val New value to set
         */
        void SetAutomobiles(vehicle* val) { Automobiles = val; }

    protected:

    private:
        road Stretch; //!< Member variable "Stretch"
        vehicle* Automobiles; //!< Member variable "Automobiles"
};

#endif // SIMULATION_H
