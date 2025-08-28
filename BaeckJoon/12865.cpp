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
// dp[i][j]: i ��° ���Ǳ��� ������� ��, �ӽ� �뷮�� j�� �� ���� �� �ִ� �ִ� ��ġ

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k;
    cin >> n >> k; // n: ���� ����, k: ���� �� �ִ� ���� ��
    vector<pair<int, int>> bag(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> bag[i].first >> bag[i].second; // {����, ��ġ}
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