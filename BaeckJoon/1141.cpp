#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> sentence(n);
    for (int i = 0; i < n; i++) {
        cin >> sentence[i];
    }

    // 길이 기준으로 정렬 (짧은 게 앞에 오도록)
    sort(sentence.begin(), sentence.end());

    // 접두사 관계 확인
    vector<bool> isPrefix(n, false);
    for (int i = 0; i < n; ++i) {
        if (isPrefix[i]) continue;  // 이미 접두사 판정 받으면 스킵
        for (int j = i + 1; j < n; ++j) {
            if (sentence[j].substr(0, sentence[i].size()) == sentence[i]) {
                isPrefix[i] = true;
                break;
            }
        }
    }

    // 접두사 아닌 애들 개수 세기
    int result = 0;
    for (int i = 0; i < n; ++i) {
        if (!isPrefix[i]) result++;
    }

    cout << result << "\n";
    return 0;
}