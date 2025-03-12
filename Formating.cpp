#include "Formating.h"

int Formating::CheckTime(string timeArrivalWay1, string timeDeparture2, int i) //��������� ������� �� �������
{
    //��������� ������ � �����
    int hours, minutes;
    char colon;

    istringstream iss1(timeArrivalWay1);
    // ��������� ����, ��������� � ������
    iss1 >> hours >> colon >> minutes;
    int totalMinuts1 = hours * 60 + minutes;

    istringstream iss2(timeDeparture2);
    // ��������� ����, ��������� � ������
    iss2 >> hours >> colon >> minutes;
    int totalMinuts2 = hours * 60 + minutes;
    int difference;

    if (i == 0)
    {//���� ����� �����
        // ��������� ������� � �������
        difference = totalMinuts2 - totalMinuts1;
    }
    else
    {//���� � ������ �����
        // ��������� ������� � �������
        totalMinuts1 = totalMinuts1 - (24 * 60); // ��������� ������� �� ������� �� ��������� ����� � ������� �������
        difference = totalMinuts2 - totalMinuts1;
    }


    return difference;
}

int Formating::CheckDate(string dateArrivalWay1, string dateDepartureWay2) // ������, �������� �� ����
{
    //�������� ����, ���������� ��
    //�������� ������, ���������� ��
    //�������� ���, ���������� ��

    string year1 = dateArrivalWay1.substr(0, 4);  // ��� (������� 0/1/2/3)
    string month1 = dateArrivalWay1.substr(5, 2); // ����� (������� 5/6)
    string day1 = dateArrivalWay1.substr(8, 2);   // ���� (������� 8-9)

    string year2 = dateDepartureWay2.substr(0, 4);  // ��� (������� 0/1/2/3)
    string month2 = dateDepartureWay2.substr(5, 2); // ����� (������� 5/6)
    string day2 = dateDepartureWay2.substr(8, 2);   // ���� (������� 8-9)

    int yearInt1 = stoi(year1);
    int monthInt1 = stoi(month1);
    int dayInt1 = stoi(day1);

    int yearInt2 = stoi(year2);
    int monthInt2 = stoi(month2);
    int dayInt2 = stoi(day2);

    //���� ���� ����������� ������� ���� ������ ����������� ������� ����
    //����� ���� ��� �� ����������
    if (yearInt2 < yearInt1 || monthInt2 < monthInt1 || dayInt2 < dayInt1)
    {//���� ������ ���� ������ ������

        return 0;
    }
    else if (dayInt2 - dayInt1 == 1 && yearInt2 == yearInt1 && monthInt2 == monthInt1)
    {//���� ������ ���� - ��������� ����� ������ ����
        return 1;
    }
    else if (dayInt2 == dayInt1 == 1 && yearInt2 == yearInt1 && monthInt2 == monthInt1)
    {//���� ���� �����
        return 2;
    }
    else if (yearInt2 > yearInt1 || monthInt2 > monthInt1 || dayInt2 > dayInt1)
    {//���� ������ ���� ������ ������
        return 3;
    }
    else
    {
        return 4;
    }
}


vector<list<Way>> Formating::FormateToTransfer(vector<list<Way>> allWays) //�������������, ���� ������ ������� �� ���������
{
    vector<list<Way>> formatedList;

    for (list<Way> list : allWays) //������� ������� � ������ // ������� ��������� � ������ ���������
    {
        bool isWayGood = false; // ���������� �� ��� ���� ����

        string timeArrivalWay1 = ""; //����� �������� ������� ����
        string timeDeparture2 = "";  //����� ����������� ������� ����

        string dateArrivalWay1; // ���� �������� ������� ����
        string dateDepartureWay2; //���� ����������� ������� ����

        for (Way way : list) // ������� ����� � ��������
        {
            if (list.size() == 1)
            {
                //���� � ������ �����, ����� 1 ����
                isWayGood = true;
            }
            else if (list.size() == 0)
            {
                //���� � ������ ����� 0 �����
            }
            else
            {//���� � ������ ����� ������ ������ ���� � ����������� ���������
                //���� ����� �������� ������� �������� �����
                //�.�. ���� ��� �� ������������� ������ ����
                if (timeArrivalWay1 == "")
                {
                    timeArrivalWay1 = way.arrivalTime;
                    dateArrivalWay1 = way.arrivalDate;
                }
                else
                {//���� ��� ������� ����� �������� ������� ��������
                    timeDeparture2 = way.departureTime;
                    dateDepartureWay2 = way.departureDate;

                    int i = CheckDate(dateArrivalWay1, dateDepartureWay2);

                    //���� ���� ����������� ������� ���� ������ ����������� ������� ���� 1
                    //����� ���� ��� �� ����������
                    if (i == 0)
                    {
                        isWayGood = false; // ������� �� ��������� �� �������
                        break; // ��������� ����� �� �����
                    }
                    else if (i == 1)
                    {//���� ���� ����������� ������� �������� �� ��������� ����� �������� ������� �������� 2

                        if (CheckTime(timeArrivalWay1, timeDeparture2, 1) < 120)
                        {
                            isWayGood = false; // ������� �� ��������� �� �������
                            break; // ��������� ����� �� �����
                        }
                        else
                        {
                            isWayGood = true; // ������� �� ��������� �������
                            //������ ������������� ����� � ���� �������� ������� � ����� � ���� ����������� ��������
                            //������������� ���� � ����� �������� ������� �������� - ������ ��� �������, �� ��������� ���� ����� ���������� � ������� � ��
                            timeArrivalWay1 = way.arrivalTime;
                            dateArrivalWay1 = way.arrivalDate;
                        }
                    }
                    else if (i == 2)
                    {//���� ��������� ����
                        //���� ���� ��������� 
                        if (CheckTime(timeArrivalWay1, timeDeparture2, 0) < 120)
                        {//���� ����� ��������� ������ 2

                            isWayGood = false; // ������� �� ��������� �� �������
                            break; // ��������� ����� �� �����

                        }
                        else
                        {//���� ������� ��������� �������
                            isWayGood = true; // ������� �� ��������� �������
                            //������ ������������� ����� � ���� �������� ������� � ����� � ���� ����������� ��������
                            //������������� ���� � ����� �������� ������� �������� - ������ ��� �������, �� ��������� ���� ����� ���������� � ������� � ��
                            timeArrivalWay1 = way.arrivalTime;
                            dateArrivalWay1 = way.arrivalDate;
                        }
                    }
                    else if (i == 3)//���� ���� ����������� ������� �������� ����� �������� (����� ����� � �����) ������� �������� 3
                    {

                        isWayGood = true;
                        timeArrivalWay1 = way.arrivalTime;
                        dateArrivalWay1 = way.arrivalDate;
                    }

                }

            }

        }
        if (isWayGood == true)
        {
            formatedList.push_back(list);
        }


    }

    return formatedList;
}

vector<list<Way>> Formating::FormateToDateDeparture(vector<list<Way>> allWays, string wantedDateDeparture) //������������� �� �������� ���� �������
{
    vector<list<Way>> formatedList;

    for (list<Way> list : allWays) //������� ������� � ������ // ������� ��������� � ������ ���������
    {
        //��� ���������� ������ ������ ���� � ��������, ���� �� �������� � ������ ��� ����, �� ��� ��

        string dateDeparture = list.front().departureDate;

        if (dateDeparture == wantedDateDeparture)
        {// ���� ���� ������� ���������� � ����� ������� ������� ��������
            formatedList.push_back(list);
        }

    }

    return formatedList;
}

vector<list<Way>> Formating::FormateToDateArrival(vector<list<Way>> allWays, string wantedDateArrival) //������������� �� �������� ���� ��������
{
    vector<list<Way>> formatedList;

    for (list<Way> list : allWays) //������� ������� � ������ // ������� ��������� � ������ ���������
    {
        //��� ���������� ������ ��������� ���� � ��������, ���� �� �������� � ������ ��� ����, �� ��� ��

        string dateArrival = list.back().arrivalDate;

        if (dateArrival == wantedDateArrival)
        {// ���� ���� ������� ���������� � ����� ������� ������� ��������
            formatedList.push_back(list);
        }

    }

    return formatedList;
}
