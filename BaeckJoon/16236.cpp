#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int map[20][20];
int n;

pair<int, int> tracker(int y, int x, int shark_size, int& dist) 
{
    vector<vector<int>> visited(n, vector<int>(n, 0));
    queue<pair<pair<int, int>, int>> q;
    q.push({{y, x}, 0});
    visited[y][x] = 1;

    vector<pair<int, int>> candidates;
    int min_dist = 1e9;

    while (!q.empty()) 
    {
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int cd = q.front().second;
        q.pop();

        if (cd > min_dist) break;

        for (int dir = 0; dir < 4; dir++) 
        {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (visited[ny][nx]) continue;
            if (map[ny][nx] > shark_size) continue;

            visited[ny][nx] = 1;
            if (map[ny][nx] != 0 && map[ny][nx] < shark_size)
            {
                if (cd + 1 < min_dist)
                {
                    candidates.clear();
                    min_dist = cd + 1;
                }
                if (cd + 1 == min_dist)
                    candidates.push_back({ny, nx});
            }
            q.push({{ny, nx}, cd + 1});
        }
    }

    if (candidates.empty()) return {-1, -1};
    sort(candidates.begin(), candidates.end());
    dist = min_dist;
    return candidates[0];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    pair<int, int> start_pos;
    int shark_size = 2;
    int eat_cnt = 0;
    int total_time = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                start_pos = {i, j};
                map[i][j] = 0;
            }
        }

    while (true)
    {
        int dist = 0;
        pair<int, int> target = tracker(start_pos.first, start_pos.second, shark_size, dist);
        if (target.first == -1) break;
        total_time += dist;
        eat_cnt++;
        if (eat_cnt == shark_size)
        {
            shark_size++;
            eat_cnt = 0;
        }
        map[target.first][target.second] = 0;
        start_pos = target;
    }

    cout << total_time;
    return 0;
}