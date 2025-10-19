#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

struct Edge {
    int u, v;
    int w;
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) 
    {
        int N, M, W;
        cin >> N >> M >> W;

        vector<Edge> edges;
        edges.reserve(2 * M + W);

        for (int i = 0; i < M; i++) 
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }

        for (int i = 0; i < W; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }

        vector<long long> dist(N + 1, 0);

        bool hasNegCycle = false;
        for (int i = 1; i <= N; i++)
        {
            bool updated = false;
            for (const auto& ed : edges) 
            {
                long long cand = dist[ed.u] + (long long)ed.w;
                if (dist[ed.v] > cand) {
                    dist[ed.v] = cand;
                    updated = true;
                }
            }
            if (!updated) break;
            if (i == N && updated)
            {
                hasNegCycle = true;
            }
        }

        cout << (hasNegCycle ? "YES" : "NO") << '\n';
    }

    return 0;
}