#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

string getLongestCommonSubstring(string str1, string str2) {
    int m = str1.size();
    int n = str2.size();
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        fill_n(dp[i], n + 1, 0);
    }

    int maxCommon = 0;
    int str1End = -1;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] != str2[j - 1]) {
                continue;
            }

            dp[i][j] = 1 + dp[i - 1][j - 1];
            if (dp[i][j] > maxCommon) {
                maxCommon = dp[i][j];
                str1End = i - 1;
            }
        }
    }

    if (maxCommon == 0) {
        return "";
    }

    return str1.substr(str1End - maxCommon + 1, maxCommon);

}

int main() {

    string str1 = "abcdxyz";
    string str2 = "xyzabcd";

    cout << getLongestCommonSubstring(str1, str2) << endl; // abcd
    return 0;
}