#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Shortcut {
    int start, end, cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    vector<Shortcut> shortcuts;
    for (int i = 0; i < n; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        // 도착 지점이 d보다 크면 무시
        if (e > d || e - s <= c) continue;
        shortcuts.push_back({ s, e, c });
    }

    vector<int> dist(d + 1);
    for (int i = 0; i <= d; i++) {
        dist[i] = i; // 초기값: 지름길 없이 i까지 가는 거리
    }

    for (int i = 0; i <= d; i++) {
        // 먼저 일반 도로로 한 칸 가는 경우 고려
        if (i + 1 <= d)
            dist[i + 1] = min(dist[i + 1], dist[i] + 1);

        // 지름길 검사
        for (const auto& sc : shortcuts) {
            if (sc.start == i && sc.end <= d) {
                dist[sc.end] = min(dist[sc.end], dist[i] + sc.cost);
            }
        }
    }

    cout << dist[d] << endl;
    return 0;
}