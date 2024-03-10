#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int getFibonacci(int n) {
    if (n <= 2) {
        return n;
    }

    int firstPrev = 1;
    int secondPrev = 1;
    int current = 0;


    for (int i = 3; i <= n; i++) {
        current = firstPrev + secondPrev;
        current %= MOD;
        firstPrev = secondPrev;
        secondPrev = current;
    }

    return current;

}

int main() {
    cout << getFibonacci(10) << endl;
    return 0;
}
