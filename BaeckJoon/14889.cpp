#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int n, _min = 50000;
int s[20][20];
bool picked[20];

static int diff_score()
{
    int start = 0, link = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (picked[i] && picked[j])
            {
                start += s[i][j] + s[j][i];
            }
            else if (!picked[i] && !picked[j])
            {
                link += s[i][j] + s[j][i];
            }
        }
    }
    return abs(start - link);
}

static void track(int idx, int cnt)
{
    // 팀 한쪽 인원을 모두 채웠으면 차이 계산
    if (cnt == n / 2)
    {
        _min = min(_min, diff_score());
        return;
    }

    // idx부터 순회하며 팀원 선택
    for (int i = idx; i < n; i++)
    {
        if (picked[i]) continue;
        picked[i] = true;
        track(i + 1, cnt + 1);
        picked[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s[i][j];
        }
    }

    // 대칭 제거: 0번은 항상 선택
    picked[0] = true;
    track(1, 1);

    cout << _min;
    return 0;
}