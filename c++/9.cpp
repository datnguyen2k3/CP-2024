#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int getMaxValue(vector<int> weights, vector<int> values, int maxCapacity) {
    int itemsNumber = weights.size();
    vector<vector<int>> maxValues(itemsNumber + 1, vector<int>(maxCapacity + 1, 0));

    for (int itemIndex = 0; itemIndex < itemsNumber; itemIndex++) {
        int currItems = itemIndex + 1;
        for (int capacity = 1; capacity <= maxCapacity; capacity++) {
            maxValues[currItems][capacity] = maxValues[currItems - 1][capacity];
            if (weights[itemIndex] <= capacity) {
                maxValues[currItems][capacity] = max(
                    maxValues[currItems][capacity], 
                    maxValues[currItems - 1][capacity - weights[itemIndex]] + values[itemIndex]
                );
            }
        }
    }

    return maxValues[itemsNumber][maxCapacity];

}

int main() {
    int n, capacity;
    cin >> n >> capacity;

    vector<int> weights(n, 0);
    vector<int> values(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    cout << getMaxValue(weights, values, capacity) << endl;
    return 0;
}