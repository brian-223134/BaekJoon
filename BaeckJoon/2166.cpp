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

// 다각형 넓이 구하기
// 점 하나를 기준으로 삼각형으로 분할하여 연산
// 점의 위치를 sorting해야하나, 문제에서 다각형을 이루는 점의 위치를 조정해서 입력으로 제공
// points[0]를 원점 벡터로 고정하여 CCW를 이용하면 됨.

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