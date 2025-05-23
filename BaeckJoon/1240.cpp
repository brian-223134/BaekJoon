#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1001;
vector<pair<int, int>> tree[MAX]; // (연결 노드, 거리)
bool visited[MAX];
int result;

bool dfs(int current, int target, int dist) {
    if (current == target) {
        result = dist;
        return true;
    }
    visited[current] = true;
    for (int i = 0; i < tree[current].size(); ++i) {
        int next = tree[current][i].first;
        int d = tree[current][i].second;
        if (!visited[next]) {
            if (dfs(next, target, dist + d)) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back(make_pair(v, w));
        tree[v].push_back(make_pair(u, w));
    }

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        memset(visited, false, sizeof(visited));
        dfs(a, b, 0);
        cout << result << '\n';
    }

    return 0;
}
