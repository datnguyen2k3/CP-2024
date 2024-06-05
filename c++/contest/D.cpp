#include <iostream>
#include <vector>

using namespace std;

// Hàm nhân hai ma trận 2x2
vector<vector<long long>> matrixMultiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B, long long k) {
    vector<vector<long long>> result(2, vector<long long>(2));
    result[0][0] = (A[0][0] * B[0][0] % k + A[0][1] * B[1][0] % k) % k;
    result[0][1] = (A[0][0] * B[0][1] % k + A[0][1] * B[1][1] % k) % k;
    result[1][0] = (A[1][0] * B[0][0] % k + A[1][1] * B[1][0] % k) % k;
    result[1][1] = (A[1][0] * B[0][1] % k + A[1][1] * B[1][1] % k) % k;
    return result;
}

// Hàm tính lũy thừa của ma trận 2x2
vector<vector<long long>> matrixPower(const vector<vector<long long>>& base, long long exponent, long long k) {
    if (exponent == 1)
        return base;

    vector<vector<long long>> half_power = matrixPower(base, exponent / 2, k);
    vector<vector<long long>> result = matrixMultiply(half_power, half_power, k);

    if (exponent % 2 == 1)
        result = matrixMultiply(result, base, k);

    return result;
}

// Hàm tính số Fibonacci thứ n modulo k
long long fibonacciModulo(long long n, long long k) {
    if (n <= 1)
        return n;

    vector<vector<long long>> base = {{1, 1}, {1, 0}};
    vector<vector<long long>> result = matrixPower(base, n - 1, k);

    return result[0][0];
}

int main() {
    long long n, k;
    cin >> n;
    cin >> k;

    long long fib_mod_k = fibonacciModulo(n + 1, k);
    cout << fib_mod_k << endl; 

    return 0;
}
