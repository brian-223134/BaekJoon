#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <tuple>

using namespace std;
int n, m; // n by m matrix

int map[1001][1001];
bool visited[1001][1001][2];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

bool OOB(int y, int x)
{
    return y > n || x > m || y <= 0 || x <= 0;
}

typedef struct Node
{
    int y, x, broken, dist;
} Node;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {   
        string temp;
        cin >> temp;
        for (int j = 0; j <= m - 1; j++)
        {
            map[i][j + 1] = temp[j] - '0';
            // 0: 움직일 수 있는 곳, 1: 벽
        }
    }

    queue<Node> q;
    visited[1][1][0] = true;
    q.push({ 1,1,0,1 });

    while (!q.empty())
    {
        int y = q.front().y;
        int x = q.front().x;
        int broken = q.front().broken;
        int dist = q.front().dist;
        q.pop();

        if (y == n && x == m)
        {
            cout << dist;
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (OOB(ny, nx)) continue;

            if (map[ny][nx] == 0 && !visited[ny][nx][broken])
            {
                visited[ny][nx][broken] = true;
                q.push({ ny,nx,broken, dist + 1 });
            }
            else if (map[ny][nx] == 1 && broken == 0 && !visited[ny][nx][1]) // 벽, 아직 안 부신 경우
            {
                visited[ny][nx][1] = true;
                q.push({ ny,nx,1,dist + 1 });
            }
        }
    }

    cout << -1;
    return 0;
}
