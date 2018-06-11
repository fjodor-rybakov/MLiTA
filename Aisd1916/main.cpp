#include <iostream>
#include "fstream"
#include "vector"

using namespace std;

unsigned long long GeneratePrimeNumbersSum(unsigned int firstNum, unsigned int secondNum)
{
    vector<bool> primeNum(secondNum + 1 - firstNum, true);
    unsigned long long result = 0;
    //set<long long> setOfPrimeNum;
    primeNum[0] = primeNum[1] = false;
    for (unsigned int i = firstNum; i <= secondNum; i++)
    {
        if (primeNum[i])
        {
            result += i;
            for (unsigned int j = i * i; j <= secondNum; j += i)
                primeNum[j] = false;
        }
    }

    return result;
}

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
    if (!output.is_open()) {
        cout << "Could not open " << outputFileName << " file!" << endl;
        return 1;
    }

    cout << GeneratePrimeNumbersSum(3, 5) << endl;

    return 0;
}