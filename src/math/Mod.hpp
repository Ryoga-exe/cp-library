/// @prefix cpMod
/// @description マイナスに対応した mod をとります \n O(1)
/// @isFileTemplate false
inline constexpr long long mod(const long long a, const long long m) noexcept {
    return (a % m + m) % m;
}
