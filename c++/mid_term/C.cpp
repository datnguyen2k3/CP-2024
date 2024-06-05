#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MOD = 1000000007;

int main() {

    int n, k;
    cin >> n >> k;

    int res = 0;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int count_zeros[33] = {0};
    int length = 0;
    int curr_and = 0;

    for (int i = 0; i < n; i++) {
        length += 1;
        curr_and = 0;

        for (int bit = 0; bit < 31; bit++) {
            int bit_val = 1 << bit;
            bool is_zero = (v[i] & bit_val) == 0;

            count_zeros[bit] += int(is_zero);
            
            if (count_zeros[bit] == 0) {
                curr_and |= bit_val;
            }
        }

        // cout << "curr_and: " << curr_and << endl;

        while (curr_and < k && length > 0) {
            int start = i - length + 1;
            curr_and = 0;

            for (int bit = 0; bit < 31; bit++) {
                int bit_val = 1 << bit;
                bool is_zero = (v[start] & bit_val) == 0;

                count_zeros[bit] -= int(is_zero);
                
                if (count_zeros[bit] == 0) {
                    curr_and |= bit_val;
                }
            }

            length -= 1;

            // cout << "remove and " << "curr_and: " << curr_and << endl;
        }

        if (curr_and >= k)
            res = max(res, length);
    }

    cout << res << endl;
    return 0;
}
