#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    long long min_surface = LLONG_MAX;
    int ans_a = 1, ans_b = 1, ans_c = n;

    // a <= b <= c 라고 가정하여 중복 계산 방지
    for (int a = 1; a * a * a <= n; ++a) {
        if (n % a == 0) {
            int remaining_vol = n / a;
            for (int b = a; b * b <= remaining_vol; ++b) {
                if (remaining_vol % b == 0) {
                    int c = remaining_vol / b;

                    // 겉넓이: (2 * (ab + bc + ca))
                    // n이 10^6이므로 겉넓이는 int 범위를 넘지 않지만, 
                    // 안전하게 long long을 사용
                    long long current_surface = 2LL * (1LL * a * b + 1LL * b * c + 1LL * c * a);

                    if (current_surface < min_surface) {
                        min_surface = current_surface;
                        ans_a = a;
                        ans_b = b;
                        ans_c = c;
                    }
                }
            }
        }
    }

    cout << ans_a << " " << ans_b << " " << ans_c << "\n";

    return 0;
}