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

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());

    vector<long long> pow2(N);
    pow2[0] = 1;
    for (int i = 1; i < N; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long add = (pow2[i] - pow2[N - 1 - i]) % MOD;
        if (add < 0) add += MOD;
        long long term = ((A[i] % MOD) * add) % MOD;
        ans += term;
        if (ans >= MOD) ans -= MOD;
        if (ans < 0) ans += MOD;
    }

    cout << (ans % MOD + MOD) % MOD << '\n';
    return 0;
}