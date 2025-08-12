#include <iostream>

using namespace std;

int dp[1001][10];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // �ʱⰪ ����: 1�ڸ� ������ ���� 0~9���� 10��
    for (int j = 0; j < 10; j++)
    {
        dp[1][j] = 1;
    }

    // DP ���̺� ä���
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
            }
        }
    }

    // ��� ����� �� �ջ�
    int ans = 0;
    for (int j = 0; j < 10; j++)
    {
        ans = (ans + dp[n][j]) % 10007;
    }

    cout << ans;

    return 0;
}