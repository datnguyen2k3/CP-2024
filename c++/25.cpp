#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

pair<int, int> getStartAndEndIndexOfMaxSubarray(vector<int> arr) {
    int n = arr.size();
    int maxSum = arr[0];
    int maxSumStart = 0;
    int maxSumEnd = 0;

    int currentSum = arr[0];
    int currentStart = 0;

    for (int i = 1; i < n; i++) {
        if (currentSum < 0) {
            currentSum = 0;
            currentStart = i;
        }
        currentSum += arr[i];

        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxSumStart = currentStart;
            maxSumEnd = i;
        }
    }

    return {maxSumStart, maxSumEnd};
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pair<int, int> result = getStartAndEndIndexOfMaxSubarray(arr);
    cout << result.first << " " << result.second << endl;

    return 0;
}