#ifndef CONSTANTS_H
#define CONSTANTS_H


class constants
{
    public:
        /** Default constructor */
        constants();
        /** Default destructor */
        virtual ~constants();
        /** Copy constructor
         *  \param other Object to copy from
         */
        constants(const constants& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        constants& operator=(const constants& other);

    protected:

    private:
};

#endif // CONSTANTS_H
