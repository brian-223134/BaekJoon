#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n; // 체스판 크기
int arr[10][10]; // 체스판
bool not_place[10][10]; // bishop이 둘 수 없는 곳

bool isused1[20]; // 우상향 대각선 사용 여부
bool isused2[20]; // 우하향 대각선 사용 여부

int max_bishop[2] = {0, 0}; // 흑/백 칸에 대한 최대 비숍 개수

// cur: 현재 탐색 중인 칸 인덱스, color: 0(흑), 1(백), cnt: 현재까지 놓은 비숍 개수
void backtrack(int cur, int color, int cnt)
{
    if (cur >= n * n) 
    {
        max_bishop[color] = max(max_bishop[color], cnt);
        return;
    }
    int y = cur / n;
    int x = cur % n;
    // 현재 칸의 색이 맞는 경우만 탐색
    if ((y + x) % 2 == color) 
    {
        if (!not_place[y][x] && !isused1[y + x] && !isused2[y - x + n - 1]) 
        {
            isused1[y + x] = true;
            isused2[y - x + n - 1] = true;
            backtrack(cur + 1, color, cnt + 1);
            isused1[y + x] = false;
            isused2[y - x + n - 1] = false;
        }
    }
    backtrack(cur + 1, color, cnt);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 0) not_place[i][j] = true;
        }
    }

    // 흑/백 칸을 분리하여 각각 백트래킹
    backtrack(0, 0, 0); // 흑 칸
    backtrack(0, 1, 0); // 백 칸

    cout << max_bishop[0] + max_bishop[1] << '\n';

    return 0;
}