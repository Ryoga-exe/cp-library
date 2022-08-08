#include "base.hpp"

template<long long m, std::enable_if_t<(1 <= m)>* = nullptr>
struct modint {
public:
    constexpr modint(const long long x = 0) : m_value((x % m + m) % m) {}
    constexpr long long value() const noexcept { return m_value; }
    constexpr modint pow(long long n) const noexcept {
        modint res(1), mul = *this;
        while(n > 0) {
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }
    constexpr modint inv() const noexcept {
        long long a = m_value, b = m, u = 1, v = 0;
        while(b) {
            long long t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return modint(u);
    }
    inline constexpr bool operator==(const modint& other) const noexcept { return m_value == other.m_value; }
    inline constexpr bool operator!=(const modint& other) const noexcept { return m_value != other.m_value; }
    inline constexpr modint& operator++() noexcept { m_value++; if (m_value == m) m_value = 0; return *this;}
    inline constexpr modint& operator--() noexcept { if (m_value == 0) m_value = m; m_value--; return *this;}
    inline constexpr modint& operator++(int) noexcept { modint res = *this; ++(*this); return res; }
    inline constexpr modint& operator--(int) noexcept { modint res = *this; --(*this); return res; }
    inline constexpr modint& operator=(const modint& other) noexcept { m_value = other.m_value; return *this; }
    inline constexpr modint& operator=(const long long other) noexcept { m_value = (other % m + m) % m; return *this; }
    inline constexpr modint& operator+=(const modint& other) noexcept { m_value += other.m_value; if (m_value >= m) m_value -= m; return *this; }
    inline constexpr modint& operator-=(const modint& other) noexcept { m_value -= other.m_value; if (m_value < m) m_value += m; return *this; }
    inline constexpr modint& operator*=(const modint& other) noexcept { m_value = m_value * other.m_value % m; return *this; }
    inline constexpr modint& operator/=(const modint& other) noexcept { (*this) *= other.inv(); return *this; }
    inline constexpr modint operator+(const modint& other) const noexcept { return modint(*this) += other; }
    inline constexpr modint operator-(const modint& other) const noexcept { return modint(*this) -= other; }
    inline constexpr modint operator*(const modint& other) const noexcept { return modint(*this) *= other; }
    inline constexpr modint operator/(const modint& other) const noexcept { return modint(*this) /= other; }
    inline constexpr modint operator+() const noexcept { return *this; }
    inline constexpr modint operator-() const noexcept { return modint(0) - modint(*this); }
    friend ostream &operator<<(ostream &os, const modint& p) {
        return os << p.value();
    }
    friend istream &operator>>(istream &is, modint &p) {
        long long tmp;
        is >> tmp;
        p = modint(tmp);
        return (is);
    }
private:
    long long m_value;
};
