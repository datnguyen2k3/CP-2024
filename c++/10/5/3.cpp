#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    vector<int> nums = {x, y, z};
    sort(nums.begin(), nums.end());

    char a, b, c;
    cin >> a >> b >> c;

    cout << nums[a - 'A'] << " " << nums[b - 'A'] << " " << nums[c - 'A'] << endl;

    return 0;
}