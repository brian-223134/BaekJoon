#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

// 점이 정사각형 변 위에 있는지 확인하는 함수
bool check(const vector<pair<int, int>>& pos, int square_min_x, int square_min_y, int side) {
    int square_max_x = square_min_x + side;
    int square_max_y = square_min_y + side;

    for (const auto& p : pos) {
        int x = p.first;
        int y = p.second;
        if (!(
            ((square_min_x <= x && x <= square_max_x) && (y == square_min_y || y == square_max_y)) ||
            ((square_min_y <= y && y <= square_max_y) && (x == square_min_x || x == square_max_x))
            )) {
            return false;
        }
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> pos(n);

    for (int i = 0; i < n; i++) {
        cin >> pos[i].first >> pos[i].second;
    }

    int min_x = pos[0].first, max_x = pos[0].first;
    int min_y = pos[0].second, max_y = pos[0].second;

    for (int i = 1; i < n; i++) {
        min_x = min(min_x, pos[i].first);
        max_x = max(max_x, pos[i].first);
        min_y = min(min_y, pos[i].second);
        max_y = max(max_y, pos[i].second);
    }

    int width = max_x - min_x;
    int height = max_y - min_y;
    int side = max(width, height);

    // x나 y쪽으로 이동해서 맞출 수 있는지 체크
    // x를 고정하고 y를 움직이거나, y를 고정하고 x를 움직여봐야 한다

    bool possible = false;
    // x 기준 고정, y 이동
    if (check(pos, min_x, min_y, side)) possible = true;
    else if (check(pos, min_x, max_y - side, side)) possible = true;
    // y 기준 고정, x 이동
    else if (check(pos, max_x - side, min_y, side)) possible = true;
    else if (check(pos, max_x - side, max_y - side, side)) possible = true;

    if (possible) cout << side << '\n';
    else cout << -1 << '\n';

    return 0;
}
