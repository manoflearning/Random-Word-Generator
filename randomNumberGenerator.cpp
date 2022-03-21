#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int numUpperBound = 99;
const int outputSz = 54;

vector<int> numbers(numUpperBound);

void makeInput() {
    srand(time(NULL));

    for (int i = 0; i < numUpperBound; i++) {
        numbers[i] = rand();
    }
}

void coordinateCompression() {
    vector<int> cc;

    for (int i = 0; i < numUpperBound; i++) {
        cc.push_back(numbers[i]);
    }

    sort(cc.begin(), cc.end());

    cc.erase(unique(cc.begin(), cc.end()), cc.end());

    for (int i = 0; i < numUpperBound; i++) {
        numbers[i] = lower_bound(cc.begin(), cc.end(), numbers[i]) - cc.begin() + 1;
    }
}

void output() {
    for (int i = 0; i < outputSz; i++)
        cout << numbers[i] << '\n';
}

int main() {
    freopen("rngOutput.txt", "w", stdout);

    makeInput();

    coordinateCompression();

    output();
}