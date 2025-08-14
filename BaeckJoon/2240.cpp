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

    int t, w; // t초 동안 자두가 떨어짐. 최대 w번만 움직이고 싶음
    // 아이는 처음에 1번 나무 아래에 있음
    cin >> t >> w;
    for (int i = 0; i < t; i++)
    {
        cin >> _move[i];
    }
    
    memset(dp, -1, sizeof(dp));

    dp[0][0][0] = 0;
    
    for (int i = 1; i <= t; i++) // 1초부터 t초까지
    {
        for (int j = 0; j <= w; j++) // 이동 횟수
        {
            for (int k = 0; k < 2; k++) // 위치(0: 1번 나무, 1: 2번 나무)
            {
                // 현재 위치에 자두가 떨어지면 1, 아니면 0
                int get = (_move[i - 1] == k + 1) ? 1 : 0;

                // 이동하지 않은 경우
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + get);

                // 이동한 경우 (이동 횟수가 1 이상일 때만)
                if (j > 0)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][1 - k] + get);
            }
        }
    }

    // t초 동안 w번 이하로 이동해서 받을 수 있는 자두의 최대 개수
    int answer = 0;
    for (int j = 0; j <= w; j++)
    {
        answer = max(answer, max(dp[t][j][0], dp[t][j][1]));
    }
    cout << answer << '\n';
    return 0;
}