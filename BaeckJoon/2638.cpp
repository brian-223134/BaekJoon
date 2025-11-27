#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int grid[100][100];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

// 외부 공기 표시 배열: true면 외부 공기
bool outside[100][100];

// 외부 공기 갱신 (BFS)
void mark_outside_air() {
    memset(outside, 0, sizeof(outside));
    queue<pair<int,int>> q;
    // (0,0)은 항상 외부 공기 시작점
    q.push(make_pair(0, 0));
    outside[0][0] = true;

    while (!q.empty()) {
        pair<int,int> curr = q.front(); q.pop();
        int y = curr.first;
        int x = curr.second;
        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            // 치즈가 아닌 칸(=공기)만 외부 공기로 확장
            if (!outside[ny][nx] && grid[ny][nx] == 0) {
                outside[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

// 이번 탐색에서 녹을 치즈인지 판별 (외부 공기 기준으로 2변 이상 접촉)
bool will_be_melted(int y, int x)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        // 외부 공기만 카운트
        if (outside[ny][nx]) cnt++;
    }
    return cnt >= 2;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int hours = 0;

    while (true) {
        // 1) 외부 공기 갱신
        mark_outside_air();

        // 2) 녹을 치즈 수집
        vector<pair<int,int>> to_melt;
        int cheese_count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    cheese_count++;
                    if (will_be_melted(i, j)) {
                        to_melt.push_back(make_pair(i, j));
                    }
                }
            }
        }

        // 치즈가 더 이상 없으면 종료
        if (cheese_count == 0) break;

        // 3) 이번 시간에 녹이기
        if (!to_melt.empty()) {
            for (size_t idx = 0; idx < to_melt.size(); idx++) {
                int y = to_melt[idx].first;
                int x = to_melt[idx].second;
                grid[y][x] = 0;
            }
            hours++;
        } else {
            // 녹을 치즈가 없으면 무한루프 방지
            break;
        }
    }

    cout << hours << '\n';
    return 0;
}