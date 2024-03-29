#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>


using namespace std;
int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    

    vector<int> lover(n);
    for (int i = 0; i < n; i++) {
        cin >> lover[i];
    }

    int res = 0;
    for (int start = 0; start < n; start++) {
        int step = 5;
        int curr = start + 1;
        unordered_set<int> visited;
        visited.insert(curr);

        while (step--) {
            curr = lover[curr - 1];
            visited.insert(curr);
        }
        res += int(curr == start + 1 && visited.size() == 5);
    }

    cout << res / 5 << endl;

    return 0;
}