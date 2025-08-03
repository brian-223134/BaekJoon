#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Meeting
{
    int t, p;
    bool possible;
} Meeting;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<Meeting> meeting(n + 1);
    for (int i = 1; i <= n; i++) 
    {
        cin >> meeting[i].t >> meeting[i].p;
        // 가능한지 여부 미리 체크
        meeting[i].possible = (i + meeting[i].t <= n + 1);
    }

    vector<int> dp(n + 2, 0); // dp[i] = i일부터 얻을 수 있는 최대 수익

    // 뒤에서부터 계산
    for (int i = n; i >= 1; i--) 
    {
        if (meeting[i].possible) 
        {
            dp[i] = max(dp[i + 1], meeting[i].p + dp[i + meeting[i].t]);
        }
        else 
        {
            dp[i] = dp[i + 1]; // 상담 불가 → 다음 날로 넘어감
        }
    }

    cout << dp[1] << "\n"; // 1일부터 시작했을 때 최대 수익
    return 0;
}