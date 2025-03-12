#include "SumCost.h"

tuple<vector<list<Way>>, list<double>> SumCost::SumCostWay(vector<list<Way>> allWays)
{
    tuple<vector<list<Way>>, list<double>> allWaysWithCostPair;
    for (list<Way> list : allWays) //сколько списков в списке // сколько маршрутов в списке маршрутов
    {
        double sumWay = 0;

        for (Way way : list) // сколько путей в маршруте
        {
            sumWay += way.cost;

        }
        get<0>(allWaysWithCostPair).push_back(list);
        get<1>(allWaysWithCostPair).push_back(sumWay);


    }
    return allWaysWithCostPair;
}