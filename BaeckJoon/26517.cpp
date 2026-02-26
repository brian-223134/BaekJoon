#include <iostream>

using namespace std;

long long k;
long long a, b, c, d;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> k >> a >> b >> c >> d)) return 0;

    long long left_val = a * k + b;
    long long right_val = c * k + d;

    if (left_val == right_val)
    {
        cout << "Yes " << left_val;
    }
    else
    {
        cout << "No";
    }

    return 0;
}