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
    int CheckTime(string timeArrivalWay1, string timeDeparture2, int i); //��������� ������� �� �������
    
    int CheckDate(string dateArrivalWay1, string dateDepartureWay2); // ������, �������� �� ����
    
    vector<list<Way>> FormateToTransfer(vector<list<Way>> allWays); //�������������, ���� ������ ������� �� ���������
	
    vector<list<Way>> FormateToDateDeparture(vector<list<Way>> allWays, string wantedDateDeparture); //������������� �� �������� ���� �������

    vector<list<Way>> FormateToDateArrival(vector<list<Way>> allWays, string wantedDateArrival); //������������� �� �������� ���� ��������
   
};

