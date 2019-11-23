#ifndef TIME_H
#define TIME_H

    /**
	 * @class Time
	 * @brief  This class is used to store the time of data.
	 *
	 * @author Sin Loo Mah
	 * @version 01
	 * @date 22/4/2019
	 *
	 * @bug My program has no bugs. Well, maybe it has...
	 */

class Time
{
    public:

        /**
        * @brief  default constructor
        *
        * @return void
        */
        Time();

        /**
        * @brief  Used to set the hour
        *
        * @return void
        */
        void SetHour(unsigned int h);


        /**
        * @brief Used to get the hour
        *
        * @return (unsigned int) hour
        */
        unsigned int GetHour()const;


        /**
        * @brief set method for private variable minutes
        *
        * @return void
        */
        void SetMinute(unsigned int m);

        /**
        * @brief accessor method for private variable minutes
        *
        * @return an unsigned int minutes
        */
        unsigned int GetMinute() const;

    private:
        /// unsigned int for storing hours of the time.
        unsigned int hour;

        /// unsigned int for storing minutes of the time.
        unsigned int minute;
};

#endif // TIME_H


