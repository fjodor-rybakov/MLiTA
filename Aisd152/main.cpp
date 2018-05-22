//  15.2. Игра в умножение (6)
//  Двое играют в умножение: умножают целое число P на одно из чисел от 2 до 5. Первый игрок
//всегда начинает с P=1, делает умножение, затем число умножает второй игрок, снова первый и т.
//д. Перед началом игры им задают число N, и победителем считается тот, кто первым добьется
//условия P ≥ N. Определить, кто выиграет при заданном N, если оба играют наилучшим образом.
// Рыбаков Федор, Среда разработки CLion

#include <iostream>
#include "fstream"
#include "string"

using namespace std;

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

    int countPart = 0;
    input >> countPart;
    while (countPart)
    {
        double a = 0, b = 0, p = 0;
        input >> p;

        unsigned int c = 0;
        a = p;
        bool sw = true;
        while (p > 1)
        {
            if (sw)
            {
                b = p = a = a / 5;
                sw = false;
            } else
            {
                a = p = b = b / 2;
                sw = true;
            }
            c++;
        }

        if (c % 2 == 0)
        {
            output << 2 << endl;
        }
        else
        {
            output << 1 << endl;
        }

        countPart--;
    }

    return 0;
}