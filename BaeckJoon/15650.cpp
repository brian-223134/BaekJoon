#include <iostream>
using namespace std;

int n, m;
int arr[8];
bool visited[9]; // 1~n���� ���, 0�� ������� ����

void solution(int index)
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
    for (int i = 1; i <= n; i++) 
    {
        if (!visited[i]) 
        {
            // �������� ����: ������ ������ ������ ū ���� ����
            if (index == 0 || arr[index - 1] < i) 
            {
                visited[i] = true;
                arr[index] = i;
                solution(index + 1);
                visited[i] = false;
            }
        }
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