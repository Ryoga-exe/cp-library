#include <vector>
#include <utility>

struct UnionFind {
    std::vector<int> par;
    inline UnionFind(const size_t n) noexcept : par(n, -1) {}
    inline void reset(const size_t n) noexcept { par.assign(n, -1); }
    inline int root(const size_t x) noexcept { return (par[x] < 0 ? x : par[x] = root(par[x])); }
    inline bool unite(size_t x, size_t y) noexcept {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) std::swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    inline bool same(const size_t x, const size_t y) noexcept { return root(x) == root(y); }
    inline int size(const size_t x) noexcept { return -par[root(x)]; };
};
