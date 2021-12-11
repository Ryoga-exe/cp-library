#include "base.hpp"

// p/q
struct fraction {
    ll p, q;
    fraction(ll _p, ll _q): p(_p), q(_q) {}
    operator double() {
        if (q == 0) return (double)(1LL << 60);
        return (double)p/q;
    }
    bool operator<(const fraction &other) const {
        return p*other.q < other.p*q;
    }
    bool operator<=(const fraction &other) const {
        return p*other.q <= other.p*q;
    }
    bool operator>(const fraction &other) const {
        return !(*this <= other);
    }
    bool operator>=(const fraction &other) const {
        return !(*this < other);
    }
    bool operator==(const fraction &other) const {
        auto t = (*this).reducted();
        auto s = other.reducted();
        return (t.p == s.p && t.q == s.q);
    }
    fraction operator*(const fraction &other){
        p *= other.p;
        q *= other.q;
        return *this;
    }
    void reduction() {
        ll r = gcd(p, q);
        p /= r;
        q /= r;
    }
    fraction reducted() const {
        fraction ret(p, q);
        ret.reduction();
        return ret;
    }
};
