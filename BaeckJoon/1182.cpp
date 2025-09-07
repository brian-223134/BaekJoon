#include <iostream>
using namespace std;

int n, s;
int arr[20];
int result = 0;

// ������ ���� �ʴ� ������ ��� Ž���ϹǷ� index == n�϶��� ���� ���ϸ� ��.
void solution(int index, int sum) 
{
    if (index == n) 
    {
        if (sum == s) result++;
        return;
    }
    // ���� ���Ҹ� �����ϴ� ���
    solution(index + 1, sum + arr[index]);
    // ���� ���Ҹ� �������� �ʴ� ���
    solution(index + 1, sum);
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> arr[i];

    solution(0, 0);

    // s�� 0�� ���, �����յ� ī��Ʈ�ǹǷ� 1�� ����
    if (s == 0) result--;

    cout << result;
    return 0;
}