#include <iostream>
#include <algorithm>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    long long d, p, q;
    cin >> d >> p >> q;

    if (p > q) swap(p, q); // p�� �� �۰�

    long long answer = 1e18;
    // q�� 0~p-1�� ���� ��, ���� �ݾ��� p�� ä��� ���
    for (long long i = 0; i < p; i++) 
    {
        long long sum = d - i * q;
        if (sum <= 0)
        {
            answer = min(answer, i * q);
            break;
        }
        long long cnt = (sum + p - 1) / p; // �ø�
        answer = min(answer, i * q + cnt * p);
    }
    cout << answer;
    return 0;
}