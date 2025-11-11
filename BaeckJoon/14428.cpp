#include <iostream>
#include <vector>
#include <cstdint>
#include <limits>

using namespace std;

struct Node {
    long long val;
    int idx; // 0-based index
};

class SegmentTree {
public:
    SegmentTree(const vector<long long>& a) {
        n = (int)a.size();
        tree.resize(n * 4);
        build(a, 1, 0, n - 1);
    }

    void update(int pos, long long value) {
        update(1, 0, n - 1, pos, value);
    }

    int queryIndex(int l, int r) {
        Node res = query(1, 0, n - 1, l, r);
        return res.idx;
    }

private:
    int n;
    vector<Node> tree;

    Node better(const Node& A, const Node& B) {
        if (A.val < B.val) return A;
        if (A.val > B.val) return B;
        // 값 동일하면 더 작은 인덱스
        return (A.idx < B.idx) ? A : B;
    }

    void build(const vector<long long>& a, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = {a[l], l};
            return;
        }
        int mid = (l + r) >> 1;
        build(a, idx << 1, l, mid);
        build(a, idx << 1 | 1, mid + 1, r);
        tree[idx] = better(tree[idx << 1], tree[idx << 1 | 1]);
    }

    void update(int idx, int l, int r, int pos, long long value) {
        if (l == r) {
            tree[idx] = {value, l};
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(idx << 1, l, mid, pos, value);
        else update(idx << 1 | 1, mid + 1, r, pos, value);
        tree[idx] = better(tree[idx << 1], tree[idx << 1 | 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) {
            return {numeric_limits<long long>::max(),
                    numeric_limits<int>::max()};
        }
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) >> 1;
        Node L = query(idx << 1, l, mid, ql, qr);
        Node R = query(idx << 1 | 1, mid + 1, r, ql, qr);
        return better(L, R);
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int M;
    if (!(cin >> N)) return 0;
    vector<long long> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];

    SegmentTree seg(arr);

    cin >> M;
    while (M--) 
    {
        int t;
        int a;
        long long b;
        cin >> t >> a >> b;
        if (t == 1) {
            seg.update(a - 1, b);
        } else if (t == 2) {
            int l = a - 1;
            int r = (int)b - 1;
            if (l > r) std::swap(l, r);
            int ansIdx = seg.queryIndex(l, r);
            cout << (ansIdx + 1) << '\n';
        }
    }

    return 0;
}