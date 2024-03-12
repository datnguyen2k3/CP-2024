#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

vector<int> getZArray(string str) {
    vector<int> z(str.size(), 0);

    int left = 0;
    int right = 0;

    for (int i = 1; i < str.size(); i++) {
        if (i <= right) {
            z[i] = min(right - i + 1, z[i - left]);
        }

        while (i + z[i] < str.size() && str[z[i]] == str[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
    }

    return z;
}

int getMaxSuffixPalindrome(string str) {
    string revStr = str;
    reverse(revStr.begin(), revStr.end());

    string newStr = revStr + "$" + str;

    vector<int> z = getZArray(newStr);

    for (int i = str.size(); i < z.size(); i++) {
        if (i + z[i] == z.size()) {
            return z[i];
        }
    }

    return 0;
}

int getMinRightCharsToMakePalindrome(string str) {
    int maxSuffixPalindrome = getMaxSuffixPalindrome(str);
    return str.size() - maxSuffixPalindrome;
}

int main() {

    string str = "aacec";

    cout << getMinRightCharsToMakePalindrome(str) << endl; // 2
    return 0;
}