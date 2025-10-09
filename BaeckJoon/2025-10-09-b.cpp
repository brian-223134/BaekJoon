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

    long long a, b;
    cin >> a >> b;

    // 불가능 경우
    // 1) b가 2의 거듭제곱이 아님
    // 2) a == 0 이면 기약분수는 0/1만 가능 -> b == 1일 때만 가능 (빈 문자열 출력)
    // 3) a >= b (기약분수에서 a < b 여야 함) 또는 a 짝수 (b=2^k와 기약이면 a는 홀수)

    auto isPowerOfTwo = [](long long x)->bool { return x > 0 && (x & (x - 1)) == 0; };

    if (!isPowerOfTwo(b)) { cout << -1; return 0; }

    if (a == 0)
    {
        if (b == 1) 
        {
            // 0/1 -> 연산 없이 0 (빈 문자열)
            cout << '\n';
        } else {
            cout << -1;
        }
        return 0;
    }

    if (a >= b || (a & 1LL) == 0) 
    { // a >= b 이거나 a 짝수면 기약 아님
        cout << -1;
        return 0;
    }

    // k = log2(b)
    int k = 0;
    while ((1LL << k) < b) ++k; // b는 2^k

    string ans;
    ans.reserve(k + __builtin_popcountll(a));

    for (int t = 0; t < k; ++t) {
        if ( (a >> t) & 1LL ) ans += "G";
        ans += "K";
    }

    cout << ans << '\n';
    return 0;
}