#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int m, n; // m: 세로, n: 가로
int height[500][500];
int dp[500][500]; // dp[y][x]: (y,x)에서 목적지까지 가는 경로의 수

// 상하좌우 이동
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool OOB(int y, int x)
{
    // x의 범위를 n으로 수정
    return y < 0 || y >= m || x < 0 || x >= n;
}

// (y, x)에서 목적지까지 가는 경로의 수를 반환하는 함수
int dfs(int y, int x)
{
    // 1. 목적지에 도착한 경우: 경로 1개 추가
    if (y == m - 1 && x == n - 1)
    {
        return 1;
    }

    // 2. 이미 방문하여 계산한 적이 있는 경우: 저장된 값 반환
    if (dp[y][x] != -1)
    {
        return dp[y][x];
    }

    // 3. 처음 방문하는 경우: 경로의 수를 계산하여 dp 배열에 저장
    dp[y][x] = 0; // 현재 위치에서 목적지까지 가는 경로의 수를 0으로 초기화
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (OOB(ny, nx)) continue;

        // 현재 위치보다 더 낮은 높이로만 이동 가능
        if (height[ny][nx] < height[y][x])
        {
            // (ny, nx)에서 목적지까지 가는 경로의 수를 더해줌
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

    // dp 배열을 -1로 초기화 (아직 방문하지 않았음을 의미)
    memset(dp, -1, sizeof(dp));

    // (0,0)에서 출발하여 목적지까지 가는 경로의 수를 계산
    cout << dfs(0, 0) << '\n';

    return 0;
}