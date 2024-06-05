#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    n *= 2;
    int masks = 1 << n;
    int ways[masks][n + 1][n + 1];
    for (int mask = 0; mask < masks; mask++) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                ways[mask][i][j] = 0;
            }
        }
    }

    vector<pair<int, int>> valid_pairs;
    for (int above = 0; above < n; above++) {
        for (int below = 0; below < n; below++) {
            if (above == below) {
                continue;
            }
            if (abs(above - below) <= r && abs(above - below) >= l) {
                valid_pairs.push_back({above, below});
            }
        }
    }

    for (auto& [above, below] : valid_pairs) {
        ways[(1 << above) + (1 << below) ][above][below] = 1;
    }

    for (int i = 2; i <= n / 2; i++) {
        int new_ways[masks][n + 1][n + 1];
        for (int mask = 0; mask < masks; mask++) {
            for (int above = 0; above < n; above++) {
                for (int below = 0; below < n; below++) {
                    new_ways[mask][above][below] = 0;
                }
            }
        }

        for (int prev_mask = 0; prev_mask < masks; prev_mask++) {
            for (auto& [above, below] : valid_pairs) {
                
                bool is_contain_above = (prev_mask & (1 << above)) > 0;
                bool is_contain_below = (prev_mask & (1 << below)) > 0;
                if (is_contain_above || is_contain_below) {
                    continue;
                }

                for (auto& [prev_above, prev_below] : valid_pairs) {

                    bool is_contain_prev_above = (prev_mask & (1 << prev_above)) > 0;
                    bool is_contain_prev_below = (prev_mask & (1 << prev_below)) > 0;

                    if (!is_contain_prev_above || !is_contain_prev_below) {
                        continue;
                    }
                    
                    int above_diff = abs(above - prev_above);
                    int below_diff = abs(below - prev_below);
                    if (above_diff < l || above_diff > r || below_diff < l || below_diff > r) {
                        continue;
                    }

                    int curr_mask = prev_mask + (1 << above) + (1 << below);
                    new_ways[curr_mask][above][below] += ways[prev_mask][prev_above][prev_below];
                    new_ways[curr_mask][above][below] %= MOD;
                }
            }
        }

        for (int mask = 0; mask < masks; mask++) {
            for (int above = 0; above < n; above++) {
                for (int below = 0; below < n; below++) {
                    ways[mask][above][below] = new_ways[mask][above][below];
                }
            }
        }
    }

    int res = 0;

    for (int above = 0; above < n; above++) {
        for (int below = 0; below < n; below++) {
            res += ways[masks - 1][above][below];
            res %= MOD;
        }
    }

    cout << res << endl;

    return 0;
}