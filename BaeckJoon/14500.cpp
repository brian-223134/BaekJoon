#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

// ��Ʈ�ι̳� ������ 5 ������ ����
// 5���� Ž���� ���� �ִ� ���� ���
// �� ������ ȸ�� �� ��Ī ��ų �� ����
// ������ �������� ��� ��ǥ�� Ž�� ������ �̿�

int n, m;
int arr[500][500];

// 1 * 4 ��� (type 0 = ����, type 1 = ����)
int first_case(int y, int x, int type)
{
    int sum = 0;
    if (type == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            sum += arr[y][x + i];
        }
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            sum += arr[y + i][x];
        }
    }
    
    return sum;
}

// 2 * 2 ���
int second_case(int y, int x)
{
    int sum = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sum += arr[y + i][x + j];
        }
    }
    return sum;
}

// 3 * 2(Ȥ�� 2 * 3) - (1*1 �ΰ�) ��� (type 0 = ���η� ��� �þ��� ���, type 1 = ���η� ��� �þ��� ���)
// ������ Ž������ �����¿� ��Ī�� ��� ���
int third_case(int y, int x, int type)
{
    int sum = 0;
    int total_sum = 0;

    if (type == 0)
    {
        // 3 * 2 ���簢���� ��
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                sum += arr[y + i][x + j];
            }
        }

        // 1 * 1 ���簢���� ���� �� �� �ִ� ���� ���Ѵ�. ('��'�� ����)
        total_sum = max(total_sum, sum - (arr[y][x] + arr[y + 1][x]));
        total_sum = max(total_sum, sum - (arr[y][x + 1] + arr[y + 1][x + 1]));
        total_sum = max(total_sum, sum - (arr[y + 1][x] + arr[y + 2][x]));
        total_sum = max(total_sum, sum - (arr[y + 1][x + 1] + arr[y + 2][x + 1]));

        // ���� ���
        total_sum = max(total_sum, sum - (arr[y][x] + arr[y + 2][x + 1]));
        total_sum = max(total_sum, sum - (arr[y][x + 1] + arr[y + 2][x]));

        // '��', '��' ���
        total_sum = max(total_sum, sum - (arr[y][x + 1] + arr[y + 2][x + 1]));
        total_sum = max(total_sum, sum - (arr[y][x] + arr[y + 2][x]));
    }
    else
    {
        // 2 * 3 ���簢���� ��
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                sum += arr[y + i][x + j];
            }
        }

        // 1 * 1 ���簢���� ���� �� �� �ִ� ���� ���Ѵ�. ('��'�� ����)
        total_sum = max(total_sum, sum - (arr[y][x] + arr[y][x + 1]));
        total_sum = max(total_sum, sum - (arr[y][x + 1] + arr[y][x + 2]));
        total_sum = max(total_sum, sum - (arr[y + 1][x] + arr[y + 1][x + 1]));
        total_sum = max(total_sum, sum - (arr[y + 1][x + 1] + arr[y + 1][x + 2]));

        // ���� ���
        total_sum = max(total_sum, sum - (arr[y][x + 2] + arr[y + 1][x]));
        total_sum = max(total_sum, sum - (arr[y][x] + arr[y + 1][x + 2]));

        // '��', '��' ���
        total_sum = max(total_sum, sum - (arr[y][x] + arr[y][x + 2]));
        total_sum = max(total_sum, sum - (arr[y + 1][x] + arr[y + 1][x + 2]));
    }

    return total_sum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    int test = 3;
    int result = 0;
    while (test--)
    {
        switch (test + 1)
        {
            case 3:
                // ���� Ÿ��
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j <= m - 4; j++)
                    {
                        result = max(result, first_case(i, j, 0));
                    }
                }
                
                // ���� Ÿ��
                for (int i = 0; i <= n - 4; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        result = max(result, first_case(i, j, 1));
                    }
                }

                break;

            case 2:
                for (int i = 0; i <= n - 2; i++)
                {
                    for (int j = 0; j <= m - 2; j++)
                    {
                        result = max(result, second_case(i, j));
                    }
                }

                break;

            case 1:
                // 3 * 2 ��翡�� ���� ���
                for (int i = 0; i <= n - 3; i++)
                {
                    for (int j = 0; j <= m - 2; j++)
                    {
                        result = max(result, third_case(i, j, 0));
                    }
                }

                // 2 * 3 ��翡�� ���� ���
                for (int i = 0; i <= n - 2; i++)
                {
                    for (int j = 0; j <= m - 3; j++)
                    {
                        result = max(result, third_case(i, j, 1));
                    }
                }
                break;

            default:
                break;
        }
    }
    
    cout << result;

    return 0;
}