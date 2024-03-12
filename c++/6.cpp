#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int getMaxSubarray(vector<int>& nums) {
    int n = nums.size();
    vector<int> maxSum(n, 0);
    maxSum[0] = nums[0];
    int maxSumValue = maxSum[0];

    for (int i = 1; i < n; i++) {
        maxSum[i] = max(nums[i], maxSum[i-1] + nums[i]);
        maxSumValue = max(maxSumValue, maxSum[i]);
    }

    return maxSumValue;
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << getMaxSubarray(nums) << endl;
    return 0;
}