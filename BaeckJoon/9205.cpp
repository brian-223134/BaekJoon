#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int test; // test case 수
int store_num; // 편의점 개수

typedef struct point {
	int y_point;
	int x_point;
} point;

point home, festival;
point store[101];
bool visited[101]; // 편의점 방문 여부

// 거리 계산 함수 (맨해튼 거리)
bool isReachable(point a, point b) 
{
	int dist = abs(a.x_point - b.x_point) + abs(a.y_point - b.y_point);
	return dist <= 1000; // 맥주 20병 * 50m
}

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> test;
	while (test--) {
		cin >> store_num;
		cin >> home.x_point >> home.y_point;

		for (int i = 0; i < store_num; i++) 
		{
			cin >> store[i].x_point >> store[i].y_point;
		}

		cin >> festival.x_point >> festival.y_point;

		memset(visited, false, sizeof(visited)); // 방문 배열 초기화

		queue<point> q;
		q.push(home);

		bool isHappy = false;

		while (!q.empty()) 
		{
			point current = q.front();
			q.pop();

			// 현재 위치에서 페스티벌까지 도달 가능하면 종료
			if (isReachable(current, festival)) 
			{
				isHappy = true;
				break;
			}

			// 편의점들 순회
			for (int i = 0; i < store_num; i++) 
			{
				if (!visited[i] && isReachable(current, store[i])) 
				{
					visited[i] = true;
					q.push(store[i]);
				}
			}
		}

		cout << (isHappy ? "happy" : "sad") << '\n';
	}

	return 0;
}