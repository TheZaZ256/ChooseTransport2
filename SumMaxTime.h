#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <windows.h>
#include <locale>
#include "City.h"
#include <vector>
#include "SearchWays.h"
#include "Formating.h"
#include <map>
#include <string>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>


class SumMaxTime
{
public:

	std::tm make_tm(int year, int month, int day, int hour, int min, int sec);

	// ‘ункци€ дл€ проверки високосного года
	bool isLeapYear(int year);

	// ‘ункци€ дл€ получени€ количества дней в мес€це
	int daysInMonth(int year, int month);

	// ‘ункци€ дл€ вычислени€ разницы в годах, мес€цах, дн€х, часах и минутах
	list<string> diffInDateTime(const std::tm& tm1, const std::tm& tm2);

	list<string> CalculateMaxTimeIfDateSecondBiggest(string dataDeparture, string timeDeparture, string dataArrival, string timeArrival);

	list<string> CalculateMaxTime(string dataDeparture, string timeDeparture, string dataArrival, string timeArrival);

	tuple<vector<list<Way>>, list<double>, list<string>> allWaysWithCostAndMaxTime(tuple<vector<list<Way>>, list<double>> allWaysWithCost);


};

