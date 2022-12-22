#include <utility>
#include "modpow.hpp"

/// start
/// @prefix cpModInv
/// @description ModInv : mod p での a の逆元 (a^{-1}) を計算します \n O(log(p))
/// @isFileTemplate false
inline constexpr long long ModInv(long long a, const long long p) noexcept {
    long long b = p, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; std::swap(a, b);
        u -= t * v; std::swap(u, v);
    }
    u %= p; 
    if (u < 0) u += p;
    return u;
}
