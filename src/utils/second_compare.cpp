#include "base.hpp"

struct second_compare {
    template<typename T, typename U>
    bool operator() (const pair<T, U> a, const pair<T, U> b) noexcept {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        else {
            return true;
        }
    }
};
