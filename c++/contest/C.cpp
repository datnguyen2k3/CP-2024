#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;
int MOD = 1000000007;

int get_ways(int n) {
    vector<string> strings = {"012", "021", "102", "120", "201", "210", "010", "101", "202", "020", "121", "212"};
    unordered_map<string, vector<string>> prev_strings;

    for (string left : strings) {
        for (string right : strings) {
            if (left[0] == right[0] || left[1] == right[1] || left[2] == right[2]) {
                continue;
            }
            prev_strings[right].push_back(left);
        }
    }

    unordered_map<string, int> ways;
    for (string s : strings) {
        ways[s] = 1;
    }

    for (int i = 1; i < n; i++) {
        unordered_map<string, int> new_ways;
        for (string s : strings) {
            for (string prev : prev_strings[s]) {
                new_ways[s] += ways[prev];
                new_ways[s] %= MOD;
            }
        }
        ways = new_ways;
    }

    int total_ways = 0;
    for (string s : strings) {
        total_ways += ways[s];
        total_ways %= MOD;
    }

    return total_ways;
}

int main() {
    int n;
    cin >> n;
    cout << get_ways(n) << endl;
    return 0;
}

/*

6 diff
6 dup

1 diff = 2 diff + 2 dup
1 dup = 

*/