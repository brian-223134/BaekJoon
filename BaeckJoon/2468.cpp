#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N;
int map[101][101];
bool visited[101][101];
int dy[4] = { -1, 1, 0, 0 }; // 상하좌우
int dx[4] = { 0, 0, -1, 1 };

void dfs(int y, int x, int h) 
{
    visited[y][x] = true;

    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
            if (!visited[ny][nx] && map[ny][nx] > h) {
                dfs(ny, nx, h);
            }
        }
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    int min_h = 101, max_h = 0;

    // 입력 받기 및 최대/최소 높이 계산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            // min_h = min(min_h, map[i][j]);
            max_h = max(max_h, map[i][j]);
        }
    }

    int result = 0;

    // 강수량 0부터 max_h까지 반복
    for (int h = 0; h <= max_h; h++) {
        // visited 초기화
        fill(&visited[0][0], &visited[0][0] + 101 * 101, false);
        int safe_zone = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && map[i][j] > h) {
                    dfs(i, j, h);
                    safe_zone++;
                }
            }
        }

        result = max(result, safe_zone);
    }

    cout << result << '\n';
    return 0;
}