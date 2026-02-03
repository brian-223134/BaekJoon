#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int x, y; // 공장이 위치한 두 섬의 번호

struct Edge {
    int to;
    int weight;
};

// 최대 중량을 찾기 위한 다익스트라 함수
int solve(int start, int end, const vector<vector<Edge>>& adj) {
    // dist[i]는 시작점에서 i번 섬까지 올 수 있는 경로 중 최대 중량 제한
    vector<int> dist(n + 1, 0);
    priority_queue<pair<int, int>> pq; // {중량, 섬 번호}

    dist[start] = 2e9; // 시작점은 제한이 없으므로 매우 큰 값으로 설정
    pq.push({ 2e9, start });

    while (!pq.empty()) {
        int cur_w = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        // 이미 더 큰 중량으로 방문했다면 스킵
        if (cur_w < dist[cur_node]) continue;

        // 도착점에 도달했다면 현재까지의 최적 중량을 반환
        if (cur_node == end) return cur_w;

        for (const auto& edge : adj[cur_node]) {
            // 다음 경로로 갈 수 있는 중량은 (현재까지의 중량)과 (다리의 제한) 중 최소값
            int next_w = min(cur_w, edge.weight);

            // 만약 그 최소값이 기존에 알고 있던 dist[next] 보다 크다면 갱신
            if (next_w > dist[edge.to]) {
                dist[edge.to] = next_w;
                pq.push({ next_w, edge.to });
            }
        }
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    if (!(cin >> n >> m)) return 0;

    // 인접 리스트 구조: vector<Edge> 를 사용하여 목적지와 중량을 저장
    vector<vector<Edge>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // 양방향 연결
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }

    cin >> x >> y;

    cout << solve(x, y, adj) << "\n";

    return 0;
}