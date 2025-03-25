#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    cin >> N;

    vector<long long> dice(6);
    for (int i = 0; i < 6; i++) 
        cin >> dice[i];

    if (N == 1) {
        sort(dice.begin(), dice.end());
        long long sum = 0;
        for (int i = 0; i < 5; i++) sum += dice[i];
        cout << sum << "\n";
        return 0;
    }

    // ����ؾ��� ����: �ֻ����� ���� �����ؾ��Ѵ�. ����� ���� ������ ���� �߿��ϴ�.
    // �� �� �ּ�
    long long min1 = *min_element(dice.begin(), dice.end());

    // �� ���� ������ ��� �� �ּ�
    long long min2 = 1e10;
    for (int i = 0; i < 6; i++) 
    {
        for (int j = i + 1; j < 6; j++) 
        {
            if (i + j == 5) 
                continue; // ���ֺ��� ���� �Ұ���
            min2 = min(min2, dice[i] + dice[j]);
        }
    }

    // �� ���� ������ ��� �� �ּ�
    long long min3 = 1e10;

    // �ֻ��� ���� ���� ���Ѵ�
    vector<pair<int, int>> adj = { {0,1}, {0,2}, {0,3}, {0,4}, {1,2}, {1,3}, {1,5},
                                  {2,4}, {2,5}, {3,4}, {3,5}, {4,5} };
    
    for (int i = 0; i < 6; i++) 
    {
        for (int j = 0; j < 6; j++) 
        {
            if (i == j || i + j == 5) 
                continue;
            for (int k = 0; k < 6; k++) 
            {
                if (k == i || k == j || k + i == 5 || k + j == 5) 
                    continue;
                min3 = min(min3, dice[i] + dice[j] + dice[k]);
            }
        }
    }

    long long count3 = 4;
    long long count2 = 8 * (N - 2) + 4;
    long long count1 = (N - 2) * (N - 2) * 5 + (N - 2) * 4;

    long long answer = min3 * count3 + min2 * count2 + min1 * count1;
    cout << answer << "\n";
    return 0;
}