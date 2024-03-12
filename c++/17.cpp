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

    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << getLongestIncreasingSubsequence(arr) << endl; // 6
    return 0;
}