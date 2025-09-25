#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

ll n;
int p, q;
unordered_map<ll, ll> memo;

// n의 크기가 매우 크기 때문에 모든 값을 저장하는 데는 무리가 있음

ll solve(ll x) 
{
    if (x == 0) return 1;
    if (memo.count(x)) return memo[x];
    return memo[x] = solve(x / p) + solve(x / q);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> p >> q;
    cout << solve(n) << '\n';

    return 0;
}