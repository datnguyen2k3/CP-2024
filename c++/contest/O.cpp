#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

vector<long long> factorial;

void buildFactorial(int n) {
    factorial.resize(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
}


long long modInverse(int n) {
    long long result = 1;
    int exp = MOD - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * n) % MOD;
        }
        n = (n * n) % MOD;
        exp /= 2;
    }
    return result;
}

long long comb(int n, int k) {
    if (k == 0 || k == n) return 1;
    if (k == 1 || k == n - 1) return n % MOD;

    long long numerator = factorial[n];
    long long denominator = (factorial[k] * factorial[n - k]) % MOD;
    return (numerator * modInverse(denominator)) % MOD;
}

int main() {
    int n, k;
    cin >> n >> k;

    if (k > n) {
        cout << 0 << endl;
        return 0;
    }

    buildFactorial(n);
    long long res = 0;
    for (int above = 0; above <= k; above++) {
        int below = k - above;

        res += comb(n, above) * comb(n - above, below);
        res %= MOD;
    }

    cout << res << endl;

    return 0;
}