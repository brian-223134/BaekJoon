#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int mn;
    int mx;
};

class SegmentTree {
public:
    SegmentTree(const vector<int>& data) {
        n = (int)data.size();
        tree.resize(n * 4);
        build(data, 1, 0, n - 1);
    }

    pair<int,int> query(int l, int r) {
        Node res = query(1, 0, n - 1, l, r);
        return {res.mn, res.mx};
    }

private:
    int n;
    vector<Node> tree;

    void build(const vector<int>& a, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = {a[l], a[l]};
            return;
        }
        int mid = (l + r) >> 1;
        build(a, idx << 1, l, mid);
        build(a, idx << 1 | 1, mid + 1, r);
        tree[idx].mn = min(tree[idx << 1].mn, tree[idx << 1 | 1].mn);
        tree[idx].mx = max(tree[idx << 1].mx, tree[idx << 1 | 1].mx);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) {
            return {INT32_MAX, INT32_MIN};
        }
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) >> 1;
        Node L = query(idx << 1, l, mid, ql, qr);
        Node R = query(idx << 1 | 1, mid + 1, r, ql, qr);
        return {min(L.mn, R.mn), max(L.mx, R.mx)};
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];

    SegmentTree seg(arr);

    while (M--) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        if (a > b) swap(a, b);
        auto res = seg.query(a, b);
        cout << res.first << ' ' << res.second << '\n';
    }
    return 0;
}