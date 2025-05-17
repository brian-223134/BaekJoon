#include <iostream>
#include <vector>

using namespace std;

int dy[] = { 1, -1, 0, 0 }, dx[] = { 0, 0, 1, -1 };
int R, C, K, answer;
vector<string> map;

void dfs(int y, int x, int cnt)
{
    if (cnt == K)
    {
        if (y == 0 && x == C - 1) // 집인지 확인하기
        {
            ++answer;
        }
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= R || nx >= C || map[ny][nx] == 'T')
        {
            continue;
        }
        map[ny][nx] = 'T';
        dfs(ny, nx, cnt + 1);
        map[ny][nx] = '.';
    }
}

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> R >> C >> K;
    map = vector<string>(R);

    for (int i = 0; i < R; ++i)
    {
        cin >> map[i];
    }

    map[R - 1][0] = 'T'; // 시작지점은 방문 처리
    dfs(R - 1, 0, 1); // 방문 처리후 dfs 시작

    cout << answer;

    return 0;
}