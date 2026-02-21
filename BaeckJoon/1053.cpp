#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int solve(const string& s)
{
    int n = (int)s.size();
    int d[51][51];
    memset(d, 0, sizeof(d));

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;

            if (s[i] == s[j])
            {
                d[i][j] = d[i + 1][j - 1];
            }
            else
            {
                int insertOrDelete = min(d[i + 1][j], d[i][j - 1]) + 1;
                int replace = d[i + 1][j - 1] + 1;
                d[i][j] = min(insertOrDelete, replace);
            }
        }
    }

    return d[0][n - 1];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;

    int n = (int)s.size();
    int ans = solve(s);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
                continue;

            swap(s[i], s[j]);
            ans = min(ans, solve(s) + 1);
            swap(s[i], s[j]);
        }
    }

    cout << ans << "\n";

    return 0;
}