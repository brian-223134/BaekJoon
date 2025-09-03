#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int arr[51][51];
int temp_arr[51][51]; // 확산 계산을 위한 임시 배열
int r, c, t;
vector<pair<int, int>> air_conditioner;

// 상하좌우
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool OOB(int y, int x)
{
    return y > r || x > c || y <= 0 || x <= 0;
}

bool is_air(int y, int x)
{
    return arr[y][x] == -1;
}

// 미세먼지 확산 함수
void spread_dust()
{
    memset(temp_arr, 0, sizeof(temp_arr)); // 임시 배열 초기화

    for (int y = 1; y <= r; y++)
    {
        for (int x = 1; x <= c; x++)
        {
            if (arr[y][x] > 0)
            {
                int spread_amount = arr[y][x] / 5;
                int spread_count = 0;

                for (int i = 0; i < 4; i++)
                {
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if (OOB(ny, nx) || is_air(ny, nx)) continue;

                    temp_arr[ny][nx] += spread_amount;
                    spread_count++;
                }
                temp_arr[y][x] -= spread_amount * spread_count;
            }
        }
    }

    // 변화량을 원래 배열에 적용
    for (int y = 1; y <= r; y++)
    {
        for (int x = 1; x <= c; x++)
        {
            arr[y][x] += temp_arr[y][x];
        }
    }
}

// 공기청정기 작동 함수
void run_air_conditioner()
{
    // 배열의 입력이 위에서부터 입력되므로 공기청정기 상단부가 0번째 index에 할당 됨.
    int top_y = air_conditioner[0].first;
    int bottom_y = air_conditioner[1].first;

    // 상단 (반시계)
    for (int y = top_y - 1; y > 1; y--) arr[y][1] = arr[y - 1][1];
    for (int x = 1; x < c; x++) arr[1][x] = arr[1][x + 1];
    for (int y = 1; y < top_y; y++) arr[y][c] = arr[y + 1][c];
    for (int x = c; x > 2; x--) arr[top_y][x] = arr[top_y][x - 1];
    arr[top_y][2] = 0;

    // 하단 (시계)
    for (int y = bottom_y + 1; y < r; y++) arr[y][1] = arr[y + 1][1];
    for (int x = 1; x < c; x++) arr[r][x] = arr[r][x + 1];
    for (int y = r; y > bottom_y; y--) arr[y][c] = arr[y - 1][c];
    for (int x = c; x > 2; x--) arr[bottom_y][x] = arr[bottom_y][x - 1];
    arr[bottom_y][2] = 0;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> r >> c >> t;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == -1)
            {
                air_conditioner.push_back({ i,j });
            }
        }
    }

    while (t--)
    {
        spread_dust();
        run_air_conditioner();
    }

    int total_dust = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (arr[i][j] > 0)
            {
                total_dust += arr[i][j];
            }
        }
    }
    cout << total_dust << "\n";

    return 0;
}