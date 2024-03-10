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

    vector<int> weights = {1, 2, 3};
    vector<int> values = {20, 10, 12};

    cout << getMaxValue(weights, values, 5) << endl; // 32
    return 0;
}