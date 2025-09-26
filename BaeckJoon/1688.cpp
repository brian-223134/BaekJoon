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

// 최대공약수(GCD) 함수
ll gcd(ll a, ll b) 
{ 
    for (; b; a %= b, swap(a, b)); return a; 
}

// 두 점 a, b를 받아 벡터(b - a) 반환
pll p2v(pll a, pll b)
{
    return { b.first - a.first, b.second - a.second };
}

// 두 벡터의 외적을 이용한 CCW(방향성) 판별
ll ccw(pll v1, pll v2)
{
    ll res = v1.first * v2.second - v1.second * v2.first;

    if (res > 0) return 1;      // 반시계 방향
    else if (res < 0) return -1;// 시계 방향
    else return 0;              // 일직선
}

int n;
vector <pll> CH; // 다각형의 꼭짓점 좌표 저장

// 오목 다각형 내부에 점이 포함되는지 판별 (Ray Casting 알고리즘)
bool isInside_nonconvex(vector <pll>& CH, pll point)
{
    int cnt = 0;
    for (int i = 0; i < CH.size(); i++)
    {
        pll p1 = CH[i], p2 = CH[(i + 1) % CH.size()];
        if (p1.second < p2.second) swap(p1, p2); // p1이 더 위에 오도록 정렬

        pll v1 = p2v(p1, point);
        pll v2 = p2v(point, p2);

        // 점이 변 위에 있는 경우
        if (ccw(v1, v2) == 0)
        {
            if (min(p1.first, p2.first) <= point.first && point.first <= max(p1.first, p2.first)
                && min(p1.second, p2.second) <= point.second && point.second <= max(p1.second, p2.second))
                return true;
        }

        // 레이 캐스팅: 교차하지 않는 경우 패스
        if (max(p1.first, p2.first) < point.first) continue;
        if (p1.second <= point.second) continue;
        if (p2.second > point.second) continue;
        if (min(p1.first, p2.first) > point.first) cnt++;
        else if (ccw(v1, v2) > 0) cnt++;
    }

    // 내부에 있으면 홀수, 외부면 짝수
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
        CH.push_back({ x,y }); // 다각형 꼭짓점 입력
    }

    // 3개의 점에 대해 다각형 내부/외부 판별
    for (int i = 0; i < 3; i++)
    {
        ll x, y; cin >> x >> y;
        if (isInside_nonconvex(CH, { x,y })) cout << "1\n"; // 내부 또는 변 위
        else cout << "0\n"; // 외부
    }
}