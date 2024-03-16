#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int getMaxProfit(vector<int> times, vector<int> profits, vector<int> deadlines) {

}

int main() {

    int n;
    cin >> n;

    vector<int> times(n);
    vector<int> profits(n);
    vector<int> deadlines(n);

    for (int i = 0; i < n; i++) {
        cin >> times[i];
        cin >> profits[i];
        cin >> deadlines[i];
    }

    cout << getMaxProfit(times, profits, deadlines) << endl;
    return 0;
}