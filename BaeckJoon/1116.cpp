#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<int> RotateToStart(const vector<int>& cycle, int startValue)
{
    int n = static_cast<int>(cycle.size());
    int startIndex = 0;
    for (int i = 0; i < n; ++i)
    {
        if (cycle[i] == startValue)
        {
            startIndex = i;
            break;
        }
    }

    vector<int> rotated;
    rotated.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        rotated.push_back(cycle[(startIndex + i) % n]);
    }
    return rotated;
}

static vector<int> MinimalRotation(const vector<int>& cycle)
{
    int n = static_cast<int>(cycle.size());
    int bestStart = 0;

    for (int s = 1; s < n; ++s)
    {
        bool better = false;
        bool worse = false;
        for (int i = 0; i < n; ++i)
        {
            int a = cycle[(s + i) % n];
            int b = cycle[(bestStart + i) % n];
            if (a < b)
            {
                better = true;
                break;
            }
            if (a > b)
            {
                worse = true;
                break;
            }
        }
        if (better && !worse)
        {
            bestStart = s;
        }
    }

    vector<int> rotated;
    rotated.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        rotated.push_back(cycle[(bestStart + i) % n]);
    }
    return rotated;
}

static bool CompareBlocks(const vector<int>& a, const vector<int>& b)
{
    int na = static_cast<int>(a.size());
    int nb = static_cast<int>(b.size());
    int total = na + nb;

    for (int i = 0; i < total; ++i)
    {
        int va = (i < na) ? a[i] : b[i - na];
        int vb = (i < nb) ? b[i] : a[i - nb];
        if (va != vb)
        {
            return va < vb;
        }
    }
    return false;
}

static bool LexicographicallySmaller(const vector<int>& a, const vector<int>& b)
{
    int n = static_cast<int>(a.size());
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
        {
            return a[i] < b[i];
        }
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N = 0;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> P[i];
    }

    vector<bool> visited(N, false);
    vector<vector<int>> cycles;
    int cycleIndexOfZero = -1;

    for (int i = 0; i < N; ++i)
    {
        if (visited[i])
        {
            continue;
        }

        vector<int> cycle;
        int cur = i;
        while (!visited[cur])
        {
            visited[cur] = true;
            cycle.push_back(cur);
            cur = P[cur];
        }

        if (find(cycle.begin(), cycle.end(), 0) != cycle.end())
        {
            cycleIndexOfZero = static_cast<int>(cycles.size());
        }
        cycles.push_back(cycle);
    }

    vector<int> cycle0 = RotateToStart(cycles[cycleIndexOfZero], 0);

    vector<vector<int>> blocks;
    for (int i = 0; i < static_cast<int>(cycles.size()); ++i)
    {
        if (i == cycleIndexOfZero)
        {
            continue;
        }
        blocks.push_back(MinimalRotation(cycles[i]));
    }

    sort(blocks.begin(), blocks.end(), CompareBlocks);

    vector<int> middle;
    for (const auto& block : blocks)
    {
        middle.insert(middle.end(), block.begin(), block.end());
    }

    vector<int> bestB;
    if (blocks.empty())
    {
        bestB = cycle0;
    }
    else
    {
        for (int cut = 0; cut < static_cast<int>(cycle0.size()); ++cut)
        {
            vector<int> candidate;
            candidate.reserve(N);

            candidate.insert(candidate.end(), cycle0.begin(), cycle0.begin() + cut + 1);
            candidate.insert(candidate.end(), middle.begin(), middle.end());
            candidate.insert(candidate.end(), cycle0.begin() + cut + 1, cycle0.end());

            if (bestB.empty() || LexicographicallySmaller(candidate, bestB))
            {
                bestB = candidate;
            }
        }
    }

    vector<int> A(N, 0);
    for (int i = 1; i < N; ++i)
    {
        A[bestB[i - 1]] = bestB[i];
    }
    A[bestB[N - 1]] = bestB[0];

    for (int i = 0; i < N; ++i)
    {
        if (i > 0)
        {
            cout << ' ';
        }
        cout << A[i];
    }
    cout << '\n';

    return 0;
}