#pragma once
#include <type_traits>
#include <utility>

/// start
/// @prefix cpMonoidXOR
/// @description Monoid::XOR : モノイド (XOR)
/// @isFileTemplate false
namespace Monoid {
    template <class Type>
    struct XOR {
        using value_type = Type;
        static constexpr bool Invertible = true;
        
        [[nodiscard]]
        static constexpr value_type Identity() noexcept(std::is_nothrow_default_constructible_v<value_type>) {
            return value_type{};
        }

        [[nodiscard]]
        static constexpr value_type Operation(const value_type& a, const value_type& b) noexcept(noexcept(std::declval<value_type>() ^ std::declval<value_type>())) {
            return (a ^ b);
        }

        [[nodiscard]]
        static constexpr value_type Inverse(const value_type& x) noexcept(noexcept(std::declval<value_type>())) {
            return x;
        }
    };
}
