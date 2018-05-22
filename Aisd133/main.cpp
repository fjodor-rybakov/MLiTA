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
#include "string"
#include "fstream"

using namespace std;

void ShowPosShift(map<char, int> dict, string const& sample)
{
    for (auto i : sample)
    {
        for (auto j : dict)
        {
            if (i == char(j.first))
            {
                cout << j.second << " ";
            }
        }
    }
    cout << endl;
}

string toLowStr(string &str){
    string res;
    for(auto elem : str)
    {
        res += tolower(elem);
        //cout << int(tolower(elem)) << endl;
    }
    return res;
}

void PrintDict(map<char, int> &dict)
{
    for (auto i : dict)
    {
        cout << i.first << " " << i.second << endl;
    }
}

map<char,  int> TableShift(const string &sample)
{
     int lenSample = sample.size(), indCh, cc;
    map<char, int> dict;
    for (int i = 32; i <= 255; i++)
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
            else
            {
                cc++;
            }
        }
        dict[char(i)] = indCh;
    }

    return dict;
}

int BM(const string &sample, const string &line, map<char,  int> &dict,  int &lamd)
{
    bool find = false;
    int counter = 0, result = 0, c = 0, size_sample = sample.size() - 1;
    while (!find)
    {
        find = true;
        counter = 0;
        for (int i = size_sample; i >= 0; i--)
        {
            if (sample[i] != line[i + lamd])
            {
                lamd += abs(dict[line[i + lamd]] - counter);
                find = false;
                break;
            }
            counter++;
        }
        c++;

        if ((lamd + sample.size() > line.size() || c > line.size()) && !find)
        {
            result = 0;
            break;
        }

        if (find)
        {
            result = lamd = lamd + 1;
        }
    }

    return result;
}

bool inLine(string const& sample, char sym)
{
    bool res = false;
    for (auto i : sample)
    {
        if (sym == i)
        {
            res = true;
            break;
        }
    }
    return res;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_CTYPE, "Russian");
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
    sample = toLowStr(sample);
    input >> nameTextFile;
    ifstream text(nameTextFile);
    if (!text.is_open())
    {
        cout << "Could not open " << nameTextFile << " file!" << endl;
        return 1;
    }

    map<char, int> dict = TableShift(sample);
    //PrintDict(dict);

    string str, tstr;
    while (getline(text, tstr))
    {
        tstr = toLowStr(tstr);
            str += tstr + " ";
    }

    //cout << str << endl;



     int lamd = 0, resultPos = 0, lengthReadStr = 0, numberLine = 1;
    string lineRead, s;
    text.close();
    text.open(nameTextFile);
    getline(text, s);
    lineRead = s;
    bool isExist = false;
    while (true)
    {
        resultPos = BM(sample, str, dict, lamd);
        //cout << resultPos << endl;
        if (resultPos)
        {
            isExist = true;
            lengthReadStr = lineRead.size();
            if (resultPos > lengthReadStr)
            {
                while (resultPos > lengthReadStr)
                {
                    getline(text, s);
                    lineRead += " " + s;
                    lengthReadStr = lineRead.size();
                    numberLine++;
                }
            }
            resultPos = resultPos - lengthReadStr + s.size();

            output << numberLine << " " << resultPos << endl;
        }
        else {
            if (!isExist)
            {
                output << "No" << endl;
            }
            break;
        }
    }

    return 0;
}