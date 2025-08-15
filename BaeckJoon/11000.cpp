#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> lec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> lec[i].first >> lec[i].second; // lec = {S, T}
    }

    // ���� �ð� ���� ����
    sort(lec.begin(), lec.end());

    // ���� �ð��� �����ϴ� �ּ� ��
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(lec[0].second);

    for (int i = 1; i < n; i++)
    {
        // ���� ���� ������ ���ǽ��� ��� ���
        if (pq.top() <= lec[i].first)
            pq.pop();
        pq.push(lec[i].second);
    }

    cout << pq.size();
    return 0;
}