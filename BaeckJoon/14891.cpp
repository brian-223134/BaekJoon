#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;
// 0: N극, 1: S극 (12시 방향부터 시계방향으로 주어짐)
char wheel[4][8];
int k;

typedef struct rotation
{
    int n, dir; // dir; 1: 시계방향, -1: 반시계방향
} rotation;

rotation r[100];

// n번째 톱니를 시계방향으로 회전
void clock_wise(int n)
{
    char temp = wheel[n][7];
    for (int i = 7; i > 0; i--)
        wheel[n][i] = wheel[n][i - 1];
    wheel[n][0] = temp;
}

// n번째 톱니를 반시계방향으로 회전
void reverse_clock_wise(int n)
{
    char temp = wheel[n][0];
    for (int i = 0; i < 7; i++)
        wheel[n][i] = wheel[n][i + 1];
    wheel[n][7] = temp;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 0; i < 4; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < 8; j++)
        {
            wheel[i][j] = temp[j];
        }
    }
    
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> r[i].n >> r[i].dir;
        r[i].n--; // 0-based index로 변환
    }
    
    for (int i = 0; i < k; i++)
    {
        int rotate_dir[4] = {0, 0, 0, 0};
        int cur = r[i].n;
        int dir = r[i].dir;
        rotate_dir[cur] = dir;

        // 왼쪽으로 전파
        int left = cur;
        int left_dir = dir;
        while (left - 1 >= 0)
        {
            if (wheel[left][6] != wheel[left - 1][2])
            {
                left_dir = -left_dir;
                rotate_dir[left - 1] = left_dir;
                left--;
            }
            else break;
        }
        // 오른쪽으로 전파
        int right = cur;
        int right_dir = dir;
        while (right + 1 < 4)
        {
            if (wheel[right][2] != wheel[right + 1][6])
            {
                right_dir = -right_dir;
                rotate_dir[right + 1] = right_dir;
                right++;
            }
            else break;
        }
        // 실제 회전
        for (int j = 0; j < 4; j++)
        {
            if (rotate_dir[j] == 1) clock_wise(j);
            else if (rotate_dir[j] == -1) reverse_clock_wise(j);
        }
    }

    // 점수 계산
    int score = 0;
    for (int i = 0; i < 4; i++)
    {
        if (wheel[i][0] == '1')
            score += (1 << i);
    }
    cout << score << '\n';
    return 0;
}