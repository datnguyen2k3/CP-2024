#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int main() {
    string input;
    cin >> input;

    string s;
    s.push_back(input[0]);

    for (int i = 1; i < input.size(); i++) {
        if (input[i] != input[i - 1]) {
            s.push_back(input[i]);
        }
    }

    int dp[s.size()][s.size()];
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            dp[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < s.size(); i++) {
        dp[i][i] = 1;
        if (i > 0) {
            dp[i - 1][i] = s[i - 1] != s[i] ? 2 : 1;
        }
    }

    // cout << dp[0][1][s[1] - 'a'] << endl;
    // cout << *max_element(dp[0][1], dp[0][1] + 26) << endl;
    // for (int c = 0; c < 26; c++) {
    //     cout << dp[0][1][c] << " ";
    // }
    // cout << endl;
    // cout << endl;


    for (int sub_length = 3; sub_length <= s.size(); sub_length++) {
        for (int start = 0; start + sub_length - 1 < s.size(); start++) {
            int end = start + sub_length - 1;
            
            dp[start][end] = 1 + dp[start + 1][end];
            for (int mid = start + 1; mid <= end; mid++) {
                if (s[start] == s[mid]) {
                    dp[start][end] = min(dp[start][end], dp[start + 1][mid - 1] + dp[mid][end]);
                }
            }
        }
    }

    std::cout << dp[0][s.size() - 1] << std::endl;
    
    return 0;
}