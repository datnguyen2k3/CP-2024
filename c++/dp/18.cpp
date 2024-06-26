#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int MOD = 1000000007;

bool canSeparateIntoTwoEqualSumSubsets(vector<int> &nums) {
    int arraySum = accumulate(nums.begin(), nums.end(), 0);
    if (arraySum % 2 != 0) {
        return false;
    }

    int n = nums.size();
    int halfArraySum = arraySum / 2;

    vector<vector<bool>> dp(n + 1, vector<bool>(halfArraySum + 1, false));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int sum = 0; sum <= halfArraySum; sum++) {
            dp[i][sum] = dp[i - 1][sum];
            if (sum - nums[i - 1] >= 0) {
                dp[i][sum] =  dp[i][sum] || dp[i - 1][sum - nums[i - 1]];
            }
        }
    }
    
    return dp[n][halfArraySum];
}

int main() {

    int testCases;
    cin >> testCases;

    for (int testCase = 0; testCase < testCases; testCase++) {
        int n;
        cin >> n;

        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        if (canSeparateIntoTwoEqualSumSubsets(nums)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}