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
    value_type m_num = 0, m_den = 1;
    inline constexpr value_type inner_sign(const value_type x) const noexcept { return (0 < x) - (x < 0); }
    inline constexpr value_type inner_abs(const value_type x) const noexcept { return (x < 0 ? -x : x); }
public:
    Fraction() noexcept = default;
    Fraction(const Fraction&) noexcept = default;
    Fraction(Fraction&&) noexcept = default;
    explicit constexpr Fraction(const value_type num, const value_type den) noexcept {
        auto g = std::gcd(num, den);
        m_num = inner_sign(num) * inner_sign(den) * inner_abs(num) / g;
        m_den = inner_abs(den) / g;
    }
    explicit constexpr Fraction(const value_type x) noexcept { m_num = x; m_den = 1; }
    constexpr Fraction& operator =(const Fraction&) noexcept = default;
    constexpr Fraction& operator =(Fraction&&) noexcept = default;
    inline constexpr value_type num() const noexcept { return m_num; }
    inline constexpr value_type den() const noexcept { return m_den; }
    inline constexpr pair_type asPair() const noexcept { return pair_type{ m_num, m_den }; }
    inline constexpr Fraction inv() const noexcept { return Fraction{ m_den, m_num }; }
    explicit inline constexpr operator traits_type() const noexcept { return (m_den == 0 ? inner_sign(m_num) * static_cast<traits_type>(1LL << 60) : static_cast<traits_type>(m_num) / m_den); }
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
    Fraction& operator +=(const Fraction& rhs) noexcept { *this = *this + rhs; return *this; }
    Fraction& operator -=(const Fraction& rhs) noexcept { *this = *this - rhs; return *this; }
    Fraction& operator *=(const Fraction& rhs) noexcept { *this = *this * rhs; return *this; }
    Fraction& operator /=(const Fraction& rhs) noexcept { *this = *this / rhs; return *this; }
};
