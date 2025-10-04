#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> tree, lazy, a;

// XOR 전파
void propagate(int node, int start, int end)
{
    if (lazy[node] != 0)
    {
        // 구간 길이가 홀수면 구간 XOR 값에 lazy를 한 번 더 XOR
        if (((end - start + 1) & 1)) tree[node] ^= lazy[node];
        if (start != end)
        {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

void init(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start];
    }
    else
    {
        int mid = (start + end) / 2;
        init(node * 2, start, mid);
        init(node * 2 + 1, mid + 1, end);
        tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
    }
}

void update(int node, int start, int end, int l, int r, int val)
{
    propagate(node, start, end);
    if (r < start || end < l) return;
    if (l <= start && end <= r)
    {
        lazy[node] ^= val;
        propagate(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, l, r, val);
    update(node * 2 + 1, mid + 1, end, l, r, val);
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int query(int node, int start, int end, int l, int r)
{
    propagate(node, start, end);
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, l, r) ^ query(node * 2 + 1, mid + 1, end, l, r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h + 1));
    tree.assign(tree_size, 0);
    lazy.assign(tree_size, 0);

    init(1, 0, n - 1);

    int m;
    cin >> m;
    while (m--)
    {
        int what;
        cin >> what;
        if (what == 1)
        {
            int l, r, val;
            cin >> l >> r >> val;
            if (l > r) swap(l, r);
            update(1, 0, n - 1, l, r, val);
        }
        else if (what == 2)
        {
            int l, r;
            cin >> l >> r;
            if (l > r) swap(l, r);
            cout << query(1, 0, n - 1, l, r) << '\n';
        }
    }
    return 0;
}
