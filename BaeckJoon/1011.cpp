#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <cmath>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        long long x, y;
        cin >> x >> y;
        long long d = y - x;

        long long n = static_cast<long long>(floor(sqrt((long double)d)));
        long long ans;
        if (d == n * n) {
            ans = 2 * n - 1;
        } else if (d <= n * n + n) {
            ans = 2 * n;
        } else {
            ans = 2 * n + 1;
        }
        cout << ans << '\n';
    }

    return 0;
}