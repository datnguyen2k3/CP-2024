#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int MOD = 1000000007;

int getEditDistance(string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();

    vector<vector<int>> editDistances(len1 + 1, vector<int>(len2 + 1, INT_MAX));
    for (int firstChars1 = 0; firstChars1 <= len1; firstChars1++) {
        editDistances[firstChars1][0] = firstChars1;
    }
    for (int firstChars2 = 0; firstChars2 <= len2; firstChars2++) {
        editDistances[0][firstChars2] = firstChars2;
    }

    for (int firstChars2 = 1; firstChars2 <= len2; firstChars2++) {
        for (int firstChars1 = 1; firstChars1 <= len1; firstChars1++) {
            int char1Index = firstChars1 - 1;
            int char2Index = firstChars2 - 1;
            
            // do nothing if the characters are the same
            if (str1[char1Index] == str2[char2Index]) {
                editDistances[firstChars1][firstChars2] = editDistances[firstChars1 - 1][firstChars2 - 1];
                continue;
            }

            // insert
            editDistances[firstChars1][firstChars2] = min(
                editDistances[firstChars1][firstChars2],
                editDistances[firstChars1][firstChars2 - 1] + 1
            );

            // delete
            editDistances[firstChars1][firstChars2] = min(
                editDistances[firstChars1][firstChars2],
                editDistances[firstChars1 - 1][firstChars2] + 1
            );

            // replace
            editDistances[firstChars1][firstChars2] = min(
                editDistances[firstChars1][firstChars2],
                editDistances[firstChars1 - 1][firstChars2 - 1] + 1
            );
        }
    }

    return editDistances[len1][len2];
}

int main() {

    string str1 = "sunday";
    string str2 = "saturday";

    cout << getEditDistance(str1, str2) << endl; // 3
    return 0;
}