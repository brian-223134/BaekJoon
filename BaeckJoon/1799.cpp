#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n; // ü���� ũ��
int arr[10][10]; // ü����
bool not_place[10][10]; // bishop�� �� �� ���� ��

bool isused1[20]; // ����� �밢�� ��� ����
bool isused2[20]; // ������ �밢�� ��� ����

int max_bishop[2] = {0, 0}; // ��/�� ĭ�� ���� �ִ� ��� ����

// cur: ���� Ž�� ���� ĭ �ε���, color: 0(��), 1(��), cnt: ������� ���� ��� ����
void backtrack(int cur, int color, int cnt)
{
    if (cur >= n * n) 
    {
        max_bishop[color] = max(max_bishop[color], cnt);
        return;
    }
    int y = cur / n;
    int x = cur % n;
    // ���� ĭ�� ���� �´� ��츸 Ž��
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

    // ��/�� ĭ�� �и��Ͽ� ���� ��Ʈ��ŷ
    backtrack(0, 0, 0); // �� ĭ
    backtrack(0, 1, 0); // �� ĭ

    cout << max_bishop[0] + max_bishop[1] << '\n';

    return 0;
}