#include <iostream>
#include<fstream>
#include<sstream>
#include <stdlib.h>
#include <cmath>

#include "Windlog.h"
#include "Vector.h"
#include "Date.h"
#include "Time.h"

//using namespace std;

std::istream & operator >> (std::istream & infile, WindLogType &wea);
std::ostream & operator <<( std::ostream & os, const Windlog & vec);

unsigned int selectMonth();
unsigned int selectYear();
float round(float var);
std::string printMonth(int m);
void MYavgWindTemp(const Windlog &vec);
void YavgWindTemp(const Windlog &vec);
void YTotalSolarRadiation(const Windlog &vec);
void YavgWsAtSrToFile(const Windlog &vec);

std::istream & operator >> (std::istream & infile, WindLogType &WLT)
{
    std::string dday, mmonth, yyear, mminute, hhour;
    float fwindspeed, fairtemp, fsolradiation;

    std::getline(infile, dday, '/');
    WLT.ddate.SetDay(atoi(dday.c_str()));
    std::getline(infile, mmonth, '/');
    WLT.ddate.SetMonth(atoi(mmonth.c_str()));
    std::getline(infile, yyear, ' ');
    WLT.ddate.SetYear(atoi(yyear.c_str()));

    std::getline(infile, hhour, ':');
    WLT.ttime.SetHour(atoi(hhour.c_str()));
    std::getline(infile, mminute, ',');
    WLT.ttime.SetMinute(atoi(mminute.c_str()));

    //Read in at the 10th column, Ingore after reading 10 characters at delimiter ','
    for(unsigned int i = 0; i < 9; i++)
    {
        infile.ignore(10, ',');
        infile >> fwindspeed;
    }
    WLT.wwindspeed = fwindspeed*3.6;

    infile.ignore(10, ',');
    infile >> fsolradiation;
    if(fsolradiation >= 100){
        WLT.ssolarRadiation = fsolradiation/6000;
    }
    else{
        WLT.ssolarRadiation = 0;
    }

    for(unsigned int i = 0; i < 6; i++)
    {
        infile.ignore(10, ',');
        infile >> fairtemp;
    }
    WLT.aairTemp = fairtemp;

    return infile;
}

unsigned int validation(unsigned int v)
{
    while(std::cin.fail())
    {
        std::cout << "Error " << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> v;
    }
    return v;
}

unsigned int selectMonth()
{
    unsigned int month;
    bool b1 = true;
    while(b1){
        std::cout << "Enter month: ";
        std::cin >> month;
        if( 1 <= month && month <= 12){
            month = validation(month);
            b1 = false;
        }
        else{
            std::cout << '\n' << "Invalid month!" << '\n' << std::endl;
        }
    }
    return month;
}

unsigned int selectYear()
{
    unsigned int year;
    std::cout << "Enter year: ";
    std::cin >> year;
    year = validation(year);
    return year;
}

float round(float var)
{
    float value = (int)(var*100 + 0.5);
    return (float) value/100;
}

void MYavgWindTemp(const Windlog &vec)
{
    unsigned int month;
    unsigned int year;
    float windspeed;
    float airTemp;

    year = selectYear();
    month = selectMonth();

    windspeed = round(vec.getAvgWindSpeed(month, year));
    airTemp = round(vec.getAvgAirTemp(month, year));

    if(windspeed < 0 && airTemp < 0){
        std::cout << '\n' << year << " " << printMonth(month) << ": " << "No data" << std::endl;
    }
    else if(windspeed < 0){
        std::cout << '\n' << year << " " << printMonth(month) << ": " << "No data of wind speed" << ", " << airTemp << " degree C" << '\n';
    }
    else if (airTemp < 0){
        std::cout << '\n' << year << " " << printMonth(month) << ": " << windspeed <<" km/h, " << "No data of ambient air temperature" << '\n';
    }
    else{
        std::cout << '\n' << year << " " << printMonth(month) << ": " << windspeed << " km/h, " << airTemp << " degree C" << '\n';
    }

}

void YavgWindTemp(const Windlog &vec)
{
    unsigned int year = selectYear();
    float avgWind;
    float avgTemp;

    std::cout << '\n' <<"Year: " << year << std::endl;

    for(unsigned int i = 1; i <= 12; i++)
    {
        avgWind = round(vec.getAvgWindSpeed(i, year));
        avgTemp = round(vec.getAvgAirTemp(i, year));

        if(avgWind < 0 && avgTemp < 0){
            std::cout << '\n' << printMonth(i) << ": " << "No data" << std::endl;
        }
        else if(avgWind < 0){
            std::cout << '\n' << printMonth(i) << ": " << "No data of wind speed" << ", "  << avgTemp << " degree C" << '\n';
        }
        else if (avgTemp < 0){
            std::cout << '\n' << printMonth(i) << ": " <<  avgWind <<" km/h, " << "No data of ambient air temperature" << '\n';
        }
        else{
            std::cout << '\n' << printMonth(i) << ": " <<  avgWind << " km/h, " <<  avgTemp << " degree C" << '\n';
        }
    }
}

void YTotalSolarRadiation(const Windlog &vec)
{
    unsigned int year = selectYear();
    float solarR;

    std::cout << '\n' <<"Year: " << year << std::endl;

    for(unsigned int i = 1; i <= 12; i++)
    {
        solarR = round(vec.getTotalSolarRadiation(i, year));

        if(solarR < 0){
            std::cout << '\n' << printMonth(i) << ": " << "No data" << std::endl;
        }
        else{
            std::cout << '\n' << printMonth(i) << ": " << solarR << " kWh/m^2 " << '\n';
        }
    }
}

std::ostream & operator << (std::ostream & os, const Windlog & vec)
{
    unsigned int year = selectYear();
    float ws, aat, sr;

    os
    << "Year" << ',' << year << '\n'
    << "Month" << ',' << "Average wind speed" << ',' << "Average ambient air temperature" << ',' << "Total solar radiation" << '\n';

    for(unsigned i = 1; i <= 12; i++)
    {
        ws = round(vec.getAvgWindSpeed(i,year));
        aat = round(vec.getAvgAirTemp(i, year));
        sr = round(vec.getTotalSolarRadiation(i, year));

        if(ws > 0 && aat > 0 && sr > 0){
            os << printMonth(i) << ',' << vec.getAvgWindSpeed(i,year) << ',' << vec.getAvgAirTemp(i, year) << ',' << vec.getTotalSolarRadiation(i, year) << '\n';
        }
        else if(ws < 0 && aat > 0 && sr > 0){
            os << printMonth(i) << ',' << "No data" << ',' << vec.getAvgAirTemp(i, year) << ',' << vec.getTotalSolarRadiation(i, year) << '\n';
        }
        else if(ws > 0 && aat < 0 && sr > 0){
            os << printMonth(i) << ',' << vec.getAvgWindSpeed(i,year) << ',' << "No data" << ',' << vec.getTotalSolarRadiation(i, year) << '\n';
        }
        else if(ws > 0 && aat > 0 && sr < 0){
            os << printMonth(i) << ',' << vec.getAvgWindSpeed(i,year) << ',' << vec.getAvgAirTemp(i, year) << ',' << "No data" << '\n';
        }
        else if(ws > 0 && aat < 0 && sr < 0){
            os << printMonth(i) << ',' << vec.getAvgWindSpeed(i,year) << ',' << "No data" << ',' << "No data" << '\n';
        }
        else if(ws < 0 && aat < 0 && sr > 0){
            os << printMonth(i) << ',' << "No data" << ',' << "No data" << ',' << vec.getTotalSolarRadiation(i, year) << '\n';
        }
        else if(ws < 0 && aat > 0 && sr < 0){
            os << printMonth(i) << ',' << "No data" << ',' << vec.getAvgAirTemp(i, year) << ',' << "No data" << '\n';
        }
        else{
            continue;
        }
    }
    return os;
}

void YavgWsAtSrToFile(const Windlog &vec)
{
    std::ofstream ofile( "WindTempSolar.csv" );
    ofile << vec;
    std::cout << "Successfully printed to file 'WindTempSolar.csv'" << std::endl;

}

std::string printMonth(int m)
{
    std::string month;
    if(m ==  1){
        month = "January   ";
        return month;
    }
    else if(m == 2){
        month = "February  ";
        return month;
    }
    else if(m == 3){
        month = "March     ";
        return month;
    }
    else if(m == 4){
        month = "April     ";
        return month;
    }
    else if(m == 5){
        month = "May       ";
        return month;
    }
    else if(m == 6){
        month = "June      ";
        return month;
    }
    else if(m == 7){
        month = "July      ";
        return month;
    }
    else if(m == 8){
        month = "August    ";
        return month;
    }
    else if(m == 9){
        month = "September ";
        return month;
    }
    else if(m == 10){
        month = "October   ";
        return month;
    }
    else if(m == 11){
        month = "November  ";
        return month;
    }
    else{
        month = "December  ";
        return month;
    }
}

void printMenu()
{
    std::cout << '\n' << "Enter '1' to display the average wind speed and average ambient air temperature for a specified month and year."<<'\n';
    std::cout << "Enter '2' to display the avarage wind speed and average ambient air temperature for each month of a specified year."<<'\n';
    std::cout << "Enter '3' to display the total solar radiation in kWh/m^2 for each month of a specified year."<<'\n';
    std::cout << "Enter '4' to display the average wind speed(km/h), ambient air temperature and total solar radiation in kWh/m^2 for each month of a specified year in a file named 'WindTempSolar.csv"<<'\n';
    std::cout << "Enter '5' to quit the program"<<'\n';
    std::cout << '\n' << "Please enter an option: " ;
}

int main()
{
    //std::ifstream infile( "MetData-31-3a.csv" );
    std::ifstream infile( "MetData_Mar01-2014-Mar01-2015-ALL.csv" );
    //std::ifstream infile( "MetData_Mar01-2015-Mar01-2016-ALL.csv" );

    if(!infile) return -1;

    Windlog vec;
    WindLogType WLT;
    std::string line;

    while(getline(infile, line, '\n'))
    {
        infile >> WLT;
        vec.SetWeatherData(WLT);
    }

    while(true)
    {
        printMenu();

        unsigned int ans;
        std::cin >> ans;

        switch(ans)
        {
            case 1:
                MYavgWindTemp(vec);
                break;

            case 2:
                YavgWindTemp(vec);
                break;

            case 3:
                YTotalSolarRadiation(vec);
                break;

            case 4:
                YavgWsAtSrToFile(vec);
                break;

            case 5:
                exit(0);

            default:
                std::cout << "Invalid option! Please enter option 1 to 5 only." << std::endl;
        }
    }
    return 0;
}

