#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int m, n, h;
int box[100][100][100];
int dz[6] = { 0,0,0,0,-1,+1 };
int dy[6] = { -1,+1,0,0,0,0 };
int dx[6] = { 0,0,-1,+1,0,0 };

struct Node {
    int z, y, x;
};

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n >> h;

    queue<tuple<int, int, int>> q;
    int unripe = 0; // 안 익은 토마토 개수

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1) {
                    q.push({ i,j,k }); // 익은 토마토는 BFS 시작점
                }
                else if (box[i][j][k] == 0) {
                    unripe++;
                }
            }
        }
    }

    if (unripe == 0) { // 처음부터 다 익음
        cout << 0;
        return 0;
    }

    int days = -1;
    while (!q.empty()) {
        int size = q.size();
        days++; // 하루 증가
        while (size--) {

            tuple<int, int, int> cur = q.front();
            q.pop();

            int z = get<0>(cur);
            int y = get<1>(cur);
            int x = get<2>(cur);

            for (int i = 0; i < 6; i++) {
                int nz = z + dz[i];
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m)
                    continue;
                if (box[nz][ny][nx] == 0) {
                    box[nz][ny][nx] = 1;
                    unripe--;
                    q.push({ nz, ny, nx });
                }
            }
        }
    }

    cout << (unripe == 0 ? days : -1);
    return 0;
}