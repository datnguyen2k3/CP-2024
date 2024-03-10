#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int getMaxBridges(vector<int>& north, vector<int>& south) {
    int n = north.size();
    vector<vector<int>> maxBridges(n, vector<int>(n, INT_MAX));

    for (int northEnd = 0; northEnd < n; northEnd++) {
        for (int southEnd = 0; southEnd < n; southEnd++) {
            int currMaxBridges = 0;
            if (northEnd > 0) {
                currMaxBridges = max(currMaxBridges, maxBridges[northEnd-1][southEnd]);
            }
            if (southEnd > 0) {
                currMaxBridges = max(currMaxBridges, maxBridges[northEnd][southEnd-1]);
            }
            if (north[northEnd] == south[southEnd] and northEnd > 0 and southEnd > 0) {
                currMaxBridges = max(currMaxBridges, maxBridges[northEnd-1][southEnd-1] + 1);
            }
            maxBridges[northEnd][southEnd] = currMaxBridges;
        }
    }

    return maxBridges[n-1][n-1];
}

int main() {
    vector<int> north = {1, 4, 2, 5, 3};
    vector<int> south = {3, 2, 4, 1, 5};
    cout << getMaxBridges(north, south) << endl; // 2
    return 0;
}