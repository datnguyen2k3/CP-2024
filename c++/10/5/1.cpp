#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> grid[row][col];
        }
    }

    int masks = 1 << n;
    vector<double> dp(masks, -1);

    dp[0] = 1;
    for (int row = 0; row < n; row++) {
        vector<double> new_dp = vector<double>(masks, -1);
        for (int prev_mask = 0; prev_mask < masks; prev_mask++) {
            if (dp[prev_mask] == -1) {
                continue;
            }

            for (int col = 0; col < n; col++) {
                int bit = 1 << col;
                if (prev_mask & bit) {
                    continue;
                }
                
                int curr_mask = prev_mask | bit;
                new_dp[curr_mask] = max(new_dp[curr_mask], grid[row][col] * dp[prev_mask] / 100);
            }
        }
        dp = new_dp;
    }

    cout << dp[masks - 1] * 100 << endl;
    return 0;
}