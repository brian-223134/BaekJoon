#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

#define INF 1e9

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < M; ++i) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    vector<long long> dist(N + 1, INF);
    dist[1] = 0; // 1번 노드에서 시작

    // N-1번 반복
    for (int i = 1; i < N; ++i)
    {
        for (auto& edge : edges)
        {
            int u, v, w;
            tie(u, v, w) = edge;
            if (dist[u] != INF && dist[v] > dist[u] + w) 
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // 음수 사이클 확인
    bool negative_cycle = false;
    for (auto& edge : edges)
    {
        int u, v, w;
        tie(u, v, w) = edge;
        if (dist[u] != INF && dist[v] > dist[u] + w) 
        {
            negative_cycle = true;
            break;
        }
    }

    if (negative_cycle) 
    {
        cout << -1 << '\n';
    } else 
    {
        for (int i = 2; i <= N; ++i) 
        {
            if (dist[i] == INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }

    return 0;
}