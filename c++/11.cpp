#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int getSubarraySum(vector<int> &prefixSums, int left, int right) {
    if (left == 0) {
        return prefixSums[right];
    }
    return (prefixSums[right] - prefixSums[left - 1] + MOD) % MOD;
}

int getRollingWays(int dices, int faces, int target) {
    vector<vector<int>> ways(dices + 1, vector<int>(target + 1, 0));
    vector<vector<int>> prefixWays(dices + 1, vector<int>(target + 1, 0));
    ways[0][0] = 1;

    prefixWays[0] = vector<int>(target + 1, 1);

    for (int dicesNumber = 1; dicesNumber <= dices; dicesNumber++) {
        for (int sum = 1; sum <= target; sum++) {
            int minPrevSum = max(0, sum - faces);
            int maxPrevSum = sum - 1;

            ways[dicesNumber][sum] = getSubarraySum(prefixWays[dicesNumber - 1], minPrevSum, maxPrevSum);
            prefixWays[dicesNumber][sum] = (prefixWays[dicesNumber][sum - 1] + ways[dicesNumber][sum]) % MOD;
        }
    }

    return ways[dices][target];
}

int main() {

    int dices = 2;
    int faces = 6;
    int target = 7;

    cout << getRollingWays(dices, faces, target) << endl; // 6
    return 0;
}