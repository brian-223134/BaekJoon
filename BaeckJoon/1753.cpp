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
int v, e, s;

const int INF = numeric_limits<int>::max();

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> v >> e; // 노드, 간선 개수
    cin >> s; // 시작 노드

    vector<vector<pair<int, int>>> graph(v + 1);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v,w });
    }

    vector<int> dist(v + 1, INF);
    dist[s] = 0; // 시작 노드의 가중치는 0이다.

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,s });

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < cost) continue;

        for (auto& edge : graph[now])
        {
            int next = edge.first;
            int nextCost = cost + edge.second;
            if (dist[next] > nextCost)
            {
                dist[next] = nextCost;
                pq.push({ nextCost, next });
            }
        }
    }

    for (int i = 1; i <= v; i++)
    {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }

    return 0;
}