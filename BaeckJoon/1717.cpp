#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;
// �ʱ⿡ ������ n + 1 �� ����: {0}, {1}, ... , {n}
// m: ������ ����
int n, m;

// �Է� ����
// 0 a b: ������ -> a�� ���� ���հ� b�� ���� ������ ��ħ
// 1 a b: Ȯ�� -> a�� b�� ���� ���տ� ���� �ִ� �� ����

int parent[1000001];

int find(int u)
{
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void union_set(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return;
    parent[u] = v;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    // parent �迭 �ʱ�ȭ
    for (int i = 0; i <= n; i++) 
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int act, a, b;
        cin >> act >> a >> b;

        switch (act)
        {
            case 0: // ������
                union_set(a, b);
                break;

            case 1: // Ȯ��
                if (find(a) == find(b))
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
                break;
        }
    }

    return 0;
}