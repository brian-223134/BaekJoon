#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;
int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    vector<int> cards(n);
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        cin >> cards[i];
        pq.push(cards[i]);
    }

    int result = 0;
    while (!pq.empty())
    {
        if (pq.size() == 1)
        {
            cout << result;
            return 0;
        }
        int _cur = pq.top(); pq.pop();
        int __cur = pq.top(); pq.pop();
        result += (_cur + __cur);
        pq.push(_cur + __cur);
    }

    return 0;
}