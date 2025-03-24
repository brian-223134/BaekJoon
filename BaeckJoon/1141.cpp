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

    // ���� �������� ���� (ª�� �� �տ� ������)
    sort(sentence.begin(), sentence.end());

    // ���λ� ���� Ȯ��
    vector<bool> isPrefix(n, false);
    for (int i = 0; i < n; ++i) {
        if (isPrefix[i]) continue;  // �̹� ���λ� ���� ������ ��ŵ
        for (int j = i + 1; j < n; ++j) {
            if (sentence[j].substr(0, sentence[i].size()) == sentence[i]) {
                isPrefix[i] = true;
                break;
            }
        }
    }

    // ���λ� �ƴ� �ֵ� ���� ����
    int result = 0;
    for (int i = 0; i < n; ++i) {
        if (!isPrefix[i]) result++;
    }

    cout << result << "\n";
    return 0;
}