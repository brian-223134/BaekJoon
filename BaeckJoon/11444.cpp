#include <iostream>
#include <utility>

using namespace std;

static const long long MOD = 1000000007LL;

/*
*   식을 2개로 분할하면 됨
* 	F(2k)   = F(k) * [2F(k+1) − F(k)]
•	F(2k+1) = F(k+1)^2 + F(k)^2
*/

// fib(n) = { F(n), F(n+1) }를 반환
pair<long long, long long> fib(long long n) 
{
    if (n == 0) return {0, 1};
    auto p = fib(n >> 1);
    long long a = p.first;   // F(k)
    long long b = p.second;  // F(k+1)

    long long two_b = (2 * b) % MOD;
    long long t = (two_b - a + MOD) % MOD;         // (2F(k+1) - F(k)) mod MOD
    long long c = (a * t) % MOD;                   // F(2k)
    long long d = ( (a * a) % MOD + (b * b) % MOD ) % MOD; // F(2k+1)

    if ((n & 1) == 0)
    {
        return {c, d};
    } 
    else 
    {
        return {d, (c + d) % MOD};
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;

    cout << fib(n).first << '\n';
    return 0;
}