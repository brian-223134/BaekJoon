#include <iostream>
#include <algorithm>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    long long d, p, q;
    cin >> d >> p >> q;

    if (p > q) swap(p, q); // p가 더 작게

    long long answer = 1e18;
    // q로 0~p-1번 더한 뒤, 남은 금액을 p로 채우는 방식
    for (long long i = 0; i < p; i++) 
    {
        long long sum = d - i * q;
        if (sum <= 0)
        {
            answer = min(answer, i * q);
            break;
        }
        long long cnt = (sum + p - 1) / p; // 올림
        answer = min(answer, i * q + cnt * p);
    }
    cout << answer;
    return 0;
}