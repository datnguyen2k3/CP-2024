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

    int amount, coinNumber;
    cin >> amount >> coinNumber;

    vector<int> coins(coinNumber, 0);
    for (int i = 0; i < coinNumber; i++) {
        cin >> coins[i];
    }

    cout << getMoneyExchangeWays(amount, coins) << endl;
    return 0;
}