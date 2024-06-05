#include <iostream>
#include <cmath>

std::string compareExponents(int a, int b, int c, int d) {
    double log_ab = b * log(a);
    double log_cd = d * log(c);

    if (std::abs(log_ab - log_cd) < 1e-9) {
        return "=";
    } else if (log_ab > log_cd) {
        return ">";
    } else {
        return "<";
    }
}

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    std::cout << compareExponents(a, b, c, d) << std::endl;

    return 0;
}
