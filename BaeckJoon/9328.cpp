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
int h, w; // h: ����, w: �ʺ�
char arr[100][100];
bool visited[100][100];

// �����¿�
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

        // ���� ���� ����
        vector<bool> has_key(26, false);
        if (!keys.empty() && keys[0] != '0') {
            for (char k : keys) has_key[k - 'a'] = true;
        }

        queue<pair<int, int>> q;
        // �� ���� ���� ��� ���� ��ġ ����
        vector<vector<pair<int, int>>> door_wait(26);

        // ���� �õ� ���� ó�� (�ܰ�/���� ��� ���� ��Ģ)
        auto try_enter = [&](int y, int x) {
            if (OOB(y, x) || visited[y][x] || arr[y][x] == '*') return;

            char c = arr[y][x];
            if (is_door(c)) {
                int di = c - 'A';
                if (has_key[di]) {                // ���� ������ ���
                    visited[y][x] = true;
                    q.push({ y, x });
                }
                else {                          // ������ �� �� ���
                    door_wait[di].push_back({ y, x });
                }
            }
            else {                              // '.', '$', 'a'~'z'
                visited[y][x] = true;
                q.push({ y, x });
            }
            };

        // �ܰ����� ���� ������ ��� ���� �õ�
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
            // ����
            if (arr[y][x] == '$') {
                doc_count++;
                arr[y][x] = '.';
            }

            // ����
            if (is_key(arr[y][x])) {
                int key_idx = arr[y][x] - 'a';
                if (!has_key[key_idx]) {
                    has_key[key_idx] = true;

                    // �ش� ����� �� �� �ִ� �� �� ��� ��ǥ�� ��� Ȱ��ȭ
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

            // 4���� Ž��
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
