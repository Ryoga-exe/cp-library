#include <vector>

struct Edge {
    Edge(long long _to, long long _w) : to(_to), w(_w) {}
    long long to, w;
};

using WeightedGraph = std::vector<std::vector<Edge>>;
