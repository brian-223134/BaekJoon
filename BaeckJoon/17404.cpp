#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

const int INF = 1e9 + 7;
int n;

int arr[1000][3];
int dp[1000][3];

// i��° ���� 2�� ���� (������ 0, 1, 2�� ����) ���� ��
// i-1��° ���� i + 1��° ���� 1�� Ȥ�� 3�� ���� ����
// dp[i][j] = arr[i][j] + min(dp[i - 1][(j+1)%3], dp[i - 1][(j+2)%3])

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    int answer = INF;
    // ù ��° ���� ���� 0, 1, 2�� ���� ����
    for (int first = 0; first < 3; first++)
    {
        // dp �迭 �ʱ�ȭ
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                dp[i][j] = INF;

        // ù ��° ���� ���� first�� ����
        dp[0][first] = arr[0][first];

        // ������ ���� �Ұ����ϰ� ����
        for (int j = 0; j < 3; j++)
            if (j != first) dp[0][j] = INF;

        // DP ����
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = arr[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = arr[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = arr[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }

        // ������ ���� ���� ù ��° ���� �ٸ� ���� ���� �ĺ��� ���
        for (int last = 0; last < 3; last++)
        {
            if (last == first) continue;
            answer = min(answer, dp[n-1][last]);
        }
    }

    cout << answer << '\n';

    return 0;
}
