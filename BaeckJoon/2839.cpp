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

    int ans = -1;
    for (int five = n / 5; five >= 0; five--) 
    {
        int rem = n - 5 * five;
        if (rem % 3 == 0)
        {
            ans = five + rem / 3;
            break; // 최소 봉지 수가 보장됨
        }
    }

    cout << ans << '\n';
    return 0;
}