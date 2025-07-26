#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
int map[300][300];
bool visited[300][300];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

bool inRange(int y, int x) 
{
    return y >= 0 && y < n && x >= 0 && x < m;
}

void bfs(int y, int x) 
{
    queue<pair<int, int>> q;
    q.push({ y, x });
    visited[y][x] = true;

    while (!q.empty()) 
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) 
        {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if (!inRange(ny, nx)) continue;
            if (!visited[ny][nx] && map[ny][nx] > 0) 
            {
                visited[ny][nx] = true;
                q.push({ ny, nx });
            }
        }
    }
}

int count_component() 
{
    memset(visited, false, sizeof(visited));
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && map[i][j] > 0) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void) 
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    int year = 0;
    while (true) 
    {
        int comp = count_component();
        if (comp >= 2) {
            cout << year << '\n';
            break;
        }
        if (comp == 0) 
        {
            cout << 0 << '\n';
            break;
        }

        int temp[300][300] = { 0, };

        // ºù»ê ³ìÀÌ±â
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (map[i][j] > 0) 
                {
                    int water = 0;
                    for (int dir = 0; dir < 4; dir++) 
                    {
                        int ny = i + dy[dir];
                        int nx = j + dx[dir];
                        if (inRange(ny, nx) && map[ny][nx] == 0) water++;
                    }
                    temp[i][j] = max(0, map[i][j] - water);
                }
            }
        }

        memcpy(map, temp, sizeof(map));
        year++;
    }

    return 0;
}