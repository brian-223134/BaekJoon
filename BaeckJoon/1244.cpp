#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int toggle(int x) { return 1 - x; } // 0<->1

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) cin >> arr[i];

    int stu_num;
    cin >> stu_num;
    while (stu_num--)
    {
        int gender, num;
        cin >> gender >> num;

        if (gender == 1) 
        {
            // ���л�: ��� ���
            for (int k = num; k <= n; k += num) arr[k] ^= 1; // xor�� �����
        }
        else {
            // ���л�: �߽� ���� ��� �� �¿� ��Ī Ȯ��
            int left = num, right = num;
            // �߽� �����ؼ� Ȯ�� ������ �ִ� ���� ã��
            while (left - 1 >= 1 && right + 1 <= n && arr[left - 1] == arr[right + 1]) 
            {
                --left; ++right;
            }
            // [left, right] ��� ���
            for (int i = left; i <= right; ++i) arr[i] ^= 1;
        }
    }

    for (int i = 1; i <= n; ++i) 
    {
        cout << arr[i] << ' ';
        if (i % 20 == 0) cout << '\n';
    }
    if (n % 20 != 0) cout << '\n';
    return 0;
}