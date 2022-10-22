/// @prefix cpRound
/// @description Round : 順に、a / b の四捨五入、切り上げ、切り下げをします \n O(1)
/// @isFileTemplate false
inline constexpr long long Round(const long long a, const long long b) noexcept {
    return (a + (b / 2)) / b;
}

inline constexpr long long RoundUp(const long long a, const long long b) noexcept {
    return (a + (b - 1)) / b;
}

inline constexpr long long RoundDown(const long long a, const long long b) noexcept {
    return a / b;
}
