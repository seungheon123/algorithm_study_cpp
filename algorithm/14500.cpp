#include <iostream>
using namespace std;

int n, m;
int map[505][505];
int visited[505][505];
int dir_x[4] = { -1,1,0,0 };
int dir_y[4] = { 0,0,-1,1 };

int ans = 0;

void dfs(int x, int y, int dept, int sum) {
	visited[x][y] = 1;
	if (dept == 3) {
		if (sum > ans) {
			ans = sum;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dir_x[i];
		int ny = y + dir_y[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (visited[nx][ny] == 0) {
			dfs(nx, ny, dept + 1, sum + map[nx][ny]);
			visited[nx][ny] = 0;
		}
	}
}

void shape1(int x, int y) {
	int temp = 0;
	temp = map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x][y + 1];
	if (temp > ans) ans = temp;
}

void shape2(int x, int y) {
	int temp = 0;
	temp = map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x][y - 1];
	if (temp > ans) ans = temp;
}

void shape3(int x, int y) {
	int temp = 0;
	temp = map[x][y] + map[x][y - 1] + map[x + 1][y] + map[x][y + 1];
	if (temp > ans) ans = temp;
}

void shape4(int x, int y) {
	int temp = 0;
	temp = map[x][y] + map[x - 1][y] + map[x][y + 1] + map[x][y - 1];
	if (temp > ans) ans = temp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j, 0, map[i][j]);
			visited[i][j] = 0;
			if (i - 1 >= 0 && i + 2 <= n) {
				if (j + 2 <= m) {
					shape1(i, j);
				}
				if (j - 1 >= 0) {
					shape2(i, j);
				}
			}
			if (j - 1 >= 0 && j + 2 <= m) {
				if (i + 2 <= n) {
					shape3(i, j);
				}
				if (i - 1 >= 0) {
					shape4(i, j);
				}
			}
		}
	}
	cout << ans;
}