#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<pair<int, int>> answer;     // 각 줄의 [L, R] (1-based)
    long long total_sum = 0;

    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        vector<int> a(m);
        vector<long long> pref(m + 1, 0);
        for (int j = 0; j < m; j++) {
            cin >> a[j];
            pref[j + 1] = pref[j] + a[j];
        }

        // 최적 구간 (합, 길이, L, R)을 관리
        long long best_sum = LLONG_MIN;
        int best_L = 1, best_R = 1;

        // 최소 prefix 값과 "가장 오른쪽" 인덱스를 유지
        // 같은 prefix 값이 여러 번 나오면, 더 "오른쪽" 인덱스를 써야
        // 같은 합에서 구간 길이가 짧아집니다.
        long long min_pref = 0;
        int min_idx = 0; // pref[min_idx] == min_pref

        for (int r = 1; r <= m; r++) {
            long long cur_sum = pref[r] - min_pref;
            int L = min_idx + 1;
            int R = r;

            // 1) 합이 더 크면 갱신
            // 2) 합이 같으면 길이가 더 짧은 구간 선택
            // 3) 그래도 같으면 L(시작)이 더 작은 것
            // 4) 그래도 같으면 R(끝)이 더 작은 것
            if (cur_sum > best_sum
                || (cur_sum == best_sum && (R - L) < (best_R - best_L))
                || (cur_sum == best_sum && (R - L) == (best_R - best_L) && L < best_L)
                || (cur_sum == best_sum && (R - L) == (best_R - best_L) && L == best_L && R < best_R)) {
                best_sum = cur_sum;
                best_L = L;
                best_R = R;
            }

            // 다음을 위해 최소 prefix 갱신:
            // 더 작은 prefix를 만나면 교체,
            // 같은 prefix를 만나면 "더 오른쪽 인덱스"로 교체해 두어
            // 이후 같은 합이 나올 때 구간이 짧아지도록 함.
            if (pref[r] < min_pref) {
                min_pref = pref[r];
                min_idx = r;
            }
            else if (pref[r] == min_pref) {
                min_idx = r; // 길이 단축을 위한 tie 처리의 핵심
            }
        }

        total_sum += best_sum;
        answer.push_back({ best_L, best_R });
    }

    cout << total_sum << '\n';
    for (auto& p : answer) cout << p.first << ' ' << p.second << '\n';
    return 0;
}
