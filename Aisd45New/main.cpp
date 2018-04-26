//4.5. Маршрут (6)
//  Дана матрица N x N, заполненная целыми положительными числами. Путь по матрице
//начинается в левом верхнем углу. За один ход можно пройти в соседнюю по вертикали или
//горизонтали клетку (если она существует). Нельзя ходить по диагонали, нельзя оставаться на
//месте. Требуется найти максимальную сумму чисел, стоящих в клетках по пути длиной K клеток
//(клетку можно посещать несколько раз).
//Рыбаков Федор, среда разработки CLion

#include <stack>
#include "vector"
#include "iostream"
#include "fstream"
#include "queue"
#include "map"

using namespace std;

int const gtx[] = {0, 0, 1, -1};
int const gty[] = {1, -1, 0, 0};

void FillingField(vector<vector<int>> &field, ifstream &input, int sizeField)
{
    int counterLine = 0, elem = 0, row = 0, col = 0;
    while (input >> elem)
    {
        field[col][row] = elem;
        row++;
        counterLine++;
        if (counterLine % sizeField == 0)
        {
            row = 0;
            col++;
        }
    }
}

bool CheckAcceptWay(int sPosX, int sPosY, int sizeField)
{
    return sPosX >= 0 && sPosX < sizeField && sPosY >= 0 && sPosY < sizeField;
}

int ChooseAct(int col, int row, int step, vector<vector<int>> &sumField, vector<int> &temp,
              map<pair<int, int>, vector<int>> &backWay)
{
    int maxElem = 0;
    int sizeField = sumField.size();
    if (((col + row) % 2 != 0) != (step % 2 != 0))
    {
        maxElem = 0;
        for (int u = 0; u < 4; u++)
        {
            if (CheckAcceptWay(col + gtx[u], row + gty[u], sizeField))
            {
                if (maxElem < sumField[col + gtx[u]][row + gty[u]])
                {
                    maxElem = sumField[col + gtx[u]][row + gty[u]];
                    temp = backWay[make_pair(col + gtx[u], row + gty[u])];
                }
            }
        }
    }
    temp.push_back(col + 1);
    temp.push_back(row + 1);

    return maxElem;
}

int SearchMaxElem(vector<vector<int>> &field, int &posX, int &posY)
{
    int maxSum = 0;
    for (int i = 0; i < field.size(); i++)
    {
        for (int j = 0; j < field.size(); j++)
        {
            if (field[i][j] > maxSum)
            {
                maxSum = field[i][j];
                posX = i;
                posY = j;
            }
        }
    }

    return maxSum;
}

void PrintField(vector<vector<int>> &field)
{
    for (auto i : field)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
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
    unsigned int sizeField = 0, lengthWay = 0;
    input >> sizeField >> lengthWay;
    vector<vector<int>> field(sizeField, vector<int>(sizeField));
    FillingField(field, input, sizeField);
    //PrintField(field);
    vector<vector<int>> sumField(sizeField, vector<int>(sizeField));
    map<pair<int, int>, vector<int>> backWay;
    backWay[make_pair(0, 0)].push_back(1);
    backWay[make_pair(0, 0)].push_back(1);
    int c = 0, r = 0;
    while (c != sizeField)
    {
        backWay[make_pair(c, r)];
        if (r == sizeField - 1)
        {
            r = 0;
            c++;
        }
        r++;
    }
    vector<int> temp;
    sumField[0][0] = field[0][0];
    int step = 0;
    while (step < lengthWay - 1)
    {
        for (int col = 0; col < sizeField; col++)
        {
            for (int row = 0; row < sizeField; row++)
            {
                if (ChooseAct(col, row, step, sumField, temp, backWay) != 0)
                {
                    sumField[col][row] = ChooseAct(col, row, step, sumField, temp, backWay) + field[col][row];
                    backWay[make_pair(col, row)] = temp;
                    //PrintField(sumField);
                    //cout << "-----" << endl;
                }
            }
        }

        step++;
    }

    //PrintField(sumField);
    int posX = 0, posY = 0;
    output << SearchMaxElem(sumField, posX, posY);
    int counter = 0;
    for (auto p : backWay[make_pair(posX, posY)])
    {
        if (counter % 2 == 0)
        {
            output << endl;
        }
        output << p << " ";
        counter++;

    }

    return 0;
}