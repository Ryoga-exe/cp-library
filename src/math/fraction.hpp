#include <numeric>

/// start
/// @prefix cpFraction
/// @description Structure representing a fraction : 分数を表す構造体
/// @isFileTemplate false
// p/q
struct Fraction {
    long long p, q;
    Fraction(long long _p, long long _q): p(_p), q(_q) {}
    operator double() {
        if (q == 0) return (double)(1LL << 60);
        return (double)p/q;
    }
    bool operator<(const Fraction &other) const noexcept { return p*other.q < other.p*q; }
    bool operator<=(const Fraction &other) const noexcept { return p*other.q <= other.p*q; }
    bool operator>(const Fraction &other) const noexcept { return !(*this <= other); }
    bool operator>=(const Fraction &other) const noexcept { return !(*this < other); }
    bool operator==(const Fraction &other) const noexcept {
        auto t = (*this).reducted();
        auto s = other.reducted();
        return (t.p == s.p && t.q == s.q);
    }
    Fraction operator*(const Fraction &other) noexcept {
        p *= other.p;
        q *= other.q;
        return *this;
    }
    void reduction() noexcept {
        long long r = std::gcd(p, q);
        p /= r;
        q /= r;
    }
    Fraction reducted() const noexcept {
        Fraction ret(p, q);
        ret.reduction();
        return ret;
    }
};
