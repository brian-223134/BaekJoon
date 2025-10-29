#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

struct person
{
    string name;
    double height;
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;

    while (cin >> t, t != 0)
    {
        vector<person> people(t);
        for (int i = 0; i < t; i++)
        {
            cin >> people[i].name >> people[i].height;
        }

        sort(people.begin(), people.end(), [](person& a, person& b) { return a.height > b.height; });
        cout << people[0].name;
        for (int i = 1; i < t; i++)
        {
            if (people[0].height == people[i].height)
            {
                cout << ' ' << people[i].name;
            }
        }
        cout << '\n';
    }

    return 0;
}