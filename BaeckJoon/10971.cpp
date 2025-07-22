#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[11][11];
bool visited[11];
int answer = 1e9; // 충분히 큰 값으로 초기화

void dfs(int start, int curr, int depth, int cost) 
{
    // 종료 조건: 모든 도시를 방문했고, 시작점으로 돌아올 수 있을 때
    if (depth == n && map[curr][start] > 0) 
    {
        answer = min(answer, cost + map[curr][start]);
        return;
    }

    for (int next = 0; next < n; ++next) 
    {
        if (!visited[next] && map[curr][next] > 0) 
        {
            visited[next] = true;
            dfs(start, next, depth + 1, cost + map[curr][next]);
            visited[next] = false; // 백트래킹
        }
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> map[i][j];

    // 각 도시를 시작점으로 하여 DFS 수행
    for (int i = 0; i < n; ++i) {
        fill(visited, visited + n, false);
        visited[i] = true;
        dfs(i, i, 1, 0); // start, current, depth, cost
    }

    cout << answer << '\n';
    return 0;
}