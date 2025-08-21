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

    vector<int> tower(n + 1, 0); // 1번 탑부터 존재
    for (int i = 1; i <= n; i++)
    {
        cin >> tower[i];
    }
    stack<int> s;
    vector<int> result(n + 1, 0);
    for (int i = n; i > 0; i--)
    {
        while (!s.empty() && tower[s.top()] < tower[i])
        {
            result[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}