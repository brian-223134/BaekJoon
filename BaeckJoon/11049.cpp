#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <climits>

using namespace std;

int n;
long long dp[500][500];
// dp[i][j]: i��° ��ĺ��� j��° ��ı����� ���� ���� ���� �ּ� ���� Ƚ��

int main(void)
{
    // ����� �ӵ� ���
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    vector<pair<int, int>> matrix(n);

    for (int i = 0; i < n; i++)
    {
        cin >> matrix[i].first >> matrix[i].second;
        dp[i][i] = 0; // �ڱ� �ڽŰ��� ���� ���� Ƚ�� 0
    }

    // len�� ���ϴ� ��� ü���� ���� (2���� n����)
    for (int len = 2; len <= n; len++)
    {
        // i�� ���� ����� �ε���
        for (int i = 0; i <= n - len; i++)
        {
            // j�� �� ����� �ε���
            int j = i + len - 1;


            dp[i][j] = LLONG_MAX;

            // k�� ��� ü���� ������ ���� ���� (A_i ... A_k) * (A_{k+1} ... A_j)
            for (int k = i; k < j; k++)
            {
                // ���� ���� ���� k������ ���� Ƚ��
                // DP[i][k] + DP[k+1][j] + A_i �� * A_k �� * A_j ��
                long long cost = dp[i][k] + dp[k + 1][j] + (long long)matrix[i].first * matrix[k].second * matrix[j].second;

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[0][n - 1] << "\n";

    return 0;
}