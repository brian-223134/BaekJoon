#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

void solution(int n)
{
    // n이 2 이하일 때 예외 처리
    if (n < 2) 
    {
        cout << "0\n";
        return;
    }

    // n/2 이하의 소수만 사용해도 충분하다는 수치적 근거에 따라 배열 크기 축소
    int sieve_max = n / 2;
    vector<bool> is_prime(sieve_max + 1, true);
    is_prime[0] = false;
    if (sieve_max >= 1) is_prime[1] = false;

    for (int p = 2; p * p <= sieve_max; p++) 
    {
        if (is_prime[p]) 
        {
            for (int i = p * p; i <= sieve_max; i += p)
            {
                is_prime[i] = false;
            }
        }
    }

    // 소수 벡터에 저장
    vector<int> primes;
    for (int i = 2; i <= sieve_max; i++) 
    {
        if (is_prime[i]) primes.push_back(i);
    }
    // n/2보다 큰 n 이하의 소수도 추가 (예: n이 소수일 때 자기 자신 포함)
    for (int i = sieve_max + 1; i <= n; i++) 
    {
        bool prime = true;
        for (int p : primes) 
        {
            if (1LL * p * p > i) break;
            if (i % p == 0) 
            {
                prime = false;
                break;
            }
        }
        if (prime && i > 1) primes.push_back(i);
    }

    int count = 0;
    int start = 0, end = 0, sum = 0;
    while (true) 
    {
        if (sum >= n) 
        {
            if (sum == n) count++;
            sum -= primes[start++];
        } 
        else 
        {
            if (end == primes.size()) break;
            sum += primes[end++];
        }
    }

    cout << count << '\n';
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    solution(n);

    return 0;
}