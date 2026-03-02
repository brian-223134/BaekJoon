#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    if (!(cin >> R >> C)) return 0;

    int min_val = 1001;
    int mr = 0, mc = 0;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            int joy;
            cin >> joy;
            // R, C가 모두 짝수일 때 방문하지 않을 홀수 칸(인덱스 합이 홀수) 찾기
            if ((i + j) % 2 == 1 && joy < min_val) {
                min_val = joy;
                mr = i;
                mc = j;
            }
        }
    }

    string ans = "";

    if (R % 2 == 1) {
        // 1. R이 홀수일 때
        for (int i = 0; i < R; ++i) {
            if (i % 2 == 0) ans += string(C - 1, 'R');
            else ans += string(C - 1, 'L');
            if (i != R - 1) ans += "D";
        }
    }
    else if (C % 2 == 1) {
        // 2. C가 홀수일 때
        for (int j = 0; j < C; ++j) {
            if (j % 2 == 0) ans += string(R - 1, 'D');
            else ans += string(R - 1, 'U');
            if (j != C - 1) ans += "R";
        }
    }
    else {
        // 3. R, C 모두 짝수일 때
        int r = (mr / 2) * 2;       // 제외할 칸이 포함된 2줄의 시작 행
        int c_hole = (mc / 2) * 2;  // 제외할 칸이 포함된 2x2 블록의 시작 열

        // 3-1. 제외할 칸이 있는 행 묶음 이전까지 순회 (Top)
        for (int i = 0; i < r; i += 2) {
            ans += string(C - 1, 'R') + "D" + string(C - 1, 'L') + "D";
        }

        // 3-2. 제외할 칸이 포함된 2줄 구간 순회 (Middle)
        for (int c = 0; c < c_hole; c += 2) {
            ans += "DRUR"; // 홀수 칸 이전 블록들
        }

        if (mr == r) ans += "DR"; // 구멍이 윗줄에 있으면 아래로 먼저 감
        else ans += "RD";         // 구멍이 아랫줄에 있으면 오른쪽으로 먼저 감

        for (int c = c_hole + 2; c < C; c += 2) {
            ans += "RURD"; // 홀수 칸 이후 블록들
        }

        // 3-3. 제외할 칸 구간 이후부터 끝까지 순회 (Bottom)
        for (int i = r + 2; i < R; i += 2) {
            ans += "D" + string(C - 1, 'L') + "D" + string(C - 1, 'R');
        }
    }

    cout << ans << "\n";
    return 0;
}