#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int n, m;
int arr[8];
bool visited[8];
int numbers[8]; // 선택할 수 있는 숫자 묶음

void solution(int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // 하나 이상의 숫자를 선택했을 경우, 이전 숫자가 현재 가리키고 있는 숫자보다 큰 경우는 제외
            if (depth > 0 && arr[depth - 1] > numbers[i]) continue;
            visited[i] = true;
            arr[depth] = numbers[i];
            solution(depth + 1);
            visited[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    sort(numbers, numbers + n); // 오름차순으로 미리 정렬
    solution(0);

    return 0;
}