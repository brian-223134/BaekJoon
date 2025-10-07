#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin >> n;

    stack<int> st;
    vector<char> ops;
    int next = 1; // 다음에 push할 값

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;

        // x가 스택 top이 될 때까지 push
        while (next <= x)
        {
            st.push(next++);
            ops.push_back('+');
        }

        // 이제 top이 x여야 pop 가능
        if (st.empty() || st.top() != x)
        {
            cout << "NO\n";
            return 0;
        }
        st.pop();
        ops.push_back('-');
    }

    for (char c : ops) cout << c << '\n';
    return 0;
}