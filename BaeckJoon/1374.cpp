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

    // ���� �ð� ���� ����
    sort(lectures.begin(), lectures.end(), [](const Lecture& a, const Lecture& b) {
        return a.start < b.start;
    });

    // ������ �ð� ���� �ּ� ��
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) 
    {
        // ���� ���� ������ ���ǽ��� ���� ���� ���� ���� ������ ����
        if (!pq.empty() && pq.top() <= lectures[i].start) 
        {
            pq.pop();
        }
        pq.push(lectures[i].end);
    }

    cout << pq.size() << '\n';
    return 0;
}