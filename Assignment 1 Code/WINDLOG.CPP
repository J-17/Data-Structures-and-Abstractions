#include<iostream>
#include "Windlog.h"
#include <cmath>


Windlog::Windlog()
{
    //constructor
}

void Windlog::SetWeatherData(WindLogType& WLT)
{
    vec.addObj(WLT);
}

unsigned int Windlog::getVectorSize() const{

    return vec.getCurrentIndex();
}

float Windlog::getAvgWindSpeed(unsigned int month ,unsigned int year) const
{
    float total = 0;
    float countc = 0;
    float avg = 0;

    for (unsigned i = 0; i < vec.getCurrentSize(); i++)
    {
        if(vec.getIndex(i).ddate.GetYear() == year && vec.getIndex(i).ddate.GetMonth() == month){
            total = total + vec.getIndex(i).wwindspeed;
            countc++;
        }
    }

    if(total > 0){
        avg = total/countc;
        return avg;
    }
    else
        return -1;
}

float Windlog::getAvgAirTemp(unsigned int month ,unsigned int year) const
{
    float avg = 0;
    float total = 0;

    for (unsigned i = 0; i < vec.getCurrentIndex(); i++)
    {
        if(vec.getIndex(i).aairTemp)
            if(vec.getIndex(i).ddate.GetYear() == year && vec.getIndex(i).ddate.GetMonth() == month)
            {
                avg = avg + vec.getIndex(i).aairTemp;
                total++;
            }
    }

    if(total > 0){
        avg = avg/total;
        return avg;
    }
    else
        return -1;
}

float Windlog::getTotalSolarRadiation(unsigned int month, unsigned int year) const
{
    float totalsolarRadiation = 0;

    for (unsigned i = 0; i < vec.getCurrentIndex(); i++)
    {

        if(vec.getIndex(i).ssolarRadiation)
        {
            if(vec.getIndex(i).ddate.GetYear() == year && vec.getIndex(i).ddate.GetMonth() == month)
            {
                totalsolarRadiation = totalsolarRadiation + vec.getIndex(i).ssolarRadiation;
            }
        }
    }

    if(totalsolarRadiation > 0)
        return totalsolarRadiation;
    else
        return -1;
}


