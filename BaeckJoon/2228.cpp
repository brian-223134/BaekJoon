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
const int INF = -987654321; // ����� ���� ������ �ʱ�ȭ

int num[101];
int dp[101][101]; // dp[i][j]: i��° ���ڱ��� j���� ������ ������� ���� �ִ� ��
int sum[101];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }

    // ���� �� ���
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + num[i];
    }

    // dp �迭 �ʱ�ȭ
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = INF;

    // 0���� ������ ���� 0
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // i��° ���ڸ� �������� �ʴ� ���
            dp[i][j] = dp[i - 1][j];

            // i��° ���ڸ� ������ ������ ������ �����ϴ� ���
            // k�� ������ ������ ������
            for (int k = 1; k <= i; k++)
            {
                // k-1��° ���ڱ��� j-1���� ������ ���� �ִ� �տ�
                // k���� i������ ���� ���Ѵ�.
                // (k-1)-1 = k-2��° ���ڱ��� j-1���� ������ ���� �ִ� ���� ã�ƾ� ��
                // ��, k�� 1�� ���� dp[0][j-1]�� ����ؾ� �ϹǷ� k-2�� �ƴ� k-1-1�� ���
                // k-1��° ���ڿ� k��° ���ڴ� �����ϸ� �ȵǹǷ� k-1��° ���ڱ��� ����
                // ���� ����ϰ�, k-1��° ���ڸ� ������ k��° ���ں��� ���ο� ������ ����
                if (k >= 2 && dp[k - 2][j - 1] != INF)
                {
                    dp[i][j] = max(dp[i][j], dp[k - 2][j - 1] + (sum[i] - sum[k - 1]));
                }
                // ù��° ������ ��� (j=1)
                else if (j == 1)
                {
                    dp[i][j] = max(dp[i][j], sum[i] - sum[k - 1]);
                }
            }
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}