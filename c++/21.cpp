#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
int MOD = 1000000007;

int getMaxRectangleAreaOfColumnArray(vector<int> heights) {
    heights.emplace_back(0);
    int n = heights.size(), ans = 0;
    stack<int> st; st.push(-1);
    for(int i = 0; i < n; i++) {
        while(st.size() > 1 && heights[st.top()] >= heights[i]) {
            int current_height = heights[st.top()];
            st.pop();
            ans = max(ans, current_height * (i - st.top() - 1));
        }
        st.push(i);
    }
    return ans;
}

int getMaxAreaOfSubMatrixFullOne(vector<vector<int>> matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int maxArea = 0;
    vector<int> columnHeights(cols, 0);

    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for (int colIndex = 0; colIndex < cols; colIndex++) {
            if (matrix[rowIndex][colIndex] == 0) {
                columnHeights[colIndex] = 0;
            } else {
                columnHeights[colIndex] += 1;
            }
        }
        maxArea = max(maxArea, getMaxRectangleAreaOfColumnArray(columnHeights));
    }

    return maxArea;
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << getMaxAreaOfSubMatrixFullOne(matrix);

    return 0;
}