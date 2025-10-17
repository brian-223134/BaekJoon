#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    int n;
    string catag, name;

    while (T--)
    {
        map<string, int> m;
        cin >> n;
        while (n--)
        {
            cin >> name >> catag;
            if (m.find(catag) == m.end())
            {
                m.insert({ catag, 1 });
            }
            else
                m[catag]++;
        }

        int ans = 1;
        for (auto i : m)
        {
            ans *= (i.second + 1);
        }
        ans -= 1;
        cout << ans << '\n';
    }

    return 0;
}