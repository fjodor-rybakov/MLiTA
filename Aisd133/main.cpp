//13.3. Алгоритм Бойера – Мура (6)
//  Требуется найти все вхождения образца в текстовом файле методом Бойера – Мура. В файле нет
//переноса слов. Образец может включать пробелы и переходить с одной строки файла на другую.
//Конец строки файла может интерпретироваться как пробел. Результаты поиска не должны
//зависеть от регистра букв, то есть каждая буква в образце и файле может быть как строчной, так и
//прописной.
//Рыбаков Федор, среда разработки CLion

#include <windows.h>
#include <map>
#include "iostream"
#include "fstream"
#include "vector"

using namespace std;

void PrintDict(map<char, int> &dict)
{
    for (auto i : dict)
    {
        cout << i.first << " " << i.second << endl;
    }
}

map<char, int> TableShift(const string &sample)
{
    int lenSample = sample.size(), indCh, cc;
    map<char, int> dict;
    for (int i = 32; i < 256; i++)
    {
        indCh = lenSample;
        cc = 0;
        for (int j = lenSample - 1; j >= 0; j--)
        {
            if (char(i) == sample[j])
            {
                indCh = cc;
                break;
            }
            cc++;
        }
        dict[char(i)] = indCh;
    }

    return dict;
}

void BM(const string &sample, const string &line, map<char, int> &dict)
{
    bool find = false;
    int lamd = 0, counter = 0;
    while (!find)
    {
        find = true;
        counter = 0;
        for (int i = sample.size() - 1; i >= 0; i--)
        {
            if (sample[i] != line[i + lamd])
            {
                cout << line[1] << " " << counter << endl;
                lamd += dict[line[i + lamd]] - counter;
                find = false;
            }
            counter++;
            if (!find)
            {
                break;
            }
        }
        //if (lamd + sample.size() == line.size() && !find)
        //{
        //    cout << "No" << endl;
        //    break;
        //}
        if (find)
        {
            cout << lamd + 1 << endl;
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string inputFileName = "input.txt";
    string outputFileName = "output.txt";
    ifstream input(inputFileName);
    if (!input.is_open())
    {
        cout << "Could not open " << inputFileName << " file!" << endl;
        return 1;
    }
    ofstream output(outputFileName);
    if (!output.is_open()) {
        cout << "Could not open " << outputFileName << " file!" << endl;
        return 1;
    }

    string sample, nameTextFile;
    getline(input, sample);
    input >> nameTextFile;
    ifstream text(nameTextFile);
    if (!text.is_open())
    {
        cout << "Could not open " << nameTextFile << " file!" << endl;
        return 1;
    }

    map<char, int> dict = TableShift(sample);
    PrintDict(dict);


    string str;
    while (getline(text, str))
    {
        BM(sample, str, dict);
    }

    return 0;
}