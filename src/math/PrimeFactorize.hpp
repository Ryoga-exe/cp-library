#include <vector>
#include <utility>

/// start
/// @prefix cpPrimeFactorize
/// @description Prime factorization of n : n を素因数分解します \n O(sqrt(N))
/// @isFileTemplate false
std::vector<std::pair<long long, long long>> PrimeFactorize(long long n) noexcept {
    std::vector<std::pair<long long, long long>> res;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i != 0) continue;
        long long ex = 0;
        while (n % i == 0) {
            ++ex; n /= i;
        }
        res.push_back({ i, ex });
    }
    if (n != 1) {
        res.push_back({ n, 1 });
    }
    return res;
}
