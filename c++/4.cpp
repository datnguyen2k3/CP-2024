#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int getMinJumps(vector<int>& jumps) {
    int n = jumps.size();
    vector<int> minJumps(n, INT_MAX);
    minJumps[0] = 0;

    for (int currIndex = 0; currIndex < n; currIndex++) {
        for (int jumpLength = 1; jumpLength <= jumps[currIndex]; jumpLength++) {
            int nextIndex = currIndex + jumpLength;

            if (nextIndex >= n) {
                break;
            }
            
            minJumps[nextIndex] = min(minJumps[nextIndex], minJumps[currIndex] + 1);
        }
    }

    if (minJumps[n-1] == INT_MAX) {
        return -1;
    }

    return minJumps[n-1];

}

int main() {
    
    vector<int> jumps = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    cout << getMinJumps(jumps) << endl; // 4
    return 0;
}