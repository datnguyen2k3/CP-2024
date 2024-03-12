#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int getMaxPartitionMultiple(int n) {
    vector<int> maxPartitionMultiple(n+1, 0);

    for (int num = 1; num <= n; num++) {
        maxPartitionMultiple[num] = num;
    }

    for (int num = 2; num <= n; num++) {
        for (int partOne = 1; partOne <= num / 2; partOne++) {
            int partTwo = num - partOne;
            maxPartitionMultiple[num] = max(
                maxPartitionMultiple[num], 
                maxPartitionMultiple[partOne] * maxPartitionMultiple[partTwo]
            );
        }
    }

    return maxPartitionMultiple[n];
}

int main() {

    int n;
    cin >> n;

    cout << getMaxPartitionMultiple(n) << endl;
    return 0;
}