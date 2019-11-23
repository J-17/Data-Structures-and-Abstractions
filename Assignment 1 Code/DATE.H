#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string.h>

    /**
	 * @class Date
	 * @brief  This class is used to store the date of the date.
	 *
	 * @author Sin Loo Mah
	 * @version 01
	 * @date 22/4/2019
	 *
	 * @bug My program has no bugs. Well, maybe it has...
	 */

class Date
{
    public:

        /**
        * @brief  default constructor for date class
        */
        Date();

        /**
        * @brief  default constructor with parameters for date class
        */
        Date( unsigned d, unsigned m, unsigned y);

        /**
        * @brief  get method for day - can be called multiple times to get day
        *
        * @return unsigned
        */
        unsigned GetDay() const;

        /**
        * @brief  set method for day - can be called multiple times to set day
        *
        * @param d - day
        * @return void
        */
        void SetDay( unsigned d );

        /**
        * @brief  get method for month - can be called multiple times to get month
        *
        * @return unsigned
        */
        unsigned GetMonth() const;

        /**
        * @brief  set method for month - can be called multiple times to set month
        *
        * @param m - month
        * @return void
        */
        void SetMonth( unsigned m );

        /**
        * @brief  get method for year - can be called multiple times to get year
        *
        * @return unsigned
        */
        unsigned GetYear() const;

        /**
        * @brief  set method for year - can be called multiple times to set year
        *
        * @param y - year
        * @return void
        */
        void SetYear( unsigned y );

    private:

        ///day
        unsigned day;

        ///month
        unsigned month;

        ///year
        unsigned year;
};

#endif // DATE_H



