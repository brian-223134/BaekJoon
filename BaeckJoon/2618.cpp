#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

struct Point {
    int y, x;
};

int n, W; // n: ���� ũ��, W: ��� ��
vector<Point> events; // ��� ��ǥ (1-based)
int dp[1001][1001];   // �޸������̼� �迭
int choice[1001][1001]; // ��� ������ (1: car1, 2: car2)

// �ع��� �Ÿ�
int dist(const Point& a, const Point& b)
{
    return abs(a.y - b.y) + abs(a.x - b.x);
}

// i: car1 ������ ���, j: car2 ������ ���
int solve(int i, int j) 
{
    int& ret = dp[i][j];
    if (ret != -1) return ret;

    int k = max(i, j) + 1; // ���� ��� ��ȣ
    if (k > W) return ret = 0;

    // car1 ��ġ
    Point pos1 = (i == 0 ? Point{ 1, 1 } : events[i]);
    // car2 ��ġ
    Point pos2 = (j == 0 ? Point{ n, n } : events[j]);

    int cost1 = dist(pos1, events[k]) + solve(k, j);
    int cost2 = dist(pos2, events[k]) + solve(i, k);

    if (cost1 <= cost2)
    {
        choice[i][j] = 1;
        ret = cost1;
    }
    else 
    {
        choice[i][j] = 2;
        ret = cost2;
    }
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> W;
    events.resize(W + 1);
    for (int i = 1; i <= W; i++) 
    {
        cin >> events[i].y >> events[i].x;
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0) << "\n";

    // ��� ����
    int i = 0, j = 0;
    for (int k = 1; k <= W; k++) 
    {
        cout << choice[i][j] << "\n";
        if (choice[i][j] == 1) i = k;
        else j = k;
    }

    return 0;
}
