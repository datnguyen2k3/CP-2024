#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int getWaysToMakeExpressionIsTrue(string expressions) {
    int n = expressions.size();

    vector<vector<int>> trueWays(n, vector<int>(n, 0));
    vector<vector<int>> falseWays(n, vector<int>(n, 0));

    for (int i = 0; i < n; i += 2) {
        if (expressions[i] == 'T') {
            trueWays[i][i] = 1;
        } else {
            falseWays[i][i] = 1;
        }
    }

    for (int subLength = 3; subLength <= n; subLength += 2) {
        for (int left = 0; left <= n - subLength; left += 2) {
            int right = left + subLength - 1;

            for (int mid = left + 1; mid < right; mid += 2) {
                int leftTrue = trueWays[left][mid - 1];
                int leftFalse = falseWays[left][mid - 1];
                int rightTrue = trueWays[mid + 1][right];
                int rightFalse = falseWays[mid + 1][right];

                if (expressions[mid] == '&') {
                    trueWays[left][right] += leftTrue * rightTrue;
                    falseWays[left][right] += leftTrue * rightFalse + leftFalse * rightTrue + leftFalse * rightFalse;
                } else if (expressions[mid] == '|') {
                    trueWays[left][right] += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
                    falseWays[left][right] += leftFalse * rightFalse;
                } else if (expressions[mid] == '^') {
                    trueWays[left][right] += leftTrue * rightFalse + leftFalse * rightTrue;
                    falseWays[left][right] += leftTrue * rightTrue + leftFalse * rightFalse;
                }
            }
        }
    }

    return trueWays[0][n - 1];
}

int main() {

    string s;
    getline(cin, s);

    cout << getWaysToMakeExpressionIsTrue(s) << endl;
    return 0;
}