
#include "SumMaxTime.h"

std::tm SumMaxTime::make_tm(int year, int month, int day, int hour, int min, int sec) {
	std::tm tm = { 0 };
	tm.tm_year = year - 1900; // Год
	tm.tm_mon = month - 1;    // Месяц
	tm.tm_mday = day;         // День
	tm.tm_hour = hour;        // Часы
	tm.tm_min = min;          // Минуты
	tm.tm_sec = sec;          // Секунды
	return tm;
}

// Функция для проверки високосного года
bool SumMaxTime::isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Функция для получения количества дней в месяце
int SumMaxTime::daysInMonth(int year, int month) {
	if (month == 2) {
		return isLeapYear(year) ? 29 : 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	else {
		return 31;
	}
}

// Функция для вычисления разницы в годах, месяцах, днях, часах и минутах
list<string> SumMaxTime::diffInDateTime(const std::tm& tm1, const std::tm& tm2) {
	int year1 = tm1.tm_year + 1900;
	int month1 = tm1.tm_mon + 1;
	int day1 = tm1.tm_mday;
	int hour1 = tm1.tm_hour;
	int min1 = tm1.tm_min;

	int year2 = tm2.tm_year + 1900;
	int month2 = tm2.tm_mon + 1;
	int day2 = tm2.tm_mday;
	int hour2 = tm2.tm_hour;
	int min2 = tm2.tm_min;

	// Вычисляем разницу в минутах и часах
	int minutes = min1 - min2;
	int hours = hour1 - hour2;

	// Корректируем разницу в минутах и часах
	if (minutes < 0) {
		minutes += 60;
		hours--;
	}
	if (hours < 0) {
		hours += 24;
		day1--;
	}

	// Вычисляем разницу в днях, месяцах и годах
	int days = day1 - day2;
	int months = month1 - month2;
	int years = year1 - year2;

	// Корректируем разницу в днях и месяцах
	if (days < 0) {
		months--;
		days += daysInMonth(year1, month1);
	}
	if (months < 0) {
		years--;
		months += 12;
	}
	//Такой список нужно вернуть

	string resultMaxTime = to_string(hours) + (":") + to_string(minutes);
	string resultMaxDate = to_string(years) + ("-") + to_string(months) + ("-") + to_string(days);

	list<string> result;
	result.push_front(resultMaxDate);
	result.push_back(resultMaxTime);

	return result;

}

list<string> SumMaxTime::CalculateMaxTimeIfDateSecondBiggest(string dataDeparture, string timeDeparture, string dataArrival, string timeArrival)
{
	//Departure - отправление
	// Arrival - прибытия

	string year1 = dataDeparture.substr(0, 4);  // Год (символы 0/1/2/3)
	string month1 = dataDeparture.substr(5, 2); // Месяц (символы 5/6)
	string day1 = dataDeparture.substr(8, 2);   // День (символы 8-9)

	string year2 = dataArrival.substr(0, 4);  // Год (символы 0/1/2/3)
	string month2 = dataArrival.substr(5, 2); // Месяц (символы 5/6)
	string day2 = dataArrival.substr(8, 2);   // День (символы 8-9)

	string hours1 = timeDeparture.substr(0, 2);
	string minuts1 = timeDeparture.substr(3, 2);

	string hours2 = timeArrival.substr(0, 2);
	string minuts2 = timeArrival.substr(3, 2);

	int yearInt1 = stoi(year1);
	int monthInt1 = stoi(month1);
	int dayInt1 = stoi(day1);

	int yearInt2 = stoi(year2);
	int monthInt2 = stoi(month2);
	int dayInt2 = stoi(day2);

	int hoursInt1 = stoi(hours1);
	int minutsInt1 = stoi(minuts1);

	int hoursInt2 = stoi(hours2);
	int minutsInt2 = stoi(minuts2);

	// Первый момент времени: 
	struct std::tm tm1 = make_tm(yearInt1, monthInt1, dayInt1, hoursInt1, minutsInt1, 0);

	// Второй момент времени: 
	struct std::tm tm2 = make_tm(yearInt2, monthInt2, dayInt2, hoursInt2, minutsInt2, 0);

	// Вычисляем разницу в годах, месяцах, днях, часах и минутах
	list <string> result = diffInDateTime(tm1, tm2);


	return result;
}

list<string> SumMaxTime::CalculateMaxTime(string dataDeparture, string timeDeparture, string dataArrival, string timeArrival)
{
	list<string> result;
	string resultMaxTime;
	string resultMaxDate;
	//Нам нужен результат формата YYYY-MM-DD
	Formating formating;

	int i = formating.CheckDate(dataDeparture, dataArrival);

	if (dataDeparture == dataArrival)
	{//Если даты совпадают

		int result = formating.CheckTime(timeDeparture, timeArrival, 0);
		int hours = 0;
		int minuts;
		if (result > 60)
		{
			hours = result / 60;
			minuts = result - (hours * 60);
		}
		else
		{
			minuts = result;
		}
		resultMaxTime = to_string(hours) + (":") + to_string(minuts);
		resultMaxDate = "0000-00-00";

	}
	else if (i == 3)
	{//Если вторая дата больше первой на сутки и более
		list<string> calculatedWithVoidResult = CalculateMaxTimeIfDateSecondBiggest(dataDeparture, timeDeparture, dataArrival, timeArrival);
		resultMaxDate = calculatedWithVoidResult.front();
		resultMaxTime = calculatedWithVoidResult.back();
	}
	else if (i == 1)
	{//Если вторая дата - следующие сутки первой даты

		int result = formating.CheckTime(timeDeparture, timeArrival, 1);

		int hours = 0;
		int minuts;
		if (result > 60)
		{
			hours = result / 60;
			minuts = result - (hours * 60);
		}
		else
		{
			minuts = result;
		}

		if (hours - 24 >= 0)
		{
			resultMaxDate = "0000-00-01";
			hours = hours - 24;
			resultMaxTime = to_string(hours) + (":") + to_string(minuts);
		}
		else
		{
			resultMaxTime = to_string(hours) + (":") + to_string(minuts);
			resultMaxDate = "0000-00-00";
		}

	}
	result.push_back(resultMaxDate);
	result.push_back(resultMaxTime);
	return result;
}

tuple<vector<list<Way>>, list<double>, list<string>> SumMaxTime::allWaysWithCostAndMaxTime(tuple<vector<list<Way>>, list<double>> allWaysWithCost)
{
	tuple<vector<list<Way>>, list<double>, list<string>> tupleAllWaysWithCostAndMaxTime;

	vector<list<Way>> listWays = get<0>(allWaysWithCost);
	list<double> listCosts = get<1>(allWaysWithCost);
	list<string> listTimes;

	get<0>(tupleAllWaysWithCostAndMaxTime) = listWays;
	get<1>(tupleAllWaysWithCostAndMaxTime) = listCosts;

	//Мы знаем, когда убывает первый маршрут и когда прибывает последний маршрут в нашем пути

	list<string> result; // для получения списка из дат и времени 
	for (list<Way> list : listWays)
	{
		string dateDeparture;
		string timeDeparture;

		string dateArrival;
		string timeArrival;

		if (list.size() > 1)
		{//Если в маршруте есть пересадки
			Way wayFirst = list.front();
			Way wayLast = list.back();

			dateDeparture = wayFirst.departureDate;
			timeDeparture = wayFirst.departureTime;

			dateArrival = wayLast.arrivalDate;
			timeArrival = wayLast.arrivalTime;
		}
		else
		{//Если в маршруте нет пересадок
			dateDeparture = list.back().departureDate;
			timeDeparture = list.back().departureTime;

			dateArrival = list.back().arrivalDate;
			timeArrival = list.back().arrivalTime;
		}

		result = CalculateMaxTime(dateDeparture, timeDeparture, dateArrival, timeArrival);

		string resultDate = result.front();
		string resultTime = result.back();

		string year = resultDate.substr(0, 4);  // Год (символы 0/1/2/3)
		string month = resultDate.substr(5, 2); // Месяц (символы 5/6)
		string day = resultDate.substr(8, 2);   // День (символы 8-9)

		string hours = resultTime.substr(0, 2);
		string minuts = resultTime.substr(3, 2);

		int monthInt = (12 * stoi(year)) +  stoi(month);
		int dayInt = (30 * monthInt) + stoi(day);
		int hoursInt = (24 * dayInt) + stoi(hours) + (stoi(minuts) / 60);

		string result = string("Years: ") + year + ("Months: ") + month + (" Days: ") + day
			+ ("Hours: ") + hours + ("Minutes: ") + minuts;

		//string result1 = to_string(hoursInt);

		listTimes.push_back(result);
	}

	get<2>(tupleAllWaysWithCostAndMaxTime) = listTimes;
	return tupleAllWaysWithCostAndMaxTime;
}
