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

// i번째 집에 2번 색상 (색상은 0, 1, 2가 있음) 선택 시
// i-1번째 집과 i + 1번째 집은 1번 혹은 3번 색상 선택
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
    // 첫 번째 집의 색을 0, 1, 2로 각각 고정
    for (int first = 0; first < 3; first++)
    {
        // dp 배열 초기화
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                dp[i][j] = INF;

        // 첫 번째 집의 색을 first로 고정
        dp[0][first] = arr[0][first];

        // 나머지 색은 불가능하게 설정
        for (int j = 0; j < 3; j++)
            if (j != first) dp[0][j] = INF;

        // DP 진행
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = arr[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = arr[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = arr[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }

        // 마지막 집의 색이 첫 번째 집과 다를 때만 정답 후보로 고려
        for (int last = 0; last < 3; last++)
        {
            if (last == first) continue;
            answer = min(answer, dp[n-1][last]);
        }
    }

    cout << answer << '\n';

    return 0;
}
