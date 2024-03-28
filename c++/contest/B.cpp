#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;
int MOD = 1000000007;

long long get_max_triangle(vector<pair<int, int>> &points) {
    unordered_map<int, int> x_max_by_y, x_min_by_y, y_max_by_x, y_min_by_x;
    unordered_set<int> ys, xs;
    int x_max = INT_MIN, x_min = INT_MAX, y_max = INT_MIN, y_min = INT_MAX;

    for (int point_index = 0; point_index < points.size(); point_index++) {
        auto [x, y] = points[point_index];
        if (x_max_by_y.find(y) == x_max_by_y.end()) {
            x_max_by_y[y] = x;
        } else {
            x_max_by_y[y] = max(x_max_by_y[y], x);
        }

        if (x_min_by_y.find(y) == x_min_by_y.end()) {
            x_min_by_y[y] = x;
        } else {
            x_min_by_y[y] = min(x_min_by_y[y], x);
        }

        if (y_max_by_x.find(x) == y_max_by_x.end()) {
            y_max_by_x[x] = y;
        } else {
            y_max_by_x[x] = max(y_max_by_x[x], y);
        }

        if (y_min_by_x.find(x) == y_min_by_x.end()) {
            y_min_by_x[x] = y;
        } else {
            y_min_by_x[x] = min(y_min_by_x[x], y);
        }
        
        ys.insert(y);
        xs.insert(x);
        y_max = max(y_max, y);
        y_min = min(y_min, y);
        x_max = max(x_max, x);
        x_min = min(x_min, x);
    }

    long long max_area = 0;
    for (auto y : ys) {
        int curr_x_max = x_max_by_y[y];
        int curr_x_min = x_min_by_y[y];
        if (curr_x_max == curr_x_min || y_max == y_min) {
            continue;
        }

        max_area = max(max_area, (long long) (curr_x_max - curr_x_min) * max((y_max - y), (y - y_min)));
    }

    for (auto x : xs) {
        int curr_y_max = y_max_by_x[x];
        int curr_y_min = y_min_by_x[x];
        if (curr_y_max == curr_y_min || x_max == x_min) {
            continue;
        }

        max_area = max(max_area, (long long) (curr_y_max - curr_y_min) * max((x_max - x), (x - x_min)));
    }

    return max_area;
}

int main() {

    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    cout << get_max_triangle(points) << endl;
    return 0;
}