#include <iostream>
#include <type_traits>
#include <utility>

/// start
/// @prefix cpModInt
/// @description ModInt : 自動で mod を取ってくれる構造体
/// @isFileTemplate false
template<long long m, std::enable_if_t<(1 <= m)>* = nullptr>
struct ModInt {
public:
    using value_type = unsigned long long;
    using signed_value_type = std::make_signed_t<value_type>;
private:
    value_type m_value = 0;
    static constexpr value_type umod() noexcept { return static_cast<value_type>(m); }
public:
    ModInt() = default;
    ModInt(const ModInt&) = default;
    ModInt(ModInt&&) noexcept = default;
    constexpr ModInt(const signed_value_type x) noexcept : m_value((x % m + m) % m) {}
    constexpr ModInt& operator =(const ModInt&) = default;
    constexpr ModInt& operator =(ModInt&&) noexcept = default;
    constexpr ModInt& operator =(const signed_value_type x) { m_value = (x % m + m) % m; return *this; }
    inline constexpr value_type value() const noexcept { return m_value; }
    explicit inline constexpr operator value_type() const noexcept { return m_value; }
    explicit inline constexpr operator signed_value_type() const noexcept { return static_cast<signed_value_type>(m_value); }
    explicit inline constexpr operator int() const noexcept { return static_cast<int>(m_value); }
    static ModInt raw(const value_type& x) { ModInt tmp; tmp.m_value = x; return tmp; }
    ModInt& operator++() { m_value++; if (m_value == umod()) m_value = 0; return *this; }
    ModInt& operator--() { if (m_value == 0) m_value = umod(); m_value--; return *this; }
    ModInt operator++(int) { ModInt tmp(*this); ++(*this); return tmp; }
    ModInt operator--(int) { ModInt tmp(*this); --(*this); return tmp; }
    ModInt& operator +=(const ModInt& rhs) { m_value += rhs.m_value; if (m_value >= umod()) m_value -= umod(); return *this; }
    ModInt& operator -=(const ModInt& rhs) { m_value -= rhs.m_value; if (m_value >= umod()) m_value += umod(); return *this; }
    ModInt& operator *=(const ModInt& rhs) { m_value = (m_value * rhs.m_value) % umod(); return *this; }
    ModInt& operator /=(const ModInt& rhs) { return *this = *this * rhs.inv(); }
    ModInt& operator ^=(const long long rhs) { return *this = pow(rhs); }
    ModInt operator +() const { return *this; }
    ModInt operator -() const { return ModInt() - *this; }
    ModInt pow(long long n) const {
        ModInt res(1), mul = *this;
        while(n > 0) {
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }
    ModInt inv() const {
        long long a = m_value, b = m, u = 1, v = 0;
        while(b) {
            long long t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return ModInt(u);
    }
    friend inline constexpr ModInt operator +(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) += rhs; }
    friend inline constexpr ModInt operator -(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) -= rhs; }
    friend inline constexpr ModInt operator *(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) *= rhs; }
    friend inline constexpr ModInt operator /(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) /= rhs; }
    friend inline constexpr bool operator==(const ModInt& lhs, const ModInt& rhs) { return lhs.m_value == rhs.m_value; }
    friend inline constexpr bool operator!=(const ModInt& lhs, const ModInt& rhs) { return !(lhs == rhs); }
    friend inline std::ostream& operator <<(std::ostream& out, const ModInt& mint) { return out << mint.value(); }
    friend inline std::istream& operator >>(std::istream& is, ModInt& mint) {
        long long tmp;
        is >> tmp;
        mint = ModInt(tmp);
        return is;
    }
};
