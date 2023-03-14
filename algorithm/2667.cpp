#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[25][25];
int visited[25][25];

int dir_x[4] = { -1,1,0,0 };
int dir_y[4] = { 0,0,-1,1 };

vector<int> vec;
int cnt = 0;

void dfs(int x, int y) {
	visited[x][y] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dir_x[i];
		int ny = y + dir_y[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

		if (map[nx][ny] == 1 && visited[nx][ny] == 0) {
			dfs(nx, ny);
		}
	}
}

int main() {
	cin >> n;
	string str;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			temp = str[j] - '0';
			map[i][j] = temp;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				dfs(i, j);
				vec.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(vec.begin(), vec.end());
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}

}