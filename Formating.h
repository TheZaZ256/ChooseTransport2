#pragma once
#include <list>
#include <vector>
#include <string>
#include "City.h"
#include <sstream>
#include <iostream>

class Formating
{
public:
    int CheckTime(string timeArrivalWay1, string timeDeparture2, int i); //¬ычислить разницу во времени
    
    int CheckDate(string dateArrivalWay1, string dateDepartureWay2); // ”знать, различны ли даты
    
    vector<list<Way>> FormateToTransfer(vector<list<Way>> allWays); //отсортировать, чтоб хватил времени на пересадку
	
    vector<list<Way>> FormateToDateDeparture(vector<list<Way>> allWays, string wantedDateDeparture); //ќтсортировать по желаемой дате отбыти€

    vector<list<Way>> FormateToDateArrival(vector<list<Way>> allWays, string wantedDateArrival); //ќтсортировать по желаемой дате прибыти€
   
};

