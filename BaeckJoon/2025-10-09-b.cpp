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

    long long a, b;
    cin >> a >> b;

    // �Ұ��� ���
    // 1) b�� 2�� �ŵ������� �ƴ�
    // 2) a == 0 �̸� ���м��� 0/1�� ���� -> b == 1�� ���� ���� (�� ���ڿ� ���)
    // 3) a >= b (���м����� a < b ���� ��) �Ǵ� a ¦�� (b=2^k�� ����̸� a�� Ȧ��)

    auto isPowerOfTwo = [](long long x)->bool { return x > 0 && (x & (x - 1)) == 0; };

    if (!isPowerOfTwo(b)) { cout << -1; return 0; }

    if (a == 0)
    {
        if (b == 1) 
        {
            // 0/1 -> ���� ���� 0 (�� ���ڿ�)
            cout << '\n';
        } else {
            cout << -1;
        }
        return 0;
    }

    if (a >= b || (a & 1LL) == 0) 
    { // a >= b �̰ų� a ¦���� ��� �ƴ�
        cout << -1;
        return 0;
    }

    // k = log2(b)
    int k = 0;
    while ((1LL << k) < b) ++k; // b�� 2^k

    string ans;
    ans.reserve(k + __builtin_popcountll(a));

    for (int t = 0; t < k; ++t) {
        if ( (a >> t) & 1LL ) ans += "G";
        ans += "K";
    }

    cout << ans << '\n';
    return 0;
}