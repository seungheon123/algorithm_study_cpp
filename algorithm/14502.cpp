#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int map[8][8];
int c_map[8][8];
int visited[8][8];

int dir_x[4] = { -1,1,0,0 };
int dir_y[4] = { 0,0,-1,1 };

int wall = 3;
int ans = 0;
vector<pair<int, int>> vec;
vector<int> v;


void clear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
}

void bfs() {
	queue<pair<int, int>> que;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c_map[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		que.push(make_pair(vec[i].first, vec[i].second));
	}
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (c_map[nx][ny] == 0 && visited[nx][ny] == 0) {
				visited[nx][ny] = 1;
				c_map[nx][ny] = 2;
				que.push(make_pair(nx, ny));
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c_map[i][j] == 0) {
				cnt++;
			}
		}
	}
	ans = max(ans, cnt);
	clear();
}

void make() {
	if (wall == 0) {
		return bfs();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				wall--;
				make();
				wall++;
				map[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				vec.push_back(make_pair(i, j));
			}
		}
	}
	make();
	cout << ans;
	return 0;
}