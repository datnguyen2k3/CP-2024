#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
int MOD = 1000000007;

int find_sol(vector<int> &heights) {
    int result = 0;
    stack<int> decreasing_stack;

    for (int i = 0; i < heights.size(); i++) {
        while (!decreasing_stack.empty() && heights[i] > heights[decreasing_stack.top()]) {
            decreasing_stack.pop();
            result += 1;
        }

        decreasing_stack.push(i);
    }

    return result;
}

int main() {

    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    long long result = 0;
    stack<pair<int, int>> decreasing_stack;

    for (int i = 0; i < heights.size(); i++) {
        while (!decreasing_stack.empty() && heights[i] > heights[decreasing_stack.top().first]) {
            decreasing_stack.pop();
            result += 1;
        }
        
        int curr_same = 1;
        if (!decreasing_stack.empty() && heights[i] == heights[decreasing_stack.top().first]) {
            curr_same += decreasing_stack.top().second;
        }
        decreasing_stack.push({i, curr_same});

        result += (long long) curr_same - 1;
        if (decreasing_stack.size() > curr_same) {
            result += 1;
        }
    }

    cout << result << endl;
}


// 2 4 1 2 2 5 1
