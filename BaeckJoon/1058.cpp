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

    vector<string> s(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }

    int answer = 0;

    for (int i = 0; i < n; ++i)
    {
        int count = 0;
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
            {
                continue;
            }

            bool isFriend = (s[i][j] == 'Y');
            if (isFriend)
            {
                ++count;
                continue;
            }

            bool isTwoFriend = false;
            for (int k = 0; k < n; ++k)
            {
                if (k == i || k == j)
                {
                    continue;
                }

                if (s[i][k] == 'Y' && s[k][j] == 'Y')
                {
                    isTwoFriend = true;
                    break;
                }
            }

            if (isTwoFriend)
            {
                ++count;
            }
        }

        answer = max(answer, count);
    }

    cout << answer;
    return 0;
}