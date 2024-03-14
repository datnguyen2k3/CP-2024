#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int getMaxSubMatrixSum(vector<vector<int>> matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> prefixRowSum(rows, vector<int>(cols, 0));

    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for (int colIndex = 0; colIndex < cols; colIndex++) {
            prefixRowSum[rowIndex][colIndex] = matrix[rowIndex][colIndex];
            if (rowIndex > 0) {
                prefixRowSum[rowIndex][colIndex] += prefixRowSum[rowIndex - 1][colIndex];
            }
        }
    }

    int maxSum = 0;
    for (int colIndexLeft = 0; colIndexLeft < cols; colIndexLeft++) {
        for (int colIndexRight = colIndexLeft; colIndexRight < cols; colIndexRight++) {
            vector<int> prefixColSum(rows, 0);
            int minPrevPrefixSum = 0;

            for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
                prefixColSum[rowIndex] = prefixRowSum[rowIndex][colIndexRight];
                if (colIndexLeft > 0) {
                    prefixColSum[rowIndex] -= prefixRowSum[rowIndex][colIndexLeft - 1];
                }
                if (colIndexLeft > 0) {
                    prefixColSum[rowIndex] += prefixRowSum[rowIndex - 1][colIndexLeft];
                }
                
                maxSum = max(maxSum, prefixColSum[rowIndex] - minPrevPrefixSum);
                minPrevPrefixSum = min(minPrevPrefixSum, prefixColSum[rowIndex]);
            }
        }
    }

    return maxSum;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int rowIndex = 0; rowIndex < n; rowIndex++) {
        for (int colIndex = 0; colIndex < m; colIndex++) {
            cin >> matrix[rowIndex][colIndex];
        }
    }

    cout << getMaxSubMatrixSum(matrix);

    return 0;
}