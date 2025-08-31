#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

// 테트로미노 종류가 5 종류가 있음
// 5번의 탐색을 통해 최대 값을 얻기
// 각 도형은 회전 및 대칭 시킬 수 있음
// 도형의 기준점을 잡고 좌표의 탐색 지점을 이용

int n, m;
int arr[500][500];

// 1 * 4 모양 (type 0 = 가로, type 1 = 세로)
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

// 2 * 2 모양
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

// 3 * 2(혹은 2 * 3) - (1*1 두개) 모양 (type 0 = 세로로 길게 늘어진 모양, type 1 = 가로로 길게 늘어진 모양)
// 각각의 탐색에서 상하좌우 대칭을 모두 고려
int third_case(int y, int x, int type)
{
    int sum = 0;
    int total_sum = 0;

    if (type == 0)
    {
        // 3 * 2 직사각형의 합
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                sum += arr[y + i][x + j];
            }
        }

        // 1 * 1 직사각형을 빼서 그 중 최대 값을 구한다. ('ㄴ'자 형태)
        total_sum = max(total_sum, sum - (arr[y][x] + arr[y + 1][x]));
        total_sum = max(total_sum, sum - (arr[y][x + 1] + arr[y + 1][x + 1]));
        total_sum = max(total_sum, sum - (arr[y + 1][x] + arr[y + 2][x]));
        total_sum = max(total_sum, sum - (arr[y + 1][x + 1] + arr[y + 2][x + 1]));

        // 번개 모양
        total_sum = max(total_sum, sum - (arr[y][x] + arr[y + 2][x + 1]));
        total_sum = max(total_sum, sum - (arr[y][x + 1] + arr[y + 2][x]));

        // 'ㅏ', 'ㅓ' 모양
        total_sum = max(total_sum, sum - (arr[y][x + 1] + arr[y + 2][x + 1]));
        total_sum = max(total_sum, sum - (arr[y][x] + arr[y + 2][x]));
    }
    else
    {
        // 2 * 3 직사각형의 합
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                sum += arr[y + i][x + j];
            }
        }

        // 1 * 1 직사각형을 빼서 그 중 최대 값을 구한다. ('ㄴ'자 형태)
        total_sum = max(total_sum, sum - (arr[y][x] + arr[y][x + 1]));
        total_sum = max(total_sum, sum - (arr[y][x + 1] + arr[y][x + 2]));
        total_sum = max(total_sum, sum - (arr[y + 1][x] + arr[y + 1][x + 1]));
        total_sum = max(total_sum, sum - (arr[y + 1][x + 1] + arr[y + 1][x + 2]));

        // 번개 모양
        total_sum = max(total_sum, sum - (arr[y][x + 2] + arr[y + 1][x]));
        total_sum = max(total_sum, sum - (arr[y][x] + arr[y + 1][x + 2]));

        // 'ㅗ', 'ㅜ' 모양
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
                // 가로 타입
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j <= m - 4; j++)
                    {
                        result = max(result, first_case(i, j, 0));
                    }
                }
                
                // 세로 타입
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
                // 3 * 2 모양에서 빼는 모양
                for (int i = 0; i <= n - 3; i++)
                {
                    for (int j = 0; j <= m - 2; j++)
                    {
                        result = max(result, third_case(i, j, 0));
                    }
                }

                // 2 * 3 모양에서 빼는 모양
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