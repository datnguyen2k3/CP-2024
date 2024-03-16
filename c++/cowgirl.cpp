#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1e9 + 7;

bool isValid(int currentMask, int previousMask, int length) {
    for (int i = 1; i < length; i++) {
        int bit1 = (currentMask & (1 << i)) > 0;
        int bit2 = (currentMask & (1 << (i - 1))) > 0;
        int bit3 = (previousMask & (1 << i)) > 0;
        int bit4 = (previousMask & (1 << (i - 1))) > 0;

        if (bit1 == bit2 and bit2 == bit3 and bit3 == bit4) {
            return false;
        }
    }

    return true;
}

void solve() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int rows, cols;
        cin >> rows >> cols;

        if (rows < cols) {
            swap(rows, cols);
        }

        int masks = 1 << cols;
        vector<vector<int>> previousMasks(masks);

        for (int currentMask = 0; currentMask < masks; currentMask++) {
            for (int previousMask = 0; previousMask < masks; previousMask++) {
                if (isValid(currentMask, previousMask, cols)) {
                    previousMasks[currentMask].push_back(previousMask);
                }
            }
        }

        vector<vector<long long>> ways(rows, vector<long long>(masks, 0));
        for (int mask = 0; mask < masks; mask++) {
            ways[0][mask] = 1;
        }

        for (int row = 1; row < rows; row++) {
            for (int currentMask = 0; currentMask < masks; currentMask++) {
                for (int previousMask : previousMasks[currentMask]) {
                    ways[row][currentMask] = (ways[row][currentMask] + ways[row - 1][previousMask]);
                }
            }
        }

        long long totalWays = 0;
        for (int mask = 0; mask < masks; mask++) {
            totalWays = (totalWays + ways[rows - 1][mask]);
        }

        cout << totalWays << endl;
    }
}

int main() {

    solve();
    return 0;
}