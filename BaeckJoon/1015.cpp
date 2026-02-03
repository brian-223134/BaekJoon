#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);   // {값, 원래 인덱스}
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }

    // 값 오름차순, 값이 같으면 원래 인덱스 오름차순
    sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[v[i].second] = i; // 원래 인덱스 위치에 정렬된 순서를 기록
    }

    for (int i = 0; i < n; ++i) {
        cout << p[i] << ' ';
    }
    return 0;
}