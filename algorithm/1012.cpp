#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int t, m, n, k, x, y;

int map[50][50];
int visited[50][50];

int dir_x[4] = { -1,1,0,0 };
int dir_y[4] = { 0,0,-1,1 };

int cnt = 0;

void reset() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

void dfs(int a, int b) {
	visited[a][b] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = a + dir_x[i];
		int ny = b + dir_y[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if (map[nx][ny] == 1 && visited[nx][ny] == 0) {
			dfs(nx, ny);
		}
	}
}




int main() {
	cin >> t;
	for (int q = 0; q < t; q++) {
		cin >> m >> n >> k;
		reset();
		vector<int> v;

		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[x][y] = 1;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {
					dfs(i, j);
					v.push_back(cnt);
					cnt = 0;
				}
			}
		}

		cout << v.size() << endl;
	}
	return 0;
}