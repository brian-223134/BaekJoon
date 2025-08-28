#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int dp[101][100001];
// dp[i][j]: i 번째 물건까지 고려했을 때, 임시 용량이 j일 때 담을 수 있는 최대 가치

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k;
    cin >> n >> k; // n: 물건 개수, k: 넣을 수 있는 무게 합
    vector<pair<int, int>> bag(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> bag[i].first >> bag[i].second; // {무게, 가치}
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (bag[i].first > j) dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = max(dp[i - 1][j], bag[i].second + dp[i - 1][j - bag[i].first]);
            }
        }
    }

    cout << dp[n][k];
    return 0;
}