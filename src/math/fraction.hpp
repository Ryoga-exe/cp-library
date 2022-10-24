#include <cmath>
#include <numeric>
#include <utility>

/// start
/// @prefix cpFraction
/// @description Structure representing a fraction : 分数を表す構造体 (値は常に約分された状態で保持されます)
/// @isFileTemplate false
struct Fraction {
public:
    using value_type = long long;
    using traits_type = double;
    using pair_type = std::pair<value_type, value_type>;
private:
    value_type m_num = 1, m_den = 1;
    inline constexpr value_type inner_sign(const value_type x) const {
        return (0 < x) - (x < 0);
    }
public:
    Fraction() = default;
    Fraction(const Fraction&) = default;
    Fraction(Fraction&&) = default;
    explicit constexpr Fraction(value_type num, value_type den) noexcept {
        auto g = std::gcd(num, den);
        m_num = inner_sign(num) * inner_sign(den) * std::abs(num) / g;
        m_den = std::abs(den) / g;
    }
    explicit constexpr Fraction(value_type x) noexcept {
        m_num = x;
        m_den = 1;
    }
    constexpr Fraction& operator =(const Fraction&) noexcept = default;
    constexpr Fraction& operator =(Fraction&&) noexcept = default;
    inline constexpr value_type num() const noexcept { return m_num; }
    inline constexpr value_type den() const noexcept { return m_den; }
    inline constexpr pair_type asPair() const noexcept { return pair_type{ m_num, m_den }; }
    explicit inline operator traits_type() const noexcept { return (m_den == inner_sign(m_num) * static_cast<traits_type>(1LL << 60) ? : static_cast<traits_type>(m_num) / m_den); }
    Fraction& operator +=(const Fraction& rhs) noexcept {
        m_num = m_num * rhs.m_den + rhs.m_num * m_den; m_den = m_den * rhs.m_den;
        auto g = std::gcd(m_num, m_den);
        m_num /= g; m_den /= g;
        return *this;
    }
    Fraction& operator -=(const Fraction& rhs) noexcept {
        m_num = m_num * rhs.m_den - rhs.m_num * m_den; m_den = m_den * rhs.m_den;
        auto g = std::gcd(m_num, m_den);
        m_num /= g; m_den /= g;
        return *this;
    }
    Fraction& operator *=(const Fraction& rhs) noexcept {
        m_num = m_num * rhs.m_num; m_den = m_den * rhs.m_den;
        auto g = std::gcd(m_num, m_den);
        m_num /= g; m_den /= g;
        return *this;
    }
    Fraction& operator /=(const Fraction& rhs) noexcept {
        m_num = m_num * rhs.m_den; m_den = m_den * rhs.m_num;
        auto g = std::gcd(m_num, m_den);
        m_num /= g; m_den /= g;
        return *this;
    }
    friend inline constexpr Fraction operator +(const Fraction& lhs, const Fraction& rhs) noexcept { return Fraction{ lhs.m_num * rhs.m_den + rhs.m_num * lhs.m_den, lhs.m_den * rhs.m_den }; }
    friend inline constexpr Fraction operator -(const Fraction& lhs, const Fraction& rhs) noexcept { return Fraction{ lhs.m_num * rhs.m_den - rhs.m_num * lhs.m_den, lhs.m_den * rhs.m_den }; }
    friend inline constexpr Fraction operator *(const Fraction& lhs, const Fraction& rhs) noexcept { return Fraction{ lhs.m_num * rhs.m_num, lhs.m_den * rhs.m_den }; }
    friend inline constexpr Fraction operator /(const Fraction& lhs, const Fraction& rhs) noexcept { return Fraction{ lhs.m_num * rhs.m_den, lhs.m_den * rhs.m_num }; }
    friend inline constexpr bool operator ==(const Fraction& lhs, const Fraction& rhs) noexcept { return (lhs.m_num == rhs.m_num) && (lhs.m_den == rhs.m_den); }
    friend inline constexpr bool operator !=(const Fraction& lhs, const Fraction& rhs) noexcept { return !(lhs == rhs); }
    friend inline constexpr bool operator  <(const Fraction& lhs, const Fraction& rhs) noexcept { return (lhs.m_num * rhs.m_den < rhs.m_num * lhs.m_den); }
    friend inline constexpr bool operator  >(const Fraction& lhs, const Fraction& rhs) noexcept { return rhs < lhs; }
    friend inline constexpr bool operator <=(const Fraction& lhs, const Fraction& rhs) noexcept { return !(lhs > rhs); }
    friend inline constexpr bool operator >=(const Fraction& lhs, const Fraction& rhs) noexcept { return !(lhs < rhs); }
};
