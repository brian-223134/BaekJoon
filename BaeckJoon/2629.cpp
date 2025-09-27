#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 30;      // 추의 최대 개수
const int MAX_W = 15000;   // 무게의 최대 합

bool dp[MAX_N + 1][MAX_W + 1]; // dp[i][w]: i번째 추까지 사용해서 무게차 w를 만들 수 있는가
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
    dp[0][0] = true; // 아무 추도 사용하지 않았을 때 무게차 0

    for (int i = 1; i <= n; i++) 
    {
        for (int w = 0; w <= MAX_W; w++) 
        {
            if (dp[i - 1][w])
            {
                // 추를 사용하지 않는 경우
                dp[i][w] = true;
                // 추를 한쪽에 올리는 경우
                if (w + weight[i] <= MAX_W)
                    dp[i][w + weight[i]] = true;
                // 추를 반대쪽에 올리는 경우
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