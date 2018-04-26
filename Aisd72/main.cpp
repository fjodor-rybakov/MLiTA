//7.2. Скобки (4)
//  Последовательность круглых скобок называют правильной, если можно добавить в
//нее числа и знаки арифметических операций так, что полученное алгебраическое
//выражение станет корректным. Например, скобочная последовательность (())()
//является правильной, а (())) и ())(() такими не являются. Пустая последовательность
//также считается правильной.
//  Задана правильная скобочная последовательность. Назовем парой внешних скобок
//первую открывающую и последнюю закрывающую скобки.
//  После удаления пары внешних скобок правильность последовательности может как
//сохраниться, так и нарушиться. Найти наибольшее число пар внешних скобок, которые
//можно удалять до первого нарушения правильности последовательности.
//Рыбаков Федор, Среда разработки CLion
#include <iostream>
#include <algorithm>
#include "fstream"
#include "vector"

using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input.is_open())
    {
        cout << "Could not open input file." << endl;
        return 1;
    }

    if (!output.is_open())
    {
        cout << "Could not open output file." << endl;
        return 1;
    }
    int count = 0;
    string line;
    input >> count >> line;
    vector<int> ind;
    bool checker = true, maxCheck = true;
    int num = 0, maxValue = 0;
    int sizeLine = count * 2 - 1;
    for (int i = 0; i <= sizeLine; i++)
    {
        if (line[i] == '(')
            num++;
        else num--;
        if (num > maxValue && maxCheck)
        {
            maxValue = num;
        }
        else
        {
            if (i == count && maxCheck)
            {
                checker = false;
            }
            maxCheck = false;
        }
        ind.push_back(num);
    }
    if (checker)
    {
        output << *min_element(ind.begin() + maxValue, ind.end() - maxValue)  << endl;
    } else output << maxValue << endl;


    return 0;
}