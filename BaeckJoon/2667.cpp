#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 컴파일러에 따른 자동초기화가 없을 수 있으므로 false로 모두 초기화
char apt_map[25][25];
bool visited[25][25] = { false };


//상하좌우
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int dfs(int y, int x, int size)
{
    visited[y][x] = true;
    int cnt = 1;
    for (int dir = 0; dir < 4; dir++)
    {
        int new_y = y + dy[dir];
        int new_x = x + dx[dir];

        if (new_y < 0 || new_y >= size || new_x < 0 || new_x >= size) continue;

        if (!visited[new_y][new_x] && apt_map[new_y][new_x] == '1')
        {
            cnt += dfs(new_y, new_x, size);
        }
    }
    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> apt_map[i][j];
        }
    }

    int count = 0;
    vector<int> apt_size;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (!visited[i][j] && apt_map[i][j] == '1')
            {
                count = dfs(i, j, size);
                apt_size.push_back(count);
            }
        }
    }
    sort(apt_size.begin(), apt_size.end());
    cout << apt_size.size() << endl;
    for (int i : apt_size)
    {
        cout << i << endl;
    }
    return 0;
}