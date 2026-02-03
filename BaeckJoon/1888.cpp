#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int wall[100][100];
int next_wall[100][100];
int m, n;

// 덩어리 체크용 (8방향: 상하좌우 + 대각선)
int dy8[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx8[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool OOB(int y, int x) {
    return y >= m || y < 0 || x >= n || x < 0;
}

int countGroups() {
    bool visited[100][100] = { false };
    int groups = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (wall[i][j] > 0 && !visited[i][j]) {
                groups++;
                queue<pair<int, int>> bq;
                bq.push({ i, j });
                visited[i][j] = true;

                while (!bq.empty()) {
                    pair<int, int> cur = bq.front();
                    bq.pop();

                    for (int d = 0; d < 8; d++) {
                        int ny = cur.first + dy8[d];
                        int nx = cur.second + dx8[d];
                        if (!OOB(ny, nx) && wall[ny][nx] > 0 && !visited[ny][nx]) {
                            visited[ny][nx] = true;
                            bq.push({ ny, nx });
                        }
                    }
                }
            }
        }
    }
    return groups;
}

// 하루 동안의 확산을 처리하는 함수
void spread() {
    memset(next_wall, 0, sizeof(next_wall));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (wall[i][j] > 0) {
                int k = wall[i][j];
                // (2k+1) x (2k+1) 영역 확산
                for (int r = i - k; r <= i + k; r++) {
                    for (int c = j - k; c <= j + k; c++) {
                        if (OOB(r, c)) continue;
                        // 여러 곰팡이가 겹치면 가장 큰 속도를 저장
                        next_wall[r][c] = max(next_wall[r][c], k);
                    }
                }
            }
        }
    }
    // 다음 날 상태를 원본에 복사
    memcpy(wall, next_wall, sizeof(wall));
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> m >> n)) return 0;

    bool has_mold = false;
    for (int i = 0; i < m; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            wall[i][j] = row[j] - '0';
            if (wall[i][j] > 0) has_mold = true;
        }
    }

    // 곰팡이가 아예 없는 경우 0 출력
    if (!has_mold) {
        cout << 0 << "\n";
        return 0;
    }

    int days = 0;
    while (true) {
        int groups = countGroups();

        // 덩어리가 1개 이하면 종료
        if (groups <= 1) {
            cout << days << "\n";
            break;
        }

        // 확산 진행
        spread();
        days++;
    }

    return 0;
}