#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int n;
char arr[50][50];

typedef struct edges
{
    int u;
    int v;
    int w;
    bool operator<(const edges& other) const
    {
        return w < other.w;
    }
} edges;

int find_parent(int x, vector<int>& parents)
{
    if (parents[x] == x)
    {
        return x;
    }
    return parents[x] = find_parent(parents[x], parents);
}

void unite(int a, int b, vector<int>& parents)
{
    a = find_parent(a, parents);
    b = find_parent(b, parents);
    if (a < b)
    {
        parents[b] = a;
    }
    else
    {
        parents[a] = b;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = temp[j];
        }
    }

    vector<edges> cable;
    vector<int> parents(n);
    for (int i = 0; i < n; i++)
    {
        parents[i] = i;
    }

    long long _total = 0; // int ������ �ʰ��� �� �����Ƿ� long long ���
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp_w = 0;
            if (arr[i][j] >= 'a' && arr[i][j] <= 'z')
            {
                temp_w = (arr[i][j] - 'a') + 1;
            }
            else if (arr[i][j] >= 'A' && arr[i][j] <= 'Z')
            {
                temp_w = (arr[i][j] - 'A') + 27;
            }

            _total += temp_w; // ��� ��ġ�� ���� ���̸� ���տ� ����

            // 0�� �ƴ� ��쿡�� �������� �߰�
            if (temp_w != 0)
            {
                cable.push_back({ i, j, temp_w });
            }
        }
    }

    sort(cable.begin(), cable.end()); // �������� ����

    long long mst_cost = 0;
    int e_cnt = 0;
    for (const auto& e : cable)
    {
        if (find_parent(e.u, parents) != find_parent(e.v, parents))
        {
            unite(e.u, e.v, parents);
            mst_cost += e.w;
            e_cnt++;
        }
    }

    // ��� ��ǻ�Ͱ� ����Ǿ����� Ȯ�� (n=1�� ��� ����)
    bool all_connected = true;
    if (n > 1) {
        int root = find_parent(0, parents);
        for (int i = 1; i < n; i++) {
            if (root != find_parent(i, parents)) {
                all_connected = false;
                break;
            }
        }
    }

    // ���� _total�� 0�̶�� ��� ��ǻ�͸� ������ ����� �����Ƿ� -1 ó��
    // ��, n=1�� ���� ����
    if (_total == 0 && n > 1)
    {
        cout << -1;
    }
    else if (all_connected)
    {
        cout << _total - mst_cost;
    }
    else
    {
        cout << -1;
    }

    return 0;
}