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
    // 2 �̸��̸� �Ҽ� ����
    // �Ҽ��� ���� ��쿡 ���� ä�� ������ ��Ȯ���� ����
    M = max(M, 2);

    // �����佺�׳׽��� ü
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