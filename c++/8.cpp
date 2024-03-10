#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int getJumpStairWays(int n) {
    if (n <= 1) return n;
    if (n == 2) return 2;

    int firstPrev = 2;
    int secondPrev = 1;
    int currWays = 0;

    for (int i = 3; i <= n; i++) {
        currWays = firstPrev + secondPrev;
        secondPrev = firstPrev;
        firstPrev = currWays;
    }

    return currWays;

}

int main() {

    cout << getJumpStairWays(4) << endl; // 5
    return 0;
}