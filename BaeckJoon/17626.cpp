#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <cmath>

using namespace std;

// 어떤 수 n의 제곱수의 합 표현 방식
// sqrt(n)보다 작은 수의 제곱을 뺀 수가 제곱수인지 확인하기

// n = 110인 경우, root(110)은 10.xxx
// 110 = 100 + 10 = 81 + 29 = 64 + 46 ... = 1 + 109
// dp[n] = min(dp[temp = (int)sqrt(n) 이하의 자연수의 제곱] + dp[n - temp])

int dp[50001]; // 제곱수의 합으로 표현되는 최소 개수

bool can_sqrt(int n)
{
    int temp = (int)sqrt(n);
    return n == temp * temp;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    dp[1] = 1; dp[2] = 2; dp[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        if (can_sqrt(i))
        {
            dp[i] = 1;
            continue;
        }

        dp[i] = 100000000000000; // dp최소 갱신을 위한 임의 값

        for (int j = 1; j <= (int)sqrt(i); j++)
        {
            dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
        }
    }

    cout << dp[n];

    return 0;
}