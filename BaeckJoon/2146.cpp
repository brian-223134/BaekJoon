#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int map[100][100];
bool visit[100][100];
int dist[100][100];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool OOB(int y, int x) {
    return y < 0 || y >= n || x < 0 || x >= n;
}

// 1�ܰ�: ���� ��ȣ �ű�� ���� BFS
void numberIsland(int y, int x, int island_id) 
{
    queue<pair<int, int>> q;
    q.push({ y, x });
    visit[y][x] = true;
    map[y][x] = island_id;

    while (!q.empty()) 
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) 
        {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];

            if (!OOB(ny, nx) && map[ny][nx] == 1 && !visit[ny][nx]) 
            {
                visit[ny][nx] = true;
                map[ny][nx] = island_id;
                q.push({ ny, nx });
            }
        }
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> map[i][j];
        }
    }

    // --- 1�ܰ�: �� ��ȣ �ű�� ---
    int island_id = 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            if (map[i][j] == 1 && !visit[i][j]) 
            {
                numberIsland(i, j, island_id++);
            }
        }
    }

    // --- 2�ܰ�: �ִ� �ٸ� ���� ã�� ---
    queue<pair<int, int>> q;
    memset(dist, -1, sizeof(dist));

    // ��� ���� ĭ�� ť�� �ְ� �Ÿ� 0���� �ʱ�ȭ
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (map[i][j] != 0) 
            {
                q.push({ i, j });
                dist[i][j] = 0;
            }
        }
    }

    int min_bridge = 987654321;

    while (!q.empty()) 
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) 
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (OOB(ny, nx)) continue;

            // �ٸ� ���� ������ ��
            if (map[ny][nx] != 0 && map[ny][nx] != map[y][x]) 
            {
                min_bridge = min(min_bridge, dist[y][x] + dist[ny][nx]);
            }
            // �ٴٸ� ������ �� (Ȯ��)
            else if (map[ny][nx] == 0 && dist[ny][nx] == -1) 
            {
                dist[ny][nx] = dist[y][x] + 1;
                map[ny][nx] = map[y][x]; // �� ���� Ȯ��
                q.push({ ny, nx });
            }
        }
    }

    cout << min_bridge << "\n";

    return 0;
}