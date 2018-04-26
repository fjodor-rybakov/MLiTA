//5.3. Число цифр (5)
//Найти суммарное число цифр во всех целых числах от M до N включительно.
//Рыбаков Федор ПС-22
//Среда разработки CLion

#include <cmath>
#include "iostream"
#include "fstream"

using namespace std;

unsigned long long powerTen(unsigned long long p) {
    unsigned long long res = 1;
    for (int j = 0; j < p; j++) {
        res *= 10;
    }
    return res;
}

int main() {
    fstream input("input.txt");
    ofstream output("output.txt");
    if (!input.is_open() && !output.is_open()) {
        cerr << "Error open file!" << endl;
        return 1;
    }
    unsigned long long m = 0;
    unsigned long long n = 0;
    input >> m >> n;
    input.close();
    string sm, sn;
    sm = to_string(m);
    sn = to_string(n);
    unsigned long long conut_num = n - m + 1;
    unsigned long long r = 0;
    unsigned long long result = 0;
    if (sn.length() == sm.length()) {
        result = conut_num * sn.length();
    } else {
        unsigned long long i = sn.length();
        do {
            r = n - powerTen(i - 1) + 1;
            n = powerTen(i - 1) - 1;
            if (i == sm.length()) {
                r = r - m + powerTen(i - 1);
            }
            result += r * i;
            i--;
        } while (i >= sm.length());
    }

    output << result;
    output.close();

    return 0;
}