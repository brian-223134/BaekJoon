#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k;
int lotto[6];

// numbers: 입력받은 숫자 벡터
// start: 탐색을 시작할 인덱스
// depth: 현재까지 선택한 숫자의 개수
void generateCombinations(const vector<int>& numbers, int start, int depth)
{
    // 1. Base Case: 6개의 숫자를 모두 선택했을 경우
    if (depth == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << lotto[i] << " ";
        }
        cout << '\n';
        return;
    }

    // 2. Recursive Step: 조합 생성
    // start 인덱스부터 시작하여 오름차순을 유지
    for (int i = start; i < k; i++)
    {
        lotto[depth] = numbers[i]; // 현재 깊이(depth)에 숫자를 저장
        generateCombinations(numbers, i + 1, depth + 1); // 다음 숫자는 현재 위치(i) 다음부터 탐색
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while (cin >> k && k != 0)
    {
        vector<int> numbers(k);
        for (int i = 0; i < k; i++)
        {
            cin >> numbers[i];
        }

        generateCombinations(numbers, 0, 0);

        cout << '\n';
    }

    return 0;
}