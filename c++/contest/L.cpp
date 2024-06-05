#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;
int MOD = 1000000007;

vector<int> get_primes(int limit) {
    vector<int> primes;
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

vector<int> primes = get_primes(3163);

int get_min_increase(int x, int y) {
    if (gcd(x, y) > 1) {
        return 0;
    }

    if (x > y) {
        swap(x, y);
    }

    y -= x;
    int res = INT_MAX;

    for (int prime : primes) {
        if (y % prime != 0) {
            continue;
        }

        res = min(res, prime - x % prime);
        
        while (y % prime == 0) {
            y /= prime;
        }
    }

    if (y > 1) {
        res = min(res, y - x % y);
    }

    if (res == INT_MAX) {
        return -1;
    }

    return res;
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << get_min_increase(x, y) << endl;
    }
    return 0;
}