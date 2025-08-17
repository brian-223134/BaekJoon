#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

// �ൿ ���
// 1. �ֽ� �ϳ��� ���.
// 2. ���ϴ� ��ŭ ������ �ִ� �ֽ��� �Ǵ�.
// 3. �ƹ��͵� ���Ѵ�.

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; // �׽�Ʈ ���̽��� ��
    cin >> T;

    while (T--) 
    {
        int N; // ���� ��
        cin >> N;

        // �� ���� �ְ��� ������ ����
        // vector<int> prices(N); �� ����
        vector<int> prices;
        prices.reserve(N); // �̸� �޸� ������ �Ҵ��Ͽ� ȿ���� ����
        for (int i = 0; i < N; ++i) 
        {
            int price;
            cin >> price;
            prices.push_back(price);
        }

        long long total_profit = 0; // �ִ� ���� (�ڷ��� ����)
        int max_price = 0;          // ��������� ���� ��� �ְ�

        // �ڿ������� ��ȸ
        for (int i = N - 1; i >= 0; --i) 
        {
            // ���� �ְ��� ���ݱ����� �ִ� ���ݺ��� ������
            if (prices[i] > max_price) 
            {
                // �ִ� ������ ����
                max_price = prices[i];
            }
            // ���� �ְ��� �ִ� ���ݺ��� ������
            else 
            {
                // �� ���͸�ŭ ���Ϳ� ����
                total_profit += (max_price - prices[i]);
            }
        }
        cout << total_profit << "\n";
    }

    return 0;
}