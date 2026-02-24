#include <iostream>
#include <algorithm>

using namespace std;

int count_arr[500005];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int max_count = 0;
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;

        // 해당 크기의 그릇 개수를 증가
        count_arr[size]++;

        // 가장 많이 등장한 빈도수 갱신
        max_count = max(max_count, count_arr[size]);
    }

    // 최솟값(최대 빈도수) 출력
    cout << max_count << "\n";

    return 0;
}