//12.1. Дороги Прима (5)
//В государстве Прим имеется ряд населенных пунктов, связанных грунтовыми дорогами.
//Между любыми двумя пунктами может быть не более одной дороги. Решено заасфальтировать
//некоторые дороги. Стоимость асфальтирования каждой дороги известна. Требуется выбрать
//дороги для асфальтирования так, чтобы можно было проехать из каждого населенного пункта в
//любой другой по асфальту, а общая стоимость работы была минимальной. Использовать алгоритм
//Прима.
// Рыбаков Федор, Clion

#include <algorithm>
#include "iostream"
#include "fstream"
#include "vector"

using namespace std;

void PrintGraph(vector<vector<int>> & graph)
{
    for (auto &i : graph)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    string inputFileName = "input.txt";
    string outputFileName = "output.txt";
    ifstream input(inputFileName);
    if (!input.is_open())
    {
        cout << "Could not open " << inputFileName << " file!" << endl;
        return 1;
    }
    ofstream output(outputFileName);
    if (!output.is_open())
    {
        cout << "Could not open " << outputFileName << " file!" << endl;
        return 1;
    }

    unsigned int countNodes = 0, countArcs = 0;
    input >> countNodes >> countArcs;
    vector<vector<int>> graph(countNodes, vector<int>(countNodes));
    int nodeOne = 0, nodeTwo = 0, cost = 0;
    const int INF = 1000000000;
    while (input >> nodeOne >> nodeTwo >> cost)
    {
        graph[nodeOne - 1][nodeTwo - 1] = cost;
        graph[nodeTwo - 1][nodeOne - 1] = cost;
    }
    for (int i = 0; i < countNodes; i++)
    {
        for (int j = 0; j < countNodes; j++)
        {
            if (graph[i][j] == 0)
            {
                graph[i][j] = INF;
            }
        }
    }
    //PrintGraph(graph);

    vector<pair<int, int>> labels(countNodes, make_pair(INF, 0)); //метки (откуда и (стоимость)куда)
    labels[0].first = 0;
    vector<bool> isPermanent(countNodes, false); //постоянные или непостоянные
    isPermanent[0] = true;
    int parent = 0, minElem = INF, lenWay = 0;
    for (int from = 0; from < countNodes; from++)
    {
        for (int to = 0; to < countNodes; to++)
        {
            if (!isPermanent[to] && labels[to].first > graph[parent][to])
            {
                labels[to].first = graph[parent][to];
                labels[to].second = parent;
            }
        }

        minElem = INF;
        for (int to = 0; to < countNodes; to++)
        {
            if (!isPermanent[to] && minElem > labels[to].first)
            {
                minElem = labels[to].first;
                parent = to;
            }
        }
        isPermanent[parent] = true;
    }

    for (int i = 1; i < labels.size(); i++)
    {
        lenWay += labels[i].first;
    }
    output << lenWay << endl;

    vector<pair<int, int>> result;
    for (int i = 1; i < labels.size(); i++)
    {
        if (i < labels[i].second)
            result.emplace_back(i + 1, labels[i].second + 1);
        else
            result.emplace_back(labels[i].second + 1, i + 1);
    }

    sort(result.begin(), result.end());
    for (auto i : result)
    {
        output << i.first << " " << i.second << endl;
    }

    return 0;
}