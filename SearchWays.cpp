#include "SearchWays.h"

vector<list<Way>> SearchWays::SearchAllWays(string sourceCity, string destinationCity, list<Way> currentPath, list<Way> listOfWays, vector<list<Way>>& SearchedWays)
{//НАЙТИ ВСЕ ПУТИ ИЗ ТОЧКИ НАЗНАЧЕНИЯ В ТОЧКУ АДРЕСНУЮ
    list<Way> currentsWays;

    //если пришли в конечный город
    if (sourceCity == destinationCity)
    {
        SearchedWays.push_back(currentPath);

        //очистить текущий маршрут
        // когда рекурсивно заканчиваем обходить путь, то мы уже убираем посещенный путь из списка путей
        //currentPath.clear();

        //выйти из функции
        // Не нужно потому что блок ЕЛСЕ не срабатывает
        // и используем ссылку на vector<list<Way>>& SearchedWays
        //return SearchedWays;

    }
    else
    {
        //получаем все пути, которые идут из нашего города
        for (Way way : listOfWays)
        {

            if (way.sourceCity == sourceCity)
            {
                currentsWays.push_back(way);
            }
        }

        //сколько есть путей из нашего города
        for (Way way : currentsWays)
        {
            //текущий город меняется на рассматриваемый путь
            sourceCity = way.destinationCity;

            //в маршрут добавляем текущий путь
            currentPath.push_back(way);

            //рекурсивно обходим этот путь
            SearchAllWays(sourceCity, destinationCity, currentPath, listOfWays, SearchedWays);

            // Убираем текущий путь из маршрута
            //Если прошли по этому пути, исследуя все вложенные пути
            currentPath.pop_back();

        }
    }

    return SearchedWays;
}