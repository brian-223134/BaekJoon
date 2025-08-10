#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int dp[100001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    dp[0] = 0;
    for (int i = 1; i <= n; i++) 
    {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++) 
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[n];
    return 0;
}