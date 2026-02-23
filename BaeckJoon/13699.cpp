#include <iostream>

using namespace std;

long long t[36];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // 초기값 설정
    t[0] = 1;

    for (int i = 1; i <= n; i++) {
        // t[i] = t[0]*t[i-1] + t[1]*t[i-2] + ... + t[i-1]*t[0]
        for (int j = 0; j < i; j++) {
            t[i] += t[j] * t[i - 1 - j];
        }
    }

    cout << t[n] << '\n';

    return 0;
}