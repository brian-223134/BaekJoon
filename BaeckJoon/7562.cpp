#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };

bool visited[301][301];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test;
    cin >> test;

    while (test--)
    {
        int board_size;
        int cur_y, cur_x;
        int dest_y, dest_x;
        cin >> board_size;
        cin >> cur_y >> cur_x;
        cin >> dest_y >> dest_x;

        memset(visited, false, sizeof(visited));

        queue<tuple<int, int, int> > q; // (y, x, depth)
        visited[cur_y][cur_x] = true;
        q.push(make_tuple(cur_y, cur_x, 0));

        while (!q.empty())
        {
            tuple<int, int, int> cur = q.front(); q.pop();
            int y = get<0>(cur);
            int x = get<1>(cur);
            int cnt = get<2>(cur);

            if (y == dest_y && x == dest_x)
            {
                cout << cnt << '\n';
                break;
            }

            for (int i = 0; i < 8; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= board_size || nx < 0 || nx >= board_size)
                    continue;

                if (!visited[ny][nx])
                {
                    visited[ny][nx] = true;
                    q.push(make_tuple(ny, nx, cnt + 1));
                }
            }
        }
    }

    return 0;
}