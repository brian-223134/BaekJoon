#include<iostream>
#include<algorithm>

using namespace std;

// 다음 세 가지 연산만 가능
// 1. X mod 3 = 0 -> X = X / 3
// 2. X mod 2 = 0 -> X = X / 2
// 3. X = X - 1

// ex: 10 -> 9 -> 3 -> 1
int dp[1000000];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin >> n;

    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    cout << dp[n];
}