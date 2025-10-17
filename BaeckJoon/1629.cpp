#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;
typedef long long ll;

// 단순 for문을 사용시 b가 2억번에 가까워질수록 시간이 오래걸림.
// a^b % c를 O(log b)로 계산
ll power(ll a, ll b, ll c)
{
    a %= c;
    ll result = 1 % c;
    while (b > 0)
    {
        if (b & 1) result = (result * a) % c;
        a = (a * a) % c;
        b >>= 1;
    }
    return result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll a, b, c;
    cin >> a >> b >> c;

    cout << power(a, b, c) << '\n';

    return 0;
}