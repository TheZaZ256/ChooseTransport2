#include "Formating.h"

int Formating::CheckTime(string timeArrivalWay1, string timeDeparture2, int i) //Вычислить разницу во времени
{
    //Переводим строки в время
    int hours, minutes;
    char colon;

    istringstream iss1(timeArrivalWay1);
    // Извлекаем часы, двоеточие и минуты
    iss1 >> hours >> colon >> minutes;
    int totalMinuts1 = hours * 60 + minutes;

    istringstream iss2(timeDeparture2);
    // Извлекаем часы, двоеточие и минуты
    iss2 >> hours >> colon >> minutes;
    int totalMinuts2 = hours * 60 + minutes;
    int difference;

    if (i == 0)
    {//Если сутки равны
        // Вычисляем разницу в минутах
        difference = totalMinuts2 - totalMinuts1;
    }
    else
    {//Если в разные сутки
        // Вычисляем разницу в минутах
        totalMinuts1 = totalMinuts1 - (24 * 60); // Вычисляем сколько не хватает до окончания суток в текущем времени
        difference = totalMinuts2 - totalMinuts1;
    }


    return difference;
}

int Formating::CheckDate(string dateArrivalWay1, string dateDepartureWay2) // Узнать, различны ли даты
{
    //Получаем года, сравнвиаем их
    //Получаем месяцы, сравниваем их
    //Получаем дни, сранвиваем их

    string year1 = dateArrivalWay1.substr(0, 4);  // Год (символы 0/1/2/3)
    string month1 = dateArrivalWay1.substr(5, 2); // Месяц (символы 5/6)
    string day1 = dateArrivalWay1.substr(8, 2);   // День (символы 8-9)

    string year2 = dateDepartureWay2.substr(0, 4);  // Год (символы 0/1/2/3)
    string month2 = dateDepartureWay2.substr(5, 2); // Месяц (символы 5/6)
    string day2 = dateDepartureWay2.substr(8, 2);   // День (символы 8-9)

    int yearInt1 = stoi(year1);
    int monthInt1 = stoi(month1);
    int dayInt1 = stoi(day1);

    int yearInt2 = stoi(year2);
    int monthInt2 = stoi(month2);
    int dayInt2 = stoi(day2);

    //Если дата отправления второго пути раньше отправления первого пути
    //Такой путь нас не устраивает
    if (yearInt2 < yearInt1 || monthInt2 < monthInt1 || dayInt2 < dayInt1)
    {//Если вторая дата меньше первой

        return 0;
    }
    else if (dayInt2 - dayInt1 == 1 && yearInt2 == yearInt1 && monthInt2 == monthInt1)
    {//Если вторая дата - следующие сутки первой даты
        return 1;
    }
    else if (dayInt2 == dayInt1 == 1 && yearInt2 == yearInt1 && monthInt2 == monthInt1)
    {//Если даты равны
        return 2;
    }
    else if (yearInt2 > yearInt1 || monthInt2 > monthInt1 || dayInt2 > dayInt1)
    {//Если вторая дата больше первой
        return 3;
    }
    else
    {
        return 4;
    }
}


vector<list<Way>> Formating::FormateToTransfer(vector<list<Way>> allWays) //отсортировать, чтоб хватил времени на пересадку
{
    vector<list<Way>> formatedList;

    for (list<Way> list : allWays) //сколько списков в списке // сколько маршрутов в списке маршрутов
    {
        bool isWayGood = false; // Устраивает ли нас этот путь

        string timeArrivalWay1 = ""; //Время прибытия первого пути
        string timeDeparture2 = "";  //Время отправления второго пути

        string dateArrivalWay1; // Дата прибытия первого пути
        string dateDepartureWay2; //Дата отправления второго пути

        for (Way way : list) // сколько путей в маршруте
        {
            if (list.size() == 1)
            {
                //если в списке путей, всего 1 путь
                isWayGood = true;
            }
            else if (list.size() == 0)
            {
                //если в списке путей 0 путей
            }
            else
            {//если в списке путей больше одного пути и потребуются пересадки
                //Если время прибытия первого маршрута пусто
                //т.е. если еще не рассматривали первый путь
                if (timeArrivalWay1 == "")
                {
                    timeArrivalWay1 = way.arrivalTime;
                    dateArrivalWay1 = way.arrivalDate;
                }
                else
                {//Если уже указано время прибытия первого маршрута
                    timeDeparture2 = way.departureTime;
                    dateDepartureWay2 = way.departureDate;

                    int i = CheckDate(dateArrivalWay1, dateDepartureWay2);

                    //Если дата отправления второго пути раньше отправления первого пути 1
                    //Такой путь нас не устраивает
                    if (i == 0)
                    {
                        isWayGood = false; // Времени на пересадку не хватает
                        break; // Досрочный выход из цикла
                    }
                    else if (i == 1)
                    {//Если дата отправления второго маршрута на следюущие сутки прибытия первого маршрута 2

                        if (CheckTime(timeArrivalWay1, timeDeparture2, 1) < 120)
                        {
                            isWayGood = false; // Времени на пересадку не хватает
                            break; // Досрочный выход из цикла
                        }
                        else
                        {
                            isWayGood = true; // Времени на пересадку хватает
                            //Теперь рассматриваем время и дату прибытия второго и время и дату отправления третьего
                            //Переназначаем дату и время прибытия первого маршрута - теперь это второго, на следующий цикл будет сравнивать с третьим и тд
                            timeArrivalWay1 = way.arrivalTime;
                            dateArrivalWay1 = way.arrivalDate;
                        }
                    }
                    else if (i == 2)
                    {//Если совпадают даты
                        //Если даты совпадают 
                        if (CheckTime(timeArrivalWay1, timeDeparture2, 0) < 120)
                        {//Если время пересадки меньше 2

                            isWayGood = false; // Времени на пересадку не хватает
                            break; // Досрочный выход из цикла

                        }
                        else
                        {//Если времени пересадки хватает
                            isWayGood = true; // Времени на пересадку хватает
                            //Теперь рассматриваем время и дату прибытия второго и время и дату отправления третьего
                            //Переназначаем дату и время прибытия первого маршрута - теперь это второго, на следующий цикл будет сравнивать с третьим и тд
                            timeArrivalWay1 = way.arrivalTime;
                            dateArrivalWay1 = way.arrivalDate;
                        }
                    }
                    else if (i == 3)//Если дата отправления второго маршрута после прибытия (через сутки и более) первого маршрута 3
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

vector<list<Way>> Formating::FormateToDateDeparture(vector<list<Way>> allWays, string wantedDateDeparture) //Отсортировать по желаемой дате отбытия
{
    vector<list<Way>> formatedList;

    for (list<Way> list : allWays) //сколько списков в списке // сколько маршрутов в списке маршрутов
    {
        //Нас интересует только первый путь в маршруте, если он отбывает в нужную нам дату, то все ок

        string dateDeparture = list.front().departureDate;

        if (dateDeparture == wantedDateDeparture)
        {// Если дата отбытия совпадлает с датой отбытия первого маршрута
            formatedList.push_back(list);
        }

    }

    return formatedList;
}

vector<list<Way>> Formating::FormateToDateArrival(vector<list<Way>> allWays, string wantedDateArrival) //Отсортировать по желаемой дате прибытия
{
    vector<list<Way>> formatedList;

    for (list<Way> list : allWays) //сколько списков в списке // сколько маршрутов в списке маршрутов
    {
        //Нас интересует только последний путь в маршруте, если он отбывает в нужную нам дату, то все ок

        string dateArrival = list.back().arrivalDate;

        if (dateArrival == wantedDateArrival)
        {// Если дата отбытия совпадлает с датой отбытия первого маршрута
            formatedList.push_back(list);
        }

    }

    return formatedList;
}
