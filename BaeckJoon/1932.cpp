#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int arr[500][500];
int dp[500][500];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin >> n;

    // 직사각형 형태로 입력값을 받음
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 초기화
    dp[0][0] = arr[0][0];
    
    // 최대가 되기 위해선 dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j]
    // 만약 j == 0인 경우 dp[i][0] = dp[i-1][0] + arr[i][0]

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0) dp[i][0] = dp[i - 1][0] + arr[i][0];
            else
            {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
            }
        }
    }

    int _max = 0;
    for (int i = 0; i < n; i++)
    {
        _max = max(_max, dp[n-1][i]);
    }

    cout << _max;

    return 0;
}