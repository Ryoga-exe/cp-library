/// @prefix cpModPow
/// @description ModPow : 高速に a ^ n mod p を計算します  \n O(log(n))
/// @isFileTemplate false
inline constexpr long long ModPow(long long a, long long n, const long long p) noexcept {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return res;
}
