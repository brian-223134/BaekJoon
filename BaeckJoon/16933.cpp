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
// visited �迭�� 4�������� ����
// visited[y][x][�� �μ� Ƚ��][0: ��, 1: ��]
bool visited[1000][1000][11][2];

// �����¿� �̵�
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

    // ���� ����: (0,0), �� 0�� �μ�, �ð� 1 (��)
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

        // ���� ������ ��/�� ���� (�ð��� Ȧ���� ��, ¦���� ��)
        bool is_morning = (cur.time % 2 == 1);
        // ���� ������ ��/��
        bool next_is_morning = !is_morning;

        // 1. �����¿�� �̵��ϴ� ���
        for (int i = 0; i < 4; i++)
        {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (OOB(ny, nx)) continue;

            // �� ĭ���� �̵�
            if (arr[ny][nx] == '0')
            {
                if (!visited[ny][nx][cur.broke][next_is_morning])
                {
                    visited[ny][nx][cur.broke][next_is_morning] = true;
                    q.push({ ny, nx, cur.broke, cur.time + 1 });
                }
            }
            // ���� �μ��� �̵� (���� ��쿡�� ����)
            else if (arr[ny][nx] == '1' && cur.broke < k && is_morning)
            {
                if (!visited[ny][nx][cur.broke + 1][next_is_morning])
                {
                    visited[ny][nx][cur.broke + 1][next_is_morning] = true;
                    q.push({ ny, nx, cur.broke + 1, cur.time + 1 });
                }
            }
        }

        // 2. ���ڸ����� ��ٸ��� ��� (�� -> ���� ����� ����)
        if (!visited[cur.y][cur.x][cur.broke][next_is_morning])
        {
            visited[cur.y][cur.x][cur.broke][next_is_morning] = true;
            q.push({ cur.y, cur.x, cur.broke, cur.time + 1 });
        }
    }

    cout << -1 << '\n';
    return 0;
}