#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 30;      // ���� �ִ� ����
const int MAX_W = 15000;   // ������ �ִ� ��

bool dp[MAX_N + 1][MAX_W + 1]; // dp[i][w]: i��° �߱��� ����ؼ� ������ w�� ���� �� �ִ°�
int weight[MAX_N + 1];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> weight[i];

    memset(dp, 0, sizeof(dp));
    dp[0][0] = true; // �ƹ� �ߵ� ������� �ʾ��� �� ������ 0

    for (int i = 1; i <= n; i++) 
    {
        for (int w = 0; w <= MAX_W; w++) 
        {
            if (dp[i - 1][w])
            {
                // �߸� ������� �ʴ� ���
                dp[i][w] = true;
                // �߸� ���ʿ� �ø��� ���
                if (w + weight[i] <= MAX_W)
                    dp[i][w + weight[i]] = true;
                // �߸� �ݴ��ʿ� �ø��� ���
                int diff = abs(w - weight[i]);
                if (diff <= MAX_W)
                    dp[i][diff] = true;
            }
        }
    }

    int m;
    cin >> m;
    while (m--) 
    {
        int bead;
        cin >> bead;
        if (bead > MAX_W) cout << "N ";
        else if (dp[n][bead]) cout << "Y ";
        else cout << "N ";
    }
    cout << '\n';

    return 0;
}