#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <limits>

using namespace std;

struct Edge
{
    int to;
    long long w;
};

struct State
{
    int node;
    int paved;
    long long cost;

    bool operator<(const State& other) const
    {
        return cost > other.cost;
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    const long long INF = numeric_limits<long long>::max() / 4;
    vector<vector<long long>> dist(n + 1, vector<long long>(k + 1, INF));

    priority_queue<State> pq;
    dist[1][0] = 0;
    pq.push({ 1, 0, 0 });

    while (!pq.empty())
    {
        State cur = pq.top();
        pq.pop();

        if (cur.cost != dist[cur.node][cur.paved])
            continue;

        for (const auto& e : graph[cur.node])
        {
            // 일반 이동
            if (dist[e.to][cur.paved] > cur.cost + e.w)
            {
                dist[e.to][cur.paved] = cur.cost + e.w;
                pq.push({ e.to, cur.paved, dist[e.to][cur.paved] });
            }

            // 포장 이동
            if (cur.paved < k && dist[e.to][cur.paved + 1] > cur.cost)
            {
                dist[e.to][cur.paved + 1] = cur.cost;
                pq.push({ e.to, cur.paved + 1, cur.cost });
            }
        }
    }

    long long ans = INF;
    for (int i = 0; i <= k; i++)
        ans = min(ans, dist[n][i]);

    cout << ans << "\n";

    return 0;
}