#include <vector>
#include <utility>
#include <algorithm>

/// start
/// @prefix cpDivisors
/// @description Enumerate divisors of n : n の約数を列挙します \n O(sqrt(N))
/// @isFileTemplate false
std::vector<long long> Divisors(const long long n) noexcept {
    std::vector<long long> res;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (n / i != i) res.push_back(n / i);
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}
