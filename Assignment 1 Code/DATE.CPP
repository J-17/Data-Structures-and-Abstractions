#include "date.h"

Date::Date()
{

}

Date::Date( unsigned d, unsigned m, unsigned y )
{
    day = d;
    month = m;
    year = y;
}

unsigned Date::GetDay() const
{
    return day;
}

void Date::SetDay( unsigned d )
{
    day = d;
}

unsigned Date::GetMonth() const
{
    return month;
}

void Date::SetMonth( unsigned m )
{
    month = m;
}

unsigned Date::GetYear() const
{
    return year;
}

void Date::SetYear( unsigned y )
{
    year = y;
}



