#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int getLongestIncreasingSubsequence(vector<int> arr) {
    int n = arr.size();
    vector<int> dp = {arr[0]};

    int result = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > dp.back()) {
            dp.push_back(arr[i]);
            result = max(result, (int) dp.size());
        } else {
            int index = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[index] = arr[i];
        }
    }

    return result;
}

int main() {

    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};

    cout << getLongestIncreasingSubsequence(arr) << endl; // 6
    return 0;
}