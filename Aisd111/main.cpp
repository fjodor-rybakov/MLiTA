//11.1. Треугольник и точка (5)
//В декартовой системе координат на плоскости заданы координаты вершин треугольника и еще
//одной точки. Определить, принадлежит ли эта точка треугольнику.
// Рыбаков Федор, CLion

#include <iostream>
#include "fstream"
#include "vector"

using namespace std;

long long EquationLine(long long c1, long long c2, long long c3, long long c4, long long c5, long long c6)
{
    return abs((c4 - c2) * (c5 - c1) - (c3 - c1) * (c6 - c2));
}

bool IsInOut(vector<pair<long long, long long>> &tr, long long coord1, long long coord2)
{
    long long oneS = EquationLine(tr[0].first, tr[0].second, tr[1].first, tr[1].second, coord1, coord2);
    long long twoS =  EquationLine(tr[2].first, tr[2].second, tr[0].first, tr[0].second, coord1, coord2);
    long long threeS = EquationLine(tr[1].first, tr[1].second, tr[2].first, tr[2].second, coord1, coord2);
    long long fourS = EquationLine(tr[0].first, tr[0].second, tr[1].first, tr[1].second, tr[2].first, tr[2].second);
    return (fourS - (oneS + twoS + threeS)) >= 0;
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

    long long coord1 = 0, coord2 = 0;
    vector<pair<long long, long long>> triangle;
    input >> coord1 >> coord2;
    triangle.emplace_back(coord1, coord2);
    input >> coord1 >> coord2;
    triangle.emplace_back(coord1, coord2);
    input >> coord1 >> coord2;
    triangle.emplace_back(coord1, coord2);
    input >> coord1 >> coord2;
    string res = IsInOut(triangle, coord1, coord2) ? "In" : "Out";
    output << res << endl;

    return 0;
}