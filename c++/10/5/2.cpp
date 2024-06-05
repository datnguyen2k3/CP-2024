#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
int MOD = 1000000007;

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    
    string s1;
    string s2;

    cin.ignore();

    getline(cin, s1);
    getline(cin, s2);


    int t;
    cin >> t;
    
    std::reverse(s1.begin(), s1.end());
    vector<vector<char>> indexes(s1.size() + s2.size() + 300);

    for (int i = 0; i < s2.size(); i++) {
        int new_index = 50 + i + s1.size() - t;
        indexes[new_index].push_back(s2[i]);
    }

    for (int i = 0; i < s1.size(); i++) {
        int new_index = 50 + i;
        indexes[new_index].push_back(s1[i]);
    }  
    
    string res = "";
    for (int i = 0; i < indexes.size(); i++) {
        for (int j = 0; j < indexes[i].size(); j++) {
            res.push_back(indexes[i][j]);
        }
    }

    cout << res << endl;

    return 0;
}
