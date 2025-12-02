#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    long long a, b;
    cin >> a >> b;

    long long cnt = 1;
    while (b > a)
    {
        if (b % 10 == 1)
        {
            b = (b - 1) / 10;
            ++cnt;
        }
        else if (b % 2 == 0)
        {
            b /= 2;
            ++cnt;
        }
        else
        {
            cout << -1;
            return 0;
        }
    }

    if (b == a) cout << cnt;
    else cout << -1;
    return 0;
}