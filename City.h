#pragma once
#include <string>
#include <unordered_map>

using namespace std;


class City
{

public:

    string name;

    bool operator==(const City& other)
    {
        return name == other.name;
    }

};


enum class TransportType {
    AIRPLANE,
    TRAIN,
    CAR,
    SHIP
};

struct Way
{

public:

    string sourceCity;          // Город отправления
    string destinationCity;     // Город назначения
    TransportType transportType; // Тип транспорта
    string departureDate;  //Дата отправления
    string departureTime;   // Время отправления
    string arrivalDate;     //Дата прибытия
    string arrivalTime;     // Время прибытия
    double cost;                 // Стоимость
    int travelClass;             // Класс обслуживания

    bool operator==(const Way& other) const 
    {
        return sourceCity == other.sourceCity &&
            destinationCity == other.destinationCity &&
            transportType == other.transportType &&
            departureDate == other.departureDate &&
            departureTime == other.departureTime &&
            arrivalDate == other.arrivalDate &&
            arrivalTime == other.arrivalTime &&
            cost == other.cost &&
            travelClass == other.travelClass;
    }

  

};

