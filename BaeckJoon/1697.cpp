#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int visited[100001]; // 최대 k가 100000이므로 +1
int dist[100001];    // 각 위치까지 도달하는 데 걸리는 시간

int bfs() 
{
    queue<int> q;
    q.push(n);
    visited[n] = 1; // 방문 표시 (시간을 0으로 쓰고 싶으면 따로 관리)
    dist[n] = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (cur == k) return dist[cur]; // 도착했으면 시간 반환

        for (int next : {cur - 1, cur + 1, cur * 2}) {
            if (next < 0 || next > 100000) continue;
            if (!visited[next]) {
                visited[next] = 1;
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cout << bfs();
    return 0;
}