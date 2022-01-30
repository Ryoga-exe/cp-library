#include "graph.hpp"

void dijkstra(const WeightedGraph& g, int s, vector<ll>& dist) {
    int n = g.size();
    dist.assign(n, INF64);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    dist[s] = 0;
    que.emplace(dist[s], s);
    while(!que.empty()) {
        auto [p, v] = que.top();
        que.pop();
        if (dist[v] < p) continue;
        for (auto& [to, w] : g[v]) {
            if (chmin(dist[to], dist[v] + w)) {
                que.emplace(dist[to], to);
            }
        }
    }
}

void dijkstra(const WeightedGraph& g, int s, vector<ll>& dist, vector<int>& prev) {
    int n = g.size();
    dist.assign(n, INF64);
    prev.assign(n, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que; 
    dist[s] = 0;
    que.emplace(dist[s], s);
    while (!que.empty()) {
        auto [p, v] = que.top();
        que.pop();
        if (dist[v] < p) continue;
        for (auto& [to, w] : g[v]) {
            if (chmin(dist[to], dist[v] + w)) {
                prev[to] = v;
                que.emplace(dist[to], to);
            }
        }
    }
}
