#include <iostream>
#include <vector>
#include <algorithm>
#include <__numeric/accumulate.h>

using namespace std;
int MOD = 1000000007;

int getMinDifferentOfTwoPartitions(vector<int> arr) {
    int n = arr.size();
    int minDiff = INT_MAX;
    int sum = accumulate(arr.begin(), arr.end(), 0);

    int mid = n / 2;
    vector<int> doubleLeftSums(1 << mid);
    for (int i = 0; i < (1 << mid); i++) {
        for (int j = 0; j < mid; j++) {
            if (i & (1 << j)) {
                doubleLeftSums[i] += arr[j] * 2;
            }
        }
        if (doubleLeftSums[i] == sum) {
            return 0;
        }
    }

    sort(doubleLeftSums.begin(), doubleLeftSums.end());
    for (int i = 0; i < (1 << (n - mid)); i++) {
        int doubleRightSum = 0;
        for (int j = 0; j < n - mid; j++) {
            if (i & (1 << j)) {
                doubleRightSum += arr[mid + j] * 2;
            }
        }

        if (doubleRightSum == sum) {
            return 0;
        }
        int target = sum - doubleRightSum;
        int minDoubleLeftSumIndex = upper_bound(doubleLeftSums.begin(), doubleLeftSums.end(), target) - doubleLeftSums.begin();
        minDoubleLeftSumIndex--;
        if (minDoubleLeftSumIndex < 0) {
            continue;
        }

        int doubleLeftSum = doubleLeftSums[minDoubleLeftSumIndex];
        minDiff = min(minDiff, sum - doubleLeftSum - doubleRightSum);
    }

    return minDiff;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << getMinDifferentOfTwoPartitions(arr) << endl;
    return 0;
}