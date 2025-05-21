#include<iostream>
#include<algorithm>

using namespace std;

int N;
bool arr[102][102] = { false };

void floyd() // 플로이드-워샬이지만 길이가 모두 1인 경우로 상정, 인접 노드간의 연결을 mapping 후 symmetric한 지를 판단
{
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][k] && arr[k][j]) {
					arr[i][j] = true;
				}
			}
		}
	}

	bool flag = false;

	for (int i = 1; i <= N; i++) {
		if (arr[1][i] && arr[i][i]) flag = true;
	}

	if (flag) cout << "CYCLE";
	else cout << "NO CYCLE";
}

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N - 1; i++) {
		int cnt;
		cin >> cnt;

		for (int c = 0; c < cnt; c++) {
			int to;
			cin >> to;
			arr[i][to] = true;
		}
	}
	floyd();
	
	return 0;
}