#ifndef WINDLOG_H
#define WINDLOG_H

#include "Vector.h"
#include "Date.h"
#include "Time.h"


    /**
	 * @class Windlog
	 * @brief  This class contain a struct that store data of date class, time class,
	 *          windspeed, air temperature and solar radiation. Besides, this class is
	 *          used to do the calculations of data, such as calculating the average of
	 *          windspeed and air temperature and the total solar radiation.
	 *
	 * @author Sin Loo Mah
	 * @version 01
	 * @date 22/4/2019
	 *
	 * @bug My program has no bugs. Well, maybe it has...
	 */

/**
* @brief this is a struct that store the date class, time class, windspeed,
*           air temperature and solar radiation with the name of
*           windlogtype.
*/
typedef struct
{
    Date ddate;
    Time ttime;
    float wwindspeed;
    float aairTemp;
    float ssolarRadiation;
}WindLogType;

class Windlog
{
    public:

        /**
        * @brief default constructor of the class WindLog.
        *
        * @return void
        */
        Windlog();

        /**
        * @brief this method is used to set the data into the struct
        *
        * @return void
        */
        void SetWeatherData(WindLogType& WLT);

        /**
        *
        *@brief returns the vector size
        *
        *@return unsigned int size
        */
        unsigned int getVectorSize() const;

        /**
        *
        *@brief returns the vector size
        *
        *@return unsigned int size
        */
        float getAvgWindSpeed(unsigned int month, unsigned int year) const;

        /**
        *
        *@brief this method return
        *
        *@return unsigned int size
        */
        float getAvgAirTemp(unsigned int month, unsigned int year) const;

        /**
        *
        *@brief returns the vector size
        *
        *@return unsigned int size
        */
        float getTotalSolarRadiation(unsigned int month, unsigned int year) const;

    private:

        /// create a windlogtype vector
        Vector<WindLogType> vec;

};

#endif
