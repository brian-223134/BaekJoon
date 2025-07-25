#include <iostream>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 1000;

int w, h;
char building[MAX][MAX];
bool visited[MAX][MAX];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> w >> h;

        queue<pair<int, int>> fire_q;
        queue<pair<pair<int, int>, int>> person_q;

        // 입력 초기화
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> building[i][j];
                if (building[i][j] == '*')
                {
                    fire_q.push({ i, j });
                }
                if (building[i][j] == '@')
                {
                    person_q.push({ { i, j }, 0 });
                    visited[i][j] = true;
                }
            }
        }

        bool escaped = false;
        int answer = -1;

        memset(visited, false, sizeof(visited));

        while (!person_q.empty())
        {
            // 불 먼저 확산
            int fire_size = fire_q.size();
            for (int i = 0; i < fire_size; i++)
            {
                int y = fire_q.front().first;
                int x = fire_q.front().second;
                fire_q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];

                    if (ny < 0 || ny >= h || nx < 0 || nx >= w)
                        continue;
                    if (building[ny][nx] == '#' || building[ny][nx] == '*')
                        continue;

                    building[ny][nx] = '*';
                    fire_q.push({ ny, nx });
                }
            }

            // 사람 이동
            int person_size = person_q.size();
            for (int i = 0; i < person_size; i++)
            {
                int y = person_q.front().first.first;
                int x = person_q.front().first.second;
                int t = person_q.front().second;
                person_q.pop();

                // 탈출 조건: 현재 위치가 경계
                if (y == 0 || y == h - 1 || x == 0 || x == w - 1)
                {
                    escaped = true;
                    answer = t + 1;
                    break;
                }

                for (int dir = 0; dir < 4; dir++)
                {
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];

                    if (ny < 0 || ny >= h || nx < 0 || nx >= w)
                        continue;
                    if (building[ny][nx] != '.' || visited[ny][nx])
                        continue;

                    visited[ny][nx] = true;
                    person_q.push({ { ny, nx }, t + 1 });
                }
            }

            if (escaped) break;
        }

        if (escaped)
        {
            cout << answer << '\n';
        }
        else {
            cout << "IMPOSSIBLE\n";
        }

        // 초기화 (visited, building)
        while (!fire_q.empty()) fire_q.pop();
        while (!person_q.empty()) person_q.pop();
        memset(building, 0, sizeof(building));
        memset(visited, false, sizeof(visited));
    }

    return 0;
}