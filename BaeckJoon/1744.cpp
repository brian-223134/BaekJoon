#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> 

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> positives;
    vector<int> negatives;
    long long sum = 0; 
    bool zero_exists = false;

    for (int i = 0; i < N; ++i) 
    {
        int num;
        cin >> num;
        if (num > 1) 
        {
            positives.push_back(num);
        }
        else if (num == 1) {
            sum += 1;
        }
        else if (num < 0) {
            negatives.push_back(num);
        }
        else 
        {
            zero_exists = true;
        }
    }


    sort(positives.begin(), positives.end(), greater<int>());

    for (size_t i = 0; i < positives.size(); i += 2) 
    {
        if (i + 1 < positives.size()) 
        {
            sum += (long long)positives[i] * positives[i + 1];
        }
        else
        {
            sum += positives[i];
        }
    }

    sort(negatives.begin(), negatives.end());

    for (size_t i = 0; i < negatives.size(); i += 2) 
    {
        if (i + 1 < negatives.size())
        { 
            sum += (long long)negatives[i] * negatives[i + 1];
        }
        else 
        {
            if (!zero_exists) 
            { 
                sum += negatives[i];
            }
        }
    }

    cout << sum << "\n";

    return 0;
}