#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int m, n; // m: ����, n: ����
int height[500][500];
int dp[500][500]; // dp[y][x]: (y,x)���� ���������� ���� ����� ��

// �����¿� �̵�
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool OOB(int y, int x)
{
    // x�� ������ n���� ����
    return y < 0 || y >= m || x < 0 || x >= n;
}

// (y, x)���� ���������� ���� ����� ���� ��ȯ�ϴ� �Լ�
int dfs(int y, int x)
{
    // 1. �������� ������ ���: ��� 1�� �߰�
    if (y == m - 1 && x == n - 1)
    {
        return 1;
    }

    // 2. �̹� �湮�Ͽ� ����� ���� �ִ� ���: ����� �� ��ȯ
    if (dp[y][x] != -1)
    {
        return dp[y][x];
    }

    // 3. ó�� �湮�ϴ� ���: ����� ���� ����Ͽ� dp �迭�� ����
    dp[y][x] = 0; // ���� ��ġ���� ���������� ���� ����� ���� 0���� �ʱ�ȭ
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (OOB(ny, nx)) continue;

        // ���� ��ġ���� �� ���� ���̷θ� �̵� ����
        if (height[ny][nx] < height[y][x])
        {
            // (ny, nx)���� ���������� ���� ����� ���� ������
            dp[y][x] += dfs(ny, nx);
        }
    }

    return dp[y][x];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> height[i][j];
        }
    }

    // dp �迭�� -1�� �ʱ�ȭ (���� �湮���� �ʾ����� �ǹ�)
    memset(dp, -1, sizeof(dp));

    // (0,0)���� ����Ͽ� ���������� ���� ����� ���� ���
    cout << dfs(0, 0) << '\n';

    return 0;
}