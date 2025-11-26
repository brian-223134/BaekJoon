#include <iostream>
#include <queue>
#include <string>

using namespace std;

char campus[600][600];
bool visited[600][600] = { false, };
int n, m;

// »óÇÏÁÂ¿ì
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

bool OOB(int y, int x)
{
    return y >= n || y < 0 || x >= m || x < 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    queue<pair<int, int>> q; // { y, x } ÁÂÇ¥

    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            campus[i][j] = temp[j];
            if (campus[i][j] == 'I')
            {
                q.push({ i, j });
                visited[i][j] = true;
            }
        }
    }

    int cnt = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (campus[cur.first][cur.second] == 'P')
        {
            cnt++;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (OOB(ny, nx)) continue;
            if (campus[ny][nx] == 'X') continue;
            if (visited[ny][nx]) continue;

            visited[ny][nx] = true;
            q.push({ ny, nx });
        }
    }

    if (cnt == 0) cout << "TT";
    else cout << cnt;

    return 0;
}