#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
int MOD = 1000000007;

long long get_isosceles_triangles(vector<int> edges) {
    sort(edges.begin(), edges.end());
    unordered_map<int, long long> edge_count;
    for (int edge : edges) {
        edge_count[edge]++;
    }

    long long res = 0;
    for (auto& [edge, count] : edge_count) {
        if (count < 2) {
            continue;
        }

        res += (count * (count - 1) * (count - 2)) / 6;

        int lefts = lower_bound(edges.begin(), edges.end(), edge * 2) - edges.begin() - count;
        res += ((count * (count - 1)) / 2) * lefts;
    }

    return res;
} 

int main() {

    int n;
    cin >> n;

    vector<int> edges(n);
    for (int i = 0; i < n; i++) {
        cin >> edges[i];
    }

    cout << get_isosceles_triangles(edges) << endl;

    return 0;
}