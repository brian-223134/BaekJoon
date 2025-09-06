#include <iostream>
using namespace std;

int n, m;
int arr[8];

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
    for (int i = 1; i <= n; i++)
    {
        arr[depth] = i;
        solution(depth + 1);
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    solution(0);

    return 0;
}