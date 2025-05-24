#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool compare(const string& a, const string& b) {
    return a + b > b + a;
}

void custom_sort(vector<string>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!compare(arr[i], arr[j])) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<string> numbers(n);

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    custom_sort(numbers);

    // 예외 처리: 모든 숫자가 0인 경우 → 000 → 0
    if (numbers[0] == "0") {
        cout << "0\n";
    }
    else {
        for (const auto& num : numbers) {
            cout << num;
        }
        cout << '\n';
    }

    return 0;
}
