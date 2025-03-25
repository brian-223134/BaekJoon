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

    // 고려해야할 조건: 주사위의 면을 고정해야한다. 경우의 수를 나누는 것이 중요하다.
    // 한 면 최소
    long long min1 = *min_element(dice.begin(), dice.end());

    // 두 면이 만나는 경우 중 최소
    long long min2 = 1e10;
    for (int i = 0; i < 6; i++) 
    {
        for (int j = i + 1; j < 6; j++) 
        {
            if (i + j == 5) 
                continue; // 마주보는 면은 불가능
            min2 = min(min2, dice[i] + dice[j]);
        }
    }

    // 세 면이 만나는 경우 중 최소
    long long min3 = 1e10;

    // 주사위 면의 쌍을 정한다
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