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
    int n;
    cin >> n;
    if (n % 2 == 1)
    {
        cout << 0;
        return 0;
    } // 홀수면 불가능

    vector<long long> dp(n + 1, 0);
    dp[0] = 1; dp[2] = 3;

    // 점화식을 설계 시 i가 2씩 증가할 때 특이 케이스가 2종류 발생
    for (int i = 4; i <= n; i += 2)
    {
        dp[i] = dp[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2)
        {
            dp[i] = dp[i] + (dp[j] * 2);
        }
    }

    cout << dp[n];
    return 0;
}