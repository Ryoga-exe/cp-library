#include "base.hpp"

inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

ll modPow(ll a, ll n, ll p) {
    if (n == 0) return 1;
    if (n == 1) return a % p;
    if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
    ll t = modPow(a, n / 2, p);
    return (t * t) % p;
}

ll modInv(ll a, ll p) {
    return modPow(a, p - 2, p);
}

ll modInvE(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}