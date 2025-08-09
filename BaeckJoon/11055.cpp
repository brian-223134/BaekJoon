#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int arr[1001];
int dp[1001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // dp[i] = dp[max(dp[0 ~ i-1], if(arr[0 ~ i-1] < arr[i]))] + arr[i]
    dp[0] = arr[0];
    int max_dp = dp[0];
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] < arr[i]) temp = max(dp[j], temp);
        }
        dp[i] = temp + arr[i];
        max_dp = max(max_dp, dp[i]);
    }

    cout << max_dp;
    return 0;
}