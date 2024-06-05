#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
int MOD = 1000000007;



int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    unordered_map<char, long long> dp;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') dp['B']++;
        else if (s[i] == 'A') dp['A'] += dp['B'];
        else if (s[i] == 'C') dp['C'] += dp['A'];
        else dp['H'] += dp['C'];

        dp['B'] %= MOD;
        dp['A'] %= MOD;
        dp['C'] %= MOD;
        dp['H'] %= MOD;
    }

    cout << dp['H'] << endl;

    return 0;
}
