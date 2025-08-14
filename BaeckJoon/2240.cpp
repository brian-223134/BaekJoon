#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int _move[1001];
int dp[1001][31][2];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t, w; // t�� ���� �ڵΰ� ������. �ִ� w���� �����̰� ����
    // ���̴� ó���� 1�� ���� �Ʒ��� ����
    cin >> t >> w;
    for (int i = 0; i < t; i++)
    {
        cin >> _move[i];
    }
    
    memset(dp, -1, sizeof(dp));

    dp[0][0][0] = 0;
    
    for (int i = 1; i <= t; i++) // 1�ʺ��� t�ʱ���
    {
        for (int j = 0; j <= w; j++) // �̵� Ƚ��
        {
            for (int k = 0; k < 2; k++) // ��ġ(0: 1�� ����, 1: 2�� ����)
            {
                // ���� ��ġ�� �ڵΰ� �������� 1, �ƴϸ� 0
                int get = (_move[i - 1] == k + 1) ? 1 : 0;

                // �̵����� ���� ���
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + get);

                // �̵��� ��� (�̵� Ƚ���� 1 �̻��� ����)
                if (j > 0)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][1 - k] + get);
            }
        }
    }

    // t�� ���� w�� ���Ϸ� �̵��ؼ� ���� �� �ִ� �ڵ��� �ִ� ����
    int answer = 0;
    for (int j = 0; j <= w; j++)
    {
        answer = max(answer, max(dp[t][j][0], dp[t][j][1]));
    }
    cout << answer << '\n';
    return 0;
}