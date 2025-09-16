#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;
// 0: N��, 1: S�� (12�� ������� �ð�������� �־���)
char wheel[4][8];
int k;

typedef struct rotation
{
    int n, dir; // dir; 1: �ð����, -1: �ݽð����
} rotation;

rotation r[100];

// n��° ��ϸ� �ð�������� ȸ��
void clock_wise(int n)
{
    char temp = wheel[n][7];
    for (int i = 7; i > 0; i--)
        wheel[n][i] = wheel[n][i - 1];
    wheel[n][0] = temp;
}

// n��° ��ϸ� �ݽð�������� ȸ��
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
        r[i].n--; // 0-based index�� ��ȯ
    }
    
    for (int i = 0; i < k; i++)
    {
        int rotate_dir[4] = {0, 0, 0, 0};
        int cur = r[i].n;
        int dir = r[i].dir;
        rotate_dir[cur] = dir;

        // �������� ����
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
        // ���������� ����
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
        // ���� ȸ��
        for (int j = 0; j < 4; j++)
        {
            if (rotate_dir[j] == 1) clock_wise(j);
            else if (rotate_dir[j] == -1) reverse_clock_wise(j);
        }
    }

    // ���� ���
    int score = 0;
    for (int i = 0; i < 4; i++)
    {
        if (wheel[i][0] == '1')
            score += (1 << i);
    }
    cout << score << '\n';
    return 0;
}