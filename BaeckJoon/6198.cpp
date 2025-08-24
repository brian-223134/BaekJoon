#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    stack<int> s;
    long long result = 0;

    for (int i = 0; i < N; ++i)
    {
        int height;
        cin >> height;

        while (!s.empty() && s.top() <= height) 
        {
            s.pop();
        }

        result += s.size();

        s.push(height);
    }

    cout << result << "\n";

    return 0;
}