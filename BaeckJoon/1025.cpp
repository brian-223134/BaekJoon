#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int n, m;
int _map[10][10];

bool isPerfectSquare(int num) {
    int root = sqrt(num);
    return root * root == num;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            _map[i][j] = (int)(temp[j] - '0');
        }
    }

    int max_sq = -1;

    // 1. 시작점 (r, c) 완전 탐색
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {

            // 2. 행/열의 증감량 (dr, dc) 설정
            for (int dr = -n; dr <= n; dr++) {
                for (int dc = -m; dc <= m; dc++) {

                    // 3. 증감량이 둘 다 0이면 제자리이므로 한 번만 확인 후 스킵
                    if (dr == 0 && dc == 0) {
                        if (isPerfectSquare(_map[r][c])) {
                            max_sq = max(max_sq, _map[r][c]);
                        }
                        continue;
                    }

                    int curr_r = r;
                    int curr_c = c;
                    int current_num = 0;

                    // 4. 격자를 벗어나기 전까지 계속 이동하며 숫자 이어 붙이기
                    while (curr_r >= 0 && curr_r < n && curr_c >= 0 && curr_c < m) {
                        current_num = current_num * 10 + _map[curr_r][curr_c];

                        // 5. 숫자가 만들어질 때마다 완전제곱수인지 확인
                        if (isPerfectSquare(current_num)) {
                            max_sq = max(max_sq, current_num);
                        }

                        // 다음 칸으로 이동
                        curr_r += dr;
                        curr_c += dc;
                    }
                }
            }
        }
    }

    cout << max_sq << "\n";
    return 0;
}