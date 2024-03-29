#pragma once
#include <type_traits>
#include <utility>
#include <algorithm>
#include <limits>

/// start
/// @prefix cpMonoidMax
/// @description Monoid::Max : モノイド (最大値)
/// @isFileTemplate false
namespace Monoid {
    template <class Type>
    struct Max {
        using value_type = Type;
        static constexpr bool Invertible = false;
        
        [[nodiscard]]
        static constexpr value_type Identity() noexcept(std::is_nothrow_default_constructible_v<value_type>) {
            return std::numeric_limits<value_type>::lowest();
        }

        [[nodiscard]]
        static constexpr value_type Operation(const value_type& a, const value_type& b) noexcept(noexcept(std::max(std::declval<value_type>(), std::declval<value_type>()))) {
            return std::max(a, b);
        }
    };
}
