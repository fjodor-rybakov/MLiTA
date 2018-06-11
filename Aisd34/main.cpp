//3.4. K-ичные числа (4)
//Найти количество натуральных N-значных (1 ≤ N ≤ 20) чисел в системе счисления с
//основанием K (2 ≤ K ≤ 8), таких, что их запись не содержит двух подряд идущих нулей.
//Рыбаков Федор ПС-22
//Среда CLion

#include <iostream>
#include <vector>
#include "fstream"

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    if (!input.is_open() || !output.is_open()) {
        cerr << "Error open file." << endl;
        exit(0);
    } else {
        unsigned long long firstNum = 0;
        unsigned long long secondNum = 0;
        input >> firstNum;
        input >> secondNum;
        input.close();
        vector<unsigned long long> arr(30);
        arr[0] = 1;
        arr[1] = secondNum - 1;
        unsigned long long i = 2;
        while (i <= firstNum) {
            arr[i] = arr[1] * (arr[i - 1] + arr[i - 2]);
            ++i;
        }
        output << arr[firstNum];
        output.close();
    }

    return 0;
}