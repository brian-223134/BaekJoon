#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k;
int lotto[6];

// numbers: �Է¹��� ���� ����
// start: Ž���� ������ �ε���
// depth: ������� ������ ������ ����
void generateCombinations(const vector<int>& numbers, int start, int depth)
{
    // 1. Base Case: 6���� ���ڸ� ��� �������� ���
    if (depth == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << lotto[i] << " ";
        }
        cout << '\n';
        return;
    }

    // 2. Recursive Step: ���� ����
    // start �ε������� �����Ͽ� ���������� ����
    for (int i = start; i < k; i++)
    {
        lotto[depth] = numbers[i]; // ���� ����(depth)�� ���ڸ� ����
        generateCombinations(numbers, i + 1, depth + 1); // ���� ���ڴ� ���� ��ġ(i) �������� Ž��
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