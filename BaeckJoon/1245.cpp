#include <iostream>
#include <vector>
using namespace std;

int map[101][71];
bool visited[101][71];
int n, m;

int dy[8] = { -1,-1,-1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool is_peak;
int height;

void dfs(int y, int x)
{
    visited[y][x] = true;

    for (int dir = 0; dir < 8; dir++)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;

        if (map[ny][nx] > height)
            is_peak = false;

        if (!visited[ny][nx] && map[ny][nx] == height)
            dfs(ny, nx);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    int result = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                is_peak = true;
                height = map[i][j];
                dfs(i, j);
                if (is_peak)
                    result++;
            }
        }
    }

    cout << result;
    return 0;
}