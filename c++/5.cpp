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

    int n;
    cin >> n;

    vector<int> north(n, 0);
    vector<int> south(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> north[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> south[i];
    }

    cout << getMaxBridges(north, south) << endl; // 2
    return 0;
}