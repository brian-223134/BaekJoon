#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int lab[8][8]; // 0: 빈칸, 1: 벽, 2: 바이러스
int best = 0;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 바이러스 확산 후 안전 영역 계산
int simulate()
{
    int tmp[8][8];
    memcpy(tmp, lab, sizeof(lab));

    queue<pair<int,int>> q;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (tmp[i][j] == 2)
                q.push(pair<int,int>(i, j));

    while (!q.empty())
    {
        pair<int,int> cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;
        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (tmp[nx][ny] == 0)
            {
                tmp[nx][ny] = 2;
                q.push(pair<int,int>(nx, ny));
            }
        }
    }

    int safe = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (tmp[i][j] == 0)
                ++safe;
    return safe;
}

// 벽 3개 설치 (백트래킹)
void placeWalls(int placed, int startIndex)
{
    if (placed == 3)
    {
        best = max(best, simulate());
        return;
    }

    for (int idx = startIndex; idx < n * m; ++idx)
    {
        int x = idx / m;
        int y = idx % m;
        if (lab[x][y] != 0) continue;

        lab[x][y] = 1;
        placeWalls(placed + 1, idx + 1);
        lab[x][y] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> lab[i][j];

    placeWalls(0, 0);

    cout << best << '\n';
    return 0;
}