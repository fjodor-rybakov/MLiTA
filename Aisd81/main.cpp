//8.1. Слова (3)
//Дано слово, состоящее из M (2 ≤ M ≤ 7) строчных букв латинского алфавита. Найти все
//перестановки символов данного слова.
//Рыбаков Федор, Среда разработки CLion
#include <iostream>
#include "algorithm"
#include "fstream"

using namespace std;

bool generate(string &line)
{
    int pos = 0;
    bool check = false;
    for (int i = line.size() - 1; i > 0; i--)
    {
        if (line[i] > line[i - 1])
        {
            pos = i - 1;
            check = true;
            break;
        }
    }
    if (!check) return false;

    for (int j = line.size() - 1; j > 0; j--)
    {
        if (line[j] > line[pos])
        {
            swap(line[j], line[pos]);
            sort(line.begin() + pos + 1, line.end());
            break;
        }
    }
    return true;
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
    string line;
    input >> line;
    sort(line.begin(), line.end());
    do
    {
        output << line << endl;
    } while (generate(line));

    return 0;
}