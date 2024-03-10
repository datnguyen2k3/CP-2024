#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int getCatalan(int n) {
    vector<int> catalan(n+1, 0);
    catalan[0] = 1;

    for (int i = 1; i <= n; i++) {
        int currCatalan = 0;
        for (int j = 0; j < i; j++) {
            currCatalan += catalan[j] * catalan[i-j-1];
        }
        catalan[i] = currCatalan;
    }

    return catalan[n];
}

int main() {

    cout << getCatalan(3) << endl; // 5
    return 0;
}