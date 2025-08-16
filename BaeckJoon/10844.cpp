#include <iostream>

using namespace std;

const int MOD = 1000000000;
int dp[101][10];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= 9; i++) dp[1][i] = 1;

    for (int i = 2; i <= n; i++) 
    {
        for (int j = 0; j <= 9; j++) 
        {
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
            if (j < 9) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
        }
    }

    int result = 0;
    for (int j = 0; j <= 9; j++) 
    {
        result = (result + dp[n][j]) % MOD;
    }
    cout << result;
    return 0;
}
