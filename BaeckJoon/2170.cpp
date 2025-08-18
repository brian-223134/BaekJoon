#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> lines(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lines[i].first >> lines[i].second;
    }

    // ������ �������� �������� �������� ����
    sort(lines.begin(), lines.end());

    // long long���� �� ���̸� �����Ͽ� �����÷ο� ����
    long long total_length = 0;

    // ù ��° ���� �������� �ʱ� ���� ���� ����
    int start = lines[0].first;
    int end = lines[0].second;

    for (int i = 1; i < n; i++)
    {
        // ���� ���� �������� ���� ���� ���� �ȿ� �ִ� ��� (���� ��ġ�� ���)
        if (lines[i].first <= end)
        {
            // ���� ������ ������ �� �� ������ ����
            end = max(end, lines[i].second);
        }
        // ���� ���� ���� ���� ������ ������ ������ ���
        else
        {
            // ���ݱ��� ���յ� ������ ���̸� �� ���̿� ����
            total_length += (end - start);
            // ���ο� ���� ������ ����
            start = lines[i].first;
            end = lines[i].second;
        }
    }

    // ������ ���� �� ���������� ���յ� ������ ���̸� ������
    total_length += (end - start);

    cout << total_length;

    return 0;
}