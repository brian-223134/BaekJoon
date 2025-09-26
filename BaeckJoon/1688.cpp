#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// �ִ�����(GCD) �Լ�
ll gcd(ll a, ll b) 
{ 
    for (; b; a %= b, swap(a, b)); return a; 
}

// �� �� a, b�� �޾� ����(b - a) ��ȯ
pll p2v(pll a, pll b)
{
    return { b.first - a.first, b.second - a.second };
}

// �� ������ ������ �̿��� CCW(���⼺) �Ǻ�
ll ccw(pll v1, pll v2)
{
    ll res = v1.first * v2.second - v1.second * v2.first;

    if (res > 0) return 1;      // �ݽð� ����
    else if (res < 0) return -1;// �ð� ����
    else return 0;              // ������
}

int n;
vector <pll> CH; // �ٰ����� ������ ��ǥ ����

// ���� �ٰ��� ���ο� ���� ���ԵǴ��� �Ǻ� (Ray Casting �˰���)
bool isInside_nonconvex(vector <pll>& CH, pll point)
{
    int cnt = 0;
    for (int i = 0; i < CH.size(); i++)
    {
        pll p1 = CH[i], p2 = CH[(i + 1) % CH.size()];
        if (p1.second < p2.second) swap(p1, p2); // p1�� �� ���� ������ ����

        pll v1 = p2v(p1, point);
        pll v2 = p2v(point, p2);

        // ���� �� ���� �ִ� ���
        if (ccw(v1, v2) == 0)
        {
            if (min(p1.first, p2.first) <= point.first && point.first <= max(p1.first, p2.first)
                && min(p1.second, p2.second) <= point.second && point.second <= max(p1.second, p2.second))
                return true;
        }

        // ���� ĳ����: �������� �ʴ� ��� �н�
        if (max(p1.first, p2.first) < point.first) continue;
        if (p1.second <= point.second) continue;
        if (p2.second > point.second) continue;
        if (min(p1.first, p2.first) > point.first) cnt++;
        else if (ccw(v1, v2) > 0) cnt++;
    }

    // ���ο� ������ Ȧ��, �ܺθ� ¦��
    return cnt % 2;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x, y; cin >> x >> y;
        CH.push_back({ x,y }); // �ٰ��� ������ �Է�
    }

    // 3���� ���� ���� �ٰ��� ����/�ܺ� �Ǻ�
    for (int i = 0; i < 3; i++)
    {
        ll x, y; cin >> x >> y;
        if (isInside_nonconvex(CH, { x,y })) cout << "1\n"; // ���� �Ǵ� �� ��
        else cout << "0\n"; // �ܺ�
    }
}