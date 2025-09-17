#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct Lecture {
    int num, start, end;
} Lecture;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<Lecture> lectures(n);

    for (int i = 0; i < n; i++) 
    {
        cin >> lectures[i].num >> lectures[i].start >> lectures[i].end;
    }

    // 시작 시간 기준 정렬
    sort(lectures.begin(), lectures.end(), [](const Lecture& a, const Lecture& b) {
        return a.start < b.start;
    });

    // 끝나는 시간 기준 최소 힙
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) 
    {
        // 가장 빨리 끝나는 강의실이 현재 강의 시작 전에 끝나면 재사용
        if (!pq.empty() && pq.top() <= lectures[i].start) 
        {
            pq.pop();
        }
        pq.push(lectures[i].end);
    }

    cout << pq.size() << '\n';
    return 0;
}