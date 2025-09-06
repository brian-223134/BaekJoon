#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

// 상하좌우 기본 움직임
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

// '날 일'자 움직임 (1 사분면 -> 4 사분면 방향)
int dh[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dw[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int k, w, h; // k: 나이트와 같은 움직임을 보일 수 있는 경우, w: 가로 길이, h: 세로 길이
bool visited[200][200][31]; // k의 최대값이 30

char _map[200][200];

typedef struct monkey 
{
    int y, x, move, cnt;
} monkey;

bool OOB(int y, int x)
{
    return y >= h || x >= w || y < 0 || x < 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> k;
    cin >> w >> h;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> _map[i][j];

    queue<monkey> q;
    q.push({ 0,0,0,k });
    visited[0][0][k] = true;

    while (!q.empty())
    {
        monkey cur = q.front(); q.pop();
        if (cur.y == h - 1 && cur.x == w - 1) 
        {
            cout << cur.move;
            return 0;
        }
        // 말 이동
        if (cur.cnt > 0) 
        {
            for (int i = 0; i < 8; i++) 
            {
                int nh = cur.y + dh[i];
                int nw = cur.x + dw[i];
                if (OOB(nh, nw)) continue;
                if (_map[nh][nw] == '1') continue;
                if (visited[nh][nw][cur.cnt - 1]) continue;
                visited[nh][nw][cur.cnt - 1] = true;
                q.push({ nh, nw, cur.move + 1, cur.cnt - 1 });
            }
        }
        // 원숭이 이동
        for (int i = 0; i < 4; i++) 
        {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            if (OOB(ny, nx)) continue;
            if (_map[ny][nx] == '1') continue;
            if (visited[ny][nx][cur.cnt]) continue;
            visited[ny][nx][cur.cnt] = true;
            q.push({ ny, nx, cur.move + 1, cur.cnt });
        }
    }
    cout << -1;
    return 0;
}