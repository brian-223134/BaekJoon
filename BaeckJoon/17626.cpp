#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <cmath>

using namespace std;

// � �� n�� �������� �� ǥ�� ���
// sqrt(n)���� ���� ���� ������ �� ���� ���������� Ȯ���ϱ�

// n = 110�� ���, root(110)�� 10.xxx
// 110 = 100 + 10 = 81 + 29 = 64 + 46 ... = 1 + 109
// dp[n] = min(dp[temp = (int)sqrt(n) ������ �ڿ����� ����] + dp[n - temp])

int dp[50001]; // �������� ������ ǥ���Ǵ� �ּ� ����

bool can_sqrt(int n)
{
    int temp = (int)sqrt(n);
    return n == temp * temp;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    dp[1] = 1; dp[2] = 2; dp[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        if (can_sqrt(i))
        {
            dp[i] = 1;
            continue;
        }

        dp[i] = 100000000000000; // dp�ּ� ������ ���� ���� ��

        for (int j = 1; j <= (int)sqrt(i); j++)
        {
            dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
        }
    }

    cout << dp[n];

    return 0;
}