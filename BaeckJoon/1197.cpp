#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> p(100005, -1);
tuple<int, int, int> edge[100005];

// union_find ���
int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v)
{
	u = find(u); v = find(v);
	if (u == v) return 0;
	if (p[u] == p[v]) p[u]--;
	if (p[u] < p[v]) p[v] = u;
	else p[u] = v;
	return 1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int v, e;
	cin >> v >> e; // ����, ���� ����

	for (int i = 0; i < e; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		edge[i] = { cost, start, end };
	}

	sort(edge, edge + e); // ������ cost�� ������������ ����
	int count = 0;
	int solution = 0;

	for (int i = 0; i < e; i++)
	{
		int start, end, cost;
		tie(cost, start, end) = edge[i];
		if (!is_diff_group(start, end)) continue;
		solution += cost;
		count++;
		if (count == v - 1) break;
	}

	cout << solution;

	return 0;
}