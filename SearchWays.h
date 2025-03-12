#pragma once
#include <list>
#include <vector>
#include <string>
#include "City.h"
using namespace std;


class SearchWays
{
public:
    vector<list<Way>> SearchAllWays(string sourceCity, string destinationCity, list<Way> currentPath, list<Way> listOfWays, vector<list<Way>>& SearchedWays);
    
    
};

