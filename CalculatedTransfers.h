#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <windows.h>
#include "City.h"
#include <vector>
#include "SearchWays.h"
#include "Formating.h"
#include <map>
#include <string>
#include <iomanip>
#include <sstream>

class CalculatedTransfers
{
public:
	tuple<vector<list<Way>>, list<double>, list<string>, list<int>> tupleAllWaysWithCostAndSumMaxTime(tuple<vector<list<Way>>, list<double>, list<string>> allWays);
	
};

