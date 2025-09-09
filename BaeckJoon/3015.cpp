#include <iostream>
#include <stack>
using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    stack<pair<int, long long>> st; // (Ű, ���� Ű ���� ����)
    long long answer = 0;

    // �� �� �������� �̵��ϸ鼭 Ž��
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        long long cnt = 1;

        // ���� top�� ���� ������� �۰ų� ������ pop
        while (!st.empty() && st.top().first <= h)
        {
            answer += st.top().second;
            if (st.top().first == h)
                cnt += st.top().second;
            st.pop();
        }
        // ������ ������� ������ �ٷ� �� ����� �� �� ����
        if (!st.empty()) answer++;
        st.push({h, cnt});
    }
    cout << answer;
    return 0;
}