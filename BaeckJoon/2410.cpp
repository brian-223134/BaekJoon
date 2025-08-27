#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

// 2^k꼴의 합으로 정수 n을 만드는 방법 구하기
// dp[1] = 1 (2^0)
// dp[2] = 2 (2^0 + 2^0, 2), dp[3] = 2 (1 * 3, 1 + 2)

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            dp[i] = (dp[i / 2] + dp[i - 1]) % 1000000000;
        }
        else
        {
            dp[i] = dp[i - 1] % 1000000000;
        }
    }

    cout << dp[n] % 1000000000;
    return 0;
}