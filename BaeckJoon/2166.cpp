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

typedef struct point
{
    int x, y;
} point;

// �ٰ��� ���� ���ϱ�
// �� �ϳ��� �������� �ﰢ������ �����Ͽ� ����
// ���� ��ġ�� sorting�ؾ��ϳ�, �������� �ٰ����� �̷�� ���� ��ġ�� �����ؼ� �Է����� ����
// points[0]�� ���� ���ͷ� �����Ͽ� CCW�� �̿��ϸ� ��.

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    vector<point> points(n, {0, 0});
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    double surface = 0.0f;
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        surface += (long long)points[i].x * points[j].y;
        surface -= (long long)points[i].y * points[j].x;
    }
    surface = abs(surface) / 2.0;

    cout << fixed;
    cout.precision(1);
    cout << surface << '\n';

    return 0;
}