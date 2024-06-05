#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int f[100001] = {0};
int g[100001] = {0};

long long get_f(int n) {
    if (n == 1) return 1;
    if (n == 2) return 5;
    if (n == 3) return 11;
    if (n == 4) return 36;

    if (f[n] != 0) return f[n];
    return f[n] = (get_f(n - 1) + 5 * get_f(n - 2) + get_f(n -3) - get_f(n - 4) + MOD) % MOD;
}

long long get_g(int n) {
    if (n <= 2) return 1;

    if (g[n] != 0) return g[n];
    return g[n] = (get_g(n - 2) + get_f(n - 1)) % MOD;
}


int main() {
    int n;
    cin >> n;

    cout << get_g(n) << endl;
    return 0;
}