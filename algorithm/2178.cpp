#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int maze[101][101];
bool visited[101][101];
int cnt[101][101] = { 0,0, };

int x_dir[4] = { -1,1,0,0 }; //»óÇÏÁÂ¿ì xÁÂÇ¥
int y_dir[4] = { 0,0,-1,1 }; //»óÇÏÁÂ¿ì yÁÂÇ¥

int n, m;

void bfs(int a, int b) {
	visited[a][b] = true;
	queue<pair<int, int>> que;
	que.push(make_pair(a, b));
	cnt[a][b]++;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + x_dir[i];
			int ny = y + y_dir[i];

			if ((nx > 0 && nx < n + 1) && (ny > 0 && ny < m + 1) && !visited[nx][ny] && maze[nx][ny] == 1) {
				visited[nx][ny] = true;
				que.push(make_pair(nx, ny));
				cnt[nx][ny] = cnt[x][y] + 1;
			}
		}
	}


}


int main() {
	cin >> n >> m;
	char temp;
	string str;
	for (int i = 1; i < n + 1; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			temp = str[j] - '0';
			maze[i][j + 1] = temp;
		}
	}
	bfs(1, 1);

	cout << cnt[n][m] << endl;


}