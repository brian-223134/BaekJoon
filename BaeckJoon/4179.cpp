#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int R, C;
char maze[1000][1000];
bool visited[1000][1000];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    queue<pair<int, int>> fire_q; // 불의 좌표를 저장
    queue<pair<pair<int, int>, int>> jihun_q; // 지훈이의 이동 좌표 및 시간
    pair<int, int> start_pos;

    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'J')
            {
                start_pos = { i, j };
                maze[i][j] = '.';
            }
            else if (maze[i][j] == 'F')
            {
                fire_q.push({ i, j });
            }
        }
    }

    jihun_q.push({ start_pos, 0 });
    visited[start_pos.first][start_pos.second] = true;

    // 지훈이의 이동 경로가 빌 때까지 loop
    while (!jihun_q.empty())
    {
        // 1. 불 먼저 퍼뜨리기 (존재하는 모든 불이 사방으로 퍼져야하기 때문에 fire queue의 size만큼 순회)
        int fire_size = fire_q.size();
        for (int i = 0; i < fire_size; i++)
        {
            int fy = fire_q.front().first;
            int fx = fire_q.front().second;
            fire_q.pop();

            for (int d = 0; d < 4; d++)
            {
                int nfy = fy + dy[d];
                int nfx = fx + dx[d];
                if (nfy < 0 || nfy >= R || nfx < 0 || nfx >= C) continue;
                if (maze[nfy][nfx] == '.' )
                {
                    maze[nfy][nfx] = 'F';
                    fire_q.push({ nfy, nfx });
                }
            }
        }

        // 2. 지훈이 이동
        int jihun_size = jihun_q.size();
        for (int i = 0; i < jihun_size; i++)
        {
            int y = jihun_q.front().first.first;
            int x = jihun_q.front().first.second;
            int cur_time = jihun_q.front().second;
            jihun_q.pop();

            // 가장자리 도달 시 탈출
            if (y == 0 || y == R - 1 || x == 0 || x == C - 1)
            {
                cout << cur_time + 1 << '\n';
                return 0;
            }

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
                if (maze[ny][nx] != '.') continue;
                if (visited[ny][nx]) continue;
                visited[ny][nx] = true;
                jihun_q.push({ { ny, nx }, cur_time + 1 });
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}