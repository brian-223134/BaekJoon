#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;
// n * m 미로
// 시작 위치 (1,1)
// n,m으로 이동하기
// arr에 매핑 (0,0) -> (n-1,m-1)로 이동

int n, m;
int arr[1000][1000];
int dp[1000][1000];
bool visited[1000][1000];
// 아래, 우, 대각 아래로만 이동 가능
int dy[3] = { 1,0,1 };
int dx[3] = { 0,1,1 };

bool OOB(int y, int x)
{
    return y >= n || x >= m;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 초기 시작 위치
    pair<int, int> pos = { 0, 0 };
    queue<pair<int, int>> q;
    dp[0][0] = arr[0][0];
    q.push(pos);
    while (!q.empty())
    {
        pair<int, int > cur = q.front();
        q.pop();
        if (visited[cur.first][cur.second]) continue;
        visited[cur.first][cur.second] = true;
        for (int i = 0; i < 3; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (OOB(ny, nx)) continue;
            if (ny == 0)
            {
                dp[ny][nx] = arr[ny][nx] + dp[ny][nx - 1];
                q.push({ ny,nx });
            }
            else if (nx == 0)
            {
                dp[ny][nx] = arr[ny][nx] + dp[ny - 1][nx];
                q.push({ ny,nx });
            }
            else
            {
                dp[ny][nx] = arr[ny][nx] + max(dp[ny - 1][nx - 1], max(dp[ny - 1][nx], dp[ny][nx - 1]));
                q.push({ ny,nx });
            }
        }
    }
    
    cout << dp[n - 1][m - 1];

    return 0;
}