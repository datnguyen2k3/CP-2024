#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int main() {

    long long n, k;
    cin >> n >> k;

    for (int num = n; num > 0; num--) {
        int lefts = num - 1;
        if (k >= lefts) {
            cout << num << " ";
            k -= lefts;
        } else if (k == 0) {
            for (int i = 1; i <= num; i++) {
                cout << i << " ";
            }
            break;
        }  else {

            vector<int> left_nums;
            for (int i = 1; i <= lefts; i++) {
                left_nums.push_back(i);
            }

            int inserted_index = lefts - k;
            left_nums.insert(left_nums.begin() + inserted_index, num);
            for (int i = 0; i < left_nums.size(); i++) {
                cout << left_nums[i] << " ";
            }
            break;
        }
    }

    return 0;
}