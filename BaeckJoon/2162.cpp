#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int n;

typedef struct line {
    int x1, y1, x2, y2;
}line;

// CCW �˰���: ������ �̿�
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) 
{
    long long op = 1LL * (x2 - x1) * (y3 - y1) - 1LL * (y2 - y1) * (x3 - x1);
    if (op > 0) return 1;    // �ݽð�
    if (op < 0) return -1;   // �ð�
    return 0;                // ������
}

// �� ������ �����ϴ��� ����
bool is_cross(const line& a, const line& b) 
{
    int ab1 = ccw(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1);
    int ab2 = ccw(a.x1, a.y1, a.x2, a.y2, b.x2, b.y2);
    int ba1 = ccw(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1);
    int ba2 = ccw(b.x1, b.y1, b.x2, b.y2, a.x2, a.y2);

    // �Ϲ����� ����
    if (ab1 * ab2 < 0 && ba1 * ba2 < 0) return true;

    // �� ���� ���� �ִ� ���
    auto on = [](int x1, int y1, int x2, int y2, int x, int y) 
        {
        return min(x1, x2) <= x && x <= max(x1, x2) &&
               min(y1, y2) <= y && y <= max(y1, y2);
    };
    if (ab1 == 0 && on(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1)) return true;
    if (ab2 == 0 && on(a.x1, a.y1, a.x2, a.y2, b.x2, b.y2)) return true;
    if (ba1 == 0 && on(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1)) return true;
    if (ba2 == 0 && on(b.x1, b.y1, b.x2, b.y2, a.x2, a.y2)) return true;

    return false;
}

vector<int> parent, group_size;

int find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// �׷��� ������ �߰������� ����� ���ÿ� ���� ���߿� �����ϰ� �̿��� �� �ְ� ����
void unite(int a, int b) 
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    parent[b] = a;
    group_size[a] += group_size[b];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    vector<line> lines(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2;
    }

    parent.resize(n);
    group_size.resize(n, 1);
    for (int i = 0; i < n; i++) parent[i] = i;

    // ��� �ֿ� ���� ���� ���� �� ��ü
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++)
        {
            if (is_cross(lines[i], lines[j]))
            {
                unite(i, j);
            }
        }
    }

    // ������ ������ �ִ� ũ��
    int group_cnt = 0, max_size = 0;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == i) 
        {
            group_cnt++;
            max_size = max(max_size, group_size[i]);
        }
    }
    cout << group_cnt << '\n' << max_size << '\n';

    return 0;
}