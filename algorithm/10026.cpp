#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int cnt = 0;
char map[100][100];
int visited[100][100];

int dir_x[4] = { -1,1,0,0 };
int dir_y[4] = { 0,0,-1,1 };

void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dir_x[i];
		int ny = y + dir_y[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (visited[nx][ny] == 0 && map[x][y] == map[nx][ny]) {
			dfs(nx, ny);
		}
	}
}


int main() {
	cin >> n;
	char temp;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			temp = str[j];
			map[i][j] = temp;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'G') map[i][j] = 'R';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;

}