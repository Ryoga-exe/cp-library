#pragma once
#include <type_traits>
#include <utility>
#include <algorithm>
#include <limits>

/// start
/// @prefix cpMonoidMin
/// @description Monoid::Min : モノイド (最小値)
/// @isFileTemplate false
namespace Monoid {
    template <class Type>
    struct Min {
        using value_type = Type;
        static constexpr bool Invertible = false;
        
        [[nodiscard]]
        static constexpr value_type Identity() noexcept(std::is_nothrow_default_constructible_v<value_type>) {
            return std::numeric_limits<value_type>::max();
        }

        [[nodiscard]]
        static constexpr value_type Operation(const value_type& a, const value_type& b) noexcept(noexcept(std::min(std::declval<value_type>(), std::declval<value_type>()))) {
            return std::min(a, b);
        }
    };
}
