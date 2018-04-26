//14.18. Вычисление выражения (7)
//Ввод. Входной файл INPUT.TXT содержит одну строку, состоящую не более чем из 255
//символов. Числа в выражении не превышают по модулю 2×10 9 . Гарантируется, что в процессе
//        вычислений получаемые значения не превышают по модулю 2×10 9 .
//Вывод. В единственной строке файла OUTPUT.TXT требуется вывести значение выражения с
//точностью 4 знака после запятой.
//Рыбаков Федор ПС-22
//Среда CLion

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int p(const char &elem);
vector<string> read_file(ifstream &input);
double calc();

int main(int argc, char* argv[]) {
    ofstream output("output.txt");
    if (!output.is_open()) {
        cerr << "Error open file" << endl;
        exit(0);
    }
    output << fixed << setprecision(4) << calc();
    output.close();

    return 0;
}

int p(const char &elem) { // priority
    switch (elem) {
        case '^':
            return 3;
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        case '=':
            return 1;
        default:
            return 0;
    }
}

vector<string> read_file(ifstream &input) { // read and transformation on RPN
    vector<string> tokens;
    vector<char> stack;
    int ind = 0, last_ind = 0, i = 0;
    string s;
    while((ind = input.get()) != EOF) {
        if ((ind >= 48) && (ind <= 57)) { // if number
            if ((last_ind >= 48) && (last_ind <= 57)) {
                s = tokens[i];
                s += char(ind);
                tokens[i] = s;
            } else {
                s = char(ind);
                tokens.insert(tokens.end(), s);
                i = tokens.size() - 1;
            }
        }
        if (((ind >= 42) && (ind <= 47)) || (ind == 94)) { // if operator
            if ((!((last_ind >= 48) && (last_ind <= 57))) && (last_ind != 41) && (ind == 43)) {
            } else {
                if ((!((last_ind >= 48) && (last_ind <= 57))) && (last_ind != 41) && (ind == 45)) {
                    stack.insert(stack.end(), '=');
                } else {
                    if (stack.empty()) {
                        stack.insert(stack.end(), char(ind));
                    } else {
                        if ((stack.back() != '^') || (char(ind) != '^')) {
                            if (p(stack.back()) >= p(char(ind))) {
                                while (p(stack.back()) >= p(char(ind))) {
                                    s = stack.back();
                                    tokens.insert(tokens.end(), s);
                                    stack.pop_back();
                                }
                                stack.insert(stack.end(), char(ind));
                            } else stack.insert(stack.end(), char(ind));
                        } else stack.insert(stack.end(), char(ind));
                    }
                }
            }
        }
        if (char(ind) == '(') stack.insert(stack.end(), char(ind)); // if brackets
        if (char(ind) == ')') {
            while (stack.back() != '(') {
                s = stack.back();
                tokens.insert(tokens.end(), s);
                stack.pop_back();
            }
            stack.pop_back();
        }

        last_ind = ind; // init last char
    }
    while (!stack.empty()) {
        s = stack.back();
        tokens.insert(tokens.end(), s);
        stack.pop_back();
    }

    input.close();

    return tokens;
}

double calc() { // calculate
    ifstream input("input.txt");
    if (!input.is_open())
    {
        cerr << "Error open file" << endl;
        exit(0);
    }
    double result = 0, r = 0, num = 0;
    char n;
    vector<double> stack;
    vector<string> tokens = read_file(input);
    int index = 0;
    while (index != tokens.size()) {
        n = tokens[index][0];
        if ((n >= 48) && (n <= 57)) {
            num = strtod(tokens[index].c_str(), nullptr);
            stack.push_back(num);
        } else {
            if (tokens[index] == "=") {
                r = 0 - stack[stack.size() - 1];
                if (!stack.empty()) stack.pop_back();
            } else if (tokens[index] == "^") {
                r = pow(stack[stack.size() - 2], stack[stack.size() - 1]);
                if (!stack.empty()) stack.pop_back();
                if (!stack.empty()) stack.pop_back();
            } else if (tokens[index] == "*") {
                r = stack[stack.size() - 2] * stack[stack.size() - 1];
                if (!stack.empty()) stack.pop_back();
                if (!stack.empty()) stack.pop_back();
            } else if (tokens[index] == "/") {
                r = stack[stack.size() - 2] / stack[stack.size() - 1];
                if (!stack.empty()) stack.pop_back();
                if (!stack.empty()) stack.pop_back();
            } else if (tokens[index] == "+") {
                r = stack[stack.size() - 2] + stack[stack.size() - 1];
                if (!stack.empty()) stack.pop_back();
                if (!stack.empty()) stack.pop_back();
            } else if (tokens[index] == "-") {
                r = stack[stack.size() - 2] - stack[stack.size() - 1];
                if (!stack.empty()) stack.pop_back();
                if (!stack.empty()) stack.pop_back();
            }
            stack.push_back(r);
        }
        index++;
    }
    result = stack[0];

    return result;
}