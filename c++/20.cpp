#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int getMaxProfit(int length, vector<int> prices, vector<int> cuts) {
    vector<int> maxProfit(length + 1, 0);
    int n = cuts.size();

    for (int i = 0; i < n; i++) {
        maxProfit[cuts[i]] = prices[i];
    }

    for (int i = 1; i <= length; i++) {
        for (int j = 1; j <= i/2; j++) {
            maxProfit[i] = max(maxProfit[i], maxProfit[j] + maxProfit[i-j]);
        }
    }

    return maxProfit[length];
}

int main() {

    int length;
    cin >> length;

    int n;
    cin >> n;

    vector<int> prices(n, 0);
    vector<int> cuts(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> cuts[i];
        cin >> prices[i];
    }

    cout << getMaxProfit(length, prices, cuts) << endl;

    return 0;
}