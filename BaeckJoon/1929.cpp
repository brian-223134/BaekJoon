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

    int M, N;
    if (!(cin >> M >> N)) return 0;

    if (N < 2) return 0; 
    // 2 미만이면 소수 없음
    // 소수가 없는 경우에 대한 채점 기준이 명확하지 않음
    M = max(M, 2);

    // 에라토스테네스의 체
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; (long long)i * i <= N; i++) 
    {
        if (!isPrime[i]) continue;
        for (long long j = 1LL * i * i; j <= N; j += i) 
        {
            isPrime[(size_t)j] = false;
        }
    }

    for (int i = M; i <= N; i++) 
    {
        if (isPrime[i]) cout << i << '\n';
    }

    return 0;
}