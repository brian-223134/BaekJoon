#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int v) {
    visited[v] = true;
    cout << v << " ";
    for (int next : graph[v]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void bfs(int v) {
    queue<int> q;
    fill(visited, visited + 1001, false);
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        cout << curr << " ";
        for (int next : graph[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // 무방향 그래프
    }

    // 작은 번호부터 방문하도록 정렬
    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    cout << "\n";
    bfs(V);

    return 0;
}