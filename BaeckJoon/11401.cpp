#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

static const long long MOD = 1000000007LL;

long long mod_pow(long long a, long long e)
{
    long long r = 1 % MOD;
    a %= MOD;
    while (e > 0)
    {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    long long N, K;
    if (!(cin >> N >> K)) return 0;

    if (K < 0 || K > N)
    {
        cout << 0 << '\n';
        return 0;
    }

    // invfact: i!의 모듈러 곱 역원
    // nCk % MOD = fact[n] * invfact[k] % MOD * invfact[n-k] % MOD
    vector<long long> fact(N + 1), invfact(N + 1);
    fact[0] = 1;
    for (long long i = 1; i <= N; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    invfact[N] = mod_pow(fact[N], MOD - 2); // 페르마의 소정리 적용
    for (long long i = N; i >= 1; i--)
        invfact[i - 1] = (invfact[i] * i) % MOD;

    long long ans = fact[N];
    ans = (ans * invfact[K]) % MOD;
    ans = (ans * invfact[N - K]) % MOD;

    cout << ans << '\n';

    return 0;
}