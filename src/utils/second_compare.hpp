#include <utility>

/// start
/// @prefix cpSecondCompare
/// @description std::pair の second で比較を行う関数オブジェクト
/// @isFileTemplate false
struct second_compare {
    template<typename T, typename U>
    inline constexpr bool operator() (const std::pair<T, U> a, const std::pair<T, U> b) const noexcept {
        return (a.second != b.second ? a.second < b.second : a.first < b.first);
    }
};
