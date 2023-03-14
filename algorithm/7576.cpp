#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int map[1001][1001];
int visited[1001][1001];

int dir_x[4] = { -1,1,0,0 };
int dir_y[4] = { 0,0,-1,1 };

queue <pair<int, int>>q;


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[j][i];
			visited[j][i] = -1;
			if (map[j][i] == 1) {
				q.push(make_pair(j, i));
				visited[j][i] = 0;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == 0 && visited[nx][ny] == -1) {
				visited[nx][ny] = visited[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(ans, visited[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == -1 && map[i][j] == 0) {
				ans = -1;
				break;
			}
		}
	}


	cout << ans << endl;
}
