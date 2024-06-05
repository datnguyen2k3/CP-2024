#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> square_count(100001, 0);

    for (int edge1 = 0; edge1 <= 100; edge1++) {
        for (int edge2 = 0; edge2 <= 100; edge2++) {
            square_count[edge1 * edge1 + edge2 * edge2] += 1;
        }
    }

    long long res = 0;

    for (int first_sum = 0; first_sum <= n; first_sum++) {
        int second_sum = n - first_sum;
        
        res += square_count[first_sum] * square_count[second_sum];
    }

    cout << res << endl;

    return 0;
}