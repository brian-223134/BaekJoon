#include <iostream>
#include <vector>
#include <cmath> // abs() �Լ��� ���� �߰�

using namespace std;

int n, l;
int arr[100][100];

// type 0: ����, type 1: ����
bool is_road(int idx, int type) 
{
    // �� ���� �˻��ϱ� ���ϵ��� 1���� �迭�� ����
    vector<int> line(n);
    for (int i = 0; i < n; i++) 
    {
        if (type == 0) { // ���� ��
            line[i] = arr[idx][i];
        }
        else { // ���� ��
            line[i] = arr[i][idx];
        }
    }

    // ���� ��ġ ���θ� ����� �迭
    bool visited[100] = { false };

    for (int i = 0; i < n - 1; i++) 
    {
        int diff = line[i] - line[i + 1];

        // ���� ���̰� 1���� ũ�� ���� ���� �� ����
        if (abs(diff) > 1)
        {
            return false;
        }

        // ���̰� ������ ���
        if (diff == 0) 
        {
            continue;
        }

        // ������ ���� (���� > ����)
        if (diff == 1) 
        {
            // ������ L���� ĭ�� Ȯ���ؾ� ��
            for (int j = 1; j <= l; j++) 
            {
                // 1. ������ ����ų�
                // 2. ���θ� ���� ���� ���̰� �ٸ��ų�
                // 3. �̹� �ٸ� ���ΰ� ��ġ�Ǿ� �ִٸ� �Ұ���
                if (i + j >= n || line[i + 1] != line[i + j] || visited[i + j]) 
                {
                    return false;
                }
            }
            // ���� ��ġ
            for (int j = 1; j <= l; j++) 
            {
                visited[i + j] = true;
            }
        }
        // ������ ���� (���� < ����)
        else if (diff == -1)
        {
            // �ڷ� L���� ĭ�� Ȯ���ؾ� ��
            for (int j = 0; j < l; j++)
            {
                // 1. ������ ����ų�
                // 2. ���θ� ���� ���� ���̰� �ٸ��ų�
                // 3. �̹� �ٸ� ���ΰ� ��ġ�Ǿ� �ִٸ� �Ұ���
                if (i - j < 0 || line[i] != line[i - j] || visited[i - j]) 
                {
                    return false;
                }
            }
            // ���� ��ġ
            for (int j = 0; j < l; j++) 
            {
                visited[i - j] = true;
            }
        }
    }

    return true; // ��� �˻縦 ����ϸ� �� �ϼ�
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int result = 0;

    // ���� �������� �� ã��
    for (int i = 0; i < n; i++) 
    {
        if (is_road(i, 0)) 
        {
            result++;
        }
    }

    // ���� �������� �� ã��
    for (int i = 0; i < n; i++) 
    {
        if (is_road(i, 1)) 
        {
            result++;
        }
    }

    cout << result;

    return 0;
}