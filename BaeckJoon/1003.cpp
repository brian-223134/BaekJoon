#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int test;
    cin >> test;

    int dp[2][41]; // dp[0][]: 0 Ãâ·Â È½¼ö, dp[1][]: 1 Ãâ·Â È½¼ö

    dp[0][0] = 1; dp[1][0] = 0;
    dp[0][1] = 0; dp[1][1] = 1;

    for (int i = 2; i <= 40; i++)
    {
        dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
        dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
    }

    while (test--)
    {
        int temp;
        cin >> temp;
        cout << dp[0][temp] << ' ' << dp[1][temp] << '\n';
    }

    return 0;
}
