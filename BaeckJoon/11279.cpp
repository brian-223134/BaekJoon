#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    priority_queue<int> maxHeap;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if (temp == 0)
        {
            if (maxHeap.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << maxHeap.top() << '\n';
                maxHeap.pop();
            }
        }
        else
        {
            maxHeap.push(temp);
        }
    }

    return 0;
}