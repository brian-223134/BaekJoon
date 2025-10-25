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

    int n;
    while (cin >> n) {
        if (n % 2 == 0 || n % 5 == 0) {
            cout << 0 << '\n';
            continue;
        }

        int len = 1;
        int rem = 1 % n;
        while (rem != 0) {
            rem = (rem * 10 + 1) % n;
            ++len;
        }
        cout << len << '\n';
    }

    return 0;
}