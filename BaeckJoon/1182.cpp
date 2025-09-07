#include <iostream>
using namespace std;

int n, s;
int arr[20];
int result = 0;

// 선택을 하지 않는 경우까지 모두 탐색하므로 index == n일때의 값을 비교하면 됨.
void solution(int index, int sum) 
{
    if (index == n) 
    {
        if (sum == s) result++;
        return;
    }
    // 현재 원소를 포함하는 경우
    solution(index + 1, sum + arr[index]);
    // 현재 원소를 포함하지 않는 경우
    solution(index + 1, sum);
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> arr[i];

    solution(0, 0);

    // s가 0인 경우, 공집합도 카운트되므로 1을 빼줌
    if (s == 0) result--;

    cout << result;
    return 0;
}