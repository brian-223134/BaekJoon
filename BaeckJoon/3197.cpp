#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1501;
int R, C;
char lake[MAX][MAX];
int id_map[MAX][MAX];
int parent[MAX * MAX];
bool visited[MAX][MAX];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

pair<int, int> swan1, swan2;
queue<pair<int, int>> water_q, next_water_q;

bool OOB(int y, int x) 
{
    return y < 0 || y >= R || x < 0 || x >= C;
}

int find(int u) 
{
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void union_set(int u, int v) 
{
    u = find(u);
    v = find(v);
    if (u == v) return;
    parent[u] = v;
}

void bfs_assign_id(int sy, int sx, int lake_id) 
{
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));
    visited[sy][sx] = true;
    id_map[sy][sx] = lake_id;
    parent[lake_id] = lake_id;

    while (!q.empty()) 
    {
        pair<int, int> cur = q.front(); q.pop();
        int y = cur.first, x = cur.second;
        water_q.push(make_pair(y, x));

        for (int dir = 0; dir < 4; ++dir) 
        {
            int ny = y + dy[dir], nx = x + dx[dir];
            if (OOB(ny, nx)) continue;
            if (!visited[ny][nx] && lake[ny][nx] == '.') 
            {
                visited[ny][nx] = true;
                id_map[ny][nx] = lake_id;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> R >> C;
    int lake_id = 0;
    bool swan_found = false;

    for (int i = 0; i < R; ++i) 
    {
        cin >> lake[i];
        for (int j = 0; j < C; ++j) 
        {
            if (lake[i][j] == 'L') 
            {
                if (!swan_found) 
                {
                    swan1 = make_pair(i, j);
                    swan_found = true;
                }
                else 
                {
                    swan2 = make_pair(i, j);
                }
                lake[i][j] = '.'; // L은 물로 간주
            }
        }
    }

    // 초기 물 영역 ID 부여
    for (int i = 0; i < R; ++i) 
    {
        for (int j = 0; j < C; ++j) 
        {
            if (lake[i][j] == '.' && !visited[i][j]) 
            {
                bfs_assign_id(i, j, lake_id++);
            }
        }
    }

    int swan1_id = id_map[swan1.first][swan1.second];
    int swan2_id = id_map[swan2.first][swan2.second];

    int day = 0;
    while (true) 
    {
        if (find(swan1_id) == find(swan2_id)) break;

        while (!water_q.empty()) 
        {
            pair<int, int> cur = water_q.front(); water_q.pop();
            int y = cur.first, x = cur.second;

            for (int dir = 0; dir < 4; ++dir) 
            {
                int ny = y + dy[dir], nx = x + dx[dir];
                if (OOB(ny, nx)) continue;

                if (lake[ny][nx] == 'X') 
                {
                    lake[ny][nx] = '.';

                    // 인접 물의 ID 하나 가져오기
                    int new_id = -1;
                    for (int d2 = 0; d2 < 4; d2++) 
                    {
                        int nny = ny + dy[d2], nnx = nx + dx[d2];
                        if (OOB(nny, nnx)) continue;
                        if (lake[nny][nnx] == '.') 
                        {
                            new_id = id_map[nny][nnx];
                            break;
                        }
                    }

                    id_map[ny][nx] = new_id;
                    next_water_q.push(make_pair(ny, nx));

                    // 모든 인접 물과 union
                    for (int d2 = 0; d2 < 4; d2++) 
                    {
                        int nny = ny + dy[d2], nnx = nx + dx[d2];
                        if (OOB(nny, nnx)) continue;
                        if (lake[nny][nnx] == '.') 
                        {
                            union_set(id_map[ny][nx], id_map[nny][nnx]);
                        }
                    }
                }
                else if (lake[ny][nx] == '.') 
                {
                    // 물과 물끼리 union
                    union_set(id_map[y][x], id_map[ny][nx]);
                }
            }
        }

        water_q = next_water_q;
        while (!next_water_q.empty()) next_water_q.pop();
        day++;
    }

    cout << day << "\n";
    return 0;
}