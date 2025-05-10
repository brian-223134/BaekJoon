#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> budget(n);
    int total = 0, max_req = 0;

    for (int i = 0; i < n; ++i) {
        cin >> budget[i];
        max_req = max(max_req, budget[i]);
    }

    int m;
    cin >> m;

    // ��û�� ���� ���꺸�� �۰ų� ������ �ִ밪 ���
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += budget[i];
    if (sum <= m) {
        cout << max_req;
        return 0;
    }

    // �̺� Ž�� ����
    int left = 0, right = max_req;
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        long long total_alloc = 0;
        for (int i = 0; i < n; ++i)
            total_alloc += min(budget[i], mid);

        if (total_alloc <= m) {
            answer = mid;          // ������ ���Ѽ� �ĺ�
            left = mid + 1;        // �� ū ���Ѽ� Ž��
        }
        else {
            right = mid - 1;       // �ʹ� ���� ������ �� ���̱�
        }
    }

    cout << answer;
    return 0;
}