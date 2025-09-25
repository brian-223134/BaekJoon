#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int t;
int h, w; // h: 높이, w: 너비
char arr[100][100];
bool visited[100][100];

// 상하좌우
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

inline bool OOB(int y, int x) {
    return y < 0 || x < 0 || y >= h || x >= w;
}

inline bool is_key(char c) {
    return c >= 'a' && c <= 'z';
}

inline bool is_door(char c) {
    return c >= 'A' && c <= 'Z';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> h >> w;

        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < h; i++) {
            string temp; cin >> temp;
            for (int j = 0; j < w; j++) arr[i][j] = temp[j];
        }

        string keys;
        cin >> keys;

        // 열쇠 보유 여부
        vector<bool> has_key(26, false);
        if (!keys.empty() && keys[0] != '0') {
            for (char k : keys) has_key[k - 'a'] = true;
        }

        queue<pair<int, int>> q;
        // 각 문에 대해 대기 중인 위치 저장
        vector<vector<pair<int, int>>> door_wait(26);

        // 진입 시도 공통 처리 (외곽/내부 모두 동일 규칙)
        auto try_enter = [&](int y, int x) {
            if (OOB(y, x) || visited[y][x] || arr[y][x] == '*') return;

            char c = arr[y][x];
            if (is_door(c)) {
                int di = c - 'A';
                if (has_key[di]) {                // 열쇠 있으면 통과
                    visited[y][x] = true;
                    q.push({ y, x });
                }
                else {                          // 없으면 문 앞 대기
                    door_wait[di].push_back({ y, x });
                }
            }
            else {                              // '.', '$', 'a'~'z'
                visited[y][x] = true;
                q.push({ y, x });
            }
            };

        // 외곽에서 진입 가능한 모든 지점 시도
        for (int i = 0; i < h; i++) {
            try_enter(i, 0);
            try_enter(i, w - 1);
        }
        for (int j = 0; j < w; j++) {
            try_enter(0, j);
            try_enter(h - 1, j);
        }

        int doc_count = 0;

        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            // 문서
            if (arr[y][x] == '$') {
                doc_count++;
                arr[y][x] = '.';
            }

            // 열쇠
            if (is_key(arr[y][x])) {
                int key_idx = arr[y][x] - 'a';
                if (!has_key[key_idx]) {
                    has_key[key_idx] = true;

                    // 해당 열쇠로 열 수 있는 문 앞 대기 좌표를 모두 활성화
                    for (auto& pos : door_wait[key_idx]) {
                        int py = pos.first, px = pos.second;
                        if (!visited[py][px]) {
                            visited[py][px] = true;
                            q.push(pos);
                        }
                    }
                    door_wait[key_idx].clear();
                }
                arr[y][x] = '.';
            }

            // 4방향 탐색
            for (int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if (OOB(ny, nx) || visited[ny][nx] || arr[ny][nx] == '*') continue;

                char c = arr[ny][nx];
                if (is_door(c)) {
                    int di = c - 'A';
                    if (has_key[di]) {
                        visited[ny][nx] = true;
                        q.push({ ny, nx });
                    }
                    else {
                        door_wait[di].push_back({ ny, nx });
                    }
                }
                else {
                    visited[ny][nx] = true;
                    q.push({ ny, nx });
                }
            }
        }

        cout << doc_count << '\n';
    }

    return 0;
}
