#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    int prev_max[3] = {0}, prev_min[3] = {0};
    int cur_max[3], cur_min[3];

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (i == 0)
        {
            prev_max[0] = prev_min[0] = a;
            prev_max[1] = prev_min[1] = b;
            prev_max[2] = prev_min[2] = c;
        } else 
        {
            cur_max[0] = max(prev_max[0], prev_max[1]) + a;
            cur_max[1] = max({prev_max[0], prev_max[1], prev_max[2]}) + b;
            cur_max[2] = max(prev_max[1], prev_max[2]) + c;

            cur_min[0] = min(prev_min[0], prev_min[1]) + a;
            cur_min[1] = min({prev_min[0], prev_min[1], prev_min[2]}) + b;
            cur_min[2] = min(prev_min[1], prev_min[2]) + c;

            for (int j = 0; j < 3; j++) 
            {
                prev_max[j] = cur_max[j];
                prev_min[j] = cur_min[j];
            } 
        }
    }
    cout << max({prev_max[0], prev_max[1], prev_max[2]}) << " " << min({prev_min[0], prev_min[1], prev_min[2]});
    return 0;
}