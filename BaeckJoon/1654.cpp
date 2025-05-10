#include <iostream>
#include <algorithm>

using namespace std;

unsigned int N, K;
unsigned int list[10000];

bool possible(unsigned int length) {
    unsigned int count = 0;
    for (int i = 0; i < K; i++) {
        count += list[i] / length;
        if (count >= N) return true; // ���� ����
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K >> N;

    unsigned int max_length = 0;
    for (int i = 0; i < K; i++) {
        cin >> list[i];
        max_length = max(max_length, list[i]);
    }

    unsigned int left = 1, right = max_length + 1;  // upper_bound ����: right�� +1

    while (left < right) {
        unsigned int mid = (left + right) / 2;

        if (possible(mid)) {
            left = mid + 1;  // mid�� ���� �� �� ū ���̸� �õ�
        }
        else {
            right = mid;     // mid�� �Ұ��� �� �� ª�� ���̷�
        }
    }

    // left�� "�Ұ����� ���� ���� ��", ���� ������ left - 1
    cout << left - 1 << '\n';
    return 0;
}
