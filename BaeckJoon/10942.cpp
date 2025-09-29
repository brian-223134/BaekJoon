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
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    // DP ���̺� ���� �� �ʱ�ȭ
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // ���� 1 (�ڱ� �ڽ�)
    for (int i = 1; i <= n; i++)
        dp[i][i] = 1;

    // ���� 2
    for (int i = 1; i < n; i++)
        if (nums[i] == nums[i + 1])
            dp[i][i + 1] = 1;

    // ���� 3 �̻�
    for (int len = 3; len <= n; len++)
    {
        for (int s = 1; s <= n - len + 1; s++)
        {
            int e = s + len - 1;
            if (nums[s] == nums[e] && dp[s + 1][e - 1])
                dp[s][e] = 1;
        }
    }

    int q; // query Ƚ��
    cin >> q;
    vector<pair<int, int>> query(q); // {S, E}
    for (int i = 0; i < q; i++)
    {
        cin >> query[i].first >> query[i].second;
    }

    // ���� ó��
    for (int i = 0; i < q; i++)
    {
        int s = query[i].first;
        int e = query[i].second;
        cout << dp[s][e] << '\n';
    }

    return 0;
}