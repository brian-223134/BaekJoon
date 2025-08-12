#include <iostream>

using namespace std;

int dp[1001][10];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 초기값 설정: 1자리 오르막 수는 0~9까지 10개
    for (int j = 0; j < 10; j++)
    {
        dp[1][j] = 1;
    }

    // DP 테이블 채우기
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
            }
        }
    }

    // 모든 경우의 수 합산
    int ans = 0;
    for (int j = 0; j < 10; j++)
    {
        ans = (ans + dp[n][j]) % 10007;
    }

    cout << ans;

    return 0;
}