#include "graph.hpp"

void dijkstra(const WeightedGraph &g, int s, vector<ll> &dist) {
    int n = g.size();
    dist.resize(n, INF64);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[s] = 0;
    pq.emplace(dist[s], s);
    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (auto &e : g[v]) {
            if (dist[e.to] > dist[v] + e.w) {
                dist[e.to] = dist[v] + e.w;
                pq.emplace(dist[e.to], e.to);
            }
        }
    }
}

void dijkstra(const WeightedGraph &G, int s, vector<ll> &dis, vector<int> &prev) {
    int N = G.size();
    dis.resize(N, INF64);
    prev.resize(N, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; 
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.w) {
                dis[e.to] = dis[v] + e.w;
                prev[e.to] = v;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}