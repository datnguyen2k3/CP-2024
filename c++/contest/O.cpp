#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int MOD = 1000000007;

vector<long long> factorial;

// int comb(int n, int r) {
//     // If r is greater than n, return 0
//     if (r > n) return 0;
//     // If r is 0 or equal to n, return 1
//     if (r == 0 || n == r) return 1;
//     // Initialize the logarithmic sum to 0
//     double res = 0;
//     // Calculate the logarithmic sum of the numerator and denominator using loop
//     for (int i = 0; i < r; i++) {
//         // Add the logarithm of (n-i) and subtract the logarithm of (i+1)
//         res += log(n-i) - log(i+1);
//     }
//     // Convert logarithmic sum back to a normal number
//     return (int)round(exp(res));
// }

int comb(int n, int k) {
 if (k == 0 || k == n) return 1;
 if (k == 1) return n;
 return comb(k - 1, n - 1) + comb(k, n - 1);
}

long long powerMod(long long x, long long y)
{
    // Initialize answer
    long long res = 1;
    long long p = 1000000007;
 
    // Check till the number becomes zero
    while (y > 0) {
 
        // If y is odd, multiply x with result
        if (y % 2 == 1)
            res = (res * x);
 
        // y = y/2
        y = y >> 1;
 
        // Change x to x^2
        x = (x * x);
    }
    return res % p;
}

int main() {
    int n, k;
    cin >> n >> k;

    long long res = 0;

    for (long long selected_groups = 1; selected_groups <= k; selected_groups++) {
        long long empty_groups = selected_groups - 1;

        if (empty_groups + selected_groups > n) continue;

        long long empty_groups = min(n - selected_groups, selected_groups + 1);

        long long left_selections = k - selected_groups;
        long long left_empties = n - k - empty_groups;

        long long selected_ways = comb(selected_groups + left_selections - 1, left_selections);
        long long empty_ways = comb(empty_groups + left_empties - 1, left_empties);
        if (empty_ways + 1 + selected_groups <= n) {
            empty_ways += 2 * comb(empty_groups + left_empties - 1 - 1, left_empties - 1);
        }
        if (empty_ways + 2 + selected_groups <= n) {
            empty_ways += 2 * comb(empty_groups + left_empties - 1 - 1, left_empties - 1);
        }










        int left_selections = k - selected_groups;
        int left_empties = n - k - (selected_groups - 1);

        // cout << "selected_groups: " << selected_groups << " empty_groups: " << empty_groups << " left_selections: " << left_selections << " left_empties: " << left_empties << endl;
        
        long long curr = comb(selected_groups + left_selections - 1, left_selections);

        if (empty_groups == selected_groups) {
            long long mid = 2 * comb(empty_groups + left_empties - 1, left_empties) - comb(empty_groups - 1 + left_empties - 1, left_empties);

            curr *= mid;
            curr %= MOD;
        }
        else {
            curr *= comb(empty_groups + left_empties - 1, left_empties);
            curr %= MOD;
        }


        curr *= powerMod(2, selected_groups);
        curr %= MOD;

        res += curr;
        res %= MOD;
        // cout << "curr: " << curr << endl;
    }

    cout << res << endl;

    return 0;
}