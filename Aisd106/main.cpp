//  10.6. Дипломы (4)
//  Когда Петя учился в школе, он часто участвовал в олимпиадах по информатике, математике и
//физике. Так как он был достаточно способным мальчиком и усердно учился, то на многих из этих
//олимпиад он получал дипломы. К окончанию школы у него накопилось n дипломов, причем, как
//оказалось, все они имели одинаковые размеры: w – в ширину и h – в высоту.
//  Сейчас Петя учится в одном из лучших российских университетов и живет в общежитии со
//своими одногруппниками. Он решил украсить свою комнату, повесив на одну из стен свои
//дипломы за школьные олимпиады. Так как к бетонной стене прикрепить дипломы достаточно
//трудно, то он решил купить специальную доску из пробкового дерева, чтобы прикрепить ее к
//стене, а к ней – дипломы. Для того чтобы эта конструкция выглядела более красиво, Петя хочет,
//чтобы доска была квадратной и занимала как можно меньше места на стене. Каждый диплом
//должен быть размещен строго в прямоугольнике размером w на h. Прямоугольники,
//соответствующие различным дипломам, не должны иметь общих внутренних точек.
//Рыбаков Федор, среда разработки CLion

#include <iostream>
#include "fstream"

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

    long long width = 0, height = 0, numbers = 0;
    input >> width >> height >> numbers;
    long long max_side = max(width, height);
    long long middle = 0, low = 0, high = max_side * numbers;
    do
    {
        middle = (low + high) / 2;
        if (numbers > (middle / height) * (middle / width))
            low = middle;
        else
            high = middle;
    }
    while ((high - low) > 1);
    output << high << endl;

    return 0;
}