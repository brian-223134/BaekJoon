#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int n, m;
int arr[200][200];
int dp[200][200];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 2차원 누적합 계산
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = arr[i][j];
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
            if (i > 0 && j > 0) dp[i][j] -= dp[i-1][j-1];
        }
    }

    int _max = arr[0][0];
    // 모든 직사각형 영역 탐색
    for (int x1 = 0; x1 < n; x1++)
    {
        for (int y1 = 0; y1 < m; y1++)
        {
            for (int x2 = x1; x2 < n; x2++)
            {
                for (int y2 = y1; y2 < m; y2++)
                {
                    int sum = dp[x2][y2];
                    if (x1 > 0) sum -= dp[x1-1][y2];
                    if (y1 > 0) sum -= dp[x2][y1-1];
                    if (x1 > 0 && y1 > 0) sum += dp[x1-1][y1-1];
                    _max = max(_max, sum);
                }
            }
        }
    }

    cout << _max;
    return 0;
}