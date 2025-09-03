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

    int t;
    cin >> t;

    while (t--)
    {
        string func, arr_str;
        int n;
        cin >> func >> n >> arr_str;

        deque<int> d;
        string current_num_str = "";

        for (int i = 1; i < arr_str.length() - 1; i++)
        {
            if (arr_str[i] >= '0' && arr_str[i] <= '9')
            {
                current_num_str += arr_str[i];
            }
            else if (arr_str[i] == ',' || arr_str[i] == ']')
            {
                if (!current_num_str.empty())
                {
                    d.push_back(stoi(current_num_str));
                    current_num_str = "";
                }
            }
        }

        if (!current_num_str.empty())
        {
            d.push_back(stoi(current_num_str));
        }

        bool is_reversed = false;
        bool error_flag = false;

        for (char cmd : func)
        {
            if (cmd == 'R')
            {
                is_reversed = !is_reversed;
            }
            else
            {
                if (d.empty())
                {
                    cout << "error" << '\n';
                    error_flag = true;
                    break;
                }

                if (is_reversed) 
                {
                    d.pop_back();
                }
                else {
                    d.pop_front();
                }
            }
        }

        if (error_flag) continue;

        cout << "[";
        while (!d.empty())
        {
            if (is_reversed) 
            {
                cout << d.back();
                d.pop_back();
            }
            else 
            {
                cout << d.front();
                d.pop_front();
            }
            if (!d.empty()) 
            {
                cout << ",";
            }
        }
        cout << "]\n";
    }

    return 0;
}