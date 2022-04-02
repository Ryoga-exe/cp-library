#include "base.hpp"

inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

ll modPow(ll a, ll n, ll p) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return res;
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
