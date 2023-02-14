#pragma once
#include <type_traits>
#include <utility>
#include <numeric>

/// start
/// @prefix cpMonoidGCD
/// @description Monoid::GCD : モノイド (最大公約数)
/// @isFileTemplate false
namespace Monoid {
    template <class Type>
    struct GCD {
        using value_type = Type;
        static constexpr bool Invertible = false;
        
        [[nodiscard]]
        static constexpr value_type Identity() noexcept(std::is_nothrow_default_constructible_v<value_type>) {
            return value_type{};
        }

        [[nodiscard]]
        static constexpr value_type Operation(const value_type& a, const value_type& b) noexcept(noexcept(std::gcd(std::declval<value_type>(), std::declval<value_type>()))) {
            return std::gcd(a, b);
        }
    };
}
