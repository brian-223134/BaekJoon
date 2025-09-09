#include <iostream>
#include <stack>
using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    stack<pair<int, long long>> st; // (키, 같은 키 연속 개수)
    long long answer = 0;

    // 한 쪽 방향으로 이동하면서 탐색
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        long long cnt = 1;

        // 스택 top이 현재 사람보다 작거나 같으면 pop
        while (!st.empty() && st.top().first <= h)
        {
            answer += st.top().second;
            if (st.top().first == h)
                cnt += st.top().second;
            st.pop();
        }
        // 스택이 비어있지 않으면 바로 앞 사람을 볼 수 있음
        if (!st.empty()) answer++;
        st.push({h, cnt});
    }
    cout << answer;
    return 0;
}