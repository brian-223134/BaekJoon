#include <iostream>
#include <algorithm>

using namespace std;

int t;
int stick[2][100000];
int dp[2][100000];

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                cin >> stick[i][j];

        dp[0][0] = stick[0][0];
        dp[1][0] = stick[1][0];
        dp[0][1] = stick[0][1] + dp[1][0];
        dp[1][1] = stick[1][1] + dp[0][0];

        for (int i = 2; i < n; i++) 
        {
            dp[0][i] = stick[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
            dp[1][i] = stick[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }

    return 0;
}