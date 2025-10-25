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

    long long n;
    if (!(cin >> n)) return 0;

    long long ans = 0;
    for (long long i = 1; i <= n; ) {
        long long q = n / i;
        long long last = n / q;
        long long cnt = last - i + 1;

        long long a = i + last;
        long long b = cnt;
        if ((a & 1LL) == 0) a /= 2;
        else b /= 2;
        long long sumRange = a * b;

        long long add = sumRange * q;
        ans += add;

        i = last + 1;
    }

    cout << ans << '\n';
    return 0;
}