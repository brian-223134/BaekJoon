#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int map[1001][1001];
bool visited[1001][1001];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int n, m;

bool OOB(int y, int x) 
{
    return y >= n || x >= m || y < 0 || x < 0;
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    queue<tuple<int, int, int>> q;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> map[i][j];
            if (map[i][j] == 2) 
            {
                q.push({ i,j,0 });
                visited[i][j] = true;
                map[i][j] = 0; // 시작점 거리 = 0
            }
        }
    }

    while (!q.empty()) 
    {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int dist = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) 
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (OOB(ny, nx)) continue;
            if (!visited[ny][nx] && map[ny][nx] == 1) 
            {
                visited[ny][nx] = true;
                map[ny][nx] = dist + 1;
                q.push({ ny, nx, dist + 1 });
            }
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (map[i][j] == 1 && !visited[i][j]) map[i][j] = -1;
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}