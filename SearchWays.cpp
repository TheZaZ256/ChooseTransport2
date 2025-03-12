#include "SearchWays.h"

vector<list<Way>> SearchWays::SearchAllWays(string sourceCity, string destinationCity, list<Way> currentPath, list<Way> listOfWays, vector<list<Way>>& SearchedWays)
{//����� ��� ���� �� ����� ���������� � ����� ��������
    list<Way> currentsWays;

    //���� ������ � �������� �����
    if (sourceCity == destinationCity)
    {
        SearchedWays.push_back(currentPath);

        //�������� ������� �������
        // ����� ���������� ����������� �������� ����, �� �� ��� ������� ���������� ���� �� ������ �����
        //currentPath.clear();

        //����� �� �������
        // �� ����� ������ ��� ���� ���� �� �����������
        // � ���������� ������ �� vector<list<Way>>& SearchedWays
        //return SearchedWays;

    }
    else
    {
        //�������� ��� ����, ������� ���� �� ������ ������
        for (Way way : listOfWays)
        {

            if (way.sourceCity == sourceCity)
            {
                currentsWays.push_back(way);
            }
        }

        //������� ���� ����� �� ������ ������
        for (Way way : currentsWays)
        {
            //������� ����� �������� �� ��������������� ����
            sourceCity = way.destinationCity;

            //� ������� ��������� ������� ����
            currentPath.push_back(way);

            //���������� ������� ���� ����
            SearchAllWays(sourceCity, destinationCity, currentPath, listOfWays, SearchedWays);

            // ������� ������� ���� �� ��������
            //���� ������ �� ����� ����, �������� ��� ��������� ����
            currentPath.pop_back();

        }
    }

    return SearchedWays;
}