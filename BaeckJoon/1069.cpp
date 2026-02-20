#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double X, Y, D, T;
    if (!(cin >> X >> Y >> D >> T)) return 0;

    double dist = sqrt(X * X + Y * Y);

    // 기본적으로 모두 걸어가는 경우를 초기 최솟값으로 설정
    double ans = dist;

    // 점프가 걷는 것보다 효율적인 경우
    if (T < D) {
        int n = dist / D; // 뛸 수 있는 최대 점프 횟수
        double rem = dist - n * D; // 점프 후 남은 거리

        if (n == 0) {
            // 거리가 점프 한 번 거리보다 짧을 때
            ans = min(ans, T + D - dist); // 1번 점프 후 남은 거리 걸어서 돌아오기
            ans = min(ans, 2.0 * T);      // 2번 점프하여 꺾어서 도달하기
        }
        else {
            // 점프를 1번 이상 할 수 있을 때
            ans = min(ans, n * T + rem);           // 최대한 점프 후 남은 거리 걷기
            ans = min(ans, (n + 1) * T);           // 한 번 더 점프하여 꺾어서 도달하기
        }
    }

    cout << fixed << setprecision(15) << ans << "\n";
    return 0;
}