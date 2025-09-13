#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
// light[r][c]: (r, c) 방의 불이 켜져 있는지 여부
bool light[101][101];
// visited[r][c]: (r, c) 방에 방문했는지 여부
bool visited[101][101];
// switches[r][c]: (r, c) 방에서 켤 수 있는 방들의 목록
vector<pair<int, int>> switches[101][101];

// 상, 하, 좌, 우 이동을 위한 배열
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        switches[y][x].push_back({ b, a });
    }

    queue<pair<int, int>> q;

    // 시작점 (1, 1) 설정
    light[1][1] = true;
    visited[1][1] = true;
    q.push({ 1, 1 });
    int lit_rooms_count = 1;

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        int r = current.first;
        int c = current.second;

        // 1. 현재 방(r, c)에서 켤 수 있는 모든 스위치를 켠다.
        for (auto const& target_room : switches[r][c])
        {
            int target_y = target_room.first;
            int target_x = target_room.second;

            // 이미 불이 켜져 있다면 넘어간다.
            if (light[target_y][target_x]) continue;

            // 불을 켜고, 켠 방의 개수를 센다.
            light[target_y][target_x] = true;
            lit_rooms_count++;

            // 2. 새로 켠 방이 방문 가능한지 (이미 방문한 방과 인접한지) 확인한다.
            for (int i = 0; i < 4; i++)
            {
                int ny = target_y + dy[i];
                int nx = target_x + dx[i];

                if (ny >= 1 && ny <= n && nx >= 1 && nx <= n && visited[ny][nx])
                {
                    // 인접한 곳에 방문한 방이 있다면, 새로 켠 이 방도 방문할 수 있게 된다.
                    // 큐에 추가하여 탐색을 계속한다.
                    if (!visited[target_y][target_x])
                    {
                        visited[target_y][target_x] = true;
                        q.push({ target_y, target_x });
                    }
                    // 한 군데라도 연결된 것을 확인했으면 더 볼 필요 없다.
                    break;
                }
            }
        }

        // 3. 현재 방(r, c)에서 인접한, 불이 켜진 방으로 이동한다.
        for (int i = 0; i < 4; i++)
        {
            int ny = r + dy[i];
            int nx = c + dx[i];

            // 맵 범위 안에 있고, 불이 켜져 있으며, 아직 방문하지 않은 방이라면
            if (ny >= 1 && ny <= n && nx >= 1 && nx <= n && light[ny][nx] && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                q.push({ ny, nx });
            }
        }
    }

    cout << lit_rooms_count << endl;

    return 0;
}