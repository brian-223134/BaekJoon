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
int numbers[8];
int arr[8];

void solution(int depth, int start)
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

    for (int i = start; i < n; i++)
    {
        if (depth > 0 && arr[depth - 1] > numbers[i]) continue;
        arr[depth] = numbers[i];
        solution(depth + 1, start);
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

    sort(numbers, numbers + n);
    solution(0, 0);

    return 0;
}