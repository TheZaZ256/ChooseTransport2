
#include <iostream>
#include <fstream>
#include <list>
#include <windows.h>
#include <locale>
#include "City.h"
#include <vector>
#include "SearchWays.h"
#include "Formating.h"
#include "SumCost.h"
#include "SumMaxTime.h"
#include "CalculatedTransfers.h"
#include "SheduleTransport.h"

using namespace std;

int StartSearchWays(string sourceCity, string destinationCity, list<Way> listOfWays, string wantedDepartureDate, string wantedArrivalDate)
{
    //список всех путей, по которым можно добратьсся до города назначения +
    vector<list<Way>> resultPathList;
    SearchWays searchWays;
    list<Way> currentPath;  //текущий маршрут
    resultPathList = searchWays.SearchAllWays(sourceCity, destinationCity, currentPath, listOfWays, resultPathList);

    Formating formating;

    //проверка путей, если пересадка менее 2х часов, убираем из списка списков путей такие маршруты +
    // Если дата отправления второго маршрута раньше прибытия первого - тоже отсеиваем
    //берем маршрут, сравниваем кадждый путь по времени прибытия и отправления
    vector<list<Way>> formatedListOnTransfer;
    formatedListOnTransfer = formating.FormateToTransfer(resultPathList);

    //проверка по датам, если прибываем в однно время, но не успеваем или даты нас не устаривают, убираем из списка списков путей такие маршруты + 
    //принимаем у пользователя желаемую дату отправления и дату прибытия
    //если не подходят какие-либо пути в списке возможных маршрутов по дате отправления или прибытия - отсеиваем их
    // убираем их из списка маршрутов
    vector<list<Way>> formatedListOnDateDeparture;
    formatedListOnDateDeparture = formating.FormateToDateDeparture(formatedListOnTransfer, wantedDepartureDate);

    vector<list<Way>> formatedListOnDateArrival;
    formatedListOnDateArrival = formating.FormateToDateArrival(formatedListOnDateDeparture, wantedArrivalDate);

    //Реализовать сортировку по стоимости
    //подсчитваем поле стоимость у всех путей в списке маршрута
    SumCost sumCost;
    tuple<vector<list<Way>>, list<double>> tupleAllWaysWithCost;
    tupleAllWaysWithCost = sumCost.SumCostWay(formatedListOnDateArrival);

    //Реализовать сортировку по максимальному времени в пути
    SumMaxTime sumMaxTime;
    tuple<vector<list<Way>>, list<double>, list<string>> tupleAllWaysWithCostAndSumMaxTime;
    tupleAllWaysWithCostAndSumMaxTime = sumMaxTime.allWaysWithCostAndMaxTime(tupleAllWaysWithCost);

    //Реализовать сортировку по пересадкам
    //сколько в списке элементов - столько и пересадок
    CalculatedTransfers calculatedTransfers;
    tuple<vector<list<Way>>, list<double>, list<string>, list<int>> waysWithCostMaxTimeTransfers;
    waysWithCostMaxTimeTransfers = calculatedTransfers.tupleAllWaysWithCostAndSumMaxTime(tupleAllWaysWithCostAndSumMaxTime);

    return 0;
}


int main()
{
    setlocale(LC_ALL, "Russian"); // Устанавливаем локаль для поддержки русского языка

    //INIZIALIZATION
    //список путей
    SheduleTransport sheduleTransport;
    list<Way> listOfWays = sheduleTransport.listOfWays();;

    string sourceCity = "Moscow";
    string destinationCity = "Rovno";
    string wantedDepartureDate = "2023-10-15";  // Желаемая дата отправления
    string wantedArrivalDate = "2023-10-16";  // Желаемая дата прибытия

    //Время для пересадки
    int timeForTransfer = 2;

    StartSearchWays(sourceCity, destinationCity, listOfWays, wantedDepartureDate, wantedArrivalDate);

    //РЕАЛИЗОВАТЬ ИНТЕРФЕЙС
    //таблица, где будут выведены маршруты, в которых отображаются список путей
    //вложенный список для города отправления
    //вложенный список для города назначения
    //окно для ввода даты отправления
    //окно для ввода даты прибытия
    //вложенный список для выбора варианта сортировки
  

}


