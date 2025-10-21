#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

using ll = long long;
const ll INF = (ll)4e18;

vector<ll> dijkstra(const vector<vector<pair<int,int>>>& adj, int n, int start) 
{
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) 
    {
        auto cur = pq.top(); pq.pop();
        ll d = cur.first;
        int u = cur.second;
        if (d != dist[u]) continue;
        for (const auto& e : adj[u]) 
        {
            int v = e.first;
            int w = e.second;
            ll nd = d + (ll)w;
            if (nd < dist[v]) 
            {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    return dist;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M, X;
    if (!(cin >> N >> M >> X)) return 0;

    vector<vector<pair<int,int>>> g(N + 1), gr(N + 1);
    for (int i = 0; i < M; i++) 
    {
        int a, b, t;
        cin >> a >> b >> t;
        g[a].push_back({b, t});
        gr[b].push_back({a, t});
    }

    auto fromX = dijkstra(g, N, X);
    auto toX = dijkstra(gr, N, X);

    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (fromX[i] == INF || toX[i] == INF) continue;
        ans = max(ans, fromX[i] + toX[i]);
    }
    cout << ans << '\n';
    return 0;
}