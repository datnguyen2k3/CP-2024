#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int getFirstPlayerMaxPoints(vector<int> coins) {
    int n = coins.size();

    vector<vector<int>> firstPlayerMaxPoints(n, vector<int>(n, 0));
    for (int coinIndex = 0; coinIndex < n; coinIndex++) {
        firstPlayerMaxPoints[coinIndex][coinIndex] = coins[coinIndex];
    }

    vector<int> prefixSum(n, 0);
    prefixSum[0] = coins[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + coins[i];
    }

    for (int subLength = 2; subLength <= n; subLength++) {
        for (int left = 0; left <= n - subLength; left++) {
            int right = left + subLength - 1;
            int subSum = prefixSum[right] - (left == 0 ? 0 : prefixSum[left - 1]);

            int takeLeft = coins[left] + (subSum - firstPlayerMaxPoints[left + 1][right] - coins[left]);
            int takeRight = coins[right] + (subSum - firstPlayerMaxPoints[left][right - 1] - coins[right]);
            firstPlayerMaxPoints[left][right] = max(takeLeft, takeRight);
        }
    }

    return firstPlayerMaxPoints[0][n - 1];
}

int main() {

    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << getFirstPlayerMaxPoints(coins) << endl;

    return 0;
}