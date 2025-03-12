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
#include <tuple>



class SumCost
{
public:

    tuple<vector<list<Way>>, list<double>> SumCostWay(vector<list<Way>> allWays);

};

