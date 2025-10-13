#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int t[10];

int t_cnt()
{
    int cnt = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (t[i] == 0) continue;
        cnt++;
    }
    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> num(n);

    // 입력과 동시에 전체 종류 수 계산용 카운트
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        t[num[i]]++;
    }

    int kinds = t_cnt();
    if (kinds <= 2)
    {
        cout << n;
        return 0;
    }

    // 슬라이딩 윈도우용 카운트로 초기화
    memset(t, 0, sizeof(t));

    int ans = 0;
    int distinct = 0;
    int left = 0;

    for (int right = 0; right < n; right++)
    {
        // 오른쪽 확장
        if (t[num[right]]++ == 0) distinct++;

        // 종류가 2를 초과하면 왼쪽 축소
        while (distinct > 2)
        {
            if (--t[num[left]] == 0) distinct--;
            left++;
        }

        // 최대 길이 갱신
        ans = max(ans, right - left + 1);
    }

    cout << ans << '\n';
    return 0;
}
