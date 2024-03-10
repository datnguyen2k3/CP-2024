#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int memo[3001][3001];

int getCombination(int n, int k) {
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    if (memo[n][k] != -1) return memo[n][k];
    
    memo[n][k] = (getCombination(n-1, k-1) + getCombination(n-1, k)) % MOD;
    return memo[n][k];
}   


int main() {
    for (int i = 0; i < 3001; i++) {
        fill_n(memo[i], 3001, -1);
    }

    cout << getCombination(5, 3) << endl; // 10
    return 0;
}