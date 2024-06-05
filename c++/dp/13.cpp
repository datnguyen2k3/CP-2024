#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int getLongestPalindromeString(string str) {
    int maxPalindromeLength = 0;

    for (int i = 0; i < str.size(); i++) {
        int left = i;
        int right = i;

        while (left >= 0 && right < str.size() && str[left] == str[right]) {
            maxPalindromeLength = max(maxPalindromeLength, right - left + 1);
            left--;
            right++;
        }

        left = i;
        right = i + 1;

        while (left >= 0 && right < str.size() && str[left] == str[right]) {
            maxPalindromeLength = max(maxPalindromeLength, right - left + 1);
            left--;
            right++;
        }
    }

    return maxPalindromeLength;
}

int main() {

    string str;
    cin >> str;

    cout << getLongestPalindromeString(str) << endl; // 3
    return 0;
}