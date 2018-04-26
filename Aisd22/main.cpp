//  2.2. Путь коня (6)
//  Дана шахматная доска, состоящая из N  N  клеток (2 ≤ N ≤ 300), несколько из них вырезано.
//Провести ходом коня через невырезанные клетки путь минимальной длины из одной заданной
//клетки в другую.
//  Ввод из файла INPUT.TXT. В первой строке задано число N. В следующих N строках
//содержится по N символов. Символом # обозначена вырезанная клетка, точкой - невырезанная
//клетка, @ - заданные клетки (таких символов два).
//  Вывод в файл OUTPUT.TXT. Если путь построить невозможно, вывести &quot;Impossible&quot;, в
//противном случае вывести такую же карту, как и на входе, но пометить все промежуточные
//положения коня символом @.
//Рыбаков Федор ПС-22
//Среда CLion

#include "vector"
#include "iostream"
#include "fstream"
#include "queue"
#include "string"

using namespace std;

const int gtx[] = {1, 2, -1, -2, 1, -1, 2, -2}; //Все возможные ходы коня
const int gty[] = {2, 1, -2, -1, -2, 2, -1, 1}; //по х и у

struct Node {
    int x, y;
    int lx, ly;
};

void MoveHorse(vector<vector<char>> &field, int fpo, int fpt, int lpo, int lpt, int len);

int main() {
    ifstream input("input.txt");
    if (!input.is_open()) {
        cerr << "Error open file!" << endl;
        exit(1);
    } else {
        string str;
        getline(input, str);
        int len = strtol(str.c_str(), nullptr, 10), fpo = 0, fpt = 0, lpo = 0, lpt = 0, row = 0, col = 0;
        vector<vector<char>> field(len, vector<char>(len));
        char ch;
        bool change = true;
        while (input.get(ch)) {
            if (ch == '@' && change) {
                fpo = col;
                fpt = row;
                change = false;
            }
            if (ch == '@' && !change) {
                lpo = col;
                lpt = row;
            }
            if (ch == '\n') {
                row = 0;
                col++;
            } else {
                field[col][row] = ch;
                row++;
            }
        }
        input.close();
        MoveHorse(field, fpo, fpt, lpo, lpt, len);
    }

    return 0;
}

void MoveHorse(vector<vector<char>> &field, int fpo, int fpt, int lpo, int lpt, int len) {
    ofstream output("output.txt");
    if (!output.is_open()) {
        cerr << "Error open file!" << endl;
        exit(1);
    } else {
        int sfpo = fpo, sfpt = fpt;
        vector<vector<bool>> visit(len, vector<bool>(len));
        queue<Node> queue1;
        Node value{}, save{};
        value.x = fpo;
        value.y = fpt;
        value.lx = fpo;
        value.ly = fpt;
        queue1.push(value);
        int c = 0;
        do {
            for (int i = 0; i < 8; i++) {
                if ((fpo + gtx[i] >= 0 && fpo + gtx[i] < len) && (fpt + gty[i] >= 0 && fpt + gty[i] < len) &&
                    (field[fpo + gtx[i]][fpt + gty[i]] != '#') && (visit[fpo + gtx[i]][fpt + gty[i]] == false)) {
                    value.x = fpo + gtx[i];
                    value.y = fpt + gty[i];
                    value.lx = fpo;
                    value.ly = fpt;
                    visit[fpo + gtx[i]][fpt + gty[i]] = true;
                    queue1.push(value);
                }
            }
            c++;
            save = queue1.front();
            queue1.push(save);
            queue1.pop();
            fpo = queue1.front().x;
            fpt = queue1.front().y;
            if (c >= 1000) {
                output << "Impossible" << endl;
                exit(0);
            }
        } while (!((fpo == lpo) && (fpt == lpt)));
        int lastX = lpo, lastY = lpt;
        while (!((lastX == sfpo) && (lastY == sfpt))) {
            if (queue1.front().x == lastX && queue1.front().y == lastY) {
                lastX = queue1.front().lx;
                lastY = queue1.front().ly;
            }
            queue1.pop();
            if (queue1.front().x == lastX && queue1.front().y == lastY) {
                field[lastX][lastY] = '@';
            }
        }
        for (auto &i : field) {
            for (char j : i) output << j;
            output << endl;
        }
    }
    output.close();
}