#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char land[50][50]; //밭의 면적
bool visited[50][50] = { false }; //non-visit으로 초기화

//상하좌우
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dfs(int y, int x, int size_y, int size_x)
{
    visited[y][x] = true;
    for (int dir = 0; dir < 4; dir++)
    {
        int new_y = y + dy[dir];
        int new_x = x + dx[dir];
        if (new_y < 0 || new_y >= size_y || new_x < 0 || new_x >= size_x) continue;
        if (!visited[new_y][new_x] && land[new_y][new_x] == '1')
        {
            dfs(new_y, new_x, size_y, size_x);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // input 순서 Test case순서 - 가로, 세로, 배추 개수
    // 처리 방안 전역변수로
    int test, x, y, num, count;
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                land[i][j] = '0';
                visited[i][j] = false;
            }
        }

        count = 0;
        cin >> x;
        cin >> y;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            int temp_x, temp_y;
            cin >> temp_x;
            cin >> temp_y;
            land[temp_y][temp_x] = '1';
        }
        
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                if (!visited[i][j] && land[i][j] == '1')
                {
                    count++;
                    dfs(i, j, y, x);
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}