#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

// ����� ���� ĭ Ȥ�� �ٴ��� ĭ���θ� ������ �� ����
// ���ӵ� ��� 3���� ���� �� ����
// ������ ����� �� ��ƾ� ��

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