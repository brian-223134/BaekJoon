#include <iostream>

using namespace std;

// a�� n������ ����ϴ� �Լ�
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

    // ������� int ������ �ʰ��� �� �����Ƿ� long long���� ����
    long long sum = 0;

    // 1. Division Block�� �̿��� 1���� (a+b)���� ��� ������ ���� ���
    for (long long i = 1, k = 1; i <= a + b; i = k + 1) 
    {
        long long val = (a + b) / i;
        k = (a + b) / val;
        sum += val * (k - i + 1);
    }

    // 2. Division Block�� �̿��� 1���� (a-1)���� ��� ������ ������ ����
    if (a > 1) 
    {
        for (long long i = 1, k = 1; i < a; i = k + 1) 
        {
            long long val = (a - 1) / i;
            k = (a - 1) / val;
            sum -= val * (k - i + 1);
        }
    }

    // 3. �� ����
    sum -= static_cast<long long>(b + 1) * 2 - (a == 1);

    // 4. ����-���� ������ �̿��� n������ ������� ����
    for (int i = 2; ; ++i) 
    {
        long long pw = power(i, n);

        // pw�� ������ ����� �� �̻� ����� �ʿ䰡 ����
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