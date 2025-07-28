#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

// 계단은 다음 칸 혹은 다다음 칸으로만 움직일 수 있음
// 연속된 계단 3개를 밟을 순 없음
// 마지막 계단은 꼭 밟아야 함

int stair[300];
int dp[300];
int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> stair[i];
    }

    dp[0] = stair[0];
    dp[1] = stair[0] + stair[1];
    dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

    for (int i = 3; i < n; i++)
    {
        dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
    }

    cout << dp[n - 1];

    return 0;
}