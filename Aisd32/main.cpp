#include <cmath>
#include <cstring>
#include <vector>
#include "algorithm"
#include "iostream"

using namespace std;

int PrintX3(int num){
    if (num/3)
        PrintX3(num/3);
    return num%3;
}

int main() {
    /*string arr = "ABD", str;
    int result = 0;
    int i, o = 0;
    result = pow(3, 8);

    for (i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                for (int l = 0; l < 3; l++)
                    for (int p = 0; p < 3; p++)
                        for (int s = 0; s < 3; s++)
                            for (int t = 0; t < 3; t++)
                                for (int f = 0; f < 3; f++){
                                    cout << arr[i] << arr[j] << arr[k] << arr[l] << arr[p] << arr[s] << arr[t] << arr[f] << " ";
                                    str += arr[i];
                                    str += arr[j];
                                    str += arr[k];
                                    str += arr[l];
                                    str += arr[p];
                                    str += arr[s];
                                    str += arr[t];
                                    str += arr[f];
                                    if (str.find("BAD") != -1) {
                                        o++;
                                    }
                                    str = "";
                                }
    cout << endl;
    cout << result << endl;
    cout << o << endl;

    int y = 0;
    Rec(y);
    cout << endl;

    vector<int> s = {0, 1, 2};
    int e = 0;
    int r = 1;

    while (s[0] != 2) {
        e++;
        s[s.size() - r] = e;
        if (e == 2) {
            r++;
            e = 0;
        }
        for (i = 0; i < 3; i++) {
            cout << s[i];
        }
        cout << endl;
    }

    int *a;
    int n = 3;
    int len = 8;
    int h = n > len ? n : len; // размер массива а выбирается как max(n,m)
    a = new int[h];
    for (int i = 0; i < h; i++)
        a[i] = 1;
    for (int i = 0; i < len; i++)
        cout << a[i] - 1 << " ";
    cout << endl;
    while (NextSet(a, n, len)) {
        for (int i = 0; i < len; i++)
            cout << a[i] - 1 << " ";
        cout << endl;
    }*/


    for (int i = 0; i < 99; i++) {
        if (i % 4 == 0) {
            cout << endl;
        } else {
            cout << PrintX3(i);
        }
    }

    return 0;
}