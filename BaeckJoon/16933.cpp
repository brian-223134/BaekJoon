#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;
int n, m, k;

char arr[1000][1000];
// visited 배열을 4차원으로 변경
// visited[y][x][벽 부순 횟수][0: 밤, 1: 낮]
bool visited[1000][1000][11][2];

// 상하좌우 이동
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

typedef struct status
{
    int y, x, broke, time;
} status;

bool OOB(int y, int x)
{
    return y >= n || x >= m || y < 0 || x < 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = temp[j];
        }
    }

    queue<status> q;

    // 시작 상태: (0,0), 벽 0개 부숨, 시간 1 (낮)
    q.push({ 0, 0, 0, 1 });
    visited[0][0][0][1] = true; // [y][x][broke][is_morning=1]

    while (!q.empty())
    {
        status cur = q.front(); q.pop();

        if (cur.y == n - 1 && cur.x == m - 1)
        {
            cout << cur.time << '\n';
            return 0;
        }

        // 현재 상태의 낮/밤 결정 (시간이 홀수면 낮, 짝수면 밤)
        bool is_morning = (cur.time % 2 == 1);
        // 다음 상태의 낮/밤
        bool next_is_morning = !is_morning;

        // 1. 상하좌우로 이동하는 경우
        for (int i = 0; i < 4; i++)
        {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (OOB(ny, nx)) continue;

            // 빈 칸으로 이동
            if (arr[ny][nx] == '0')
            {
                if (!visited[ny][nx][cur.broke][next_is_morning])
                {
                    visited[ny][nx][cur.broke][next_is_morning] = true;
                    q.push({ ny, nx, cur.broke, cur.time + 1 });
                }
            }
            // 벽을 부수고 이동 (낮인 경우에만 가능)
            else if (arr[ny][nx] == '1' && cur.broke < k && is_morning)
            {
                if (!visited[ny][nx][cur.broke + 1][next_is_morning])
                {
                    visited[ny][nx][cur.broke + 1][next_is_morning] = true;
                    q.push({ ny, nx, cur.broke + 1, cur.time + 1 });
                }
            }
        }

        // 2. 제자리에서 기다리는 경우 (밤 -> 낮을 만들기 위함)
        if (!visited[cur.y][cur.x][cur.broke][next_is_morning])
        {
            visited[cur.y][cur.x][cur.broke][next_is_morning] = true;
            q.push({ cur.y, cur.x, cur.broke, cur.time + 1 });
        }
    }

    cout << -1 << '\n';
    return 0;
}