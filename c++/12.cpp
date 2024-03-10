#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int getMoneyExchangeWays(int amount, vector<int> &coins) {
    vector<int> ways(amount + 1, 0);
    ways[0] = 1;

    for (int coin : coins) {
        for (int currentAmount = coin; currentAmount <= amount; currentAmount++) {
            ways[currentAmount] = (ways[currentAmount] + ways[currentAmount - coin]) % MOD;
        }
    }

    return ways[amount];
}

int main() {

    int amount = 5;
    vector<int> coins = {1, 2, 5};

    cout << getMoneyExchangeWays(amount, coins) << endl; // 4

    return 0;
}