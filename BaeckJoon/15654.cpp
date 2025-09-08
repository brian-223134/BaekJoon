#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
bool visited[8];

void solution(int index, const vector<int>& numbers)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[index] = numbers[i];
            solution(index + 1, numbers);
            visited[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());

    solution(0, numbers);

    return 0;
}