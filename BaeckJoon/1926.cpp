#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char picture[500][500];
bool visited[500][500] = { false };

//상하좌우
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int dfs(int y, int x, int size_y, int size_x)
{
    visited[y][x] = true;
    int cnt = 1;
    for (int dir = 0; dir < 4; dir++)
    {
        int new_y = y + dy[dir];
        int new_x = x + dx[dir];
        if (new_y < 0 || new_y >= size_y || new_x < 0 || new_x >= size_x) continue;
        if (!visited[new_y][new_x] && picture[new_y][new_x] == '1')
        {
            cnt += dfs(new_y, new_x, size_y, size_x);
        }
    }
    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    //입력 set: y축,x축 개수 -> 0, 1의 묶음
    int y, x;
    cin >> y >> x;

    int num = 0; //그림의 개수
    int pic_val = 0; //그림의 크기 (vector의 값에 들어갈)
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cin >> picture[i][j];
        }
    }

    vector<int> pic_size;

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (!visited[i][j] && picture[i][j] == '1')
            {
                num++;
                pic_val = dfs(i, j, y, x);
                pic_size.push_back(pic_val);
            }
        }
    }

    sort(pic_size.rbegin(), pic_size.rend()); //내림차순

    if (num == 0)
    {
        cout << 0 << endl;
        cout << 0;
    }
    else
    {
        cout << num << endl;
        cout << pic_size[0];
    }

}