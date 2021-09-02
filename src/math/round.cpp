#include "base.hpp"

inline ll Round(ll a, ll b) {
    return (a + (b / 2)) / b;
}

inline ll RoundUp(ll a, ll b) {
    return (a + (b - 1)) / b;
}

inline ll RoundDown(ll a, ll b) {
    return a / b;
}