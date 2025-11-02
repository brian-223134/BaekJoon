#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    queue<pair<int,int>> q;

    visited[1] = true;
    q.push(make_pair(1, 0));

    int invited = 0;
    while (!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        int u = cur.first;
        int d = cur.second;

        if (d == 2) continue;

        for (int v : adj[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            if (d + 1 <= 2) {
                ++invited;
                q.push(make_pair(v, d + 1));
            }
        }
    }

    cout << invited << '\n';
    return 0;
}