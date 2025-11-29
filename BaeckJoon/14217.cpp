#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int n, m; // n: 도시 개수, m: 도로 개수
int q; // 정비 예정인 도로 수

static vector<unordered_set<int>> adj;

vector<int> bfs_from_1() {
    vector<int> dist(n + 1, -1);
    queue<int> qu;
    dist[1] = 0;
    qu.push(1);
    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                qu.push(v);
            }
        }
    }
    return dist;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    adj.assign(n + 1, unordered_set<int>());

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        if (u == v) continue;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {
        int op, u, v; cin >> op >> u >> v;
        if (u == v) {
            // 자기 자신 간선은 무시
        } else if (op == 1) {
            // 도로 추가
            adj[u].insert(v);
            adj[v].insert(u);
        } else if (op == 2) {
            // 도로 제거
            adj[u].erase(v);
            adj[v].erase(u);
        }
        // 변경 후 BFS 수행 및 출력
        vector<int> dist = bfs_from_1();
        for (int city = 1; city <= n; ++city) {
            cout << dist[city] << (city == n ? '\n' : ' ');
        }
    }

    return 0;
}