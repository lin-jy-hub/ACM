#include <bits/stdc++.h>

#include <optional>

namespace Shortest_path {
static std::vector<int> Dijkstra(
    const std::vector<std::vector<std::pair<int, int>>> &v, const int begin) {
    std::vector<int> dis(v.size(), LONG_LONG_MAX);
    std::vector<bool> vis(v.size());
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        q;
    dis[begin] = 0;
    q.push({0, begin});
    while (!q.empty()) {
        auto it = q.top();
        q.pop();
        int ds = it.first, pos = it.second;
        if (vis[pos]) continue;
        vis[pos] = true;
        for (auto i : v[pos]) {
            int p = i.first;
            int k = i.second;
            if (ds + k < dis[p]) {
                dis[p] = ds + k;
                q.push({dis[p], p});
            }
        }
    }
    return dis;
}
constexpr static void Floyd(std::vector<std::vector<int>> &v) {
    int n = v.size() - 1;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (v[i][j] > v[i][k] + v[k][j]) v[i][j] = v[i][k] + v[k][j];
            }
        }
    }
}
constexpr static void Floyd(int **v, const int n) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (v[i][j] > v[i][k] + v[k][j]) v[i][j] = v[i][k] + v[k][j];
            }
        }
    }
}
static std::optional<std::vector<int>> SPFA(
    const std::vector<std::vector<std::pair<int, int>>> &v, const int begin) {
    std::vector<int> dis(v.size(), LONG_LONG_MAX), cnt(v.size());
    std::vector<bool> vis(v.size());
    std::queue<int> q;
    dis[begin] = 0, vis[begin] = 1;
    q.push(begin);
    while (!q.empty()) {
        int u = q.front();
        q.pop(), vis[u] = 0;
        for (auto [p, w] : v[u]) {
            if (dis[p] > dis[u] + w) {
                dis[p] = dis[u] + w;
                cnt[p] = cnt[u] + 1;  // 记录最短路经过的边数
                if (cnt[p] >= v.size()) return std::nullopt;  //! ERROR
                // 在不经过负环的情况下，最短路至多经过 n - 1 条边
                // 因此如果经过了多于 n 条边，一定说明经过了负环
                if (!vis[p]) q.push(p), vis[p] = 1;
            }
        }
    }
    return dis;
}
}  // namespace Shortest_path