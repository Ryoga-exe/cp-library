#include <vector>

/// start
/// @prefix cpEratosthenes
/// @description Eratosthenes : エラトステネスの篩 - [1, N] の自然数について素数かどうかのテーブルを返します \n O(sqrt(N))
/// @isFileTemplate false
std::vector<bool> Eratosthenes(int n) {
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 0; p <= n; p++) {
        if (!isPrime[p]) {
            continue;
        }
        for (int q = p * 2; q <= n; q += p) {
            isPrime[q] = false;
        }
    }
    return isPrime;
}
