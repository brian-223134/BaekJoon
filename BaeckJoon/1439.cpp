#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int count0 = 0; // 0으로 이루어진 연속된 그룹의 수
    int count1 = 0; // 1로 이루어진 연속된 그룹의 수

    // 첫 번째 문자에 대한 처리
    if (s[0] == '0') {
        count0++;
    }
    else {
        count1++;
    }

    // 두 번째 문자부터 이전 문자와 비교하며 그룹 개수 카운트
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != s[i - 1]) { // 문자가 달라지는 지점(새로운 그룹 시작)
            if (s[i] == '0') {
                count0++;
            }
            else {
                count1++;
            }
        }
    }

    // 두 그룹 중 더 적은 횟수를 출력
    cout << min(count0, count1) << '\n';

    return 0;
}