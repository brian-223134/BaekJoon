#include <iostream>
#include <cstring>
using namespace std;

int dp[201][201];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    // dp[0][j] = 1 (0을 j개로 만드는 방법은 1가지)
    for (int j = 1; j <= k; j++) dp[0][j] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;
        }
    }

    cout << dp[n][k];
    return 0;
}