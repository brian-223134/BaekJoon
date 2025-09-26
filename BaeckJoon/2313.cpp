#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<pair<int, int>> answer;     // �� ���� [L, R] (1-based)
    long long total_sum = 0;

    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        vector<int> a(m);
        vector<long long> pref(m + 1, 0);
        for (int j = 0; j < m; j++) {
            cin >> a[j];
            pref[j + 1] = pref[j] + a[j];
        }

        // ���� ���� (��, ����, L, R)�� ����
        long long best_sum = LLONG_MIN;
        int best_L = 1, best_R = 1;

        // �ּ� prefix ���� "���� ������" �ε����� ����
        // ���� prefix ���� ���� �� ������, �� "������" �ε����� ���
        // ���� �տ��� ���� ���̰� ª�����ϴ�.
        long long min_pref = 0;
        int min_idx = 0; // pref[min_idx] == min_pref

        for (int r = 1; r <= m; r++) {
            long long cur_sum = pref[r] - min_pref;
            int L = min_idx + 1;
            int R = r;

            // 1) ���� �� ũ�� ����
            // 2) ���� ������ ���̰� �� ª�� ���� ����
            // 3) �׷��� ������ L(����)�� �� ���� ��
            // 4) �׷��� ������ R(��)�� �� ���� ��
            if (cur_sum > best_sum
                || (cur_sum == best_sum && (R - L) < (best_R - best_L))
                || (cur_sum == best_sum && (R - L) == (best_R - best_L) && L < best_L)
                || (cur_sum == best_sum && (R - L) == (best_R - best_L) && L == best_L && R < best_R)) {
                best_sum = cur_sum;
                best_L = L;
                best_R = R;
            }

            // ������ ���� �ּ� prefix ����:
            // �� ���� prefix�� ������ ��ü,
            // ���� prefix�� ������ "�� ������ �ε���"�� ��ü�� �ξ�
            // ���� ���� ���� ���� �� ������ ª�������� ��.
            if (pref[r] < min_pref) {
                min_pref = pref[r];
                min_idx = r;
            }
            else if (pref[r] == min_pref) {
                min_idx = r; // ���� ������ ���� tie ó���� �ٽ�
            }
        }

        total_sum += best_sum;
        answer.push_back({ best_L, best_R });
    }

    cout << total_sum << '\n';
    for (auto& p : answer) cout << p.first << ' ' << p.second << '\n';
    return 0;
}
