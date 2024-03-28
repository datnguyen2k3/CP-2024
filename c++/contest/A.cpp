#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int MOD = 1000000007;



int main() {

    long long n;
    cin >> n;

    cout << (n / 2 + 1) * (n - n / 2 + 1) << endl;

    return 0;
}