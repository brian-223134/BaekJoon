#include <iostream>
using namespace std;

int n, m;
int arr[9];

void solution(int index, int start)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = start; i <= n; i++)
    {
        arr[index] = i;
        solution(index + 1, i);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    solution(0, 1);

    return 0;
}