#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <unordered_map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    unordered_map<string, pair<bool, bool>> table;
    
    int n, m; // n: 듣지도 못한 사람 수, m: 못 본 사람의 수
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        if (table.find(name) == table.end())
        {
            table[name].first = true;
        }
    }

    for (int i = 0; i < m; i++)
    {
        string name;
        cin >> name;
        table[name].second = true;
    }

    vector<string> name_set;
    int result = 0;

    for (const auto& entry : table)
    {
        if (entry.second.first == true && entry.second.second == true)
        {
            name_set.push_back(entry.first);
            result++;
        }
    }
    
    sort(name_set.begin(), name_set.end());
    cout << result << '\n';

    for (string it : name_set)
    {
        cout << it << '\n';
    }

    return 0;
}