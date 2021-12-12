#include "base.hpp"

struct Edge {
    Edge(ll _to, ll _w) : to(_to), w(_w) {}
    ll to;
    ll w;
};

using WeightedGraph = vector<vector<Edge>>;