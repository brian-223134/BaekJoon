#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

// 행동 방식
// 1. 주식 하나를 산다.
// 2. 원하는 만큼 가지고 있는 주식을 판다.
// 3. 아무것도 안한다.

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; // 테스트 케이스의 수
    cin >> T;

    while (T--) 
    {
        int N; // 날의 수
        cin >> N;

        // 각 날의 주가를 저장할 벡터
        // vector<int> prices(N); 와 동일
        vector<int> prices;
        prices.reserve(N); // 미리 메모리 공간을 할당하여 효율을 높임
        for (int i = 0; i < N; ++i) 
        {
            int price;
            cin >> price;
            prices.push_back(price);
        }

        long long total_profit = 0; // 최대 이익 (자료형 주의)
        int max_price = 0;          // 현재까지의 가장 비싼 주가

        // 뒤에서부터 순회
        for (int i = N - 1; i >= 0; --i) 
        {
            // 현재 주가가 지금까지의 최대 가격보다 높으면
            if (prices[i] > max_price) 
            {
                // 최대 가격을 갱신
                max_price = prices[i];
            }
            // 현재 주가가 최대 가격보다 낮으면
            else 
            {
                // 그 차익만큼 이익에 더함
                total_profit += (max_price - prices[i]);
            }
        }
        cout << total_profit << "\n";
    }

    return 0;
}