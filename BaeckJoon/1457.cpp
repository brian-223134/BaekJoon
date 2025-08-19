#include <iostream>

using namespace std;

// a의 n제곱을 계산하는 함수
long long power(int a, int n) 
{
    long long result = 1;
    for (int i = 0; i < n; ++i) 
    {
        result *= a;
    }
    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int a, b, n;
    cin >> a >> b >> n;

    // 결과값이 int 범위를 초과할 수 있으므로 long long으로 선언
    long long sum = 0;

    // 1. Division Block을 이용해 1부터 (a+b)까지 약수 개수의 총합 계산
    for (long long i = 1, k = 1; i <= a + b; i = k + 1) 
    {
        long long val = (a + b) / i;
        k = (a + b) / val;
        sum += val * (k - i + 1);
    }

    // 2. Division Block을 이용해 1부터 (a-1)까지 약수 개수의 총합을 빼기
    if (a > 1) 
    {
        for (long long i = 1, k = 1; i < a; i = k + 1) 
        {
            long long val = (a - 1) / i;
            k = (a - 1) / val;
            sum -= val * (k - i + 1);
        }
    }

    // 3. 값 보정
    sum -= static_cast<long long>(b + 1) * 2 - (a == 1);

    // 4. 포함-배제 원리를 이용해 n제곱수 배수들을 제외
    for (int i = 2; ; ++i) 
    {
        long long pw = power(i, n);

        // pw가 범위를 벗어나면 더 이상 계산할 필요가 없음
        if (pw > a + b)
        {
            break;
        }

        long long m = (pw < a) ? (a - 1) : (pw - 1);
        sum -= (a + b) / pw - m / pw;
    }

    cout << sum << "\n";

    return 0;
}