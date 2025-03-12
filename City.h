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

    string sourceCity;          // ����� �����������
    string destinationCity;     // ����� ����������
    TransportType transportType; // ��� ����������
    string departureDate;  //���� �����������
    string departureTime;   // ����� �����������
    string arrivalDate;     //���� ��������
    string arrivalTime;     // ����� ��������
    double cost;                 // ���������
    int travelClass;             // ����� ������������

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

