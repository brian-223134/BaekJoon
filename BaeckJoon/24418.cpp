#include <iostream>

using namespace std;

int comb[31][31];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 31; i++) comb[i][0] = comb[i][i] = 1;
	for (int i = 2; i < 31; i++) {
		for (int j = 1; j < i; j++) comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
	}

	int N; cin >> N;
	cout << 2 * comb[2 * N - 1][N] << ' ' << N * N;
}