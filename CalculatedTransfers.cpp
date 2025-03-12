#include "CalculatedTransfers.h"

tuple<vector<list<Way>>, list<double>, list<string>, list<int>> CalculatedTransfers::tupleAllWaysWithCostAndSumMaxTime(tuple<vector<list<Way>>, list<double>, list<string>> allWays)
{
	vector<list<Way>> listWays = get<0>(allWays);
	list<double> listCosts = get<1>(allWays);
	list<string> listMaxTime = get<2>(allWays);
	list<int> listSumTransfers;

	tuple<vector<list<Way>>, list<double>, list<string>, list<int>> waysWithCostMaxTimeTransfers;

	for (list<Way> list : listWays)
	{
		int sumTransfers = int(list.size());
		listSumTransfers.push_back(sumTransfers);
	}

	get<0>(waysWithCostMaxTimeTransfers) = listWays;
	get<1>(waysWithCostMaxTimeTransfers) = listCosts;
	get<2>(waysWithCostMaxTimeTransfers) = listMaxTime;
	get<3>(waysWithCostMaxTimeTransfers) = listSumTransfers;

	return waysWithCostMaxTimeTransfers;
}
