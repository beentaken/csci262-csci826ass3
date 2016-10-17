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
        Road GetStretch() { return Stretch; }
        /** Set Stretch
         * \param val New value to set
         */
        void SetStretch(Road val) { Stretch = val; }
        /** Access Automobiles
         * \return The current value of Automobiles
         */
        Vehicle* GetAutomobiles() { return Automobiles; }
        /** Set Automobiles
         * \param val New value to set
         */
        void SetAutomobiles(Vehicle* val) { Automobiles = val; }

    protected:

    private:
        Road Stretch; //!< Member variable "Stretch"
        Vehicle* Automobiles; //!< Member variable "Automobiles"
};

#endif // SIMULATION_H
