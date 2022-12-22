#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include "WeightedGraph.hpp"

/// start
/// @prefix cpDijkstra
/// @description Dijkstra : ダイクストラ法、重みが非負数のグラフにおける単一始点最短経路問題を解きます \n O(|E|log|V|)
/// @isFileTemplate false
void Dijkstra(const WeightedGraph& g, const int s, std::vector<long long>& dist) noexcept {
    const int n = g.size();
    dist.assign(n, 1LL<<60);
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> que;
    dist[s] = 0;
    que.emplace(dist[s], s);
    while(!que.empty()) {
        auto [p, v] = que.top();
        que.pop();
        if (dist[v] < p) continue;
        for (auto& [to, w] : g[v]) {
            if (dist[to] > dist[v] + w) {
                dist[to] = dist[v] + w;
                que.emplace(dist[to], to);
                // prev[to] = v;
            }
        }
    }
}
