#pragma once
#include <vector>
#include <utility>

/// start
/// @prefix cpSCC
/// @description 強連結成分分解
/// @isFileTemplate false
struct StronglyConnectedComponents {
public:
    using graph_type = std::vector<std::vector<int>>;

    StronglyConnectedComponents() = default;
    explicit StronglyConnectedComponents(const size_t n) : m_size(n), m_graph(n), m_revGraph(n) {}
    explicit StronglyConnectedComponents(const graph_type& g) : m_size(m_graph.size()), m_graph(g), m_revGraph(g.size()) {
        for (int i = 0; i < m_size; i++) {
            for (const auto to : g[i]) {
                m_revGraph[to].push_back(i);
            }
        }
    }
    constexpr bool isEmpty() const noexcept {
        return (m_size == 0);
    }
    constexpr size_t size() const noexcept {
        return m_size;
    }
    void addEdge(const size_t from, const size_t to) {
        m_graph[from].push_back(to);
        m_revGraph[to].push_back(from);
    }
    std::pair<graph_type, std::vector<std::vector<size_t>>> build() const {
        std::vector<bool> visited(m_size);
        std::vector<size_t> order, group(m_size);
        std::vector<std::vector<size_t>> groupList;
        auto dfs = [&](auto self, const size_t v) -> void {
            visited[v] = true;
            for (auto to : m_graph[v]) {
                if (!visited[to]) {
                    self(self, to);
                }
            }
            order.push_back(v);
        };
        auto rdfs = [&](auto self, const size_t v, int k) -> void {
            visited[v] = true;
            group[v] = k;
            groupList.back().push_back(v);
            for (auto to : m_revGraph[v]) {
                if (!visited[to]) {
                    self(self, to, k);
                }
            }
        };
        for (int i = 0; i < m_size; i++) {
            if (!visited[i]) {
                dfs(dfs, i);
            }
        }
        visited.assign(m_size, false);
        int groups = 0;
        for (int i = m_size - 1; i >= 0; i--) {
            if (!visited[order[i]]) {
                groupList.push_back({});
                rdfs(rdfs, order[i], groups++);
            }
        }
        graph_type compressedGraph(groups);
        for (int i = 0; i < m_size; i++) {
            for (auto e : m_graph[i]) {
                compressedGraph[group[i]].push_back(group[e]);
            }
        }
        return { compressedGraph, groupList };
    }
private:
    size_t m_size = 0;
    graph_type m_graph, m_revGraph;
};
