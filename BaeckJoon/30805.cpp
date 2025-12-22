#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int getCount(const unordered_map<int, int>& mp, int v)
{
    auto it = mp.find(v);
    return (it == mp.end()) ? 0 : it->second;
}

void updateCandidate(set<int>& cand,
                     const unordered_map<int, int>& ca,
                     const unordered_map<int, int>& cb,
                     int v)
{
    if (getCount(ca, v) > 0 && getCount(cb, v) > 0)
        cand.insert(v);
    else
        cand.erase(v);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int& v : a) cin >> v;

    int m;
    if (!(cin >> m)) return 0;

    vector<int> b(m);
    for (int& v : b) cin >> v;

    unordered_map<int, int> ca, cb;
    ca.reserve(static_cast<size_t>(n) * 2);
    cb.reserve(static_cast<size_t>(m) * 2);
    for (int v : a) ++ca[v];
    for (int v : b) ++cb[v];

    set<int> cand;
    for (const auto& kv : ca)
    {
        if (cb.find(kv.first) != cb.end())
            cand.insert(kv.first);
    }

    vector<int> ans;
    int i = 0, j = 0;
    while (!cand.empty() && i < n && j < m)
    {
        int pick = *cand.rbegin(); // 가장 큰 공통 값

        while (i < n && a[i] != pick)
        {
            int v = a[i++];
            if (--ca[v] == 0) updateCandidate(cand, ca, cb, v);
        }
        if (i == n) break;

        while (j < m && b[j] != pick)
        {
            int v = b[j++];
            if (--cb[v] == 0) updateCandidate(cand, ca, cb, v);
        }
        if (j == m) break;

        ans.push_back(pick);
        if (--ca[pick] == 0) updateCandidate(cand, ca, cb, pick);
        if (--cb[pick] == 0) updateCandidate(cand, ca, cb, pick);
        ++i; ++j;
    }

    cout << ans.size() << '\n';
    for (size_t idx = 0; idx < ans.size(); ++idx)
    {
        if (idx) cout << ' ';
        cout << ans[idx];
    }
    if (!ans.empty()) cout << '\n';
    return 0;
}