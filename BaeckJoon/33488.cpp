#include <iostream>
using namespace std;

int T, N;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> N;

        cout << "YES\n";
        for (int i = 1; i <= N; ++i)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}