#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

class SegmentTree {
public:
    SegmentTree(const vector<long long>& data) {
        n = (int)data.size();
        tree.resize(n * 4);
        build(data, 1, 0, n - 1);
    }

    void update(int pos, long long value) {
        update(1, 0, n - 1, pos, value);
    }

    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

private:
    int n;
    vector<long long> tree;

    void build(const vector<long long>& a, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(a, idx << 1, l, mid);
        build(a, idx << 1 | 1, mid + 1, r);
        tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
    }

    void update(int idx, int l, int r, int pos, long long value) {
        if (l == r) {
            tree[idx] = value;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(idx << 1, l, mid, pos, value);
        else update(idx << 1 | 1, mid + 1, r, pos, value);
        tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
    }

    long long query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0LL;
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) >> 1;
        return query(idx << 1, l, mid, ql, qr) + query(idx << 1 | 1, mid + 1, r, ql, qr);
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    if (!(cin >> N >> M >> K)) return 0;
    vector<long long> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];

    SegmentTree seg(arr);

    int total = M + K;
    while (total--) {
        int a;
        long long b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            seg.update((int)b - 1, c);
        } else if (a == 2) {
            int l = (int)b - 1;
            int r = (int)c - 1;
            if (l > r) std::swap(l, r);
            cout << seg.query(l, r) << '\n';
        }
    }
    return 0;
}
